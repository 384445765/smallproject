/*
 * Roler.cpp
 *
 *  Created on: 2017��7��20��
 *      Author: xiaoquan
 */

#include "Roler.h"
#include<iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
//						����  CRole ����
//////////////////////////////////////////////////////////////////////

CRole::CRole(string Init_name,int Init_HP,int Init_ATK,int Init_DEF,int Init_Lv,int Init_EXP) {
	name = Init_name;
	HP = Init_HP;
	ATK = Init_ATK;
	DEF = Init_DEF;
	Lv = Init_Lv;
	EXP = Init_EXP;
}

bool CRole::attack(CRole &CR){
	//��������
	int Damage = ATK - CR.DEF;//�����ĵ�Ѫ��

	cout << name << " attack " << CR.getname() << " " << Damage << "Hp\n";//��ʾ�˺����

	if(CR.HP > Damage)
		CR.HP -= Damage;//�Է�Ѫ���㹻���ܹ������˺�
	else
		CR.HP = 0;//�Է�Ѫ������������

	return CR.HP == 0 ? true : false;
}
bool CRole::jump(){//��Ծ
	cout << name << " jump.\n";

	return true;
}

string CRole::getname() const{
	return name;
}

int CRole::getHP() const{
	return HP;
}

int CRole::getATK() const{
	return ATK;
}

int CRole::getDEF() const{
	return DEF;
}

int CRole::getLv() const{
	return Lv;
}

int CRole::getEXP() const{
	return EXP;
}

void CRole::chargename(string s){
	cout << "name: "<< name << " ---> " << s << "\n";//��ʾ

	name = s;
}

void CRole::chargeHP(int hp){
	cout << "HP: " << HP << " ---> " << hp << "\n";

	HP = hp;
}

void CRole::chargeATK(int atk){
	cout << "ATK: " << ATK << " ---> " << atk << "\n";

	ATK = atk;
}

void CRole::chargeDEF(int def){
	cout << "DEF: " << DEF << " ---> " << def << "\n";

	DEF = def;
}

void CRole::chargeLv(int lv){
	cout << "Lv: " << Lv << " ---> " << lv << "\n";

	Lv = lv;
}

void CRole::chargeEXP(int exp){
	cout << "EXP: " << EXP << " ---> " << exp << "\n";

	EXP = exp;
}

//////////////////////////////////////////////////////////////////////
//						Ӣ����  CHero ����
//////////////////////////////////////////////////////////////////////

CHero::CHero():CRole(Hero_Init_name,Hero_HP_Max[0],Hero_Init_ATK,Hero_Init_DEF,Hero_Init_Lv,Hero_Init_EXP){
	kick_ATK = Init_kick;
	counter_ATK = Init_kick;
}

CHero::~CHero() {

}

bool CHero::kick(CRole & CE){//����
	//���ȹ���
	int Damage = kick_ATK + getATK() - CE.getDEF();//�����ĵ�Ѫ��

	cout << getname() << " kick " << CE.getname() << " " << Damage << "Hp\n";//��ʾ�˺����

	int resHP = CE.getHP() - Damage;//ʣ��Ѫ��
	if(resHP <= 0)//�Է�Ѫ������������
		resHP = 0;

	CE.chargeHP(resHP);

	return resHP == 0 ? true : false;
}

bool CHero::counter(CRole & CE){
	//���ȹ���
	int Damage = counter_ATK + getATK() - CE.getDEF();//�����ĵ�Ѫ��

	cout << getname() << " counter " << CE.getname() << " " << Damage << "Hp\n";//��ʾ�˺����

	int resHP = CE.getHP() - Damage;//ʣ��Ѫ��
	if(resHP <= 0)//�Է�Ѫ������������
		resHP = 0;

	CE.chargeHP(resHP);

	return resHP == 0 ? true : false;
}


void CHero::addexp(int exp){
	int cur_exp = getEXP() + exp;//��ø��º�ľ���ֵ
	chargeEXP(cur_exp);
	if(cur_exp >= Hero_EXP_Max[getLv()])
		upgrade();//����
}

