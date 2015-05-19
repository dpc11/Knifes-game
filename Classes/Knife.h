#ifndef __knifes__Knife__
#define __knifes__Knife__

#include "cocos2d.h"
USING_NS_CC;

class Knife : public Ref
{
public:
//    static Sprite* createSword(float v,float y);
//    static Sprite* createChopper(float v,float y);
//    static Sprite* createFruitKnife(float v,float y);
//    static Sprite* createFence(float v,float y);
    virtual bool init();
    //CREATE_FUNC(Knife);
    virtual bool isInCutterEdge() = 0;
    virtual bool isInHilt() = 0;
    virtual void removeFromParent() = 0;
    virtual Sprite* getKnife() = 0;
};

#endif /* defined(__knifes__Knife__) */
