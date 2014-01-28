/*
 * SceneManager.cpp
 *
 *  Created on: 28 Jan 2014
 *      Author: happyfinish
 */

#include "SceneManager.h"

SceneManager::SceneManager() {
	string SCENES_PATH, SCENES_DESCRIPTOR;
	Configuration::Instance().Get("SCENES_PATH", SCENES_PATH);
	Configuration::Instance().Get("SCENES_DESCRIPTOR", SCENES_DESCRIPTOR);
	this->loadSceneDescriptors(SCENES_PATH+SCENES_DESCRIPTOR);
}
	SceneManager::~SceneManager() {
	// TODO Auto-generated destructor stub
}


void loadSceneDescriptors(string p_file) {
	//todo::needs android context to open files, works like configuration key value
}

void loadSceneByName(string path){
	//todo:: get rid of all objects in scene and remember to detach from managers
	//todo:: blocking and non blocking
}

void loadSceneByID(int p_id) {
	//todo:: get rid of all objects in scene and remember to detach from managers
	//todo:: blocking and non blocking
}



