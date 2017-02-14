#ifndef __TEXT_INPUT_H__ 
#define __TEXT_INPUT_H__ 
  
#include "cocos2d.h"  
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;  


class TextInput : public CCLayer  
{  
public:  
    virtual bool init();     
    /*static Scene* createScene();*/
	CREATE_FUNC(TextInput); 
  
	// �����¼�
	bool onTouchBegan(Touch  *touch, Event  *event);

	// ��ť�ص�����
	void menupswCallback(cocos2d::Ref* pSender);
	void menushowCallback(cocos2d::Ref* pSender);
	void menucountCallback(cocos2d::Ref* pSender);
	void menuchangeColorCallback(cocos2d::Ref* pSender);

private:
	Size visibleSize;
	CCTextFieldTTF* textEdit;
//	CCTextFieldTTF* textEdit2;
};  
  
#endif