//
//  Component.cpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/Component.hpp"
#include "headers/AXEntity.hpp"
#include "headers/Transform.hpp"
#include "headers/Renderer.hpp"

Component::Component(){
}

Component::~Component(){
}

AXEntity* Component::getOwner(){
    return owner;
}

Scene* Component::getScene() {
    return owner->getScene();
}

void Component::setOwner(AXEntity* o){
    this->owner = o;
    this->transform = owner->getTransform();
    this->renderer = owner->getRenderer();
}
