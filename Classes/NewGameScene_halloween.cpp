//
//  NewGameScene_halloween.cpp
//  Ninja
//
//  Created by Haimo Bai on 4/1/15.
//
//

#include "NewGameScene_halloween.h"
#include "HelloWorldScene.h"

#include "simpleAudioEngine.h"
#include "player.h"

#include "GameOverHalloween.h"
#include "MenuSettings.h"
#include "GamePauseHalloween.h"



NewGameScene_halloween::~NewGameScene_halloween(){}


Scene* NewGameScene_halloween::createScene()
{
    
    auto Halloween= Scene::createWithPhysics();
    // 'scene' is an autorelease object
    Vect gravity(0, -0.5f);
    Halloween->getPhysicsWorld()->setGravity(gravity);
    //NewGameScene_japan->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    
    auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto node = Node::create();
    node->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
    node->setPhysicsBody(body);
    
    Halloween->addChild(node);
    
    
    
    // 'layer' is an autorelease object
    auto layer = NewGameScene_halloween::create();
    // add layer as a child to scene
    Halloween->addChild(layer);


    return Halloween;
}


bool NewGameScene_halloween::init()
{
    if (!Layer::init()){
        return false;
    }
    //this->schedule(schedule_selector(TollgateScene::logic));
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //set up the border
    
    // position the label on the center of the screen
    auto label = Label::createWithTTF("Halloween Mission!", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            label->getContentSize().height / 2));
    
    // add the label as a child to this layer
    this->addChild(label, 6);
    
    //running sound
    //    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/running.wav");
    //    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/running.wav", true);
    //    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swipSword.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swipSword.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
    
    
    //menu
    auto menu_item_1 = MenuItemImage::create("Menu/pause.png", "Menu/pause1.png", CC_CALLBACK_1(NewGameScene_halloween::GoBack, this));
    
    menu_item_1->setScale(1.2);
    //menu_item_1->setPosition(Vec2(visibleSize.width - menu_item_1->getContentSize().width - borderWidth/2,
    //                              menu_item_1->getContentSize().height / 2));
    menu_item_1->setPosition(Vec2(origin.x + visibleSize.width - menu_item_1->getContentSize().width / 2,
                                  origin.y + menu_item_1->getContentSize().height / 2));
    
    
    ////background
    auto bg_sprite_1 = Sprite::create("halloween/Halloween1.png");
    
    if (visibleSize.width / bg_sprite_1->getContentSize().width >= visibleSize.height / bg_sprite_1->getContentSize().height)
        bg_sprite_1->setScale(bg_scale = visibleSize.height / bg_sprite_1->getContentSize().height);
    else bg_sprite_1->setScale(bg_scale = visibleSize.width / bg_sprite_1->getContentSize().width);
    
    bg_sprite_1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
    bg_origin = Vec2(bg_sprite_1->getBoundingBox().getMinX(), bg_sprite_1->getBoundingBox().getMinY());
    bg_size = Vec2(bg_sprite_1->getBoundingBox().size);
    
    //    bg_sprite_1->setScale(0.8);
    // position the sprite on the center of the screen
    
    
    auto Move_Down_1 = MoveTo::create(100, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
    //	auto action_1 = RepeatForever::create(Move_Down_1);
    bg_sprite_1->runAction(Move_Down_1);
    // add the sprite as a child to this layer
    this->addChild(bg_sprite_1, 4);
    
    auto bg_sprite_2 = Sprite::create("halloween/Halloween2.png");
    //    bg_sprite_2->setScale(0.5);
    // position the sprite on the center of the screen
    bg_sprite_2->setScale(bg_scale);
    bg_sprite_2->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
    auto Move_Down_2 = MoveTo::create(300, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
    //	auto action_2 = RepeatForever::create(Move_Down_2);
    bg_sprite_2->runAction(Move_Down_2);
    
    // add the sprite as a child to this layer
    this->addChild(bg_sprite_2, 3);
    auto bg_sprite_3 = Sprite::create("halloween/Halloween3.png");
    
    // position the sprite on the center of the screen
    bg_sprite_3->setScale(bg_scale);
    bg_sprite_3->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
    auto Move_Down_3 = MoveTo::create(500, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
    //	auto action_3 = RepeatForever::create(Move_Down_3);
    bg_sprite_3->runAction(Move_Down_3);
    
    // add the sprite as a child to this layer
    this->addChild(bg_sprite_3, 2);
    auto bg_sprite_4 = Sprite::create("halloween/Halloween4.png");
    
    
    
    // position the sprite on the center of the screen
    bg_sprite_4->setScale(bg_scale);
    bg_sprite_4->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
    bg_sprite_4->setTag(1);
    // add the sprite as a child to this layer
    this->addChild(bg_sprite_4, 1);
    auto bg_start = Sprite::create("halloween/Halloween_bottom.png");
    bg_start->setScale(bg_scale);
    bg_start->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
    //bg_start->setTag(1);
    // add the sprite as a child to this layer
    this->addChild(bg_start, 7);
    auto Move_Down_4 = MoveTo::create(30, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
    bg_start->runAction(Move_Down_4);

    
    // HP label
    
    auto labelHp = Label::createWithSystemFont(StringUtils::format("Hp: %d", HP), "fonts/Marker Felt.ttf", 40);
    labelHp->setColor(Color3B::RED);
    labelHp->setPosition(Vec2(origin.x + visibleSize.width / 2,
                              origin.y + visibleSize.height - label->getContentSize().height));
    labelHp->setTag(110);
    this->addChild(labelHp, 2);
    
    
    //height label
    score = 0;
    auto labelHeight = Label::createWithSystemFont(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 40);
    labelHeight->setColor(Color3B::RED);
    labelHeight->setPosition(Vec2(bg_origin.x + bg_size.width / 2,
                                  bg_origin.y + bg_size.height - labelHp->getContentSize().height - labelHeight->getContentSize().height));
    labelHeight->setTag(111);
    this->addChild(labelHeight, 2);
    
    
    //item array& skill
    {
        item_Array[0] = item_type::none_item;
        item_Array[1] = item_type::none_item;
        current_skill = skill_type::none_skill;
        LeftWarningLifeTimer = 0.f;
        RightWarningLifeTimer = 0.f;
    }
    
    //boarder
    
    {
        auto border1 = Sprite::create("halloween/border_h.png");
        auto border3 = Sprite::create("halloween/border_h.png");
        auto border2 = Sprite::create("halloween/border_h_2.png");
        auto border4 = Sprite::create("halloween/border_h_2.png");
        border1->setScale(bg_scale);
        border3->setScale(bg_scale);
        border2->setScale(bg_scale);
        border4->setScale(bg_scale);
        
        borderWidth = border1->getBoundingBox().size.width;
        
        border1->setPosition(Point(bg_origin.x + borderWidth / 2, bg_origin.y + bg_size.height / 2));
        this->addChild(border1, 5, Scene_Tag::border1);
        
        border3->setPosition(Point(bg_origin.x + borderWidth / 2, bg_origin.y + bg_size.height * 3 / 2));
        this->addChild(border3, 5, Scene_Tag::border3);
        
        border2->setPosition(Point(bg_origin.x + bg_size.width - borderWidth / 2, bg_origin.y + bg_size.height / 2));
        this->addChild(border2, 5, Scene_Tag::border2);
        
        border4->setPosition(Point(bg_origin.x + bg_size.width - borderWidth / 2, bg_origin.y + bg_size.height * 3 / 2));
        this->addChild(border4, 5, Scene_Tag::border4);
        
    }
    
    
    //player
    
    m_player = Player::create();
    m_player->setScale(bg_scale);
    m_player->playerWidth *= bg_scale;
    /*
     m_player->allframe.clear();
     for (int i = 1; i < 6; i++){
     auto sf = SpriteFrame::create(StringUtils::format("run/run_left%d.png", i), Rect(0, 0, m_player->playerWidth, m_player->playerWidth));
     m_player->allframe.pushBack(sf);
     }
     */
    
    //m_player->spPlayer->setPosition(Point(bg_origin.x + borderWidth + m_player->playerWidth / 2, bg_origin.y + bg_size.height * 0.16f));
    //m_player->setTag(0);
    
    m_player->setPosition(Point(bg_origin.x + borderWidth + m_player->playerWidth / 2, bg_origin.y + bg_size.height * 0.2f));
    this->addChild(m_player, 5, 0);
    
    //skill button
    
    
    auto createSkillButton = MenuItemImage::create(
                                                   "scroll.png",
                                                   "scroll.png",
                                                   CC_CALLBACK_1(NewGameScene_halloween::create_skill, this)
                                                   );
    
    createSkillButton->setScale(bg_scale);
    
    createSkillButton->setPosition(bg_origin.x + bg_size.width / 2, bg_origin.y + bg_size.height*0.125);
    
    auto abilityButtonItem = MenuItemImage::create(
                                                   "Teleport",
                                                   "Teleport_1",
                                                   CC_CALLBACK_1(NewGameScene_halloween::use_skill, this)
                                                   );
    
    abilityButtonItem->setScale(bg_scale);
    abilityButtonItem->setPosition(bg_origin + abilityButtonItem->getBoundingBox().size / 2);
    abilityButtonItem->setVisible(false);
    
    //touch related func init
    valid_touch = false;
    sweep_angle = 0.f;
    
    //abilityButtonItem->setTag(112);
    // create menu, it's an autorelease object
    auto *menu1 = Menu::create(menu_item_1, createSkillButton, NULL);
    
    menu1->setPosition(Point(0, 0));
    
    menu1->addChild(abilityButtonItem, 10, Scene_Tag::skill_button);
    //menu->setColor(Color3B::BLUE);
    this->addChild(menu1, 20, Scene_Tag::menu);
    //menu1->setTag(112);
    //===========
    
    
    
    Sprite* item0 = Sprite::create("japan/sakura.png");
    item0->setPosition(bg_origin.x + bg_size.width / 2 - item0->getContentSize().width / 2, bg_origin.y + bg_size.height*0.15);
    item0->setVisible(false);
    Sprite* item1 = Sprite::create("japan/sakura.png");
    item1->setPosition(bg_origin.x + bg_size.width / 2 + item1->getContentSize().width / 2, bg_origin.y + bg_size.height*0.15);
    item1->setVisible(false);
    
    this->addChild(item0, 21, Scene_Tag::item_0);
    this->addChild(item1, 21, Scene_Tag::item_1);
    
    //===================
    
    EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
    event->setSwallowTouches(true);
    event->onTouchBegan = CC_CALLBACK_2(NewGameScene_halloween::onTouchBegan, this);
    event->onTouchMoved = CC_CALLBACK_2(NewGameScene_halloween::onTouchMoved, this);
    event->onTouchEnded = CC_CALLBACK_2(NewGameScene_halloween::onTouchEnded, this);
    event->onTouchCancelled = CC_CALLBACK_2(NewGameScene_halloween::onTouchCancelled, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);
    
    
    //
    enemyLeftRightDis = -1;
    
    speedTime = 0;
    
    //Enemy
    this->schedule(schedule_selector(NewGameScene_halloween::logic)); // borderSpeed;
    this->schedule(schedule_selector(NewGameScene_halloween::moveEnemyRoof)); // same as borderSpeed
    this->schedule(schedule_selector(NewGameScene_halloween::newEnemy), 1.315);
    
    this->schedule(schedule_selector(NewGameScene_halloween::newEnemy_speedUp), 1);
    this->schedule(schedule_selector(NewGameScene_halloween::timeController), 0.1);
    
    
    this->schedule(schedule_selector(NewGameScene_halloween::moveEnemyFallen));
    this->schedule(schedule_selector(NewGameScene_halloween::moveStar));
    this->schedule(schedule_selector(NewGameScene_halloween::moveEnemyLeft));
    this->schedule(schedule_selector(NewGameScene_halloween::moveEnemyRight));
    
    
    
    
    //http://www.hawstein.com/posts/ctci-solutions-contents.html
    
    this->scheduleUpdate();
    
    
    
    return true;
}


//void NewGameScene_japan::onExit()
//{
//	Layer::onExit();
//
//	_eventDispatcher->removeEventListenersForTarget(this);
//}


void NewGameScene_halloween::GoBack(cocos2d::Ref *pSender){
    CCLOG("go back");
    Director::getInstance()->pushScene(GamePauseHalloween::createScene());
}

void NewGameScene_halloween::logic(float t) {
    int posY1 = this->getChildByTag(Scene_Tag::border1)->getPositionY();
    int posY2 = this->getChildByTag(Scene_Tag::border3)->getPositionY();
    
    if(!m_player->speedUp){
        posY1 += iSpeed;
        posY2 += iSpeed;
    }
    else{
        if (speedTime < 30) {
            posY1 += 5 * iSpeed;
            posY2 += 5 * iSpeed;
        }else if(speedTime < 40){
            posY1 += 3 * iSpeed;
            posY2 += 3 * iSpeed;
        }else if(speedTime < 45){
            posY1 += 2 * iSpeed;
            posY2 += 2 * iSpeed;
        }else {
            posY1 += iSpeed;
            posY2 += iSpeed;
        }
    }
    //auto myborder = Sprite::create("border/border_j.png");
    
    if (posY1 < -bg_size.height / 2) {
        posY1 = posY2 + bg_size.height;
    }
    
    if (posY2 < -bg_size.height / 2) {
        posY2 = posY1 + bg_size.height;
    }
    
    this->getChildByTag(Scene_Tag::border1)->setPositionY(posY1);
    this->getChildByTag(Scene_Tag::border3)->setPositionY(posY2);
    //-------------------------------------------------------------------------
    int posY3 = this->getChildByTag(Scene_Tag::border2)->getPositionY();
    int posY4 = this->getChildByTag(Scene_Tag::border4)->getPositionY();
    
    //
    //	posY3 += iSpeed;
    //	posY4 += iSpeed;
    
    if(!m_player->speedUp){
        posY3 += iSpeed;
        posY4 += iSpeed;
        
    }else{
        if(speedTime < 30){
            posY3 += 5 * iSpeed;
            posY4 += 5 * iSpeed;
        }else if(speedTime < 40){
            posY3 += 3 * iSpeed;
            posY4 += 3 * iSpeed;
        }else if(speedTime < 45){
            posY3 += 2 * iSpeed;
            posY4 += 2 * iSpeed;
        }else {
            posY3 += iSpeed;
            posY4 += iSpeed;
        }
    }
    
    
    if (posY3 < -bg_size.height / 2) {
        posY3 = posY4 + bg_size.height;
    }
    
    if (posY4 < -bg_size.height / 2) {
        posY4 = posY3 + bg_size.height;
    }
    
    this->getChildByTag(Scene_Tag::border2)->setPositionY(posY3);
    this->getChildByTag(Scene_Tag::border4)->setPositionY(posY4);
}


bool NewGameScene_halloween::onTouchBegan(Touch *touch, Event *unsured_event){
    
//    if (touch->getLocation().x >= bg_origin.x + borderWidth&&touch->getLocation().x <= bg_origin.x + bg_size.width - borderWidth)
    if (touch->getLocation().x >= bg_origin.x &&touch->getLocation().x <= bg_origin.x + bg_size.width)
    {
        testTouchBegin = touch->getLocation();
        valid_touch = true;
    }
    else valid_touch = false;
    
    return true;
}

void NewGameScene_halloween::onTouchMoved(Touch * touch, Event *unsured_event){
    
}

void NewGameScene_halloween::onTouchEnded(Touch *touch, Event *unused_event){
    
    auto my_player = (Player *) this->getChildByTag(0);
    
    /*
     if (testTouchBegin.distance(touch->getLocation()) > 1 && testTouchBegin.x<touch->getLocation().x && player->isLeft == true)
     {
     player->setScaleX((player->getScaleX()) * -1.f);
     player->isLeft = false;
     player->moveRight();
     }
     
     else if (testTouchBegin.distance(touch->getLocation()) > 1 && testTouchBegin.x>touch->getLocation().x && player->isLeft == false)
     {
     player->setScaleX((player->getScaleX()) * -1.f);
     player->isLeft = true;
     player->moveLeft();
     }
     */
    
    
//    if (valid_touch&&testTouchBegin.distance(touch->getLocation()) > 50 && touch->getLocation().x >= bg_origin.x + borderWidth&&touch->getLocation().x <= bg_origin.x + bg_size.width - borderWidth)
    if (valid_touch&&testTouchBegin.distance(touch->getLocation()) > 50 && touch->getLocation().x >= bg_origin.x&&touch->getLocation().x <= bg_origin.x + bg_size.width){
        Vec2 tmp = touch->getLocation() - testTouchBegin;
        sweep_angle = tmp.getAngle();
        if (sweep_angle<0)sweep_angle = 0;
        if (sweep_angle>M_PI / 2.f)sweep_angle = M_PI - sweep_angle;
        CCLOG("angle : %f,%f", sweep_angle, M_PI / 2.f);
        if (testTouchBegin.x>touch->getLocation().x&&!my_player->isInAir && my_player->isLeft == false){
            
            my_player->isInAir = true;
            my_player->isMovingLeft = true;
            
            //my_player-> runAction(MoveTo::create(0.5, Point(x_left, size.height * 0.16f)));
            my_player->m_dir = DIR_LEFT;
            my_player->isLeft = true;
            //my_player->logic();
        }
        else if (testTouchBegin.x<touch->getLocation().x&&!my_player->isInAir && my_player->isLeft == true){
            //my_player-> runAction(MoveTo::create(0.5, Point(x_right, size.height * 0.16f)));
            my_player->isInAir = true;
            my_player->isMovingLeft = false;
            
            
            my_player->m_dir = DIR_RIGHT;
            my_player->isLeft = false;
            //my_player->logic();
        }
        my_player->logic();
        valid_touch = false;
    }
}

void NewGameScene_halloween::onTouchCancelled(Touch *touch, Event *unused_event){
    
}


//move enemy roof
void NewGameScene_halloween::moveEnemyRoof(float t) {
    
    
    for (int i = 0; i < allEnemyRoof.size(); i++)
    {
        auto enemy = allEnemyRoof.at(i);
        enemy->setPositionY(enemy->getPositionY() + iSpeed);
        if (enemy->getPositionY() < 0)
        {
            enemy->removeFromParent();
            allEnemyRoof.eraseObject(enemy);
            i--;
        }
    }
};

void NewGameScene_halloween::moveEnemyFallen(float t)
{
    
    for (int i = 0; i < allEnemyFallen.size(); i++)
    {
        auto enemy = allEnemyFallen.at(i);
        enemy->setPositionY(enemy->getPositionY() + iSpeed - 15);
        if (enemy->getPositionY() < 0)
        {
            enemy->removeFromParent();
            allEnemyFallen.eraseObject(enemy);
            i--;
        }
    }
};

void NewGameScene_halloween::moveStar(float t)
{
    
    for (int i = 0; i < allStar.size(); i++)
    {
        auto enemy = allStar.at(i);
        enemy->setPositionY(enemy->getPositionY() + iSpeed - 5);
        if (enemy->getPositionY() < 0)
        {
            enemy->removeFromParent();
            allStar.eraseObject(enemy);
            i--;
        }
    }
    
};

void NewGameScene_halloween::moveEnemyLeft(float t) {
    auto size = Director::getInstance()->getWinSize();
    //    for(auto enemyLeftCrow: allEnemyLeftCrow) {
    for (int i = 0; i < allEnemyLeftCrow.size(); i++) {
        auto enemyLeftCrow = allEnemyLeftCrow.at(i);
        if (enemyLeftCrow->getPositionY() > size.height - 300) {
            enemyLeftCrow->setPositionY(enemyLeftCrow->getPositionY() + iSpeed);
        }
        else {
            enemyLeftCrow->runAction(Sequence::create(MoveBy::create(1.5, Point(0, 0)), MoveBy::create(80, Point(size.width, size.height * -0.78)), NULL));
        }
        
        if (enemyLeftCrow->getPositionY() < 0 || enemyLeftCrow->getPositionX() > size.width) {
            enemyLeftCrow->removeFromParent();
            allEnemyLeftCrow.eraseObject(enemyLeftCrow);
            i--;
        }
    }
}

void NewGameScene_halloween::moveEnemyRight(float t) {
    auto size = Director::getInstance()->getWinSize();
    for (int i = 0; i < allEnemyRightCrow.size(); i++) {
        auto enemyRightCrow = allEnemyRightCrow.at(i);
        if (enemyRightCrow->getPositionY() > size.height - 300) {
            enemyRightCrow->setPositionY(enemyRightCrow->getPositionY() + iSpeed);
        }
        else {
            enemyRightCrow->runAction(Sequence::create(MoveBy::create(1.5, Point(0, 0)), MoveBy::create(80, Point(-size.width, -0.78*size.height)), NULL));
        }
        
        if (enemyRightCrow->getPositionY() < 0 || enemyRightCrow->getPositionX() < 0) {
            enemyRightCrow->removeFromParent();
            allEnemyRightCrow.eraseObject(enemyRightCrow);
            i--;
        }
    }
    
}

void NewGameScene_halloween::killMe(Node * pSender) {
    pSender->removeFromParentAndCleanup(true);
};

void NewGameScene_halloween::jumpToMenu(){
    Director::getInstance()->replaceScene(HelloWorld::createScene());
    
};

void NewGameScene_halloween::newEnemy_speedUp(float t){
    if (m_player->speedUp && speedTime < 30) {
        auto size = Director::getInstance()->getWinSize();
        auto border = Sprite::create("halloween/border_h.png");
        auto border_width = border->getContentSize().width;
        auto roof = Sprite::create("japan/roof_r.png");
        
        int roofWidth = roof->getContentSize().width * 0.8f;
        
        Sprite * enemy;
        Sprite * star;
        Sprite * crow;
        Sprite * tree;
        Vector<SpriteFrame *> crowFram;
        Vector<SpriteFrame *> treeFram;
        
        enemyNum ++;
        CCLOG("Speed up now!\n");
        switch (enemyNum) {
                
            case 0: {
                enemy = Sprite::create("aaa.png");
                
                CCLOG("*****%f*****\n", border_width + enemy->getContentSize().width/2 + roofWidth - size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                
                int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                enemy->setPosition(Point(x, size.height+100));
                enemy->setScale(1.2);
                allEnemyFallen.pushBack(enemy);
                this->addChild(enemy, 7);
            }
                break;
            case 1: {
                
                enemy = Sprite::create("halloween/Halloween_sickle.png");
//                enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(size.width - border_width - enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
                
            }
                break;
            case 2: {
                enemy = Sprite::create("halloween/Halloween_sickle_l.png");
//                enemy->setPosition(Point(border_width + enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle_l.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(border_width + enemy->getContentSize().width * 0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 3: {
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("halloween/Halloween_ghost1.png", Rect(i*425/3, 0, 425/3, 98));
                    crowFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(crowFram, 0.12);
                crow = Sprite::create();
                
                crow->runAction(RepeatForever::create(Animate::create(ani)));
                crow->setScale(1.2);
                crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyLeftCrow.pushBack(crow);
            }
                break;
            case 4: {
                for (int i = 0; i < 8; i++) {
                    auto sf = SpriteFrame::create("halloween/Halloween_ghost2.png", Rect(i*425/3, 0, 425/3, 98));
                    crowFram.pushBack(sf);
                }
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.12))));
                crow->setScale(1.2);
                crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyRightCrow.pushBack(crow);
                
                int RandNum = random(0, 3);
                switch (RandNum) {
                    case 0:
                        enemyNum = -1;
                        break;
                        
                    case 1:
                        enemyNum = 4;
                        break;
                        
                    case 2:
                        enemyNum = 7;
                        break;
                        
                    case 3:
                        enemyNum = 9;
                        
                    default:
                        break;
                }
            }
                break;
                
            case 5: {
                star = Sprite::create("halloween/Halloween_pumpkin.png");
                //CCLOG("*********************\n");
                
                int x = random(border_width + star->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - star->getContentSize().width/2);
                star->setPosition(Point(x, size.height+100));
                this->addChild(star, 7);
                allStar.pushBack(star);
            }
                break;
            case 6: {
                enemy = Sprite::create("japan/roof_l.png");
//                enemy->setPosition(Point(border_width + enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle_l.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(border_width + enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 7: {
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                    crowFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(ani)));
                crow->setScale(1.2);
                crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyLeftCrow.pushBack(crow);
            }
                break;
            case 8: {
                enemy = Sprite::create("japan/roof_r.png");
//                enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(size.width - border_width - enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 9: {
                //                for (int i = 0; i < 4; i++) {
                //                    auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                //                    crowFram.pushBack(sf);
                //                }
                for (int i = 0; i < 8; i++) {
                    auto sf = SpriteFrame::create("japan/goose_left.png", Rect(i*945/8, 0, 945/8, 85));
                    crowFram.pushBack(sf);
                }
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.12))));
                crow->setScale(1.2);
                crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 40, size.height + 100);
                this->addChild(crow, 7);
                allEnemyRightCrow.pushBack(crow);
                int RandNum = random(0, 2);
                CCLOG("RandNum %d", RandNum);
                switch (RandNum) {
                    case 0:
                        enemyNum = -1;
                        break;
                        
                    case 1:
                        enemyNum = 4;
                        break;
                        
                    case 2:
                        enemyNum = 9;
                        break;
                        
                    default:
                        break;
                }
            }
                break;
                
            case 10: {
                enemy = Sprite::create("ccc.png");
                CCLOG("******%f******\n", border_width + enemy->getContentSize().width/2 + roofWidth - size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                
                int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                enemy->setPosition(Point(x, size.height+100));
                enemy->setScale(1.2);
                allEnemyFallen.pushBack(enemy);
                this->addChild(enemy, 7);
            }
                break;
            case 11: {
                enemy = Sprite::create("japan/roof_l.png");
//                enemy->setPosition(Point(border_width + enemy->getContentSize().width/2, size.height + 100));
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle_l.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(border_width + enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 12: {
                enemy = Sprite::create("japan/roof_r.png");
//                enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2, size.height + 100));
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(size.width - border_width - enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 13: {
                //                for (int i = 0; i < 4; i++) {
                //                    auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                //                    crowFram.pushBack(sf);
                //                }
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("halloween/Halloween_ghost1.png", Rect(i*425/3, 0, 425/3, 98));
                    crowFram.pushBack(sf);
                }
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
                crow->setScale(1.2);
                crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 40, size.height + 100);
                this->addChild(crow, 7);
                allEnemyRightCrow.pushBack(crow);
            }
                break;
            case 14: {
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("halloween/Halloween_ghost2.png", Rect(i*425/3, 0, 425/3, 98));
                    crowFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(ani)));
                crow->setScale(1.2);
                crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyLeftCrow.pushBack(crow);
                int RandNum = random(0, 2);
                
                switch (RandNum) {
                    case 0:
                        enemyNum = -1;
                        break;
                        
                    case 1:
                        enemyNum = 4;
                        break;
                        
                    case 2:
                        enemyNum = 9;
                        break;
                        
                    default:
                        break;
                }
            }
                break;
                
                
            default:
                break;
        }
    }
}



