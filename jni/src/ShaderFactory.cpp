#include "ShaderFactory.h"

// for native asset manager
#include <sys/types.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

extern AAssetManager* p_asset_mgr;

/**
 * Lazy implementation. @TODO
 * http://stackoverflow.com/questions/449436/singleton-instance-declared-as-static-variable-of-getinstance-method/449823#449823
 */
ShaderFactory& ShaderFactory::Instance()
{
    static ShaderFactory sShaderFactory;
    return sShaderFactory;
}


ProgramPtr ShaderFactory::registerProgram(string name)
{
	GLuint vertexShader;
	GLuint fragmentShader;

	string V_SHADER_EXT, F_SHADER_EXT,SHADERS_PATH;
	Configuration::Instance().Get("VERTEX_SHADER_EXT",V_SHADER_EXT);
	Configuration::Instance().Get("FRAGMENT_SHADER_EXT",F_SHADER_EXT);
	Configuration::Instance().Get("SHADERS_PATH",SHADERS_PATH);

	vertexShader = compileShader(SHADERS_PATH+name+V_SHADER_EXT, GL_VERTEX_SHADER);
	fragmentShader = compileShader(SHADERS_PATH+name+F_SHADER_EXT, GL_FRAGMENT_SHADER);

	ProgramPtr program(new Program(vertexShader, fragmentShader));

	if(!link(program)) {
		LOGE("Cannot link program");
		ProgramPtr program;
		return program;
	} else {
		LOGI("Program: %s linked\n", name.c_str());
		mProgramsMap.insert(pair<string, ProgramPtr>(name,program));
		return program;
	}

}

ProgramPtr ShaderFactory::getProgram(string name)
{
	ProgramPtr program;
	map<string, ProgramPtr>::iterator it;
	it = mProgramsMap.find(name);
	if (it != mProgramsMap.end()) {
		program = it->second;
	}
	return program;
}


GLuint ShaderFactory::compileShader(string path, GLenum shaderType)
{
    GLuint shader;
    GLint compiled;

    const char *s_path = path.c_str();
    char *shaderSrc = loadShaderFromFile(s_path);

    shader = glCreateShader(shaderType);

    if(shader == 0)
        return 0;

    glShaderSource(shader, 1,  const_cast<const GLchar**>(&shaderSrc), NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled) {
        GLint infoLen = 0;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1) {
            char *infoLog = (char*) malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            LOGI("Error compiling shader:\n%s\n", infoLog);
            free(infoLog);
        }

        glDeleteShader(shader);
        return 0;
    }

    free(shaderSrc);
    return shader;
}

char* ShaderFactory::loadShaderFromFile(const char *path)
{
    AAsset *shaderAsset= AAssetManager_open(p_asset_mgr, path, AASSET_MODE_BUFFER);
    size_t length = AAsset_getLength(shaderAsset);

    LOGI("Shader source size: %d\n", length);

    char* buffer = (char*) malloc(length);

    AAsset_read(shaderAsset, buffer, length);

    buffer[length - 1] = '\0';

    LOGI("Shader source : %s\n", buffer);

    AAsset_close(shaderAsset);

    return buffer;
}

bool ShaderFactory::link(ProgramPtr program)
{
    GLint linked;

    GLuint program_id = program->getProgramId();
    GLuint vertex_shader = program->getVertexShader();
    GLuint fragment_shader = program->getFragmentShader();

    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);

    glLinkProgram(program_id);

    // Get linkage errors if any
    glGetProgramiv(program_id, GL_LINK_STATUS, &linked);

    if (!linked) {
        GLint infoLen = 0;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &infoLen);
        char *infoLog = (char*) malloc(sizeof(char) * infoLen);
        glGetProgramInfoLog(program_id, infoLen, NULL, infoLog);
        LOGI("Error linking shader program\n%s\n", infoLog);
        glDeleteProgram(program_id);
        free(infoLog);
        return false;
    }

    // Init atribs & uniforms of program
    initUniformLocations(program);
    initAttributeLocations(program);

    return true;
}

void ShaderFactory::initUniformLocations(ProgramPtr program) {
	// Init
	int total = -1;
	int name_len=-1;
	int num = -1;
	GLenum type = GL_ZERO;
	char name[100];

	GLuint program_id = program->getProgramId();

	// Get total
	glGetProgramiv( program_id,
				GL_ACTIVE_UNIFORMS,
				&total );

	// Iterate over all
	for(int i=0; i<total; ++i)  {
	    name_len=-1;
	    num=-1;

	    glGetActiveUniform( program_id,
	    		GLuint(i),
	    		sizeof(name)-1,
	    		&name_len,
	    		&num,
	    		&type,
	    		name );

	    name[name_len] = 0;

	    GLuint location = glGetUniformLocation( program_id, name );

	    program->setUniformLocation(name,location);
	}
}

void ShaderFactory::initAttributeLocations(ProgramPtr program) {
	// Init
	int total = -1;
	int name_len=-1;
	int num = -1;
	GLenum type = GL_ZERO;
	char name[100];

	GLuint program_id = program->getProgramId();

	// Get total
	glGetProgramiv( program_id,
				GL_ACTIVE_ATTRIBUTES,
				&total );

	// Iterate over all
	for(int i=0; i<total; ++i)  {
		name_len=-1;
		num=-1;

		glGetActiveAttrib( program_id,
				GLuint(i),
				sizeof(name)-1,
				&name_len,
				&num,
				&type,
				name );

		name[name_len] = 0;

		GLuint location = glGetAttribLocation( program_id, name );

		program->setAttributeLocation(name,location);
	}
}

