/*
 * TextAsset.cpp
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#include "Assets/TextAsset.h"
#include "my_log.h"
TextAsset::TextAsset() {
	// TODO Auto-generated constructor stub

}
TextAsset::~TextAsset() {
	free(_content);
}

void TextAsset::initialize(char* p_stream) {
	_content = p_stream;
}

char* TextAsset::getContent() {
	return _content;
}


