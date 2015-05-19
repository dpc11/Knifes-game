//
//  GameOverScene.cpp
//  knifes
//
//  Created by 李令昆 on 15/5/12.
//
//

#include "GameOverScene.h"
#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Score.h"
#include "MusicButton.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 创建背景
    
    auto BackgroundSprite = Sprite::create("background.jpg");
    BackgroundSprite->setAnchorPoint(Vec2(0,0));
    BackgroundSprite->setPosition(Vec2(0,0));
    addChild(BackgroundSprite);
    
    Vec2 size = Director::getInstance()->getVisibleSize();
    
    int randNum = rand()%5;
    char subtitleFilename[50];
    sprintf(subtitleFilename, "word%d.png",randNum+1);
    SubtitleSprite = Sprite::createWithSpriteFrameName(subtitleFilename);

    SubtitleSprite->setAnchorPoint(Vect::ZERO);
    SubtitleSprite->setPosition(Vec2(55, size.y/5*3));
    SubtitleSprite->setScale(1.1, 1.2);
    addChild(SubtitleSprite);
    
    // 显示分数
    auto SwordSprite = Sprite::createWithSpriteFrameName("knife3.png");
    SwordSprite->setAnchorPoint(Vec2::ZERO);
    SwordSprite->setPosition(Vec2(size.x/2-90, size.y/5*3-130));
    SwordSprite->setScale(0.5, 0.2);
    addChild(SwordSprite);
    
    auto xSprite = Sprite::createWithSpriteFrameName("x.png");
    xSprite->setAnchorPoint(Vec2::ZERO);
    xSprite->setPosition(Vec2(size.x/2-42, size.y/5*3-93));
    xSprite->setScale(0.8);
    addChild(xSprite);
    displayScore();
    
    // 重新开始按钮
    auto RestartButtonSprite = Sprite::createWithSpriteFrameName("continue.png");
    auto RestartButtonPushed = Sprite::createWithSpriteFrameName("continue.png");
    RestartButtonPushed->setAnchorPoint(Vec2::ZERO);
    RestartButtonPushed->setPosition(Vec2(16, 4));
    RestartButtonPushed->setScale(0.9);
    
    auto RestartMenuItem = MenuItemSprite::create(RestartButtonSprite,RestartButtonPushed, CC_CALLBACK_1(GameOverScene::restartEvent, this));
    RestartMenuItem->setAnchorPoint(Vect::ZERO);
    RestartMenuItem->setPosition(Vec2(0, 120));
    
    // 分享按钮
    //auto ShareButtonSprite = Sprite::createWithSpriteFrameName("share.png");
    //auto ShareButtonPushed = Sprite::createWithSpriteFrameName("share.png");
    //ShareButtonPushed->setAnchorPoint(Vec2::ZERO);
    //ShareButtonPushed->setPosition(Vec2(16, 4));
    //ShareButtonPushed->setScale(0.9);
    
    //auto ShareMenuItem = MenuItemSprite::create(ShareButtonSprite, ShareButtonPushed, CC_CALLBACK_1(GameOverScene::restartEvent, this));
    //ShareMenuItem->setAnchorPoint(Vect::ZERO);
    //ShareMenuItem->setPosition(Vect::ZERO);
    
    auto RestartMenu = Menu::create(RestartMenuItem /*, ShareMenuItem */, NULL);
    RestartMenu->setAnchorPoint(Vect::ZERO);
    RestartMenu->setPosition(Vec2(160, size.y/6));
    
    addChild(RestartMenu, 5);
    
    MusicButton *mb = MusicButton::getInstance();
    addChild(mb->getStopSprite(),7);
    addChild(mb->getStartSprite(),7);
    
    return true;
}

void GameOverScene::displayScore()
{
    Vec2 size = Director::getInstance()->getVisibleSize();
    auto scoreVector = Score::getInstance()->getSpriteList();
    for(int i=0;i<scoreVector.size();i++)
    {
        auto sprite = scoreVector.at(i);
        //sprite->setScale(0.8);
        sprite->setPosition(Vec2(size.x/2-30*i+20, size.y/5*3-100));
        addChild(sprite);
    }
}

void GameOverScene::restartEvent(Ref *sender)
{
    auto director = Director::getInstance();
    auto aGameScene = GameScene::createScene();
    director->runWithScene(aGameScene);
}