/*
 * AssetManager.h
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_
#include <android/asset_manager.h>

#include <string>

class AssetManager {
public:
	static AssetManager& Instance();
	void Initialize(AAssetManager* _androidContext){
		mAndroidAssetManager = _androidContext;
	}
	bool hasFile(std::string p_path);
	char* loadFile(std::string p_path);
	AAsset* Open(std::string pPath, int pMode);
	void Close(AAsset* pAsset);

private:
	AssetManager(){}
	AssetManager(AssetManager const&);
	AAssetManager* mAndroidAssetManager;

};

#endif /* ASSETMANAGER_H_ */
