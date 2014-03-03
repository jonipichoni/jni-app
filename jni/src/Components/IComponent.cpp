/*
 * IComponent.cpp
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#include "Components/IComponent.h"

IComponent::IComponent(const GameObject& p_parent):mGameObject(p_parent) {
	// TODO Auto-generated constructor stub

}

IComponent::~IComponent() {
	// TODO Auto-generated destructor stub
}

void IComponent::Destroy() {
	//TODO::implement destroy component, should notify all listeners for that type and the attached gameobject
}

