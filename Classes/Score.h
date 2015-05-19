//
//  Score.h
//  knifes
//
//  Created by 罗夕 on 15/5/12.
//
//

#ifndef __knifes__Score__
#define __knifes__Score__

#include "cocos2d.h"
USING_NS_CC;

//
//auto scoreFont = Label::createWithSystemFont("X 3","Arial",30);
//scoreFont->setPosition(Vec2(150,150));
//scoreFont->setAnchorPoint(Vect::ZERO);
//scoreFont->retain();
//addChild(scoreFont,10);

class Score
{
public:
    static Score* getInstance();
    void reset();
    void addOne();
    //Label* getScoreLabel();
    const Vector<Sprite*>& getSpriteList() const;
private:
    Score();
    static Score* pScore;
    Vector<Sprite*> mSprite;
    int miScore;
};



#endif /* defined(__knifes__Score__) */
