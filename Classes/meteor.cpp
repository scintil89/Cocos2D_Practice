#include "Meteor.h"
#include "Elie.h"

CMeteor::CMeteor()
{
	
}

CMeteor::~CMeteor()
{
// 	pElie = nullptr;
// 	delete pElie;
}

bool CMeteor::init()
{
	if (!cocos2d::Node::init())
	{
		return false;
	}

	this->schedule(schedule_selector(CMeteor::setBullet), 5.0);

	return true;
}

Rect CMeteor::returnHitBox()
{
	auto spear_spr = this->getChildByTag(TAG_SPRITE_METEOR);

	HitBox = spear_spr->getBoundingBox();

	return HitBox;
}

void CMeteor::setBullet(float delta)
{
	auto spr = Sprite::create("meteor.png");
	spr->setAnchorPoint(Point(0.5, 0.5));
	spr->setPosition(Point(480+20, randumSpawn()));
	spr->setTag(TAG_SPRITE_METEOR);
	this->addChild(spr);

	auto action = Sequence::create(
		MoveTo::create(0.9, targetPoint()),
		RemoveSelf::create(),
		NULL);

	spr->runAction(action);
}

Point CMeteor::targetPoint()
{
	Point target = this->getParent()->getChildByName("ELIE")->getPosition();
	
	return target;
}

int CMeteor::randumSpawn()
{
	// 480 x 320
	// 320 / 8 = 40

	int ySize = Director::getInstance()->getWinSize().height;
	int yInterval = 0;
	yInterval = ySize / 8; // 40

	srand((unsigned)time(NULL));
	int ran = rand() % 2 + 1; // 1 2 3 4 5 6 7 8

	switch (ran)
	{
	case 1:
		return METEOR_SPAWNPOINT_4;
		break;
	case 2:
		return METEOR_SPAWNPOINT_5;
		break;
	default:
		return 0;
		break;
	}
}
