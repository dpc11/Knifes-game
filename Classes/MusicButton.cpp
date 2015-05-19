#include "MusicButton.h"


MusicButton* MusicButton::m_instance = nullptr;

MusicButton* MusicButton::getInstance(){
    if (m_instance == nullptr) {
        m_instance = new MusicButton();
    }
    return m_instance;
}

MusicButton::MusicButton()
{
    Vec2 size = Director::getInstance()->getVisibleSize();
    stopSprite = Sprite::create("stop.png");
    stopSprite->setScale(0.7);
    stopSprite->setPosition(size.x-70, 20);
    stopSprite->setAnchorPoint(Vect::ZERO);
    playBackground();
    startSprite = Sprite::create("start.png");
    startSprite->setScale(0.7);
    startSprite->setPosition(size.x-70, 20);
    startSprite->setAnchorPoint(Vect::ZERO);
    startSprite->setVisible(false);
    stopSprite->setVisible(true);
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MusicButton::onTouchBegan,this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,stopSprite);
    isMusicPlaying = true;
}

bool MusicButton::onTouchBegan(Touch *touch, Event *unused_event)
{
    Vec2 pt = touch->getLocation();
    if(pt.x < stopSprite->getPositionX() && pt.y>stopSprite->getPositionY() ) return false;
    if(isMusicPlaying){
        stopPlay();
        stopSprite->setVisible(false);
        startSprite->setVisible(true);
    } else {
        stopSprite->setVisible(true);
        startSprite->setVisible(false);
        CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
        playBackground();
    }
    isMusicPlaying = !isMusicPlaying;
    return true;
}

Sprite* MusicButton::getStopSprite(){
    return stopSprite;
}

Sprite* MusicButton::getStartSprite(){
    return startSprite;
}

void MusicButton::playBackground(){
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("areyouok.mp3", true);
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3);

}
void MusicButton::playCatchHilt(){
    if(isMusicPlaying) CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sword.wav", false);
    
}
void MusicButton::playCatchCutterEdge(){
    if(isMusicPlaying) CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("ku.wav", false);
}
void MusicButton::playNotCatch(){
    if(isMusicPlaying) CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("diao.wav", false);
}

void MusicButton::playGameOver(){
    if(isMusicPlaying) CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("xiao.mp3", false);
}
void MusicButton::stopPlay(){
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();

}

void MusicButton::prepare(){
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("areyouok.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sword.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("ku.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("diao.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("xiao.mp3");

}
