#include "GLESDemo.h"
#include "ShaderFactory.h"
#include "Resource.h"
#include "Managers/SceneManager.h"
#include "Managers/AssetManager.h"
#include "Managers/RenderManager.h"

extern AAssetManager* p_asset_mgr;

void GLESDemo::initShaders() {
	// Load configuration order matters
	Configuration::Instance().Load("GLDemo.cfg");

	// Register Simple Program
	mSimpleProgram = ShaderFactory::Instance().registerProgram("simple");

	// Error check
	if (!mSimpleProgram) {
		LOGE("Pogram simple not found in shader factory");
	}
}

void GLESDemo::drawOneFrame(float ellapsedTime) {

	float angle = ellapsedTime * 1000 / 75;

	mRenderManager.Render();

	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
	glm::mat4 mvp = projection * view * model;

	GLint mvpId = mSimpleProgram->getUniformLocation("mvp");
	GLint textureLocation = mSimpleProgram->getUniformLocation("atexcoord");

	glUniform1i(textureLocation, 0);
	glUniformMatrix4fv(mvpId, 1, GL_FALSE, &mvp[0][0]);
	//todo: extract the world position of object, mesh should just
	cube->draw(mSimpleProgram);
}

void GLESDemo::positInit() {
	initManagers();
	initShaders();
	initScene();
}

void GLESDemo::InitializeCamera() {
	LOGI("initializing camera");
	GameObject::GameObjectPtr camera(new GameObject());
	LOGI("camera initialized");
	Camera::CameraPtr cam = camera->addComponent<Camera>();
	LOGI("component added");
	cam->setPerspective(45.0, (double) width / height, 1, 100);
	LOGI("set perspective");
}

void GLESDemo::initScene() {
	//TODO: should go to scene manager
	InitializeCamera();
	LOGI("camera exit");
	Material::MaterialPtr mat(new Material());
	pTexture = mTextureManager.getTexture(std::string("textures/image.png"));
	mat->initialize(mSimpleProgram, pTexture);
	LOGI("material init");
	go = new GameObject();
	LOGI("object created");
	Renderer::RendererPtr rend = go->addComponent<Renderer>();
	rend->setMaterial(mat);
	mRenderManager.AddRenderer(rend);
	cube = new Cube();
	projection = glm::perspective(45.0, (double) width / height, 0.1, 100.0);
	view = glm::lookAt(glm::vec3(0, 0, -15), glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0));
	model = glm::mat4(1.0f);
}

void GLESDemo::initManagers() {
	AssetManager::Instance().Initialize(p_asset_mgr);
	mRenderManager.init(width, height);
}

