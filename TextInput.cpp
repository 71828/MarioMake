#include "TextInput.h"

//Scene* TextInput::createScene()
//{
//    auto scene = Scene::create();
//    auto layer = TextInput::create();
//    scene->addChild(layer);
//    return scene;
//}


bool TextInput::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//�õ���Ļ��ش�С
    visibleSize = Director::getInstance()->getVisibleSize();  

    //�����ı���  
    //��һ���������ı�������ʾ������  
    //�ڶ�������������  
    //�������������ı��Ĵ�С 

	// �����ı���1
    textEdit = CCTextFieldTTF::textFieldWithPlaceHolder("Please input:","Arial", 36);  
    textEdit->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));  
	textEdit->setColorSpaceHolder(Color3B::BLUE);
    this->addChild(textEdit);  
/*  
	// �����ı���2��
	textEdit2 = CCTextFieldTTF::textFieldWithPlaceHolder("Please input:",CCSizeMake(100,100), CCTextAlignment::LEFT, "Arial", 36);
	textEdit2->setPosition(Vec2(visibleSize.width/2,visibleSize.height/4));
	this->addChild(textEdit2);
*/


	// ���ְ�ť�������� ģʽ
	auto btn_psw = MenuItemFont::create("password",CC_CALLBACK_1(TextInput::menupswCallback,this));  
	btn_psw->setPosition(Vec2(btn_psw->getContentSize().width,visibleSize.height/4)); 
	
	// ���ְ�ť����չʾ �ı�������
	auto btn_show = MenuItemFont::create("show",CC_CALLBACK_1(TextInput::menushowCallback,this));
	btn_show->setPosition(Vec2(btn_psw->getContentSize().width*2,visibleSize.height/4));

	// ���ְ�ť���������ı������ַ�����
	auto btn_count = MenuItemFont::create("count",CC_CALLBACK_1(TextInput::menucountCallback,this));
	btn_count->setPosition(Vec2(btn_psw->getContentSize().width,visibleSize.height/6));

	// ���ְ�ť�����ı��ı�����������ɫ
	auto btn_color = MenuItemFont::create("color",CC_CALLBACK_1(TextInput::menuchangeColorCallback,this));
	btn_color->setPosition(Vec2(btn_psw->getContentSize().width*2,visibleSize.height/6));

	auto menu = Menu::create(btn_psw,btn_show,btn_count,btn_color, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


	auto label_show = Label::create(textEdit->getString(),"Arial", 24);
	label_show->setPosition(Vec2(visibleSize.width/2-50,visibleSize.height/1.5));
	label_show->setTag(111);
	this->addChild(label_show);

	auto label_count = Label::create(textEdit->getString(),"Arial", 24);
	label_count->setPosition(Vec2(visibleSize.width/2+50,visibleSize.height/1.5));
	label_count->setTag(112);
	this->addChild(label_count);


    //���������ؼ���ʱ�򵯳������  
    setTouchMode(kCCTouchesOneByOne);  
    setTouchEnabled(true);  

    return true;
}

// �����¼�
bool TextInput::onTouchBegan(CCTouch* touch, CCEvent* ev)  
{  
    //�����ж��Ƿ�����˿ؼ�  
    bool isClicked = textEdit->boundingBox().containsPoint(touch->getLocation());  

    //��������˿ؼ�  
	if( isClicked )  
    {  
        //���������  
        textEdit->attachWithIME();  
    }
	else
	{
		textEdit->detachWithIME();
	}

    //��ʾ���ܴ�����Ϣ  
    return true;  
} 

// �Ƿ����ó� ���� ģʽ
void TextInput::menupswCallback(cocos2d::Ref* pSender)
{
	if( textEdit->isSecureTextEntry() )
	{
		textEdit->setSecureTextEntry(false);
	}
	else
	{
		textEdit->setSecureTextEntry(true);
	}
}

// չʾ�ı�������
void TextInput::menushowCallback(cocos2d::Ref* pSender)
{
	auto label = (Label*) this->getChildByTag(111);
	label->setString(textEdit->getString());
}

// �����ı��������ַ�����
void TextInput::menucountCallback(cocos2d::Ref* pSender)
{
	auto label = (Label*) this->getChildByTag(112);
	label->setString( StringUtils::format(" %d ",textEdit->getCharCount()) );
}

// �ı��ı���������ɫ
void TextInput::menuchangeColorCallback(cocos2d::Ref* pSender)
{
	textEdit->setColor(Color3B::GREEN);
}