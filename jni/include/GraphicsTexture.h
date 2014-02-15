#ifndef _PACKT_GRAPHICSTEXTURE_HPP_
#define _PACKT_GRAPHICSTEXTURE_HPP_

#include "Resource.h"


#include <GLES/gl.h>
#include <png.h>

class GraphicsTexture {
public:
	GraphicsTexture(AAssetManager* pAssetManager, const char* pPath);

	const char* getPath();
	int32_t getHeight();
	int32_t getWidth();

	bool load();
	void unload();
	void apply();

protected:
	uint8_t* loadImage();

private:
	static void callback_read(png_structp pStruct,
		png_bytep pData, png_size_t pSize);

private:
	Resource mResource;
	GLuint mTextureId;
	int32_t mWidth, mHeight;
	GLint mFormat;
};

#endif
