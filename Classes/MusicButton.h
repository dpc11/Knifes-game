#ifndef __knifes__MusicButton__
#define __knifes__MusicButton__


#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class MusicButton{
public:
    
    static MusicButton* getInstance();
    void playBackground();
    void playCatchHilt();
    void playCatchCutterEdge();
    void playNotCatch();
    void stopPlay();
    void playGameOver();
    void prepare();
    Sprite* getStopSprite();
    Sprite* getStartSprite();
    void clickButton();
    bool onTouchBegan(Touch *touch, Event *unused_event);
    //bool onPlayBegan(Touch *touch, Event *unused_event);
    void flushEventHandler();
private:
    static MusicButton* m_instance;
    MusicButton();
    Sprite* stopSprite;
    Sprite* startSprite;
    bool isMusicPlaying;
};
#endif /* defined(__knifes__MusicButton__) */
