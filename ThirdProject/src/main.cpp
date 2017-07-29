/*
 * main.cpp
 *
 *  Created on: 2017��7��29��
 *      Author: xiaoquan
 */

#include"Singleton.h"
#include"Factory.h"

int main(){


	//��2�����
	// ���ó�ʼ�������Ϳ��Է�����
	Manager * p = Manager::GetManager();
	p->test();

	//��4�����
	// ����Playerʵ��
	PlayerFactory *pPlayerFactory = new PlayerFactory;
	Actor *pPlayer = pPlayerFactory->CreateActor();

	// ����Demonʵ��
	DemonFactory *pDemonFactory = new DemonFactory;
	Actor *pDemon = pDemonFactory->CreateActor();

	// ����Fairyʵ��
	FairyFactory * pFairyFactory = new FairyFactory;
	Actor *pFairy = pFairyFactory->CreateActor();

	// ����Civilianʵ��
	CivilianFactory *pCivilianFactory = new CivilianFactory;
	Actor *pCivilian = pCivilianFactory->CreateActor();

	delete pPlayerFactory;
	delete pPlayer;
	delete pDemonFactory;
	delete pDemon;
	delete pFairyFactory;
	delete pFairy;
	delete pCivilianFactory;
	delete pCivilian;

	return 0;
}


