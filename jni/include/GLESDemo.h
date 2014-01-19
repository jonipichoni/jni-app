#ifndef GLESDEMO_H
#define GLESDEMO_H

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/quaternion.hpp"

#include "GLESApplication.h"
#include "Program.h"
#include "Cube.h"

using namespace std;

class GLESDemo : public GLESApplication
{
public:
    GLESDemo(android_app *app) : GLESApplication(app) {}
    ~GLESDemo() {}
    
    
protected:
    void initShaders();
    void drawOneFrame(double ellapsedTime);
    void positInit();
    void terminateWindow(android_app *app);
    void createTexture();

    ProgramPtr mSimpleProgram;
    
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    Cube *cube;
    GLuint texId;
    
};


#endif // GLESDEMO_H
