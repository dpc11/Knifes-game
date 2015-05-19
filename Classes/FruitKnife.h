//
//  FruitKnife.h
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#ifndef __knifes__FruitKnife__
#define __knifes__FruitKnife__

#include "cocos2d.h"
#include "Knife.h"
USING_NS_CC;

class FruitKnife : public Knife
{
public:
    CREATE_FUNC(FruitKnife);
    static FruitKnife* createKnife(float v,float y);
    bool isInCutterEdge();
    bool isInHilt();
    void removeFromParent();
    Sprite* getKnife();
private:
    Sprite* fruitKnife;
};


#endif /* defined(__knifes__FruitKnife__) */
