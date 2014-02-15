#ifndef SHADERFACTORY_H_
#define SHADERFACTORY_H_

#include <EGL/egl.h>
#include <GLES2/gl2.h>

// for native asset manager
#include <sys/types.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <boost/shared_ptr.hpp>
#include <string>
#include <map>

#include "my_log.h"
#include "Program.h"
#include "Configuration.h"

using namespace std;

// The factory - implements singleton pattern!
class ShaderFactory
{
public:
    // Get the single instance of the factory
    static ShaderFactory& Instance();

    // register a factory function to create an instance of className
    // It return the program created
    ProgramPtr registerProgram(string name);

    // Get a program
    ProgramPtr getProgram(string name);


private:
    // Singleton protection
    ShaderFactory(){}
    ShaderFactory(ShaderFactory const&);
    void operator=(ShaderFactory const&);

    // Compile a shader
    GLuint compileShader(string path,GLenum shaderType);

    // Load a buffer with the shader on path
    char* loadShaderFromFile(const char *path);

    // Link V and F of program
    bool link(ProgramPtr program);

    // Initialize uniforms of program
    void initUniformLocations(ProgramPtr program);

    // Initialize atribs of program
    void initAttributeLocations(ProgramPtr program);


private:

    // Map of the Programs
    map<string, ProgramPtr> mProgramsMap;

};

#endif /* SHADERFACTORY_H_ */
