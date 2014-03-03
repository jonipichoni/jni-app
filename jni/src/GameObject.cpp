/*
 * GameObject.cpp
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#include "GameObject.h"
#include "Components/Renderer.h"
GameObject::GameObject(): mTransform(*this) {

}
GameObject::GameObject(GameObject::GameObjectPtr p_parent = boost::shared_ptr<GameObject>(),
		bool p_isStatic = false)
:mpParent(p_parent), mIsStatic(p_isStatic), mTransform(*this), mUID((int)0564654654564) {

}

GameObject::~GameObject() {
	if (mpParent!=0) {
		//_parent->notifyDelete();
	}
	mChild.clear();
	mComponents.clear();
}

void GameObject::notifyDelete(GameObjectPtr p_child) {
	//remove child from child list
	p_child->getUID();
	//TODO:: implement observer. IDea could use udid on each gameObject to find in a map or iterate,
}




