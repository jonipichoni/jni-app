/*
 * Material.h
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_
#include "GLES2/gl2.h"
#include "boost/shared_ptr.hpp"
#include "GraphicsTexture.h"
#include "Program.h"

class Material {
public:
	typedef boost::shared_ptr<Material> MaterialPtr;

	Material();
	virtual ~Material();
	void initialize(ProgramPtr p_program, GraphicsTexture::TexturePtr p_texture);
	GLuint getProgramId() const {
		return mpProgram->getProgramId();
	}
	GLuint getTextureId() const {
		return  mpTexture->getTextureId();
	}

	GLuint getUniformLocation(std::string pName) {
		return mpProgram->getUniformLocation(pName);
	}

private :
	ProgramPtr mpProgram;
	//could be more than one texture and variables and stuff
	GraphicsTexture::TexturePtr mpTexture;
};



#endif /* MATERIAL_H_ */