void NewGameScene_halloween::newEnemy(float t) {
    //	auto size = Director::getInstance()->getWinSize();
    //	auto border = Sprite::create("japan/border_j.png");
    //
    //	auto border_width = border->getBoundingBox().size.width;
    //
    //	auto roof = Sprite::create("japan/roof_r.png");
    //	roof->setScale(bg_scale);
    //	int roofWidth = roof->getBoundingBox().size.width * 0.8f;
    //
    //
    //	Sprite * enemy;
    //	Sprite * star;
    //	Sprite * crow;
    //	Vector<SpriteFrame *> crowFram;
    //
    //	//enemyNum = 4;
    //
    //	enemyNum++;
    //	CCLOG("working!\n");
    //	switch (enemyNum) {
    //
    //	case 0: {
    //		enemy = Sprite::create("aaa.png");
    //		int x = random(border_width + enemy->getContentSize().width / 2 + roofWidth, size.width - border_width - roofWidth - enemy->getContentSize().width / 2);
    //		enemy->setPosition(Point(x, size.height + 100));
    //		enemy->setScale(1.2);
    //		allEnemyFallen.pushBack(enemy);
    //		this->addChild(enemy, 7);
    //	}
    //			break;
    //	case 1: {
    //		enemy = Sprite::create("japan/roof_r.png");
    //		enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width / 2 * 0.8, size.height + 100));
    //		enemy->setScale(0.8);
    //		this->addChild(enemy, 7);
    //		allEnemyRoof.pushBack(enemy);
    //	}
    //			break;
    //	case 2: {
    //		enemy = Sprite::create("japan/roof_l.png");
    //		enemy->setPosition(Point(border_width + enemy->getContentSize().width / 2 * 0.8, size.height + 100));
    //		enemy->setScale(0.8);
    //		this->addChild(enemy, 7);
    //		allEnemyRoof.pushBack(enemy);
    //	}
    //			break;
    //	case 3: {
    //		for (int i = 0; i < 4; i++) {
    //			auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i * 300 / 4, 0, 300 / 4, 63));
    //			crowFram.pushBack(sf);
    //		}
    //		auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
    //		crow = Sprite::create();
    //
    //		crow->runAction(RepeatForever::create(Animate::create(ani)));
    //		crow->setScale(1.2);
    //		crow->setPosition(borderWidth + crow->getContentSize().width / 2 + 30, size.height + 100);
    //		this->addChild(crow, 7);
    //		allEnemyLeftCrow.pushBack(crow);
    //	}
    //			break;
    //	case 4: {
    //		for (int i = 0; i < 4; i++) {
    //			auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i * 300 / 4, 0, 300 / 4, 63));
    //			crowFram.pushBack(sf);
    //		}
    //		crow = Sprite::create();
    //		crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
    //		crow->setScale(1.2);
    //		crow->setPosition(size.width - borderWidth - crow->getContentSize().width / 2 - 30, size.height + 100);
    //		this->addChild(crow, 7);
    //		allEnemyRightCrow.pushBack(crow);
    //
    //		int RandNum = random(0, 2);
    //		//            CCLOG("RandNum %d", RandNum);
    //		switch (RandNum) {
    //		case 0:
    //			enemyNum = -1;
    //			break;
    //
    //		case 1:
    //			enemyNum = 4;
    //			break;
    //
    //		case 2:
    //			enemyNum = 9;
    //			break;
    //
    //		default:
    //			break;
    //		}
    //	}
    //			break;
    //	case 5: {
    //		star = Sprite::create("star.png");
    //		star->setScale(bg_scale);
    //		int x = random(borderWidth + roofWidth + star->getBoundingBox().size.width / 2, bg_size.width - borderWidth - roofWidth - star->getBoundingBox().size.width / 2);
    //		star->setPosition(bg_origin.x + x, bg_origin.y + size.height + 100);
    //		this->addChild(star, 7);
    //		allStar.pushBack(star);
    //	}
    //			break;
    //	case 6: {
    //		enemy = Sprite::create("japan/roof_l.png");
    //		enemy->setPosition(Point(border_width + enemy->getContentSize().width / 2 * 0.8, size.height + 100));
    //		enemy->setScale(0.8);
    //		this->addChild(enemy, 7);
    //		allEnemyRoof.pushBack(enemy);
    //	}
    //			break;
    //	case 7: {
    //		for (int i = 0; i < 4; i++) {
    //			auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i * 300 / 4, 0, 300 / 4, 63));
    //			crowFram.pushBack(sf);
    //		}
    //		auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
    //		crow = Sprite::create();
    //		crow->runAction(RepeatForever::create(Animate::create(ani)));
    //		crow->setScale(1.2);
    //		crow->setPosition(borderWidth + crow->getContentSize().width / 2 + 30, size.height + 100);
    //		this->addChild(crow, 7);
    //		allEnemyLeftCrow.pushBack(crow);
    //	}
    //			break;
    //	case 8: {
    //		enemy = Sprite::create("japan/roof_r.png");
    //		enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width / 2 * 0.8, size.height + 100));
    //		enemy->setScale(0.8);
    //		this->addChild(enemy, 7);
    //		allEnemyRoof.pushBack(enemy);
    //	}
    //			break;
    //	case 9: {
    //		for (int i = 0; i < 4; i++) {
    //			auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i * 300 / 4, 0, 300 / 4, 63));
    //			crowFram.pushBack(sf);
    //		}
    //		crow = Sprite::create();
    //		crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
    //		crow->setScale(1.2);
    //		crow->setPosition(size.width - borderWidth - crow->getContentSize().width / 2 - 30, size.height + 100);
    //		this->addChild(crow, 7);
    //		allEnemyRightCrow.pushBack(crow);
    //		int RandNum = random(0, 2);
    //		CCLOG("RandNum %d", RandNum);
    //		switch (RandNum) {
    //		case 0:
    //			enemyNum = -1;
    //			break;
    //
    //		case 1:
    //			enemyNum = 4;
    //			break;
    //
    //		case 2:
    //			enemyNum = 9;
    //			break;
    //
    //		default:
    //			break;
    //		}
    //	}
    //			break;
    //
    //	case 10: {
    //		enemy = Sprite::create("ccc.png");
    //		int x = random(border_width + enemy->getContentSize().width / 2 + roofWidth, size.width - border_width - roofWidth - enemy->getContentSize().width / 2);
    //		enemy->setPosition(Point(x, size.height + 100));
    //		enemy->setScale(1.2);
    //		allEnemyFallen.pushBack(enemy);
    //		this->addChild(enemy, 7);
    //	}
    //			 break;
    //	case 11: {
    //		enemy = Sprite::create("japan/roof_l.png");
    //		enemy->setPosition(Point(border_width + enemy->getContentSize().width / 2, size.height + 100));
    //		this->addChild(enemy, 7);
    //		allEnemyRoof.pushBack(enemy);
    //	}
    //			 break;
    //	case 12: {
    //		enemy = Sprite::create("japan/roof_r.png");
    //		enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width / 2, size.height + 100));
    //		this->addChild(enemy, 7);
    //		allEnemyRoof.pushBack(enemy);
    //	}
    //			 break;
    //	case 13: {
    //		for (int i = 0; i < 4; i++) {
    //			auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i * 300 / 4, 0, 300 / 4, 63));
    //			crowFram.pushBack(sf);
    //		}
    //		crow = Sprite::create();
    //		crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
    //		crow->setScale(1.2);
    //		crow->setPosition(size.width - borderWidth - crow->getContentSize().width / 2 - 30, size.height + 100);
    //		this->addChild(crow, 7);
    //		allEnemyRightCrow.pushBack(crow);
    //	}
    //			 break;
    //	case 14: {
    //		for (int i = 0; i < 4; i++) {
    //			auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i * 300 / 4, 0, 300 / 4, 63));
    //			crowFram.pushBack(sf);
    //		}
    //		auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
    //		crow = Sprite::create();
    //		crow->runAction(RepeatForever::create(Animate::create(ani)));
    //		crow->setScale(1.2);
    //		crow->setPosition(borderWidth + crow->getContentSize().width / 2 + 30, size.height + 100);
    //		this->addChild(crow, 7);
    //		allEnemyLeftCrow.pushBack(crow);
    //		int RandNum = random(0, 2);
    //		CCLOG("RandNum %d", RandNum);
    //		switch (RandNum) {
    //		case 0:
    //			enemyNum = -1;
    //			break;
    //
    //		case 1:
    //			enemyNum = 4;
    //			break;
    //
    //		case 2:
    //			enemyNum = 9;
    //			break;
    //
    //		default:
    //			break;
    //		}
    //	}
    //			 break;
    //
    //
    //	default:
    //		break;
    if (!m_player->speedUp || (m_player->speedUp && speedTime > 30)) {
        auto size = Director::getInstance()->getWinSize();
        auto border = Sprite::create("halloween/border_h.png");
        auto border_width = border->getContentSize().width;
        auto roof = Sprite::create("japan/roof_r.png");
        
        int roofWidth = roof->getContentSize().width * 0.8f;
        
        
        Sprite * enemy;
        Sprite * star;
        Sprite * crow;
        Sprite * tree;
        Vector<SpriteFrame *> crowFram;
        Vector<SpriteFrame *> treeFram;
        //enemyNum = 4;
        enemyNum ++;
        CCLOG("working!\n");
        switch (enemyNum) {
                
            case 0: {
                enemy = Sprite::create("aaa.png");
                CCLOG("*****%f*****\n", border_width + enemy->getContentSize().width/2 + roofWidth - size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                
                int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                enemy->setPosition(Point(x, size.height+100));
                enemy->setScale(1.2);
                allEnemyFallen.pushBack(enemy);
                this->addChild(enemy, 7);
            }
                break;
            case 1: {
                enemy = Sprite::create("japan/roof_r.png");
//                CCLOG("***********rooof**********\n");
//                
//                enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                if (RightWarningLifeTimer <= 0.f)
                {
                    RightWarning = Sprite::create("warning.png");
                    RightWarning->setPosition(size.width - RightWarning->getContentSize().width / 2.f, size.height*2.f / 5.f);
                    RightWarning->setScale(0.5f);
                    RightWarningLifeTimer = 0.5f;
                    this->addChild(RightWarning, 10);
                }
                
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(size.width - border_width - enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 2: {
                enemy = Sprite::create("japan/roof_l.png");
//                enemy->setPosition(Point(border_width + enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                
                if (LeftWarningLifeTimer <= 0.f)
                {
                    LeftWarning = Sprite::create("warning.png");
                    LeftWarning->setPosition(LeftWarning->getContentSize().width / 2.f, size.height*2.f / 5.f);
                    LeftWarning->setScale(0.5f);
                    LeftWarningLifeTimer = 0.5f;
                    this->addChild(LeftWarning, 10);
                }
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle_l.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(border_width + enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 3: {
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                    crowFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
                crow = Sprite::create();
                
                crow->runAction(RepeatForever::create(Animate::create(ani)));
                crow->setScale(1.2);
                crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyLeftCrow.pushBack(crow);
            }
                break;
            case 4: {
                //                for (int i = 0; i < 4; i++) {
                //                    auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                //                    crowFram.pushBack(sf);
                //                }
                for (int i = 0; i < 8; i++) {
                    auto sf = SpriteFrame::create("japan/goose_left.png", Rect(i*945/8, 0, 945/8, 85));
                    crowFram.pushBack(sf);
                }
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
                crow->setScale(1.2);
                crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 40, size.height + 100);
                this->addChild(crow, 7);
                allEnemyRightCrow.pushBack(crow);
                
                int RandNum = random(0, 2);
                switch (RandNum) {
                    case 0:
                        enemyNum = -1;
                        break;
                        
                    case 1:
                        enemyNum = 4;
                        break;
                        
                    case 2:
                        enemyNum = 9;
                        break;
                        
                    default:
                        break;
                }
            }
                break;
                
            case 5: {
                //CCLOG("*********************\n");
                
                star = Sprite::create("halloween/Halloween_pumpkin.png");
                int x = random(border_width + star->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - star->getContentSize().width/2);
                //CCLOG("%d", x);
                star->setPosition(Point(x, size.height+100));
                this->addChild(star, 7);
                allStar.pushBack(star);
            }
                break;
            case 6: {
                enemy = Sprite::create("japan/roof_l.png");
//                enemy->setPosition(Point(border_width + enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                if (LeftWarningLifeTimer <= 0.f)
                {
                    LeftWarning = Sprite::create("warning.png");
                    LeftWarning->setPosition(LeftWarning->getContentSize().width / 2.f, size.height*2.f / 5.f);
                    LeftWarning->setScale(0.5f);
                    LeftWarningLifeTimer = 0.5f;
                    this->addChild(LeftWarning, 10);
                }
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle_l.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(border_width + enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 7: {
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                    crowFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(ani)));
                crow->setScale(1.2);
                crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyLeftCrow.pushBack(crow);
            }
                break;
            case 8: {
                enemy = Sprite::create("japan/roof_r.png");
//                enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2 * 0.8, size.height + 100));
//                enemy->setScale(0.8);
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                if (RightWarningLifeTimer <= 0.f)
                {
                    RightWarning = Sprite::create("warning.png");
                    RightWarning->setPosition(size.width - RightWarning->getContentSize().width / 2.f, size.height*2.f / 5.f);
                    RightWarning->setScale(0.5f);
                    RightWarningLifeTimer = 0.5f;
                    this->addChild(RightWarning, 10);
                }

                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(size.width - border_width - enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 9: {
                //                for (int i = 0; i < 4; i++) {
                //                    auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                //                    crowFram.pushBack(sf);
                //                }
                for (int i = 0; i < 8; i++) {
                    auto sf = SpriteFrame::create("japan/goose_left.png", Rect(i*945/8, 0, 945/8, 85));
                    crowFram.pushBack(sf);
                }
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
                crow->setScale(1.2);
                crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 40, size.height + 100);
                this->addChild(crow, 7);
                allEnemyRightCrow.pushBack(crow);
                int RandNum = random(0, 2);
                CCLOG("RandNum %d", RandNum);
                switch (RandNum) {
                    case 0:
                        enemyNum = -1;
                        break;
                        
                    case 1:
                        enemyNum = 4;
                        break;
                        
                    case 2:
                        enemyNum = 9;
                        break;
                        
                    default:
                        break;
                }
            }
                break;
                
            case 10: {
                enemy = Sprite::create("ccc.png");
                
                CCLOG("******%f*****\n", border_width + enemy->getContentSize().width/2 + roofWidth - size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width -roofWidth - enemy->getContentSize().width/2);
                enemy->setPosition(Point(x, size.height+100));
                enemy->setScale(1.2);
                allEnemyFallen.pushBack(enemy);
                this->addChild(enemy, 7);
            }
                break;
            case 11: {
                enemy = Sprite::create("japan/roof_l.png");
//                enemy->setPosition(Point(border_width + enemy->getContentSize().width/2, size.height + 100));
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                if (LeftWarningLifeTimer <= 0.f)
                {
                    LeftWarning = Sprite::create("warning.png");
                    LeftWarning->setPosition(LeftWarning->getContentSize().width / 2.f, size.height*2.f / 5.f);
                    LeftWarning->setScale(0.5f);
                    LeftWarningLifeTimer = 0.5f;
                    this->addChild(LeftWarning, 10);
                }
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle_l.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(border_width + enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 12: {
                enemy = Sprite::create("japan/roof_r.png");
//                enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2, size.height + 100));
//                this -> addChild(enemy, 7);
//                allEnemyRoof.pushBack(enemy);
                if (RightWarningLifeTimer <= 0.f)
                {
                    RightWarning = Sprite::create("warning.png");
                    RightWarning->setPosition(size.width - RightWarning->getContentSize().width / 2.f, size.height*2.f / 5.f);
                    RightWarning->setScale(0.5f);
                    RightWarningLifeTimer = 0.5f;
                    this->addChild(RightWarning, 10);
                }
                for(int i = 0; i < 4; i ++){
                    auto sf = SpriteFrame::create("halloween/Halloween_sickle.png", Rect(i * 736 / 4, 0, 736 / 4, 223));
                    treeFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(treeFram, 0.3);
                tree = Sprite::create();
                tree->runAction(RepeatForever::create(Animate::create(ani)));
                tree->setPosition(Point(size.width - border_width - enemy->getContentSize().width*0.8, size.height + 100));
                //tree->setScale(0.8);
                this -> addChild(tree, 3);
                allEnemyRoof.pushBack(tree);
            }
                break;
            case 13: {
                //                for (int i = 0; i < 4; i++) {
                //                    auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                //                    crowFram.pushBack(sf);
                //                }
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("halloween/Halloween_ghost1.png", Rect(i*425/3, 0, 425/3, 98));
                    crowFram.pushBack(sf);
                }
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.16))));
                crow->setScale(1.2);
                crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyRightCrow.pushBack(crow);
            }
                break;
            case 14: {
                for (int i = 0; i < 4; i++) {
                    auto sf = SpriteFrame::create("halloween/Halloween_ghost2.png", Rect(i*425/3, 0, 425/3, 98));
                    crowFram.pushBack(sf);
                }
                auto ani = Animation::createWithSpriteFrames(crowFram, 0.16);
                crow = Sprite::create();
                crow->runAction(RepeatForever::create(Animate::create(ani)));
                crow->setScale(1.2);
                crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
                this->addChild(crow, 7);
                allEnemyLeftCrow.pushBack(crow);
                int RandNum = random(0, 2);
                
                switch (RandNum) {
                    case 0:
                        enemyNum = -1;
                        break;
                        
                    case 1:
                        enemyNum = 4;
                        break;
                        
                    case 2:
                        enemyNum = 9;
                        break;
                        
                    default:
                        break;
                }
            }
                break;
                
                
            default:
                break;
        }
        
    }
    //	auto size = Director::getInstance()->getWinSize();
    //	auto border = Sprite::create("border/border_j.png");
    //	auto border_width = border->getContentSize().width*bg_scale;
    //
    //	Sprite * enemy;
    //    Sprite * star;
    //    Sprite * crow;
    //
    //    int RandNum = random(0, 6);
    //
    //    if (enemyLeftRightDis < 12 && enemyLeftRightDis > 9) {
    //        while (enemyLeftRightDis == RandNum) {
    //            RandNum = random(0, 13);
    //        }
    //
    //        if (enemyLeftRightDis < 12 && enemyLeftRightDis > 9){
    //            enemyLeftRightDis = RandNum;
    //        }
    //    }
    //
    //    auto roof = Sprite::create("japan/roof_r.png");
    //    int roofWidth = roof->getContentSize().width * bg_scale;
    //
    //    if (RandNum < 3) {
    //        enemy = Sprite::create("japan/roof_r.png");
    //		enemy->setScale(bg_scale);
    //		enemy->setPosition(Point(bg_origin.x + bg_size.width - border_width - roofWidth/2, size.height + 100));
    //    }
    //    else if (RandNum < 6) {
    //        enemy = Sprite::create("japan/roof_l.png");
    //		enemy->setScale(bg_scale);
    //		enemy->setPosition(Point(bg_origin.x + border_width + roofWidth / 2, size.height + 100));
    //    }
    //    else if (RandNum < 9) {
    //        if (RandNum < 8) {
    //           enemy = Sprite::create("aaa.png");
    //        }
    //        else{
    //           enemy = Sprite::create("ccc.png");
    //        }
    //        int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - enemy->getContentSize().width/2);
    //        enemy->setPosition(Point(x, size.height+100));
    //    }
    //    else if (RandNum == 9) {
    //        star = Sprite::create("star.png");
    //        int x = random(border_width + star->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - star->getContentSize().width/2);
    //        star->setPosition(Point(x, size.height+100));
    //    }
    //    else if (RandNum < 12) {
    //        Vector<SpriteFrame *> crowFram;
    //        if (RandNum == 10) {
    //            for (int i = 0; i < 4; i++) {
    //                auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
    //                crowFram.pushBack(sf);
    //            }
    //
    //        }
    //        else {
    //            for (int i = 0; i < 4; i++) {
    //                auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
    //                crowFram.pushBack(sf);
    //            }
    //        }
    //        auto ani = Animation::createWithSpriteFrames(crowFram, 0.03);
    //        crow = Sprite::create();
    //        crow->runAction(RepeatForever::create(Animate::create(ani)));
    //    }
    //
    //
    //    if (RandNum < 6 && allEnemyRightCrow.size() == 0 && allEnemyLeftCrow.size() == 0) {
    //        this->addChild(enemy, 7);
    //        allEnemyRoof.pushBack(enemy);
    //    }
    //    else if (RandNum < 9 && allEnemyRightCrow.size() == 0 && allEnemyLeftCrow.size() == 0) {
    //        this->addChild(enemy, 7);
    //        allEnemyFallen.pushBack(enemy);
    //    }
    //    else if (RandNum == 9) {
    //        this->addChild(star, 7);
    //        allStar.pushBack(star);
    //    }
    //    else if (RandNum < 12) {
    //        if (RandNum == 10 && allEnemyLeftCrow.size() == 0) {
    //            crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2, size.height + 100);
    //            allEnemyRightCrow.pushBack(crow);
    //            this->addChild(crow, 7);
    //        }
    //        else if (RandNum == 11 && allEnemyRightCrow.size() == 0){
    //            crow->setPosition(borderWidth + crow->getContentSize().width/2, size.height + 100);
    //            allEnemyLeftCrow.pushBack(crow);
    //            this->addChild(crow, 7);
    //        }
    //
    //    }
    
}

void NewGameScene_halloween::update(float t) {
    
    Size visibleSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto plane = (Player *) this->getChildByTag(0);
    
    Rect pp(plane->getPositionX(), plane->getPositionY(), plane->playerWidth, plane->playerWidth);
    auto p_x = this->getPositionX();
    auto p_y = this->getPositionY();
    if (LeftWarningLifeTimer > 0.f)
    {
        LeftWarningLifeTimer -= t;
        if (LeftWarningLifeTimer <= 0.f)
        {
            LeftWarning->removeFromParent();
            LeftWarning = NULL;
            LeftWarningLifeTimer = 0.f;
        }
    }
    
    if (RightWarningLifeTimer > 0.f)
    {
        RightWarningLifeTimer -= t;
        if (RightWarningLifeTimer <= 0.f)
        {
            RightWarning->removeFromParent();
            RightWarning = NULL;
            RightWarningLifeTimer = 0.f;
        }
    }

    
    
    //enemy roof
    for (int i = 0; i < allEnemyRoof.size(); i++) {
        auto enemy = allEnemyRoof.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 115, 103);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 15.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 15.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        
        if ((pp.intersectsRect(er) && HP > 1) || (pp.intersectsRect(er) && HP == 1 && (m_player->shelled || m_player->speedUp))) {
            if (!m_player->shelled && !m_player->speedUp) {
                HP --;
            }else {
                if (!m_player->speedUp){
                    m_player->shelled = false;
                }
            }
            enemy->removeFromParent();
            allEnemyRoof.eraseObject(enemy);
            i--;
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
            if (!m_player->speedUp) {
                this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            }
            
            
            
            //			auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            //			auto action_3 = RepeatForever::create(Move_Down_3);
            //			label->setColor(Color3B::RED);
            //			label->runAction(action_3);
            //			this->addChild(label, 8);
            
        }
        else if (pp.intersectsRect(er) && HP == 1){
            
            enemy->removeFromParent();
            allEnemyRoof.eraseObject(enemy);
            i--;
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
            if(!m_player->speedUp){
                this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            }
            //			auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            //			auto action_3 = RepeatForever::create(Move_Down_3);
            //			label->setColor(Color3B::RED);
            //			label->runAction(action_3);
            //			this->addChild(label, 8);
            
            this->pause();
            Director::getInstance()->replaceScene(TransitionMoveInB::create(2, GameOverHalloween::createScene()));
            
            
        }
    }
    
    //enemy fallen
    for (int i = 0; i < allEnemyFallen.size(); i++) {
        auto enemy = allEnemyFallen.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 40, 50);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 50.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 50.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        
        if (pp.intersectsRect(er)) {
            //auto abilityButton = (Menu *) this->getChildByTag(112);
            //abilityButton->setEnabled(true);
            //abilityButton->setVisible(true);
            //HP--;
            enemy->removeFromParent();
            allEnemyFallen.eraseObject(enemy);
            i--;
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/attackBomb.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/attackBomb.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            enemy_killed++;
            m_player->shelled = true;
            if (enemy_killed == 1) {
                auto label = Label::createWithTTF("First Blood! \n +1000!", "fonts/Marker Felt.ttf", 60);
                label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
                auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
                auto action_3 = RepeatForever::create(Move_Down_3);
                label->setColor(Color3B::BLACK);
                label->runAction(action_3);
                this->addChild(label, 8);
                score += 1000;
            }
            else if (enemy_killed == 2){
                auto label = Label::createWithTTF("Double Kill! \n +2000", "fonts/Marker Felt.ttf", 60);
                label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
                auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
                auto action_3 = RepeatForever::create(Move_Down_3);
                label->setColor(Color3B::BLACK);
                label->runAction(action_3);
                this->addChild(label, 8);
                score += 2000;
            }
            else{
                auto label = Label::createWithTTF("Ninja Kill! \n +3000", "fonts/Marker Felt.ttf", 60);
                label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
                auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
                auto action_3 = RepeatForever::create(Move_Down_3);
                label->setColor(Color3B::BLACK);
                label->runAction(action_3);
                this->addChild(label, 8);
                score += 3000;
            }
        }
        
        
        // }
        //       else if (pp.intersectsRect(er) && HP == 1){
        //
        //            enemy->removeFromParent();
        //            allEnemyFallen.eraseObject(enemy);
        //            i--;
        //            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
        //
        //            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
        //            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
        //            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
        //            auto action_3 = RepeatForever::create(Move_Down_3);
        //            label->setColor(Color3B::RED);
        //            label->runAction(action_3);
        //            this->addChild(label, 8);
        //
        //            this->pause();
        //            Director::getInstance()->replaceScene(TransitionMoveInB::create(2, GameOver::createScene()));
        //        }
    }
    
    //enemy left crow
    for (int i = 0; i < allEnemyLeftCrow.size(); i++) {
        auto enemy = allEnemyLeftCrow.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 75, 63);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 50.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 50.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        if (!m_player->isInAir) {
            if ((pp.intersectsRect(er) && HP > 1) || (pp.intersectsRect(er) && HP == 1 && (m_player->shelled || m_player->speedUp))) {
                
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
                
                if (!m_player->shelled && !m_player->speedUp) {
                    HP--;
                }
                else {
                    if (!m_player->speedUp) {
                        m_player->shelled = false;
                    }
                }
                enemy->removeFromParent();
                allEnemyLeftCrow.eraseObject(enemy);
                i--;
                if (!m_player->speedUp) {
                    this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
                }
                
                
            }
            else if (pp.intersectsRect(er) && HP == 1 && !m_player->shelled && !m_player->speedUp){
                
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
                
                
                enemy->removeFromParent();
                allEnemyLeftCrow.eraseObject(enemy);
                i--;
                if (!m_player->speedUp) {
                    this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
                }
                
                
                this->pause();
                Director::getInstance()->replaceScene(TransitionMoveInB::create(2, GameOverHalloween::createScene()));
            }
        }
        
        else {
            if (pp.intersectsRect(er)) {
                
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
                
                enemy->stopAllActions();
                enemy->removeFromParent();
                allEnemyLeftCrow.eraseObject(enemy);
                i--;
                if (!m_player->speedUp) {
                    m_player->speedUp = true;
                }
                
            }
        }
        //		if (pp.intersectsRect(er) && HP > 1) {
        //
        //
        //			HP--;
        //			enemy->removeFromParent();
        //			allEnemyLeftCrow.eraseObject(enemy);
        //			i--;
        //			CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
        //			this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
        //
        //			auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
        //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
        //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
        //			auto action_3 = RepeatForever::create(Move_Down_3);
        //			label->setColor(Color3B::RED);
        //			label->runAction(action_3);
        //			this->addChild(label, 8);
        //
        //		}
        //		else if (pp.intersectsRect(er) && HP == 1){
        //
        //			enemy->removeFromParent();
        //			allEnemyLeftCrow.eraseObject(enemy);
        //			i--;
        //			CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
        //			this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
        //
        //			auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
        //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
        //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
        //			auto action_3 = RepeatForever::create(Move_Down_3);
        //			label->setColor(Color3B::RED);
        //			label->runAction(action_3);
        //			this->addChild(label, 8);
        //
        //			this->pause();
        //			Director::getInstance()->replaceScene(TransitionMoveInB::create(2, GameOver::createScene()));
        //		}
    }
    
    //enemy right crow
    for (int i = 0; i < allEnemyRightCrow.size(); i++) {
        auto enemy = allEnemyRightCrow.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 75, 63);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 50.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 50.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        if (!m_player->isInAir) {
            if ((pp.intersectsRect(er) && HP > 1) || (pp.intersectsRect(er) && HP == 1 && (m_player->shelled || m_player->speedUp))) {
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
                
                
                if (!m_player->shelled && !m_player->speedUp) {
                    HP--;
                }
                else {
                    if (!m_player->speedUp) {
                        m_player->shelled = false;
                    }
                }
                enemy->removeFromParent();
                allEnemyRightCrow.eraseObject(enemy);
                i--;
                if (!m_player->speedUp) {
                    this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
                }
                
                
            }
            else if (pp.intersectsRect(er) && HP == 1 && !m_player->shelled && !m_player->speedUp && !m_player->speedUp){
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
                
                
                enemy->removeFromParent();
                allEnemyRightCrow.eraseObject(enemy);
                i--;
                if (!m_player->speedUp) {
                    this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
                }
                
                
                
                this->pause();
                Director::getInstance()->replaceScene(TransitionMoveInB::create(2, GameOverHalloween::createScene()));
            }
        }
        else {
            
            if (pp.intersectsRect(er)) {
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
                
                
                enemy->stopAllActions();
                enemy->removeFromParent();
                allEnemyRightCrow.eraseObject(enemy);
                i--;
                if (!m_player->speedUp) {
                    m_player -> speedUp = true;
                }
            }
            
        }
        
        //		if (pp.intersectsRect(er) && HP > 1) {
        //
        //
        //			HP--;
        //			enemy->removeFromParent();
        //			allEnemyRightCrow.eraseObject(enemy);
        //			i--;
        //			CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
        //			this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
        //
        //			auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
        //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
        //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
        //			auto action_3 = RepeatForever::create(Move_Down_3);
        //			label->setColor(Color3B::RED);
        //			label->runAction(action_3);
        //			this->addChild(label, 8);
        //
        //		}
        //		else if (pp.intersectsRect(er) && HP == 1){
        //
        //			enemy->removeFromParent();
        //			allEnemyRightCrow.eraseObject(enemy);
        //			i--;
        //			CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/touchCrow.wav");
        //			CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
        //			this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
        //
        //			auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
        //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
        //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
        //			auto action_3 = RepeatForever::create(Move_Down_3);
        //			label->setColor(Color3B::RED);
        //			label->runAction(action_3);
        //			this->addChild(label, 8);
        //
        //			this->pause();
        //			Director::getInstance()->replaceScene(TransitionMoveInB::create(2, GameOver::createScene()));
        //		}
    }
    
    auto labelHp = (Label *) this->getChildByTag(110);
    labelHp->setString(StringUtils::format("Hp: %d", HP));
    
    //score height
    
    auto labelHeight = (Label *) this->getChildByTag(111);
    if (score < 10000000)score++;
    labelHeight->setString(StringUtils::format("%d", score));
    
    
    
    //star
    for (int i = 0; i < allStar.size(); i++)
    {
        auto star = allStar.at(i);
        Rect er(star->getPositionX(), star->getPositionY(), 40, 50);
        
        if (pp.intersectsRect(er)) {
            //MenuItemImage *specialSkill= (MenuItemImage*)this->getChildByTag(112);
            
            //this->addChild(specialSkill);
            //skill button
            //
            //            auto abilityButtonItem = MenuItemImage::create(
            //                                                           "bang.png",
            //                                                           "bang.png",
            //                                                           CC_CALLBACK_1(NewGameScene_japan::playerAbility_Teleportation, this)
            //                                                           );
            //
            //            abilityButtonItem->setScale(bg_scale);
            //
            //            abilityButtonItem->setPosition(bg_origin + abilityButtonItem->getBoundingBox().size/2);
            //            this->addChild(abilityButtonItem);
            //abilityButtonTouched = true;
            
            //add star into item array
            push_item(item_type::star);
            
            
            /*
             
             
             if (item_Array[0] == item_Array[1] && item_Array[0] == item_type::star)
             {
             Menu *menu = (Menu*) getChildByTag(Scene_Tag::menu);
             
             auto abilityButtonItem = MenuItemImage::create(
             "Teleport.png",
             "Teleport.png",
             CC_CALLBACK_1(NewGameScene_japan::playerAbility_Teleportation, this)
             );
             
             abilityButtonItem->setScale(bg_scale);
             
             abilityButtonItem->setPosition(bg_origin + abilityButtonItem->getBoundingBox().size / 2);
             
             menu->addChild(abilityButtonItem, 10, Scene_Tag::skill_button);
             item_Array[0] = item_Array[1] = item_type::none_item;
             
             }
             */
            
            
            //HP++;
            star->removeFromParent();
            allStar.eraseObject(star);
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/getStar.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/getStar.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
            i--;
            //			auto label = Label::createWithTTF("HP +1", "fonts/Marker Felt.ttf", 24);
            //			label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            //			auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            //			auto action_3 = RepeatForever::create(Move_Down_3);
            //			label->setColor(Color3B::RED);
            //			label->runAction(action_3);
            //			this->addChild(label, 8);
        }
    }
    
    labelHp->setString(StringUtils::format("Hp: %d", HP));
    
    {
        
        auto my_player = (Player *) this->getChildByTag(0);
        
        float a = -1.f*(0.05 + 0.15*(sweep_angle / (M_PI / 2.f)))*bg_size.height / (0.25 * (bg_size.width - my_player->playerWidth - 2 * borderWidth) * (bg_size.width - my_player->playerWidth - 2 * borderWidth));
        
        if (my_player->isInAir&&!my_player->isMovingLeft)
        {
            
            if (my_player->getPositionX() == bg_origin.x + borderWidth + my_player->playerWidth / 2){
                
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/flyAttack.aif");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/flyAttack.aif");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
            }
            my_player->setPositionX(my_player->getPositionX() + 20);
            float y = a * (my_player->getPositionX() - bg_origin.x - borderWidth - 0.5 * my_player->playerWidth)*(my_player->getPositionX() - bg_origin.x + borderWidth - bg_size.width + 0.5 * my_player->playerWidth);
            my_player->setPositionY(y + bg_size.height*0.16);
            
            if (my_player->getPositionX() >= bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2)
            {
                my_player->isInAir = false;
                my_player->setPosition(bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2, bg_origin.y + bg_size.height*0.16);
                
            }
            /*
             else if (this->getPositionX() >= origin.x + bgSize.x / 2 && isLeft)
             {
             this->setScaleX((this->getScaleX()) * -1.f);
             isLeft = false;
             }
             */
            
        }
        else if (my_player->isInAir&&my_player->isMovingLeft)
        {
            
            if (my_player->getPositionX() == bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2){
                CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/flyAttack.aif");
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/flyAttack.aif");
                CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(2.5);
            }
            
            my_player->setPosition(my_player->getPositionX() - 20, bg_origin.y + bg_size.height*0.16);
            float y = a * (my_player->getPositionX() - bg_origin.x - borderWidth - 0.5 * my_player->playerWidth)*(my_player->getPositionX() - bg_origin.x + borderWidth - bg_size.width + 0.5 * my_player->playerWidth);
            my_player->setPositionY(y + bg_size.height*0.16);
            
            if (my_player->getPositionX() <= bg_origin.x + borderWidth + my_player->playerWidth / 2)
            {
                my_player->isInAir = false;
                my_player->setPosition(bg_origin.x + borderWidth + my_player->playerWidth / 2, bg_origin.y + bg_size.height*0.16);
                
                
            }
            /*
             else if (this->getPositionX() <= origin.x + bgSize.x / 2 && !isLeft)
             {
             this->setScaleX((this->getScaleX()) * -1.f);
             isLeft = true;
             }
             */
        }
        
        
    }
}


