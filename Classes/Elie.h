#ifndef __ELIE_H__
#define __ELIE_H__

#include "cocos2d.h"

USING_NS_CC;

#define TAG_SPRITE_ELIE			0
#define TAG_SPRITE_ELIE_DIE		1
#define TAG_JUMP				2
#define TAG_DOUBLE_JUMP			3

class CElie : public Node
{
public:
	CElie();
	~CElie();

	CREATE_FUNC(CElie);

	virtual bool init();
	//virtual bool initWithTexture();

	bool isElieLive();
	void Hit();
	int returnLife();
	void resetLife();
	void plusLife();
	void Die();

	// jump
	void Jump();
	void DoubleJump();
	bool isJump();
	bool isDoubleJump();
	void nowJumping();
	void nowDoubleJumping();

	void resetJump();
	void resetDoubleJump();

	// HitBox
	Rect returnHitBox();

	Point returnNowPoint();
	
private:
	int life;
	Rect HitBox;

	bool jump;
	bool doublejump;

};

#endif