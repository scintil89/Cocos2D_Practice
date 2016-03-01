#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

USING_NS_CC;

#define TAG_SPRITE_FAK			100
#define TAG_SPRITE_SPEAR		99
#define TAG_SPRITE_METEOR		98

#define SPEAR_SPAWNPOINT_1		20
#define SPEAR_SPAWNPOINT_2		60
#define SPEAR_SPAWNPOINT_3		100
#define SPEAR_SPAWNPOINT_4		140
#define SPEAR_SPAWNPOINT_5		180
#define SPEAR_SPAWNPOINT_6		220
#define SPEAR_SPAWNPOINT_7		260
#define SPEAR_SPAWNPOINT_8		300

#define METEOR_SPAWNPOINT_1		60
#define METEOR_SPAWNPOINT_2		115
#define METEOR_SPAWNPOINT_3		170
#define	METEOR_SPAWNPOINT_4		225
#define	METEOR_SPAWNPOINT_5		280

#define BEAM_SPAWNPOINT_1		20
#define BEAM_SPAWNPOINT_2		60
#define BEAM_SPAWNPOINT_3		100
#define BEAM_SPAWNPOINT_4		140

class CBullet : public Node
{
public:
	CBullet();
	virtual ~CBullet();

	virtual bool init() = 0;
	virtual void setBullet(float delta) = 0;

	Rect HitBox;
	virtual Rect returnHitBox() = 0;

	void removeBullet();
};

#endif