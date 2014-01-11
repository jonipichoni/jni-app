#include "GLESDemo.h"
#include "res_texture.c"
#include "terran.c"

void GLESDemo::initShaders()
{
    GLuint vertexShader;
    GLuint fragmentShader;



    vertexShader = compileShader("shaders/simple.vsh", GL_VERTEX_SHADER);
    fragmentShader = compileShader("shaders/simple.fsh", GL_FRAGMENT_SHADER);
    
    simpleProgram = new ShaderProgram(vertexShader, fragmentShader);
    if(!simpleProgram->link()) {
        LOGI("Cannot link program");
    }
    
    shaderProgramObject = simpleProgram->getProgramId();
    
}

void GLESDemo::drawOneFrame(double ellapsedTime)
{
    float angle = ellapsedTime / 1000.0 * 75;
    model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
    
    
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    //glClearDepthf(0.0); ?
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shaderProgramObject);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texId);
    
    
    
    glm::mat4 mvp = projection * view * model;
    
    GLint mvpId = simpleProgram->getUniformLocation(MVP);
    
    GLint textureLocation = simpleProgram->getUniformLocation(TEXTURE);
    
    glUniform1i(textureLocation, 0);
    
    glUniformMatrix4fv(mvpId, 1, GL_FALSE, &mvp[0][0]);
    
    cube->draw(simpleProgram);
    
}

void GLESDemo::positInit()
{
	initShaders();
    createTexture();
    // Enable depth buffer
    glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	// Enable back face culling
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
    cube = new Cube();
    
    projection = glm::perspective(45.0, (double) width / height, 0.1, 100.0);
    view = glm::lookAt(glm::vec3(0, 0, -15), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    model = glm::mat4(1.0f);
}

void GLESDemo::terminateWindow(android_app *app)
{
    delete cube;
    delete simpleProgram;
}

void GLESDemo::createTexture()
{
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, // target
                 0,  // level, 0 = base, no minimap,
                 GL_RGB, // internalformat
                 terran.width,  // width
                 terran.height,  // height
                 0,  // border, always 0 in OpenGL ES
                 GL_RGB,  // format
                 GL_UNSIGNED_BYTE, // type
                 terran.pixel_data);
}
