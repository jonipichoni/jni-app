/*
 * IComponent.h
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#ifndef ICOMPONENT_H_
#define ICOMPONENT_H_

#include "boost/shared_ptr.hpp"
#include <list>
#include <string>

class GameObject;

class IComponent {

public:
	typedef boost::shared_ptr<IComponent> IComponentPtr;
	typedef std::list<IComponentPtr> ComponentList;
	IComponent(const GameObject&  p_gameObject);
	virtual ~IComponent() = 0;
	virtual std::string getComponentType() = 0;
	const GameObject& getGameObject() {return mGameObject;};
	void Destroy();
private:
	const GameObject& mGameObject;
};



#endif /* ICOMPONENT_H_ */
