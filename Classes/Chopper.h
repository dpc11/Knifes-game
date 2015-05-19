//
//  Chopper.h
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#ifndef __knifes__Chopper__
#define __knifes__Chopper__

#include "cocos2d.h"
#include "Knife.h"
USING_NS_CC;

class Chopper : public Knife
{
public:
    CREATE_FUNC(Chopper);
    static Chopper* createKnife(float v,float y);
    bool isInCutterEdge();
    bool isInHilt();
    void removeFromParent();
    Sprite* getKnife();
private:
    Sprite* chopper;
};

#endif /* defined(__knifes__Chopper__) */
