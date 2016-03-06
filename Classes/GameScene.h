#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Elie.h"
#include "Spear.h"
#include "Meteor.h"
#include "FirstAidKit.h"

USING_NS_CC;

#define tag1 0
#define tag2 1
#define tag3 2

class GameScene : public Layer
{
public:
	GameScene();
	~GameScene();

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(GameScene);

	CElie* Elie;
	CSpear* pSpear;
	CMeteor* pMeteor;
	CFirstAidKit* pFAK;

	void initBG();

	void initElieLife();
	void minusElieLife();
	void plusElieLife();

	bool onTouchBegan(Touch *touch, Event *unused_event);

	void update(float delta);
	void GameOver();
	bool isGameOver();
	void resetGameOver();

private:
	bool gameover;
};

#endif