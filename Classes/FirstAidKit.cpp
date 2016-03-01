#include "FirstAidKit.h"


CFirstAidKit::CFirstAidKit()
{

}

CFirstAidKit::~CFirstAidKit()
{

}

bool CFirstAidKit::init()
{
	if (!cocos2d::Node::init())
	{
		return false;
	}

	this->schedule(schedule_selector(CFirstAidKit::setBullet), 7.0);

	return true;
}

Rect CFirstAidKit::returnHitBox()
{
	auto FAK = this;
	auto FAK_spr = this->getChildByTag(TAG_SPRITE_FAK);

	HitBox = FAK_spr->getBoundingBox();

	return HitBox;
}

void CFirstAidKit::setBullet(float delta)
{
	auto spr = Sprite::create("FirstAidKit.png");
	spr->setAnchorPoint(Point(0.5, 0));
	spr->setPosition(Point(500, 20));
	spr->setTag(TAG_SPRITE_FAK);
	this->addChild(spr);

	auto action = Sequence::create(
		MoveBy::create(1, Point(-600, 0)),
		RemoveSelf::create(),
		NULL);

	spr->runAction(action);
}