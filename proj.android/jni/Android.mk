LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Chopper.cpp \
                   ../../Classes/FruitKnife.cpp \
                   ../../Classes/GameOverScene.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/Hence.cpp \
                   ../../Classes/Knife.cpp \
                   ../../Classes/MusicButton.cpp \
                   ../../Classes/Score.cpp \
                   ../../Classes/Sword.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)
