/*
 * CBattle.cpp
 *
 *  Created on: 2017��7��20��
 *      Author: xiaoquan
 */

#include "CBattle.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


CBattle::CBattle() {
	CH = new CHero();
	CE = new CEnemy();
}

CBattle::~CBattle() {
	delete CH;
	delete CE;
}

void CBattle::fight(){
	//jump������ζ�´ζԷ�������Ч������jump��

	srand(time(0));
	show();
	cout << "Fight Start:\n";
	int priority = rand()%2;//���ȹ���Ȩ�����������0-1,0����Ӣ���ȳ��֣�1��������ȳ���

	int H_index,E_index;
	//�����H_index�����ķ�ΧΪ0-3�����α�ʾӢ�۵ĳ�����ʽ ��������������Ծ�����ȣ���ˤ
	//�����E_index�����ķ�ΧΪ0-3�����α�ʾ���˵ĳ�����ʽ��������������Ծ�����ƣ�������

	bool H_dead = false;//����Ӣ��û������ģ�
	bool E_dead = false;//�������û��(��ģ�

	bool H_jump = false;//Ӣ���Ƿ���Ծ
	bool E_jump = false;//�����Ƿ���Ծ

	while(1){
		if(priority == 0){
			if(!E_jump){
				H_index = rand() % 4;
				switch(H_index){
				case 0 : E_dead = CH->attack(*CE); break;
				case 1 : H_jump = CH->jump();break;
				case 2 : E_dead = CH->kick(*CE);break;
				default : E_dead = CH->counter(*CE);break;
				}
			}else{
				E_jump = false;
				cout << CH->getname() << " miss!!!\n";
			}
			priority = 1;
			show();
		}else{
			if(!H_jump){
				E_index = rand() % 4;
				switch(E_index){
				case 0 : H_dead = CE->attack(*CH);break;
				case 1 : E_jump = CE->jump();break;
				case 2 : H_dead = CE->chop(*CH);break;
				default : H_dead = CE->catching(*CH);break;
				}
			}else{
				H_jump = false;
				cout << CE->getname() << " miss!!!\n";
			}
			priority = 0;
			show();
		}
		if(H_dead){
			CE->addexp(Hero_EXP_Per[CH->getLv()]);
			cout << "The hero died!!!";
			break;
		}
		if(E_dead){
			CH->addexp(Enemy_EXP_Per[CE->getLv()]);
			cout << "The enemy died!!!";
			break;
		}
	}
	cout << "Battle finish!!!\n";
}

void CBattle::show(){
	cout << "The two sides battle situation��\n";
	cout << CH->getname() << string(6,' ') << CE->getname() << "\n";
	cout << "HP: " << CH->getHP() << string(3,' ') << "HP: " << CE->getHP() << "\n";
	cout << "ATK: " << CH->getATK() << string(4,' ') << "ATK: " << CE->getATK() << "\n";
	cout << "DEF: " << CH->getDEF() << string(4,' ') << "DEF: " << CE->getDEF() << "\n";
	cout << "Lv: " << CH->getLv() << string(5,' ') << "Lv: " << CE->getLv() << "\n";
	cout << "EXP: " << CH->getEXP() << string(4,' ') << "EXP: " << CE->getEXP() << "\n";
}