void NewGameScene_halloween::create_skill(cocos2d::Ref* pSender)
{
    if (item_Array[0] == item_Array[1] && item_Array[0] == item_type::star)
    {
        
        Menu* menu = (Menu*)getChildByTag(Scene_Tag::menu);
        MenuItemImage* skill = (MenuItemImage*)menu->getChildByTag(Scene_Tag::skill_button);
        auto teleport_img = Sprite::create("Teleport.png");
        skill->setNormalImage(teleport_img);
        skill->setScale(bg_scale);
        skill->setPosition(bg_origin + skill->getBoundingBox().size / 2);
        skill->setVisible(true);
        
        current_skill = skill_type::teleport;
        clear_item();
    }
    
}

void NewGameScene_halloween::use_skill(cocos2d::Ref* pSender)
{
    if (current_skill == skill_type::teleport)
    {
        playerAbility_Teleportation();
        Menu* menu = (Menu*)getChildByTag(Scene_Tag::menu);
        MenuItem* skill = (MenuItem*)menu->getChildByTag(Scene_Tag::skill_button);
        skill->setVisible(false);
        
        current_skill = skill_type::none_skill;
        
    }
    
}

void NewGameScene_halloween::playerAbility_Teleportation()
{
    Player *my_player = (Player *)(this->getChildByTag(Scene_Tag::player));
    
    if (!my_player->isInAir&&my_player->isLeft)
    {
        
        if (my_player->getPositionX() == bg_origin.x + borderWidth + my_player->playerWidth / 2){
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swipSword.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swipSword.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(10);
        }
        my_player->isLeft = false;
        my_player->m_dir = DIR_RIGHT;
        //my_player->logic();
        my_player->setPositionX(bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2);
        abilityButtonTouched = true;
    }
    else if (!my_player->isInAir&&!my_player->isLeft)
    {
        
        if (my_player->getPositionX() == bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2){
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swipSword.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swipSword.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(10);
        }
        my_player->isLeft = true;
        my_player->m_dir = DIR_LEFT;
        //my_player->logic();
        my_player->setPositionX(bg_origin.x + borderWidth + my_player->playerWidth / 2);
        abilityButtonTouched = true;
    }
}

