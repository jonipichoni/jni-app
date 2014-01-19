#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <android/asset_manager.h>
#include <android/native_activity.h>
#include <android_native_app_glue.h>

#include "my_log.h"

using namespace std;

class Configuration
{
public:
    // clear all values
    void Clear();

    /**
     * Lazy implementation. @TODO
     * http://stackoverflow.com/questions/449436/singleton-instance-declared-as-static-variable-of-getinstance-method/449823#449823
     */
    static Configuration& Instance()
    {
        static Configuration sConfiguration;
        return sConfiguration;
    }

    // load a configuration file
    bool Load(const string& File);

    // check if value associated with given key exists
    bool Contains(const string& key) const;

    // get value associated with given key
    bool Get(const string& key, string& value) const;
    bool Get(const string& key, int&    value) const;
    bool Get(const string& key, long&   value) const;
    bool Get(const string& key, double& value) const;
    bool Get(const string& key, bool&   value) const;

    // We need the android context for the asset manager
	void setAndroidContext(android_app* _androidContext){
		mAndroidContext = _androidContext;
	}

private:
	//This is the interface for the standard glue code of a threaded application.
    android_app* mAndroidContext;

    // the container
    map<string,string> data;

    // remove leading and trailing tabs and spaces
    static string Trim(const string& str);
};


#endif /* CONFIGURATION_H_ */
