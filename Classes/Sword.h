//
//  Sword.h
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#ifndef __knifes__Sword__
#define __knifes__Sword__

#include "cocos2d.h"
#include "Knife.h"
USING_NS_CC;

class Sword : public Knife
{
public:
    CREATE_FUNC(Sword);
    static Sword* createKnife(float v,float y);
    bool isInCutterEdge();
    bool isInHilt();
    void removeFromParent();
    Sprite* getKnife();
private:
    Sprite* sword;
};

#endif /* defined(__knifes__Sword__) */
