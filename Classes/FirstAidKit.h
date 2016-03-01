#ifndef __FIRST_AID_KIT_H__
#define __FIRST_AID_KIT_H__

#include "cocos2d.h"
#include "Bullet.h"

USING_NS_CC;

class CFirstAidKit : public CBullet
{
public:
	CFirstAidKit();
	~CFirstAidKit();

	virtual bool init();
	virtual	Rect returnHitBox();
	virtual void setBullet(float delta);
};

#endif