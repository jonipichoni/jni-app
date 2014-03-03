#ifndef _PACKT_GRAPHICSTEXTURE_HPP_
#define _PACKT_GRAPHICSTEXTURE_HPP_

#include "Resource.h"

#include "boost/shared_ptr.hpp"
#include <GLES/gl.h>
#include <png.h>
//#include <png/png.h>

class GraphicsTexture {
public:
	typedef boost::shared_ptr<GraphicsTexture> TexturePtr;
	GraphicsTexture(const char* pPath);
	GraphicsTexture(AAssetManager* pAssetManager, const char* pPath);

	const char* getPath();
	int32_t getHeight();
	int32_t getWidth();
	void setSize(int32_t pWidth,int32_t pHeight);
	void setFormat(GLint pFormat);
	void setTextureId(GLuint pTextureId);
	bool load();
	void unload();
	void apply();
	GLuint getTextureId() const {return mTextureId;}
	GLint getFormat() const {return mFormat;};
	Resource& getResource() {return mResource;};

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
