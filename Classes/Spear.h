#ifndef __SPEAR_H__
#define __SPEAR_H__

#include "cocos2d.h"
#include "Bullet.h"

// elie point : 50 , 20
// jump max : 120



USING_NS_CC;

class CSpear : public CBullet
{
public:
	CSpear();
	~CSpear();

	virtual bool init();
	virtual	Rect returnHitBox();
	virtual void setBullet(float delta);
	
	int randumSpawn();

};

#endif