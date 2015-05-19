//
//  Hence.h
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#ifndef __knifes__Hence__
#define __knifes__Hence__

#include "cocos2d.h"
#include "Knife.h"
USING_NS_CC;

class Hence : public Knife
{
public:
    CREATE_FUNC(Hence);
    static Hence* createKnife(float v,float y);
    bool isInCutterEdge();
    bool isInHilt();
    void removeFromParent();
    Sprite* getKnife();
private:
    Sprite* hence;
};

#endif /* defined(__knifes__Hence__) */
