#include "GameScene.h"
#include "GameSceneManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	if (pElie)
	{
		delete pElie;
		pElie = nullptr;
	}

	if (pSpear)
	{
		delete pSpear;
		pSpear = nullptr;
	}

	if (pMeteor)
	{
		delete pMeteor;
		pMeteor = nullptr;
	}

	if (pFAK)
	{
		delete pFAK;
		pFAK = nullptr;
	}
}


Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	// 터치
 	auto listener = EventListenerTouchOneByOne::create();
 	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
 	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//배경화면
	initBG();
	initElieLife();

	// elie 
	pElie = new CElie();
	pElie->autorelease();
	pElie->init();
	this->addChild(pElie, 2);
	pElie->initELIEdata();

	// spear 
	pSpear = new CSpear();
	pSpear->autorelease();
	pSpear->init();
	this->addChild(pSpear, 1);

	// Meteor
 	pMeteor = new CMeteor();
 	pMeteor->autorelease();
 	pMeteor->init();
 	this->addChild(pMeteor);

	//First Aid Kit
	pFAK = new CFirstAidKit();
	pFAK->autorelease();
	pFAK->init();
	this->addChild(pFAK, 2);

	// 충돌 체크를 위한 update 메소드 호출
	this->scheduleUpdate();

	return true;
}

void GameScene::initBG()
{
	auto node = ParallaxNode::create();
	this->addChild(node);

	auto action0 = MoveBy::create(10.0, Point(-1200, 0) );
	auto action1 = Place::create( Point::ZERO );
	auto action2 = Sequence::create(action0, action1, NULL);
	auto action3 = RepeatForever::create(action2);
	node->runAction(action3);

	auto spr_0 = Sprite::create("GameScene_BG.png");
	spr_0->setAnchorPoint(Point::ZERO);
	node->addChild(spr_0, 0, Point(1, 0), Point::ZERO);

	auto spr_1 = Sprite::create("GameScene_BG.png", Rect(0, 0, 640, 480));
	spr_1->setAnchorPoint(Point::ZERO);
	node->addChild(spr_1, 0, Point(1, 0), Point(1200, 0));

}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (pElie->isJump == false) //hp<=0 일때 점프 안되도록 수정
	{
		pElie->Jump();
	}
	else
	{
		if (pElie->isDoubleJump == false)
			pElie->DoubleJump();			
	}
	return true;
}

void GameScene::update(float delta)
{
	//error
	//1.
	//auto sprELIE = this->getChildByTag(TAG_SPRITE_ELIE);
	//Rect restELIE = sprELIE.getBoundingBox
	//rect 애러 
	//아마도 this(GameScene) > pElie > sprELIE 라서 그런듯
	//
	//2.
	//auto ELIE = this->getChildByName("ELIE"); //pElie
	//Rect restELIE = ELIE.getBoundingBox
	// 히트박스 움직임, 태두리 X */
	//
	//3.
	//auto sprELIE = pElie->getChildByTag(TAG_SPRITE_ELIE);  //spr
	//Rect restELIE = sprELIE.getBoundingBox
	// 히트박스 안움직임, 태두리 O
	//
	//해결법
	//ELIE의 좌표와 sprELIE를 합쳐 새로운 히트박스를 만듬
	//
	//auto sprSPEAR = this->getChildByTag(TAG_SPRITE_SPEAR);
	//Rect rectSPEAR = sprSPEAR->getBoundingBox();

	Rect elieBox = pElie->returnHitBox();

	if (pSpear->getChildByTag(TAG_SPRITE_SPEAR) != NULL)
	{
		Rect spearBox = pSpear->returnHitBox();

		if (elieBox.intersectsRect(spearBox)) // 충돌
		{
			//피격시 효과
			//auto particle = ParticleExplosion::create();
			//particle->setPosition(Point(50, 20));
			//pElie->addChild(particle, 2);

			pSpear->getChildByTag(TAG_SPRITE_SPEAR)->runAction(RemoveSelf::create());
			// 소멸

			pElie->Hit(); // hp--
			minusElieLife();
		}
	}

	if (pMeteor->getChildByTag(TAG_SPRITE_METEOR) != NULL)
	{
		Rect meteorBox = pMeteor->returnHitBox();

		if (elieBox.intersectsRect(meteorBox)) // 충돌
		{
			//피격시 효과
			//auto particle = ParticleFireworks::create();
			//pElie->addChild(particle, 2);

			pMeteor->getChildByTag(TAG_SPRITE_METEOR)->runAction(RemoveSelf::create());
			//소멸

			pElie->Hit(); // hp--
			minusElieLife();
		}
	}

	if (pFAK->getChildByTag(TAG_SPRITE_FAK) != NULL)
	{
		Rect fakBox = pFAK->returnHitBox();
		
		if (elieBox.intersectsRect(fakBox)) // 충돌
		{
			pFAK->getChildByTag(TAG_SPRITE_FAK)->runAction(RemoveSelf::create()); // 소멸
			
			pElie->plusLife(); // hp++
			plusElieLife();
		}
	}
		
	if ( !pElie->isElieLive() ) // hp <= 0
	{
		pElie->Die();
		GameOver();
		//Director::getInstance()->pause();
	}
	
}

void GameScene::GameOver()
{
	auto spr = Sprite::create("GameOver.png");
	spr->setAnchorPoint(Point::ZERO);
	this->addChild(spr, 4);
}

void GameScene::initElieLife()
{
	auto spr1 = Sprite::create("elie.png");
	spr1->setPosition(Point(30, 290));
	spr1->setTag(tag1);
	this->addChild(spr1, 4);

	auto spr2 = Sprite::create("elie.png");
	spr2->setPosition(Point(50, 290));
	spr2->setTag(tag2);
	this->addChild(spr2, 4);

	auto spr3 = Sprite::create("elie.png");
	spr3->setPosition(Point(70, 290));
	spr3->setTag(tag3);
	this->addChild(spr3, 4);
}

void GameScene::minusElieLife()
{
	auto minusLife = FadeOut::create(0.5);

	switch (pElie->returnLife())
	{
	case 0:
		this->getChildByTag(tag1)->runAction(minusLife);
		break;
	case 1:
		this->getChildByTag(tag2)->runAction(minusLife);
		break;
	case 2:
		this->getChildByTag(tag3)->runAction(minusLife);
	default:
		break;
	}
}

void GameScene::plusElieLife()
{
	auto plusLife = FadeIn::create(0.5);

	switch (pElie->returnLife())
	{
	case 1:
		this->getChildByTag(tag1)->runAction(plusLife);
		break;
	case 2:
		this->getChildByTag(tag2)->runAction(plusLife);
		break;
	case 3:
		this->getChildByTag(tag3)->runAction(plusLife);
		break;
	default:
		break;
	}
}
