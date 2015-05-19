//
//  Chopper.cpp
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#include "Chopper.h"

Chopper* Chopper::createKnife(float v, float y)
{
    Chopper* knife = Chopper::create();
    knife->retain();
    knife->chopper = Sprite::createWithSpriteFrameName("knife4.png");
    knife->chopper->setScale(0.6);
    PhysicsBody *body = PhysicsBody::create();
    body->setGravityEnable(true);
    //body->setGravityEnable(false);
    body->setVelocity(Vec2(0, -v));
    knife->chopper->setPhysicsBody(body);
    knife->chopper->setPosition(Vec2(410, y));
    return knife;
}

bool Chopper::isInCutterEdge()
{
    //return false;
    return chopper->getPositionY()>468.606934&&chopper->getPositionY()<712.269897;
}

bool Chopper::isInHilt()
{
    //return false;
    return chopper->getPositionY()>=365.625458&&chopper->getPositionY()<=468.606934;
}

void Chopper::removeFromParent()
{
    chopper->removeFromParent();
    this->release();
}

Sprite* Chopper::getKnife()
{
    
    return chopper;
}