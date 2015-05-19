#include "HelloWorldScene.h"
#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "MusicButton.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //背景音乐
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("areyouok.mp3",true);
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Plist.plist");
    Vec2 size = Director::getInstance()->getVisibleSize();
    
    // 创建背景
    auto BackgroundSprite = Sprite::create("background.jpg");
    BackgroundSprite->setAnchorPoint(Vec2(0, 0));
    BackgroundSprite->setPosition(Vec2(0, 0));
    addChild(BackgroundSprite);
    
    // 游戏名称
    auto LogoSprite = Sprite::createWithSpriteFrameName("title.png");
    LogoSprite->setAnchorPoint(Vect::ZERO);
    LogoSprite->setPosition(Vec2(80, 640));
    LogoSprite->setScale(0.9);
    addChild(LogoSprite);
    
    // 游戏名称图层
    MusicButton::getInstance()->playCatchHilt();
    auto Title1Sprite = Sprite::createWithSpriteFrameName("title1.png");
    Title1Sprite->setAnchorPoint(Vect::ZERO);
    Title1Sprite->setPosition(Vec2(110, 1400));
    Title1Sprite->setScale(0.9);
    addChild(Title1Sprite);
    auto Title1Move = MoveTo::create(0.4, Vec2(110, 640));
    Title1Sprite->runAction(Title1Move);
    
    auto Title2Sprite = Sprite::createWithSpriteFrameName("title2.png");
    Title2Sprite->setAnchorPoint(Vect::ZERO);
    Title2Sprite->setPosition(Vec2(500, 1400));
    Title2Sprite->setScale(0.9);
    addChild(Title2Sprite);
    auto Title2Delay = DelayTime::create(0.3);
    auto Title2Move = MoveTo::create(0.4, Vec2(225, 630));
    auto Title2Seq = Sequence::create(Title2Delay, Title2Move, NULL);
    Title2Sprite->runAction(Title2Seq);
    
    auto Title3Sprite = Sprite::createWithSpriteFrameName("title3.png");
    Title3Sprite->setAnchorPoint(Vec2(0.5, 0.8));
    Title3Sprite->setPosition(Vec2(800, 1000));
    Title3Sprite->setScale(0.9);
    addChild(Title3Sprite);
    auto Title3Delay = DelayTime::create(0.6);
    auto Title3Move = MoveTo::create(0.3, Vec2(485, 750));
    auto Title3Rot = RotateBy::create(0.3, -360);
    auto Title3Spa = Spawn::create(Title3Move, Title3Rot, NULL);
    auto Title3Seq = Sequence::create(Title3Delay, Title3Spa, NULL);
    Title3Sprite->runAction(Title3Seq);
    
    // 开始按钮
    auto StartButtonSprite = Sprite::createWithSpriteFrameName("button.png");
    
    // 开始按钮按下效果
    auto StartButtonPushed = Sprite::createWithSpriteFrameName("button.png");
    StartButtonPushed->setAnchorPoint(Vec2::ZERO);
    StartButtonPushed->setPosition(Vec2(20, 6));
    StartButtonPushed->setScale(0.9);
    
    // 开始菜单（仅包含开始按钮）
    auto StartMenuItem = MenuItemSprite::create(StartButtonSprite,StartButtonPushed, CC_CALLBACK_1(HelloWorld::startEvent, this));
    StartMenuItem->setAnchorPoint(Vect::ZERO);
    StartMenuItem->setPosition(Vect::ZERO);
    
    auto StartMenu = Menu::create(StartMenuItem, NULL);
    StartMenu->setAnchorPoint(Vect::ZERO);
    StartMenu->setPosition(Vec2(120, 200));
    
    addChild(StartMenu, 5);
    
    MusicButton *mb = MusicButton::getInstance();
    addChild(mb->getStopSprite(),7);
    addChild(mb->getStartSprite(),7);
    //mb->flushEventHandler();
    return true;
}

void HelloWorld::startEvent(Ref *sender)
{
    auto director = Director::getInstance();
    auto aGameScene = GameScene::createScene();
    director->runWithScene(aGameScene);
}