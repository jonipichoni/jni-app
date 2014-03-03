/*
 * TextureAsset.h
 *
 *  Created on: 5 Feb 2014
 *      Author: rogelio
 */

/*#ifndef TEXTUREASSET_H_
#define TEXTUREASSET_H_
#include <GLES/gl.h>
#include "png/png.h"

class Texture {
public:
	Texture();
	void initialize(char*  p_path);
	virtual ~Texture();
	int32_t getHeight();
	int32_t getWidth();
	GLuint getTexID() const {return _textureId;};
private:
	//void callback_read( png_structp png, png_bytep data, png_size_t size);
	GLuint _textureId;
	int32_t _width;
	int32_t _height;
	GLint _format;




};

#endif /* TEXTUREASSET_H_ */
