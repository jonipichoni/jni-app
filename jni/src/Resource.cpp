#include "Resource.h"

Resource::Resource(AAssetManager* pAssetManager, const char* pPath):
	mPath(pPath),
	mAssetManager(pAssetManager),
	mAsset(NULL)
{
}

bool Resource::open() {
	mAsset = AAssetManager_open(mAssetManager, mPath,
								AASSET_MODE_UNKNOWN);
	return (mAsset != NULL) ? true : false;
}

void Resource::close() {
	if (mAsset != NULL) {
		AAsset_close(mAsset);
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
