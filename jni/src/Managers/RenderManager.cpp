/*
 * RenderManager.cpp
 *
 *  Created on: 26 Feb 2014
 *      Author: rogelio
 */

#include "Managers/RenderManager.h"

#include "glm/glm.hpp"
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/quaternion.hpp"
#include "my_log.h"
//class Transform;

RenderManager::RenderManager() {


}

RenderManager::~RenderManager() {
	// TODO Auto-generated destructor stub
}

void RenderManager::init(int pWidth, int pHeight) {
	mWidth = pWidth;
	mHeight = pHeight;
	// Enable depth buffer
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	// Enable back face culling
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
}

void RenderManager::BindMaterial(const Material::MaterialPtr pMaterial, glm::mat4 pMVP) const {
	glUseProgram(pMaterial->getProgramId());
	//foreach texture in the material
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pMaterial->getTextureId());
	/*model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
	model = glm::translate(model, glm::vec3(0,0.1,0));*/
	/*GLint mvpId = pMaterial->getUniformLocation("mvp");
	GLint textureLocation = pMaterial->getUniformLocation("atexcoord");
	glUniform1i(textureLocation, 0);
	glUniformMatrix4fv(mvpId, 1, GL_FALSE, &pMVP[0][0]);*/
}

/*void RenderManager::BindMesh(const Mesh::MeshPtr pMesh) const {

	//cube->draw(mSimpleProgram);
}*/

void RenderManager::Render() {

	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	//glClearDepthf(0.0); ?
	glViewport(0, 0, mWidth, mHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//todo:projection and view product should be cached unless values change
	//todo:if we have more than one camera, objects per camera should be managed using tags and mask manager
	glm::mat4 projection = mCameras.front().get()->getProjection();
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, -15), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 vp = projection*view;
	glm::mat4 mvp;
	//todo:needs typedef
	//todo: static objects dont net to be rendered every time and separately, static array or fbo
	for( std::list<Renderer::RendererPtr>::iterator it = mRenderers.begin(); it!=mRenderers.end(); ++it) {
		//todo: get transform of object
		//Transform tr = (*it)->getGameObject().getTransform();
		mvp = vp;
		BindMaterial((*it)->getMaterial(), mvp);
		//BindMesh((*it)->getMesh());
	}
}
void RenderManager::AddCamera(Camera::CameraPtr p_camera) {
	mCameras.push_back(p_camera);
}
void RenderManager::AddRenderer(Renderer::RendererPtr p_renderer) {
	mRenderers.push_back(p_renderer);
}

