/*
 * Singleton.cpp
 *
 *  Created on: 2017��7��29��
 *      Author: xiaoquan
 */

#include "Singleton.h"
#include<iostream>
#include<cstdlib>


// ��ľ�̬��Ա����Ҫ����������ж���
Manager* Manager::m_pStatic = NULL;

Manager::Manager() {
	// TODO Auto-generated constructor stub

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

// ��̬��Ա����,�ṩȫ�ַ��ʵĽӿ�
Manager * Manager::GetManager(){
	if(NULL == m_pStatic){
		m_pStatic =  new Manager();
	}
	return m_pStatic;
}

void Manager::test(){
	std::cout << "Test Manager!\n";
}
