#ifndef __METEOR_H__
#define __METEOR_H__

#include "cocos2d.h"
#include "Bullet.h"


USING_NS_CC;

class CMeteor : public CBullet
{
public:
	CMeteor();
	~CMeteor();
	CREATE_FUNC(CMeteor);

	virtual bool init();
	
	virtual	Rect returnHitBox();

	virtual void setBullet(float delta);

	int randumSpawn();

 	Point targetPoint();

};

#endif