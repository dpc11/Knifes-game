
//
//  Score.cpp
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#include "Score.h"

Score* Score::pScore = nullptr;

Score* Score::getInstance()
{
    if(pScore==nullptr){
        Score::pScore = new Score;
    }
    return Score::pScore;
}

void Score::reset()
{
    miScore = 0;
    mSprite.clear();
    mSprite.pushBack(Sprite::createWithSpriteFrameName("0.png"));
}

void Score::addOne()
{
    miScore++;
    for(int i=0;i<mSprite.size();i++)
    {
        mSprite.at(i)->removeFromParent();
    }
    mSprite.clear();
    int t = miScore;
    char scoreFileName[10];
    while( t )
    {
        sprintf(scoreFileName,"%d.png",t%10);
        mSprite.pushBack(Sprite::createWithSpriteFrameName(scoreFileName));
        t/=10;
    }
}

const Vector<Sprite*>& Score::getSpriteList() const
{
    return mSprite;
}

Score::Score()
{
    miScore = 0;
}