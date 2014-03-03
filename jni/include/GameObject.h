/*
 * GameObject.h
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Components/IComponent.h"
#include "Components/Transform.h"
#include "Components/Renderer.h"
#include "boost/shared_ptr.hpp"
#include "boost/make_shared.hpp"
#include <list>

class IComponent;

class GameObject {

public:
	typedef boost::shared_ptr<GameObject> GameObjectPtr;
	typedef std::list<GameObjectPtr> ChildGameObject;
	GameObject();
	GameObject(GameObject::GameObjectPtr p_parent, bool p_isStatic);
	virtual ~GameObject();

	template <class T>
	boost::shared_ptr<T> addComponent() {
		boost::shared_ptr<T> ptr(new T(*this));
		mComponents.push_back(ptr);
		return ptr;
	}
	void notifyDelete(GameObjectPtr p_child);
	//inline const boost::uuids::uuid GetUID() const { return m_UID;};
	inline int getUID() const { return mUID;};
	inline bool getIsStatic() const {return mIsStatic;};
	Transform& getTransform() {return mTransform;};

private:
	GameObjectPtr mpParent;
	bool mIsStatic;
	Transform mTransform;
	int mUID;
	IComponent::ComponentList mComponents;
	ChildGameObject mChild;
};

#endif /* GAMEOBJECT_H_ */
