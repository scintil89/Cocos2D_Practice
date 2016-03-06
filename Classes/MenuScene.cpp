#include "MenuScene.h"
#include "GameScene.h"
#include "TitleScene.h"

cocos2d::Scene* MenuScene::createScene()
{
	auto scene = cocos2d::Scene::create();

	auto layer = MenuScene::create();

	scene->addChild(layer);

	return scene;

}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initBG();
 	initMenu();	//menu

	return true;

}

void MenuScene::initBG()
{
	auto node = ParallaxNode::create();
	this->addChild(node);

	auto action0 = MoveBy::create(10.0, Point(-1200, 0));
	auto action1 = Place::create(Point::ZERO);
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

void MenuScene::initMenu()
{
	auto stage_1 = CCMenuItemImage::create("stage/01.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_2 = CCMenuItemImage::create("stage/02.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_3 = CCMenuItemImage::create("stage/03.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_4 = CCMenuItemImage::create("stage/04.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_5 = CCMenuItemImage::create("stage/05.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_6 = CCMenuItemImage::create("stage/06.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_7 = CCMenuItemImage::create("stage/07.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_8 = CCMenuItemImage::create("stage/08.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_9 = CCMenuItemImage::create("stage/09.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	auto stage_10 = CCMenuItemImage::create("stage/10.png", "stage/10.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	stage_1->setTag(STAGE_1);
	stage_2->setTag(STAGE_2);
	stage_3->setTag(STAGE_3);
	stage_4->setTag(STAGE_4);
	stage_5->setTag(STAGE_5);
	stage_6->setTag(STAGE_6);
	stage_7->setTag(STAGE_7);
	stage_8->setTag(STAGE_8);
	stage_9->setTag(STAGE_9);
	stage_10->setTag(STAGE_10);

	auto menu1 = Menu::create(stage_1, stage_2, stage_3, NULL);
	auto menu2 = Menu::create(stage_4, stage_5, stage_6, NULL);
	auto menu3 = Menu::create(stage_7, stage_8, stage_9, NULL);

	menu1->setPosition(Director::getInstance()->getWinSize().width / 2,
		Director::getInstance()->getWinSize().height * 8 / 10);
	menu1->alignItemsHorizontallyWithPadding(20);

	menu2->setPosition(Director::getInstance()->getWinSize().width / 2,
		Director::getInstance()->getWinSize().height * 5 / 10);
	menu2->alignItemsHorizontallyWithPadding(20);

	menu3->setPosition(Director::getInstance()->getWinSize().width / 2,
		Director::getInstance()->getWinSize().height * 2 / 10);
	menu3->alignItemsHorizontallyWithPadding(20);

	
	this->addChild(menu1, 2);
	this->addChild(menu2, 2);
	this->addChild(menu3, 2);
}

void MenuScene::menuCallback(Ref* sender)
{
	auto item = (MenuItem*)sender;

	switch (item->getTag())
	{
	case STAGE_1:
	{
		Scene* pScene = TransitionFadeTR::create(1.0, GameScene::createScene());
		Director::getInstance()->replaceScene(pScene);
	}
		break;

	case STAGE_2:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}	
		break;

	case STAGE_3:
	{
 		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case STAGE_4:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case STAGE_5:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case STAGE_6:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case STAGE_7:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case STAGE_8:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case STAGE_9:
	{
		auto Scene = TransitionFadeTR::create(1.0, TitleScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;
	
	default:
		break;
	}
}
