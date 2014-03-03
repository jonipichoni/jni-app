/*
 * Material.cpp
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#include "AssetComponents/Material.h"

Material::Material() {
	// TODO Auto-generated constructor stub

}

Material::~Material() {
	// TODO Auto-generated destructor stub
}
void Material::initialize(ProgramPtr p_program, GraphicsTexture::TexturePtr p_texture) {
	mpProgram = p_program;
	mpTexture = p_texture;
}
