#include "Resource.h"
#include "Managers/AssetManager.h"

Resource::Resource(const char* pPath):
	mPath(pPath),
	mAsset(NULL)
{
}
Resource::Resource(AAssetManager* pAssetManager, const char* pPath):
	mPath(pPath),
	mAssetManager(pAssetManager),
	mAsset(NULL)
{
}

bool Resource::open() {
	mAsset = AssetManager::Instance().Open(mPath, AASSET_MODE_UNKNOWN);
	return (mAsset != NULL) ? true : false;
}

void Resource::close() {
	if (mAsset != NULL) {
		AssetManager::Instance().Close(mAsset);
		mAsset = NULL;
	}
}

bool Resource::read(void* pBuffer, size_t pCount) {
	int32_t lReadCount = AAsset_read(mAsset, pBuffer, pCount);
	return (lReadCount == (int32_t)pCount) ? true : false;
}

const char* Resource::getPath() {
	return mPath;
}

off_t Resource::getLength() {
	return AAsset_getLength(mAsset);
}

const void* Resource::bufferize() {
	return AAsset_getBuffer(mAsset);
}
