#include "Beam.h"
#include "Elie.h"

CBeam::CBeam()
{
	
}

CBeam::~CBeam()
{
}

bool CBeam::init()
{
	if (!Node::init())
	{
		return false;
	}

	this->schedule(schedule_selector(CBeam::setBullet), 10.0);

	return true;
}

Rect CBeam::returnHitBox()
{
	auto spear = this;
	auto spear_spr = this->getChildByTag(TAG_SPRITE_METEOR);

	HitBox = spear_spr->getBoundingBox();

	return HitBox;
}

void CBeam::setBullet(float delta)
{
	// °æ°í -> 1ÃÊÈÄ -> Äâ±¤
	warning();

	auto spr = Sprite::create("9.png");
	spr->setAnchorPoint(Point(0.5, 0.5));
	spr->setPosition(Point(480+20, spawnPointY));
	spr->setTag(TAG_SPRITE_METEOR);
	this->addChild(spr);

	auto action = Sequence::create(
		FadeIn::create(0.9),
		RemoveSelf::create(),
		NULL);

	spr->runAction(action);
}

int CBeam::randSpawn()
{
	// 480 x 320
	// 320 / 8 = 40

	int ySize = Director::getInstance()->getWinSize().height;
	int yInterval = ySize / 8; // 40

	srand((unsigned)time(NULL));
	int ran = rand() % 4 + 1; // 1 2 3 4

	switch (ran)
	{
	case 1:
		return BEAM_SPAWNPOINT_1;
		break;
	case 2:
		return BEAM_SPAWNPOINT_2;
		break;
	case 3:
		return BEAM_SPAWNPOINT_3;
		break;
	case 4:
		return BEAM_SPAWNPOINT_4;
		break;
	default:
		return 0;
		break;
	}
}

void CBeam::warning()
{
	int spawnPointY = randSpawn();

	auto spr = Sprite::create("warning.png");
	spr->setPosition(340, spawnPointY);
	this->getParent()->addChild(spr);

	auto action1 = FadeIn::create(0.1);
	auto action2 = RotateBy::create(1, 360);
	auto action3 = FadeOut::create(0.1);
	auto action4 = Sequence::create(action1, action2, action3, RemoveSelf::create(), NULL);

	spr->runAction(action4);
	spr->release();
}