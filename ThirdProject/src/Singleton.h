/*
 * Singleton.h
 *
 *  Created on: 2017��7��29��
 *      Author: xiaoquan
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

class Manager {
private:
	// ��̬��Ա����,�ṩȫ��Ωһ��һ��ʵ��
	static Manager *m_pStatic;
public:
	Manager();
	virtual ~Manager();

	// ��̬��Ա����,�ṩȫ�ַ��ʵĽӿ�
	static Manager * GetManager();

	void test();
};

#endif /* SINGLETON_H_ */
