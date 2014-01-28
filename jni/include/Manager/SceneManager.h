/*
 * SceneManager.h
 *
 *  Created on: 28 Jan 2014
 *      Author: happyfinish
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_
#include <string>
#include <map>

using namespace std;
class SceneManager {

public:
	SceneManager();
	virtual ~SceneManager();
	void loadSceneByName(string path);
	void loadSceneByID(int p_id);
private:
	std::string m_sceneName;
	int m_sceneID;
	map<string,int> m_allScenes;
	void loadSceneDescriptors(string p_file);
};

#endif /* SCENEMANAGER_H_ */
