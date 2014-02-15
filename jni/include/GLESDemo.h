#ifndef GLESDEMO_H
#define GLESDEMO_H

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/quaternion.hpp"

#include "GLESApplication.h"
#include "Program.h"
#include "Cube.h"
#include "GraphicsTexture.h"

using namespace std;

class GLESDemo : public GLESApplication
{
public:
    GLESDemo() : GLESApplication() {}
    ~GLESDemo() {
    	if(cube) delete cube;
    	if(pTexture) delete pTexture;
    }
    
    void drawOneFrame(float ellapsedTime);
    
private:

    uint8_t* loadpng();

protected:
    void initShaders();
    void positInit();
    void createTexture();

    ProgramPtr mSimpleProgram;
    
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    Cube *cube;
    GraphicsTexture* pTexture;
    GLuint texId;
    
};


#endif // GLESDEMO_H
