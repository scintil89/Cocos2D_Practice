#include "TitleScene.h"
#include "MenuScene.h"

Scene* TitleScene::createScene()
{
	auto scene = Scene::create();

	auto layer = TitleScene::create();

	scene->addChild(layer);

	return scene;

}

bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initBG();	//background
	//initBGM();
	initMenu();	//menu

	return true;

}

void TitleScene::initBG()
{
	auto spr = Sprite::create("TitleScene_BG.png");
	spr->setAnchorPoint(Point(0, 0));
	spr->setPosition(Point(0, 0));
	this->addChild(spr);
}

void TitleScene::initMenu()
{
	auto item_0 = CCMenuItemImage::create("TitleScene_icon_Play_1.png",				 "TitleScene_icon_Play_2.PNG", CC_CALLBACK_1(TitleScene::menuCallback, this));

	auto item_1 = CCMenuItemImage::create("TitleScene_icon_Option_1.png", "TitleScene_icon_Option_2.png", CC_CALLBACK_1(TitleScene::menuCallback, this));

	auto item_2 = CCMenuItemImage::create("TitleScene_icon_About_1.png",
		"TitleScene_icon_About_2.png", CC_CALLBACK_1(TitleScene::menuCallback, this));

	auto item_3 = CCMenuItemImage::create("TitleScene_icon_Quit_1.png", "TitleScene_icon_Quit_2.png", CC_CALLBACK_1(TitleScene::menuCallback, this));

	item_0->setTag(TAG_TITLE__PLAY);
	item_1->setTag(TAG_TITLE__OPTION);
	item_2->setTag(TAG_TITLE__ABOUT);
	item_3->setTag(TAG_TITLE__QUIT);

	auto menu = Menu::create(item_0, item_1, item_2, item_3, NULL);
	menu->alignItemsHorizontallyWithPadding(20);
	menu->setAnchorPoint(Point(0.5, 0.5));
	menu->setPosition(Point(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 8));

	this->addChild(menu);

}

void TitleScene::menuCallback(Ref* sender)
{
	auto item = (MenuItem*)sender;

	switch (item->getTag())
	{
	case TAG_TITLE__PLAY: 
	{
		auto Scene = TransitionFadeTR::create(1.0, MenuScene::createScene());
		Director::getInstance()->replaceScene(Scene);
	}
		break;

	case TAG_TITLE__OPTION: //todo bgm, effect volume setting
		break;

	case TAG_TITLE__ABOUT:
		break;

	case TAG_TITLE__QUIT:
		Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
		break;

	default:
		break;
	}

}

void TitleScene::initBGM()
{
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.001);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3");
}
