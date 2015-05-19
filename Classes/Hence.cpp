//
//  Hence.cpp
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#include "Hence.h"
Hence* Hence::createKnife(float v,float y)
{
    Hence* knife = Hence::create();
    knife->retain();
    knife->hence = Sprite::createWithSpriteFrameName("knife1.png");
    knife->hence->setScale(0.7, 0.6);
    PhysicsBody *body = PhysicsBody::create();
    //body->setGravityEnable(false);
    body->setGravityEnable(true);
    body->setVelocity(Vec2(0, -v));
    knife->hence->setPhysicsBody(body);
    knife->hence->setPosition(Vec2(425, y));
    return knife;
}

bool Hence::isInCutterEdge()
{
    //return false;
    return hence->getPositionY()>491.514191&&hence->getPositionY()<693.101013;
}

bool Hence::isInHilt()
{
    //return false;
    return hence->getPositionY()>=386.336761&&hence->getPositionY()<=491.514191;
}

void Hence::removeFromParent()
{
    hence->removeFromParent();
    this->release();
}

Sprite* Hence::getKnife()
{
    
    return hence;
}