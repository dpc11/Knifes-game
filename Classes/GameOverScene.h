//
//  GameOverScene.h
//  knifes
//
//  Created by 李令昆 on 15/5/12.
//
//

#ifndef __knifes__GameOverScene__
#define __knifes__GameOverScene__

#include "cocos2d.h"

USING_NS_CC;

class GameOverScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //bool onTouchBegan(Touch *touch, Event *unused_event);
    
    //void onTouchMoved(Touch *touch, Event *unused_event);
    
    void startEvent(Ref *sender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);
    
    void restartEvent(Ref *sender);
    
private:
    Sprite* SubtitleSprite;
    void displayScore();
};


#endif /* defined(__knifes__GameOverScene__) */
