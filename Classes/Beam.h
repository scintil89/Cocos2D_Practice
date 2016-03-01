#ifndef __BEAM_H__
#define __BEAM_H__

#include "cocos2d.h"
#include "Bullet.h"


USING_NS_CC;

class CBeam : public CBullet
{
public:
	CBeam();
	~CBeam();

	virtual bool init();
	
	virtual	Rect returnHitBox();

	virtual void setBullet(float delta);

	int spawnPointY;
	int randSpawn();

	void warning();


};

#endif