/*
 * Factory.h
 *
 *  Created on: 2017��7��29��
 *      Author: xiaoquan
 */

#ifndef FACTORY_H_
#define FACTORY_H_

//�����ɫ  �����ɫ�ĳ���
class Actor{
public:
	Actor(){}
	virtual ~Actor(){}
};

//����ʵ����ɫ

//����Player��ɫ��ʵ��
class Player:public Actor{
public:
	Player();
	~Player();
};

//����Demon��ɫ��ʵ��
class Demon:public Actor{
public:
	Demon();
	~Demon();
};

//����Fairy��ɫ��ʵ��
class Fairy:public Actor{
public:
	Fairy();
	~Fairy();
};

//����Civilian��ɫ��ʵ��
class Civilian:public Actor{
public:
	Civilian();
	~Civilian();
};

//�����ĳ�����,������ɫ
class Factory {
public:
	Factory(){}
	virtual ~Factory(){}

	virtual Actor * CreateActor(){ return new Actor();}
};

// ����Player
class PlayerFactory:public Factory{
public:
	PlayerFactory();
	~PlayerFactory();

	virtual Actor * CreateActor();
};

// ����Demon
class DemonFactory:public Factory{
public:
	DemonFactory();
	~DemonFactory();

	virtual Actor * CreateActor();
};

// ����Fairy
class FairyFactory:public Factory{
public:
	FairyFactory();
	~FairyFactory();

	virtual Actor * CreateActor();
};

// ����Civilian
class CivilianFactory:public Factory{
public:
	CivilianFactory();
	~CivilianFactory();

	virtual Actor *CreateActor();
};

#endif /* FACTORY_H_ */
