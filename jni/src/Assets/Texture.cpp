/*
 * TextureAsset.cpp
 *
 *  Created on: 5 Feb 2014
 *      Author: rogelio
 */

/*#include "Assets/Texture.h"
#include "my_log.h"
#include <stdio.h>
#include <string>
Texture::Texture() {
	// TODO Auto-generated constructor stub

}

Texture::~Texture() {
	// TODO Auto-generated destructor stub
}
void callback_read(png_structp png, png_bytep data, png_size_t size) {

	char* reader = (char*)png_get_io_ptr(png);
	//void* read = data;
	LOGI("reading %s", (char*)reader);
	LOGI("reading2 %d", size);
	for (unsigned int i =0 ; i<size; i++) {
		//LOGI("value %d %c",i, png[i]);
		data[i]=reader[i];
		//reader++;
	}
	memcpy(data, reader, size);
	LOGI("reading3 %d", size);
}
void error_fn(png_structp png_ptr, png_const_charp error_msg) {
	LOGI("pngERROR:%s", error_msg);
}
void warning_fn(png_structp png_ptr, png_const_charp error_msg) {
	LOGI("pngWARNING:%s", error_msg);
}
void Texture::initialize(char* p_stream) {
	png_byte lHeader[8];
	png_structp lPngPtr = NULL;
	png_infop lInfoPtr = NULL;
	png_byte* lImageBuffer = NULL;
	png_bytep* lRowPtrs = NULL;
	png_int_32 lRowSize;
	bool lTransparency;
	//memcpy(lHeader, p_stream, 8);
	for (unsigned int i =0 ; i<8; i++) {
			//LOGI("value %d %c",i, png[i]);
			lHeader[i]=p_stream[i];
			LOGI("value:.%d, %#02x\n.",i, lHeader[i]);
	}

	LOGI("pngsignature:.%s.",lHeader);
	if (png_sig_cmp(lHeader, 0, 8) != 0) {
		LOGI("error on png");
		return;
	}

	lPngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if (!lPngPtr) {
		LOGI("error on png");
		return;
	}
	lInfoPtr = png_create_info_struct(lPngPtr);
	if (!lPngPtr) {
		png_destroy_read_struct(&lPngPtr, (png_infopp) NULL, (png_infopp) NULL);
		LOGI("error on png");
		return;
	}
	png_set_error_fn(lPngPtr,p_stream, error_fn, warning_fn);
	png_set_read_fn(lPngPtr, p_stream, callback_read);
	if (setjmp(png_jmpbuf(lPngPtr))) {
		LOGI("error on png");
		return;
	}
	LOGI("before 8 byte");
	png_set_sig_bytes(lPngPtr, 8);
	LOGI("readinfo");
	png_read_info(lPngPtr, lInfoPtr);
	LOGI("ihdr");
	png_int_32 lDepth, lColorType;
	png_uint_32 lWidth, lHeight;
	png_get_IHDR(lPngPtr, lInfoPtr, &lWidth, &lHeight, &lDepth, &lColorType,
			NULL, NULL, NULL);
	_width = lWidth;
	_height = lHeight;
	LOGI("asdfasdf");
	lTransparency = false;
	if (png_get_valid(lPngPtr, lInfoPtr, PNG_INFO_tRNS)) {
		png_set_tRNS_to_alpha(lPngPtr);
		lTransparency = true;
		LOGI("error on png");
		return;
	}
	if (lDepth < 8) {
		png_set_packing(lPngPtr);
	} else if (lDepth == 16) {
		png_set_strip_16(lPngPtr);
	}
	switch (lColorType) {
	case PNG_COLOR_TYPE_PALETTE:
		png_set_palette_to_rgb(lPngPtr);
		_format = lTransparency ? GL_RGBA : GL_RGB;
		break;
	case PNG_COLOR_TYPE_RGB:
		_format = lTransparency ? GL_RGBA : GL_RGB;
		break;
	case PNG_COLOR_TYPE_RGBA:
		_format = GL_RGBA;
		break;
	case PNG_COLOR_TYPE_GRAY:
		png_set_expand_gray_1_2_4_to_8(lPngPtr);
		_format = lTransparency ? GL_LUMINANCE_ALPHA : GL_LUMINANCE;
		break;
	case PNG_COLOR_TYPE_GA:
		png_set_expand_gray_1_2_4_to_8(lPngPtr);
		_format = GL_LUMINANCE_ALPHA;
		break;
	}
	//png_read_update_info(lPngPtr, lInfoPtr);

	lRowSize = png_get_rowbytes(lPngPtr, lInfoPtr);
	if (lRowSize <= 0) {
		LOGI("error on png");
		return;
	}
	lImageBuffer = new png_byte[lRowSize * lHeight];
	if (!lImageBuffer) {
		LOGI("error on png");
		return;
	}
	lRowPtrs = new png_bytep[lHeight];
	if (!lRowPtrs) {
		LOGI("error on png");
		return;
	}
	for (uint32_t i = 0; i < lHeight; ++i) {
		lRowPtrs[lHeight - (i + 1)] = lImageBuffer + i * lRowSize;
	}
	png_read_image(lPngPtr, lRowPtrs);

	png_destroy_read_struct(&lPngPtr, &lInfoPtr, NULL);
	delete[] lRowPtrs;
	LOGI("read succesful");
	if (lImageBuffer == NULL) {
		return;
	}

	//GLenum errorResult;
	glGenTextures(1, &_textureId);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	LOGI("width:%d", _width);
	LOGI("height:%d", _height);
	glTexImage2D(GL_TEXTURE_2D, 0, _format, _width, _height, 0, _format,
			GL_UNSIGNED_BYTE, (void*) lImageBuffer);
	delete[] lImageBuffer;
	//checkGLError();
}
*/
