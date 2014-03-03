/*
 * AssetManager.cpp
 *
 *  Created on: 4 Feb 2014
 *      Author: rogelio
 */

#include "my_log.h"
#include "Managers/AssetManager.h"
#include "Assets/IAsset.h"

//#include <android/native_activity.h>

AssetManager& AssetManager::Instance()
{
    static AssetManager AssetManager;
    return AssetManager;
}

bool AssetManager::hasFile(std::string p_path) {
	return true;
}
AAsset* AssetManager::Open(std::string pPath, int pMode) {
	return AAssetManager_open(mAndroidAssetManager, pPath.c_str(), pMode);
}

void AssetManager::Close(AAsset* pAsset) {
	AAsset_close(pAsset);
}
char* AssetManager::loadFile(std::string p_path) {
	//if has no file throw exception
	AAsset *file= AAssetManager_open(mAndroidAssetManager, p_path.c_str(), AASSET_MODE_BUFFER);
	//assert(file!=NULL);
	size_t length = AAsset_getLength(file);
	LOGI("file name: %s\n", p_path.c_str());
   LOGI("file size: %d\n", length);

    char* buffer = (char*) malloc(length);

    int a = AAsset_read(file, buffer, length);
    LOGI("bytes read: %d\n", a);
    buffer[length - 1] = '\0';

   LOGI("file content: %s\n", buffer);

   AAsset_close(file);

   return buffer;
}
