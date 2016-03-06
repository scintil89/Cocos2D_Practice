#include "Elie.h"


CElie::CElie()
{
}


CElie::~CElie()
{
}

bool CElie::init()
{
	if ( !Node::init() )
	{
		return false;
	}

	Sprite* spr = Sprite::create("elie11.png");
	spr->setAnchorPoint(Point(0.5, 0));
	spr->setTag(TAG_SPRITE_ELIE);
	this->addChild(spr);

	this->setAnchorPoint(Point(0.5, 0));
	this->setPosition(Point(50, 20));
	this->setName("ELIE");

	return true;
}

void CElie::initELIEdata()
{
	life = 3;
	isJump = false;
	isDoubleJump = false;
}

bool CElie::isElieLive()
{
	if (life > 0)
		return true;
	else
		return false;
}

void CElie::Hit()
{
	life--;
}

int CElie::returnLife()
{
	return life;
}


void CElie::resetLife()
{
	life = 3;
}


void CElie::plusLife()
{
	if (life < 3)
	{
		life++;
	}
}

void CElie::Die()
{
	auto elie = this->getChildByTag(TAG_SPRITE_ELIE);
	elie->setVisible(false);

	Sprite* spr = Sprite::create("elie_die.png");
	spr->setAnchorPoint(Point(0.5, 0));
	spr->setTag(TAG_SPRITE_ELIE);
	this->addChild(spr);

	this->setAnchorPoint(Point(0.5, 0));
	this->setPosition(Point(50, 20));
}


void CElie::Jump()
{
	nowJumping();

	auto jump1 = JumpBy::create(0.7, Point(0, 0), 80, 1);
	auto jump2 = Sequence::create(jump1, CallFunc::create(CC_CALLBACK_0(CElie::resetJump, this)), NULL);
		
	jump2->setTag(TAG_JUMP);

	this->runAction(jump2);
}

void CElie::DoubleJump()
{
	nowDoubleJumping();

	auto DoubleJump1 = JumpTo::create(0.7, Point(50, 20), 120, 1);
	auto DoubleJump2 = Sequence::create(DoubleJump1, CallFunc::create(CC_CALLBACK_0(CElie::resetDoubleJump, this)), NULL);

	this->stopActionByTag(TAG_JUMP);
	this->runAction(DoubleJump2);
}

void CElie::nowJumping()
{
	isJump = true;
}

void CElie::nowDoubleJumping()
{
	isDoubleJump = true;
}

void CElie::resetJump()
{
	isJump = false;
}

void CElie::resetDoubleJump()
{
	isJump = false;
	isDoubleJump = false;
}

Rect CElie::returnHitBox()
{
	auto elie = this;
	auto elie_spr = this->getChildByTag(TAG_SPRITE_ELIE);

	HitBox = Rect(
		elie->getBoundingBox().getMidX() 
			- elie_spr->getBoundingBox().getMidX(), // x
		elie->getBoundingBox().getMinY(), // y 
		elie_spr->getBoundingBox().getMaxX(), // width
		elie_spr->getBoundingBox().getMaxY()// height
		);
	
	return HitBox;
}


Point CElie::returnNowPoint()
{
	return 	this->getChildByTag(TAG_SPRITE_ELIE)->getPosition();
}