void NewGameScene_halloween::push_item(int item)
{
    if (item_Array[0] == item_type::none_item) item_Array[0] = item;
    else if (item_Array[1] == item_type::none_item) item_Array[1] = item;
    else
    {
        item_Array[0] = item_Array[1];
        item_Array[1] = item;
    }
    Sprite* item0 = (Sprite*)getChildByTag(Scene_Tag::item_0);
    Sprite* item1 = (Sprite*)getChildByTag(Scene_Tag::item_1);
    
    
    if (item_Array[0] == item_type::star)
    {
        Texture2D* tmp = TextureCache::sharedTextureCache()->addImage("halloween/Halloween_pumpkin.png");
        item0->setTexture(tmp);
        item0->setScale(bg_scale);
        item0->setPosition(bg_origin.x + bg_size.width / 2 - item0->getBoundingBox().size.width / 2, bg_origin.y + bg_size.height*0.125);
        item0->setVisible(true);
    }
    else if (item_Array[0] == item_type::none_item)
    {
        item0->setVisible(false);
    }
    
    if (item_Array[1] == item_type::star)
    {
        Texture2D* tmp = TextureCache::sharedTextureCache()->addImage("halloween/Halloween_pumpkin.png");
        item1->setTexture(tmp);
        item1->setScale(bg_scale);
        item1->setPosition(bg_origin.x + bg_size.width / 2 + item1->getBoundingBox().size.width / 2, bg_origin.y + bg_size.height*0.125);
        item1->setVisible(true);
    }
    else if (item_Array[1] == item_type::none_item)
    {
        item1->setVisible(false);
    }
    
}

void NewGameScene_halloween::clear_item()
{
    item_Array[0] = item_Array[1] = item_type::none_item;
    Sprite* item0 = (Sprite*)getChildByTag(Scene_Tag::item_0);
    Sprite* item1 = (Sprite*)getChildByTag(Scene_Tag::item_1);
    item0->setVisible(false);
    item1->setVisible(false);
}
void NewGameScene_halloween::timeController(float t) {
    
    // speedUp time
    if (m_player->speedUp) {
        speedTime ++;
    }
    if (speedTime == 50) {
        speedTime = 0;
        m_player->speedUp = false;
    }
}

