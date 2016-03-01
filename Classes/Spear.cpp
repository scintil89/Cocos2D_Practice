#include "Spear.h"
#include <stdlib.h>


CSpear::CSpear()
{
}


CSpear::~CSpear()
{
}

bool CSpear::init()
{
	if (!cocos2d::Node::init())
	{
		return false;
	}

	this->schedule(schedule_selector(CSpear::setBullet), 0.7);

	return true;
}

Rect CSpear::returnHitBox()
{
	auto spear = this;
	auto spear_spr = this->getChildByTag(TAG_SPRITE_SPEAR);

// 	HitBox = Rect(
// 		spear->getBoundingBox().getMidX()
// 		- spear_spr->getBoundingBox().getMidX(), // x
// 		spear->getBoundingBox().getMinY(), // y 
// 		spear_spr->getBoundingBox().getMaxX(), // width
// 		spear_spr->getBoundingBox().getMaxY()// height
// 		);

	HitBox = spear_spr->getBoundingBox();

	return HitBox;
}

void CSpear::setBullet(float delta)
{
	auto spr = Sprite::create("spear.png");
	spr->setAnchorPoint(Point(0.5, 0));
	spr->setPosition(Point(480 + 50, randumSpawn()));
	spr->setTag(TAG_SPRITE_SPEAR);
	this->addChild(spr);

	auto action = Sequence::create(
		MoveBy::create(1.3, Point(-600, 0)),
		RemoveSelf::create(),
		NULL);

	spr->runAction(action);
}

int CSpear::randumSpawn()
{
	// 480 x 320
	// 320 / 8 = 40

	int ySize = Director::getInstance()->getWinSize().height;
	int yInterval = ySize / 8; // 40
	
	srand((unsigned)time(NULL));
	int ran = rand() % 8 + 1; // 1 2 3 4 5 6 7 8

	switch (ran)
	{
	case 1:
		return SPEAR_SPAWNPOINT_1;
		break;
	case 2:
		return SPEAR_SPAWNPOINT_2;
		break;
	case 3:
		return SPEAR_SPAWNPOINT_3;
		break;
	case 4:
		return SPEAR_SPAWNPOINT_4;
		break;
	case 5:
		return SPEAR_SPAWNPOINT_5;
		break;
	case 6:
		return SPEAR_SPAWNPOINT_6;
		break;
	case 7:
		return SPEAR_SPAWNPOINT_7;
		break;
	case 8:
		return SPEAR_SPAWNPOINT_8;
		break;
	default:
		return 0;
		break;
	}
}