void CHero::upgrade(){
	//��ǰ�����Ѿ�������ǰ�����������

	cout << "congratulations!!! " << getname() << " upgrade!!!!\n";

	int curLv = getLv();//��ǰ�ȼ�
	if(curLv == Hero_Lv_Max){//�Ѿ�����ߵȼ�����������
		cout << "Your have are the highest grade.\n";

		chargeHP(Hero_HP_Max[Hero_Lv_Max]);//������Ѫ
		chargeEXP(Hero_EXP_Max[Hero_Lv_Max]);//����Ϊ��ǰ���������
	}else{
		//�ȼ����ӣ���������Ҳ��֮�ı�
		cout << getname() << " \'s changing situation��\n";

		chargeEXP(getEXP() - Hero_EXP_Max[curLv]);
		chargeLv(curLv+1);
		chargeHP(Hero_HP_Max[curLv+1]);
		chargeATK(int(getATK() * Hero_ATK_Ratio));
		chargeDEF( int(getDEF() * Hero_DEF_Ratio));

		kick_ATK *= Hero_kick_Ratio;
		counter_ATK *= Hero_counter_Ratio;
	}
}

//////////////////////////////////////////////////////////////////////
//						������  CEnemy ����
//////////////////////////////////////////////////////////////////////

CEnemy::CEnemy():CRole(Enemy_Init_name,Enemy_HP_Max[0],Enemy_Init_ATK,Enemy_Init_DEF,Enemy_Init_Lv,Enemy_Init_EXP) {
	chop_ATK = Init_chop;
	catching_ATK = Init_catching;
}

CEnemy::~CEnemy() {

}


bool CEnemy::chop(CRole & CH){//����
	int Damage = chop_ATK + getATK() - CH.getDEF();//�����ĵ�Ѫ��

	cout << getname() << " chop " << CH.getname() << " " << Damage << "Hp\n";//��ʾ�˺����

	int resHP = CH.getHP() - Damage;//ʣ��Ѫ��
	if(resHP <= 0)//�Է�Ѫ������������
		resHP = 0;

	CH.chargeHP(resHP);

	return resHP == 0 ? true : false;
}
bool CEnemy::catching(CRole & CH){//������
	int Damage = catching_ATK + getATK() - CH.getDEF();//�����ĵ�Ѫ��

	cout << getname() << " catching " << CH.getname() << " " << Damage << "Hp\n";//��ʾ�˺����

	int resHP = CH.getHP() - Damage;//ʣ��Ѫ��
	if(resHP <= 0)//�Է�Ѫ������������
		resHP = 0;

	CH.chargeHP(resHP);

	return resHP == 0 ? true : false;
}


void CEnemy::addexp(int exp){
	int cur_exp = getEXP() + exp;//��ø��º�ľ���ֵ
	chargeEXP(cur_exp);

	if(cur_exp >= Hero_EXP_Max[getLv()])
		upgrade();//����
}

void CEnemy::upgrade(){
	//��ǰ�����Ѿ�������ǰ�����������

	cout << "congratulations!!! " << getname() << " upgrade!!!!\n";

	int curLv = getLv();//��ǰ�ȼ�
	if(curLv == Hero_Lv_Max){//�Ѿ�����ߵȼ�����������
		cout << "Your have are the highest grade.\n";

		chargeHP(Hero_HP_Max[Hero_Lv_Max]);//������Ѫ
		chargeEXP(Hero_EXP_Max[Hero_Lv_Max]);//����Ϊ��ǰ���������
	}else{
		//�ȼ����ӣ���������Ҳ��֮�ı�
		cout << getname() << " \'s changing situation��\n";

		chargeEXP(getEXP() - Hero_EXP_Max[curLv]);
		chargeLv(curLv+1);
		chargeHP(Hero_HP_Max[curLv+1]);
		chargeATK(int(getATK() * Hero_ATK_Ratio));
		chargeDEF( int(getDEF() * Hero_DEF_Ratio));

		chop_ATK *= Enemy_chop_Ratio;
		catching_ATK *= Enemy_catching_Ratio;
	}


}


