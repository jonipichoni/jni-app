#include "GLESDemo.h"
#include "ShaderFactory.h"
#include "Resource.h"

extern AAssetManager* p_asset_mgr;

void GLESDemo::initShaders()
{
	// Load configuration order matters
	Configuration::Instance().Load("GLDemo.cfg");

    // Register Simple Program
	mSimpleProgram = ShaderFactory::Instance().registerProgram("simple");

	// Error check
    if(!mSimpleProgram) {
    	LOGE("Pogram simple not found in shader factory");
    }
}

void GLESDemo::drawOneFrame(float ellapsedTime)
{

    float angle = ellapsedTime * 1000 / 75;

    model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
    
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    //glClearDepthf(0.0); ?
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(mSimpleProgram->getProgramId());

    if(pTexture) pTexture->apply();

    glm::mat4 mvp = projection * view * model;
    
    GLint mvpId = mSimpleProgram->getUniformLocation("mvp");
    GLint textureLocation = mSimpleProgram->getUniformLocation("atexcoord");
    
    glUniform1i(textureLocation, 0);
    glUniformMatrix4fv(mvpId, 1, GL_FALSE, &mvp[0][0]);
    
    cube->draw(mSimpleProgram);
    
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


void GLESDemo::createTexture()
{
	std::string file("image.png");
	pTexture = new GraphicsTexture(p_asset_mgr,file.c_str());

	if(!pTexture->load()) LOGE("Could load %s",file.c_str());
}
