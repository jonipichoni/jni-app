/*
 * Renderer.cpp
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#include "Components/Renderer.h"

Renderer::Renderer(const GameObject& p_parent):IComponent(p_parent)  {
	// TODO Auto-generated constructor stub

}
Renderer::Renderer(const GameObject& p_parent, int a):IComponent(p_parent) {

}
Renderer::~Renderer() {
	//
	if (mpMesh!=NULL) {
		//delete _mesh;
	}
	if (mpMaterial!=NULL) {
		//delete _material;
	}
}
void Renderer::setMesh(const Mesh::MeshPtr p_mesh) {
	mpMesh = p_mesh;
}

void Renderer::setMaterial(const Material::MaterialPtr p_material) {
	mpMaterial = p_material;
}
void Renderer::Render(){

}
const Mesh::MeshPtr Renderer::getMesh() const {
	return mpMesh;
}

const Material::MaterialPtr Renderer::getMaterial() const {
	return mpMaterial;
}

