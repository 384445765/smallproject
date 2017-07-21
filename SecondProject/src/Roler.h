/*
 * Roler.h
 *
 *  Created on: 2017��7��20��
 *      Author: xiaoquan
 */
#include<string>

using namespace std;

#ifndef ROLER_H_
#define ROLER_H_

//////////////////////////////////////////////////////////////////////
//						����  CRole
//////////////////////////////////////////////////////////////////////
class CRole {
private:
	string name;//ͷ����ʾ����
	int HP;//Ѫ��
	int ATK;//������
	int DEF;//������
	int Lv;//�ȼ�
	int EXP;//����ֵ
public:
	CRole():name(""),HP(0),ATK(0),DEF(0),Lv(0),EXP(0){}
	CRole(string Init_name,int Init_HP,int Init_ATK,int Init_DEF,int Init_Lv,int Init_EXP);
	virtual ~CRole(){}

	/*��ͨ�����Է������Է��ܹ������˺����򷵻�false,
	 * ������Է�����������true*/
	bool attack(CRole &CR);//��������

	/*��Ծ�����������һ�ζ��ֵĹ���*/
	bool jump();//��Ծ

	string getname() const;//������ﵱǰ������
	int getHP() const;//��ȡ���ﵱǰ��Ѫ��
	int getATK() const;//��ȡ���ﵱǰ����ͨ����
	int getDEF() const;//��ȡ���ﵱǰ�ķ�����
	int getLv() const;//������ﵱǰ�ĵȼ�
	int getEXP() const;//������ﵱǰ�ľ���

	void chargename(string s);//��������
	void chargeHP(int hp);//����Ѫ��
	void chargeATK(int atk);//���Ĺ���
	void chargeDEF(int def);//���ķ�����
	void chargeLv(int lv);//���ĵȼ�
	void chargeEXP(int exp);//���ľ���ֵ

};

//////////////////////////////////////////////////////////////////////
//						Ӣ����  CHero �����̳��� ��CRole
//////////////////////////////////////////////////////////////////////

static string Hero_Init_name = "Hero";
const int Hero_Init_ATK = 5;//��ʼ������
const int Hero_Init_DEF = 3;//��ʼ������
const int Hero_Init_Lv = 0;//��ʼ�ȼ�
const int Hero_Init_EXP = 0;//��ʼ����ֵ
const int Init_kick = 10;//��ʼ�����˺�
const int Init_counter = 15;//��ʼ��ˤ�˺�

const int Hero_Lv_Max = 8;//Ӣ����ߵĵȼ���0��8����
const int Hero_HP_Max[] = {100,200,300,400,500,600,700,800,900};//Ӣ��ÿ����Ӧ�����Ѫ��
const int Hero_EXP_Max[] = {2,20,40,80,160,320,640,1280,2560};//�����¸���������Ҫ�������ֵ
const int Hero_EXP_Per[] = {2,4,8,16,32,64,128,256,512};//ɱ����Ӧ�ȼ��ĵ�������ľ���ֵ

const double Hero_ATK_Ratio = 1.2;//��ͨ�������������ʣ���ȼ����ӣ���ͨ��������һ�Σ�
const double Hero_DEF_Ratio = 1.1;//�������������ʣ�ͬ�ϣ�

const double Hero_kick_Ratio = 1.3;//���ȹ������������ʣ���ȼ����ӣ���ͨ��������һ�Σ�
const double Hero_counter_Ratio = 1.5;//��ˤ���������ʣ�ͬ�ϣ�

class CHero:public CRole{
private:
	int kick_ATK;//�����˺�
	int counter_ATK;//��ˤ�˺�
public:
	CHero();
	~CHero();

	bool kick(CRole & CE);//����
	bool counter(CRole & CE);//��ˤ

	void addexp(int exp);//ɱ��������Ӧ�ľ���ֵ
	void upgrade();//����
};

//////////////////////////////////////////////////////////////////////
//						������  CEnemy �����̳��� ��CRole
//////////////////////////////////////////////////////////////////////

static string Enemy_Init_name = "Enemy";
const int Enemy_Init_ATK = 3;//��ʼ������
const int Enemy_Init_DEF = 4;//��ʼ������
const int Enemy_Init_Lv = 0;//��ʼ�ȼ�
const int Enemy_Init_EXP = 0;//��ʼ����ֵ
const int Init_chop = 10;//��ʼ�����˺�
const int Init_catching = 15;//��ʼ�������˺�

const int Enemy_Lv_Max = 8;//Ӣ����ߵĵȼ���0��8����
const int Enemy_HP_Max[] = {100,200,300,400,500,600,700,800,900};//Ӣ��ÿ����Ӧ�����Ѫ��
const int Enemy_EXP_Max[] = {2,20,40,80,160,320,640,1280,2560};//�����¸���������Ҫ�������ֵ
const int Enemy_EXP_Per[] = {2,4,8,16,32,64,128,256,512};//ɱ����Ӧ�ȼ��ĵ�������ľ���ֵ

const double Enemy_ATK_Ratio = 1.1;//��ͨ�������������ʣ���ȼ����ӣ���ͨ��������һ�Σ�
const double Enemy_DEF_Ratio = 1.2;//�������������ʣ�ͬ�ϣ�

const double Enemy_chop_Ratio = 1.3;//���ȹ������������ʣ���ȼ����ӣ���ͨ��������һ�Σ�
const double Enemy_catching_Ratio = 1.5;//��ˤ���������ʣ�ͬ�ϣ�


class CEnemy:public CRole{
private:
	int chop_ATK;
	int catching_ATK;
public:
	CEnemy();
	~CEnemy();

	bool chop(CRole & CH);//����
	bool catching(CRole & CH);//������

	void addexp(int exp);//ɱ��������Ӧ�ľ���ֵ
	void upgrade();//����

};

#endif /* ROLER_H_ */
