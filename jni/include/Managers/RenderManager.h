/*
 * RenderManager.h
 *
 *  Created on: 26 Feb 2014
 *      Author: rogelio
 */

#ifndef RENDERMANAGER_H_
#define RENDERMANAGER_H_
#include "Components/Camera.h"
#include "Components/Renderer.h"
#include "AssetComponents/Material.h"
#include "AssetComponents/Mesh.h"

#include <list>

class RenderManager {
public:
	RenderManager();
	virtual ~RenderManager();
	void init(int pWidth, int pHeight);
	void Render();
	void AddCamera(Camera::CameraPtr p_camera);
	void AddRenderer(Renderer::RendererPtr p_camera);
private:
	std::list<Camera::CameraPtr> mCameras;
	std::list<Renderer::RendererPtr> mRenderers;
	int mWidth;
	int mHeight;
	void BindMaterial(const Material::MaterialPtr pMaterial, glm::mat4 pMVP) const;
	//void BindMesh(const Mesh::MeshPtr pMesh) const;
};

#endif /* RENDERMANAGER_H_ */
