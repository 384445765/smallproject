/*
 * CBattle.h
 *
 *  Created on: 2017��7��20��
 *      Author: xiaoquan
 */

#ifndef CBATTLE_H_
#define CBATTLE_H_

#include"Roler.h"

class CBattle{
private:
	CHero  *CH;//Ӣ��
	CEnemy *CE;//����
public:
	CBattle();
	~CBattle();

	void fight();//ս��
	void show();//��ʾ�Ϸ�״̬
};

#endif /* CBATTLE_H_ */
