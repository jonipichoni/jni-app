/*
 * TextureManager.h
 *
 *  Created on: 28 Feb 2014
 *      Author: rogelio
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include <map>
#include <string>
#include <GLES2/gl2.h>
#include "GraphicsTexture.h"
#include "boost/shared_ptr.hpp"

class TextureManager {
public:
	TextureManager();
	virtual ~TextureManager();
	GraphicsTexture::TexturePtr getTexture(std::string pPath);
private:
	std::map<std::string, boost::shared_ptr<GraphicsTexture> > mTextures;
	bool registerTexture(std::string pPath);
	static void callback_read(png_structp pStruct,
			png_bytep pData, png_size_t pSize);
protected:
	uint8_t* loadImage(GraphicsTexture::TexturePtr pTexture);
	void unload(std::string pPath);

};

#endif /* TEXTUREMANAGER_H_ */
