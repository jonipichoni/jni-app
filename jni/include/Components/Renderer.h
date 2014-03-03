/*
 * Renderer.h
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "Components/IComponent.h"
#include "AssetComponents/Material.h"
#include "AssetComponents/Mesh.h"


class Renderer: public IComponent {
public:
	typedef boost::shared_ptr<Renderer> RendererPtr;
	Renderer(const GameObject& p_parent);
	Renderer(const GameObject& p_parent, int a);
	virtual ~Renderer();
	std::string getComponentType() {return std::string("Renderer");};
	void setMesh(const Mesh::MeshPtr p_mesh);
	void setMaterial(const Material::MaterialPtr p_material);
	void Render();
	const Mesh::MeshPtr getMesh() const;
	const Material::MaterialPtr getMaterial() const;
private:
	Mesh::MeshPtr mpMesh;
	Material::MaterialPtr mpMaterial;
};

#endif /* RENDERER_H_ */
