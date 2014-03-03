/*
 * SceneManager.cpp
 *
 *  Created on: 28 Jan 2014
 *      Author: happyfinish
 */
#include "Configuration.h"
#include "Managers/SceneManager.h"
#include "my_log.h"
//#include "boost/property_tree/ptree.hpp"
//#include "boost/property_tree/json_parser.hpp"
#include <sstream>


SceneManager::SceneManager() {
	string SCENES_PATH, SCENES_DESCRIPTOR;
	//Configuration::Instance().Get("SCENES_PATH", SCENES_PATH);
	//Configuration::Instance().Get("SCENES_DESCRIPTOR", SCENES_DESCRIPTOR);
	this->loadSceneDescriptors(std::string("asdfasdf"));
	//this->loadSceneDescriptors(SCENES_PATH+SCENES_DESCRIPTOR);
}

SceneManager::~SceneManager() {

}


void SceneManager::loadSceneDescriptors(string p_file) {
	std::string json("{'foo':'bar'}");
	std::istringstream is(json);
	//boost::property_tree::ptree scene_tree;
	//boost::property_tree::read_json(is,scene_tree);
	//std::string foo = scene_tree.get<std::string> ("foo");
	//LOGI("json madafaka%s\n", foo.c_str());
}

void SceneManager::loadSceneByName(string path){
	//todo:: get rid of all objects in scene and remember to detach from managers
	//todo:: blocking and non blocking
}

void SceneManager::loadSceneByID(int p_id) {
	//todo:: get rid of all objects in scene and remember to detach from managers
	//todo:: blocking and non blocking
}



