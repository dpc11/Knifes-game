#include "Knife.h"
USING_NS_CC;

//Sprite* Knife::createSword(float v,float y)
//{
//    Sprite* sword = Sprite::createWithSpriteFrameName("knife3.png");
//    sword->setScale(0.5);
//    PhysicsBody *body = PhysicsBody::create();
//    body->setGravityEnable(true);
//    body->setVelocity(Vec2(0,-v));
//    sword->setPhysicsBody(body);
//    sword->setPosition(Vec2(405,y));
//    return sword;
//}
//
////knife1
//Sprite* Knife::createChopper(float v, float y)
//{
//    Sprite* chopper = Sprite::createWithSpriteFrameName("knife1.png");
//    chopper->setScale(0.5);
//    PhysicsBody *body = PhysicsBody::create();
//    body->setGravityEnable(true);
//    body->setVelocity(Vec2(0,-v));
//    chopper->setPhysicsBody(body);
//    chopper->setPosition(Vec2(405,y));
//    return chopper;
//}

bool Knife::init()
{
    return true;
}