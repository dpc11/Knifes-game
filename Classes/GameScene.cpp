#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Knife.h"
#include "Sword.h"
#include "Chopper.h"
#include "FruitKnife.h"
#include "Hence.h"
#include "Score.h"
#include "GameOverScene.h"
#include "MusicButton.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    srand(time(NULL));
    
    Vec2 size = Director::getInstance()->getVisibleSize();
    
    mV = 0;
    
    
    // 创建背景
    auto BackgroundSprite = Sprite::create("background.jpg");
    BackgroundSprite->setAnchorPoint(Vec2(0, 0));
    BackgroundSprite->setPosition(Vec2(0, 0));
    addChild(BackgroundSprite);
    
    // 记分板
    auto SwordSprite = Sprite::createWithSpriteFrameName("knife3.png");
    SwordSprite->setAnchorPoint(Vec2::ZERO);
    SwordSprite->setPosition(Vec2(size.x-155, size.y-118));
    SwordSprite->setScale(0.4, 0.18);
    addChild(SwordSprite);
    
    auto xSprite = Sprite::createWithSpriteFrameName("x.png");
    xSprite->setAnchorPoint(Vec2::ZERO);
    xSprite->setPosition(Vec2(size.x-115, size.y-95));
    xSprite->setScale(0.7);
    addChild(xSprite);
    Score::getInstance()->reset();
    displayScore();
    
    // 添加主角人物
    auto PersonSprite = Sprite::createWithSpriteFrameName("person.png");
    PersonSprite->setAnchorPoint(Vec2(0, 0));
    PersonSprite->setPosition(Vec2(20, 30));
    PersonSprite->setScale(0.7);
    addChild(PersonSprite);
    
    // 添加脸部
    mFaceSprite = Sprite::createWithSpriteFrameName("face1.png");
    mFaceSprite->setAnchorPoint(Vect::ZERO);
    mFaceSprite->setPosition(Vect(73, 546));
    mFaceSprite->setScale(0.7);
    addChild(mFaceSprite);
    
    mFaceAnimationSucc.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("face3.png"));
    mFaceAnimationSucc.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("face1.png"));
    
    mFaceAnimationFail.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("face4.png"));
    mFaceAnimationFail.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("face1.png"));
    
    mFaceAnimationMiss.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("face2.png"));
    mFaceAnimationMiss.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("face1.png"));
    
    // 添加手部
    mHandSprite = Sprite::createWithSpriteFrameName("hand1.png");
    mHandSprite->setAnchorPoint(Vec2(0,0));
    mHandSprite->setScale(0.7);
    mHandSprite->setPosition(Vec2(365,511));
    addChild(mHandSprite);
    
    mHandAnimations.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("hand1.png"));
    mHandAnimations.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("hand2.png"));
    mHandAnimations.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("hand4.png"));
    mHandAnimations.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("hand1.png"));
    
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan,this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded,this);
    listener->setSwallowTouches(true);
    
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithSceneGraphPriority(listener,this);
    
    // 刀子测试
    //sword->setPosition(Vec2(420, orign.y));
    mKnife = createKnife();
    addChild(mKnife->getKnife());
    
    /*
     663.365173
     ng
     474.713837
     ok
     429.050385
     */
    
    MusicButton *mb = MusicButton::getInstance();
    addChild(mb->getStopSprite(),7);
    addChild(mb->getStartSprite(),7);
    
    this->schedule(schedule_selector(GameScene::downSword), 0.05);
    return true;
}

