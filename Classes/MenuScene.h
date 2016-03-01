#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#define STAGE_1	1
#define STAGE_2 2
#define STAGE_3 3
#define STAGE_4 4
#define STAGE_5 5
#define STAGE_6 6
#define STAGE_7 7
#define STAGE_8 8
#define STAGE_9 9
#define STAGE_10 10

USING_NS_CC;

class MenuScene : public cocos2d::Layer
{
public:

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(MenuScene);

	void initBG(); //background
	void initMenu(); //

	void menuCallback(Ref* sender);

};

#endif