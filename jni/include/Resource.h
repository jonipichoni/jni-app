#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <sys/types.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

class Resource {
public:
	Resource(const char* pPath);
	Resource(AAssetManager* pAssetManager, const char* pPath);

	const char* getPath();

	bool open();
	void close();
	bool read(void* pBuffer, size_t pCount);

	off_t getLength();
	const void* bufferize();

private:
	const char* mPath;
	AAssetManager* mAssetManager;
	AAsset* mAsset;
};
#endif
