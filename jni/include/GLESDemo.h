#ifndef GLESDEMO_H
#define GLESDEMO_H

// @todo investigate
#define GLM_FORCE_COMPILER_UNKNOWN
#define GLM_FORCE_PURE

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/quaternion.hpp"

#include "GLESApplication.h"
#include "Program.h"
#include "Cube.h"
#include "GraphicsTexture.h"
#include "GameObject.h"
#include "Managers/RenderManager.h"
#include "Managers/TextureManager.h"
using namespace std;

class GLESDemo : public GLESApplication
{
public:
    GLESDemo() : GLESApplication() {}
    ~GLESDemo() {
    	if(cube) delete cube;
    	//if(pTexture) delete pTexture;
    }
    
    void drawOneFrame(float ellapsedTime);
    
private:

    uint8_t* loadpng();
	void InitializeCamera();

protected:
	void initManagers();
	void initScene();
    void initShaders();
    void positInit();

    ProgramPtr mSimpleProgram;
    RenderManager mRenderManager;
    TextureManager mTextureManager;
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    Cube *cube;
    GraphicsTexture::TexturePtr pTexture;
    GLuint texId;
    GameObject* go;
    
};


#endif // GLESDEMO_H
