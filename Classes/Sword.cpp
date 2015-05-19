//
//  Sword.cpp
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#include "Sword.h"

Sword* Sword::createKnife(float v, float y)
{
    Sword* knife = Sword::create();
    knife->retain();
    knife->sword = Sprite::createWithSpriteFrameName("knife3.png");
    knife->sword->setScale(0.6);
    PhysicsBody *body = PhysicsBody::create();
    body->setGravityEnable(true);
    //body->setGravityEnable(false);
    body->setVelocity(Vec2(0, -v));
    knife->sword->setPhysicsBody(body);
    knife->sword->setPosition(Vec2(415, y));
    return knife;
}

bool Sword::isInCutterEdge()
{
    //return false;
    return sword->getPositionY()>449.457510&&sword->getPositionY()<678.506775;
}

bool Sword::isInHilt()
{
    //return false;
    return sword->getPositionY()>=399.492188&&sword->getPositionY()<=449.457510;
}

void Sword::removeFromParent()
{
    sword->removeFromParent();
    this->release();
}

Sprite* Sword::getKnife()
{
    //this->retain();
    return sword;
}