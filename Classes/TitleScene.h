#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
using namespace CocosDenshion;

#define TAG_TITLE__PLAY		0
#define TAG_TITLE__OPTION	1
#define TAG_TITLE__ABOUT	2
#define TAG_TITLE__QUIT		3

class TitleScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(TitleScene);

	void initBG();		//background
	void initMenu();	//
	void initBGM();		//BGM - the story of me

	void menuCallback(Ref* sender);

};

#endif