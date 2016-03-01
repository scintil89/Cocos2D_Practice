#ifndef __ELIE_H__
#define __ELIE_H__

#include "cocos2d.h"

USING_NS_CC;

#define TAG_SPRITE_ELIE		0
#define TAG_JUMP			1

class CElie : public Node
{
public:
	CElie();
	~CElie();

	//CREATE_FUNC(CElie);

	virtual bool init();
	//virtual bool initWithTexture();

	void initELIEdata();

	bool isElieLive();
	void Hit();
	int returnLife();
	void resetLife();
	void plusLife();
	void Die();

	// jump
	bool isJump;
	bool isDoubleJump;

	void Jump();
	void DoubleJump();

	void nowJumping();
	void nowDoubleJumping();

	void resetJump();
	void resetDoubleJump();

	// HitBox
	Rect returnHitBox();

	Point returnNowPoint();
	
protected:
	int life;
	Rect HitBox;
};

#endif