// 夕夕：定时器调用的函数
void GameScene::downSword(float dt)
{
    if(mKnife != nullptr && mKnife->getKnife()->getPositionY()<1e-8){
        mKnife->removeFromParent();
        mKnife = nullptr;
        
        // 失败脸部表情
        auto FaceAnimation = Animation::createWithSpriteFrames(mFaceAnimationFail, 1);
        auto FaceAnimate = Animate::create(FaceAnimation);
        mFaceSprite->runAction(FaceAnimate);
        
        MusicButton::getInstance()->playNotCatch();
        
        // NG
        unschedule(schedule_selector(GameScene::downSword));
        scheduleOnce(schedule_selector(GameScene::gameOver), 1);
        
        return;
    } else if(mKnife!=nullptr) return;
    
    Vec2 orign = Director::getInstance()->getVisibleSize();
    mKnife = createKnife();
    addChild(mKnife->getKnife());
    //gameOver();
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
    return true;
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    Vec2 size = Director::getInstance()->getVisibleSize();
    
    auto HandAnimation = Animation::createWithSpriteFrames(mHandAnimations, 0.05);
    auto HandAnimate = Animate::create(HandAnimation);
    mHandSprite->runAction(HandAnimate);

    if (mKnife == nullptr) return;
    
    CCLOG ("%f\n", mKnife->getKnife()->getPositionY());
    if (mKnife->isInCutterEdge())
    {
        
        // 失败脸部表情
        auto FaceAnimation = Animation::createWithSpriteFrames(mFaceAnimationFail, 1);
        auto FaceAnimate = Animate::create(FaceAnimation);
        mFaceSprite->runAction(FaceAnimate);
        
        MusicButton::getInstance()->playCatchCutterEdge();
        
        // 停止刀子
        mKnife->getKnife()->getPhysicsBody()->setVelocity(Vec2(0, 0));
        mKnife->getKnife()->getPhysicsBody()->setGravityEnable(false);
        
        // 流血效果
        ParticleSystem* BloodPar = ParticleSystemQuad::create("blood.plist");
        BloodPar->retain();
        ParticleBatchNode* BloodNode = ParticleBatchNode::createWithTexture(BloodPar->getTexture());
        BloodNode->addChild(BloodPar);
        BloodNode->setAnchorPoint(Vec2::ZERO);
        BloodNode->setPosition(Vec2(250, 300));
        addChild(BloodNode, 10);
        BloodPar->release();
        
        // NG
        scheduleOnce(schedule_selector(GameScene::gameOver), 1);
    }
    else if (mKnife->isInHilt())
    {
        // 成功脸部表情
        auto FaceAnimation = Animation::createWithSpriteFrames(mFaceAnimationSucc, 0.5);
        auto FaceAnimate = Animate::create(FaceAnimation);
        mFaceSprite->runAction(FaceAnimate);
        
        MusicButton::getInstance()->playCatchHilt();
        
        // 刀子动作
        mKnife->getKnife()->getPhysicsBody()->setVelocity(Vec2(0, 0));
        mKnife->getKnife()->getPhysicsBody()->setGravityEnable(false);
        auto KnifeMove = MoveTo::create(0.3, Vec2(Vec2(size.x-140, size.y-82)));
        auto KnifeScale = ScaleTo::create(0.4, 0.1);
        auto KnifeSpa = Spawn::create(KnifeMove, KnifeScale, NULL);
        mKnife->getKnife()->runAction(KnifeSpa);
        
        scheduleOnce(schedule_selector(GameScene::gotKnife), 0.5);
    }
    else
    {
        // Miss表情
        auto FaceAnimation = Animation::createWithSpriteFrames(mFaceAnimationMiss, 0.2);
        auto FaceAnimate = Animate::create(FaceAnimation);
        mFaceSprite->runAction(FaceAnimate);
    }
}

Knife* GameScene::createKnife()
{
    Vec2 orign = Director::getInstance()->getVisibleSize();
    mV += 0.15;
    float VV = mV/(mV+1)*1000;
    int randNum = rand()%4;
    //int randNum = 0;
    if(randNum==0)
        return Sword::createKnife(VV, orign.y);
    else if (randNum==1)
        return Chopper::createKnife(VV, orign.y);
    else if (randNum==2)
        return FruitKnife::createKnife(VV, orign.y);
    else
        return Hence::createKnife(VV, orign.y);
}

void GameScene::gameOver(float dt)
{
    auto gameOverScene = GameOverScene::createScene();
    Director::getInstance()->runWithScene(gameOverScene);
}

void GameScene::gotKnife(float dt)
{
    mKnife->removeFromParent();
    mKnife = nullptr;
    Score::getInstance()->addOne();
    displayScore();
}

void GameScene::displayScore()
{
    Vec2 size = Director::getInstance()->getVisibleSize();
    auto scoreVector = Score::getInstance()->getSpriteList();
    for(int i=0; i < scoreVector.size(); i++)
    {
        auto sprite = scoreVector.at(i);
        sprite->setAnchorPoint(Vect::ZERO);
        sprite->setPosition(Vec2(size.x-65-25*i, size.y-100));
        sprite->setScale(0.8);
        addChild(sprite, 5);
    }
}
