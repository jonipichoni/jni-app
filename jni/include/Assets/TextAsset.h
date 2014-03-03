/*
 * TextAsset.h
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#ifndef TEXTASSET_H_
#define TEXTASSET_H_
#include "Assets/IAsset.h"


class TextAsset : public IAsset{
public:
	TextAsset();
	virtual ~TextAsset();
	void initialize(char* p_stream);
	char* getContent();
private:
	char* _content;
};

#endif /* TEXTASSET_H_ */
