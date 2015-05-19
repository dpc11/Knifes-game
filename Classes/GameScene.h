#ifndef __knifes__GameScene__
#define __knifes__GameScene__

#include "cocos2d.h"
#include "Knife.h"
#include <cstdlib>
#include <ctime>

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
        
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    void onTouchEnded(Touch *touch, Event *unused_event);
    
    bool onTouchBegan(Touch *touch, Event *unused_event);
    
    void downSword(float dt);
    
    
private:
    Knife* createKnife();
    void gameOver(float dt);
    void gotKnife(float dt);
    void displayScore();
    Vector<SpriteFrame*> mFaceAnimationSucc;
    Vector<SpriteFrame*> mFaceAnimationFail;
    Vector<SpriteFrame*> mFaceAnimationMiss;
    Vector<SpriteFrame*> mHandAnimations;
    Sprite* mHandSprite;
    Sprite* mFaceSprite;
    Knife* mKnife;
    float mV;    
};

#endif /* defined(__knifes__GameScene__) */
