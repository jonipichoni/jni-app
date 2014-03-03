/*
 * IAsset.h
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#ifndef IASSET_H_
#define IASSET_H_

#include <string>

class IAsset {
public:
	IAsset();
	virtual void initialize(char*  p_stream) = 0;
	virtual ~IAsset() = 0;
private:
	std::string mPath;
};

#endif /* IASSET_H_ */
