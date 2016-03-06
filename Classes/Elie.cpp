#include "Elie.h"


CElie::CElie() 
{
	life = 3;
	jump = false;
	doublejump = false;
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
	if (this->getActionByTag(TAG_JUMP))
	{
		this->stopActionByTag(TAG_JUMP);
	}
	if (this->getActionByTag(TAG_DOUBLE_JUMP))
	{
		this->stopActionByTag(TAG_DOUBLE_JUMP);
	}
	this->removeAllChildren();

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
	this->stopActionByTag(TAG_JUMP);

	auto DoubleJump1 = JumpTo::create(0.7, Point(50, 20), 120, 1);
	auto DoubleJump2 = Sequence::create(DoubleJump1, CallFunc::create(CC_CALLBACK_0(CElie::resetDoubleJump, this)), NULL);

	DoubleJump2->setTag(TAG_DOUBLE_JUMP);

	this->runAction(DoubleJump2);
}

void CElie::nowJumping()
{
	jump = true;
}

void CElie::nowDoubleJumping()
{
	doublejump = true;
}

void CElie::resetJump()
{
	jump = false;
}

void CElie::resetDoubleJump()
{
	jump = false;
	doublejump = false;
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

bool CElie::isJump()
{
	if (jump)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CElie::isDoubleJump()
{
	if (doublejump)
	{
		return true;
	}
	else
	{
		return false;
	}
}
