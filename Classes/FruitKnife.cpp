//
//  FruitKnife.cpp
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#include "FruitKnife.h"
FruitKnife* FruitKnife::createKnife(float v,float y)
{
    FruitKnife* knife = FruitKnife::create();
    knife->retain();
    knife->fruitKnife = Sprite::createWithSpriteFrameName("knife2.png");
    knife->fruitKnife->setScale(0.6);
    PhysicsBody *body = PhysicsBody::create();
    //body->setGravityEnable(false);
    body->setGravityEnable(true);
    body->setVelocity(Vec2(0, -v));
    knife->fruitKnife->setPhysicsBody(body);
    knife->fruitKnife->setPosition(Vec2(410, y));
    return knife;
}

bool FruitKnife::isInCutterEdge()
{
    //return false;
    return fruitKnife->getPositionY()>443.144409&&fruitKnife->getPositionY()<528.970520;
}

bool FruitKnife::isInHilt()
{
    //return false;
    return fruitKnife->getPositionY()>=528.970520&&fruitKnife->getPositionY()<=638.976013;
}

void FruitKnife::removeFromParent()
{
    fruitKnife->removeFromParent();
    this->release();
}

Sprite* FruitKnife::getKnife()
{
    
    return fruitKnife;
}