/*
 * main.cpp
 *
 *  Created on: 2017��7��10��
 *      Author: xiaoquan
 */

#include"first.h"
#include<iostream>
#include<cstdio>
using namespace std;

int main(){

	//����1������char * itostr(int n,char *string);����
	cout << "��������1����� \n";
	int t;
	freopen("case/pro1.txt","r",stdin);
	while(cin >> t){
		char *s = new char[12];//int �ͱ�����󳤶�Ϊ10 + ����λ  + '\0';
		char *res = itostr(t,s);
		cout << "���� n: " << t;
		cout << "��������ֵ: " << res;
		cout << "��Ӧ�ַ���string��" << s << "\n";
		delete []s;
	}
	//����2��������CNString
	cout << "����2��������CNString�����\n";
	CNString str1("abc");
	CNString str2 = str1;
	cout << "str1: " << str1 << "\n";
	cout << "str2 = str1,str2: " << str2 << "\n";

	CNString str3("abc");
	CNString str4("efg");
	cout << "str3: " << str3 << "\n";
	cout << "str4: " << str4 << "\n";
	cout << "str3 = str3+str4: "
			"str3: " << str3 << "\n"
			"str3+str4:" << str3+str4 << "\n";

	cout << "str3[0]: " << str3[0] << "\n";
	cout << "str3[2]: " << str3[2] << "\n";

	if(str3 < str4)
		cout << str3 << " < " << str4;
	else if(str3 > str4)
		cout << str3 << " > " << str4;
	else
		cout << str3 << " == " << str4;
	cout << "\n";

	//����Ϊ��3��˫������
	cout << "��������3��˫������ \n";
	dlist dl;
	dl.insert(1);
	dl.insert(4);
	dl.insert(3);
	cout << "dlist1:";
	dl.printNode();

	dlist dl2(dl);
	cout << "dlist2:";
	dl2.printNode();
	dl2.del(3);
	cout << "delete 3,dlist2:";
	dl2.printNode();
	dl2.insert(2);
	cout << "insert 2,dlist2:";
	dl2.printNode();
	dl2.del(4);
	cout << "delete 4,dlist2:";
	dl2.printNode();
	dl2.del(1);
	cout << "delete 1,dlist2:";
	dl2.printNode();


	dl.insert(2);
	cout << "dlist1:";
	dl.printNode();
	dl.sort();
	cout << "dlist1,ascending sort:";
	dl.printNode();
	cout << "dlist1,descending sort:";
	dl.sort(1);
	dl.printNode();

	//��������4����������
	cout << "��������4���������� \n";
	slist dl3;
	dl3.insert(1);
	dl3.insert(4);
	dl3.insert(3);
	cout << "dlist3:";
	dl3.printNode();

	slist dl4(dl3);
	cout << "dlist4:";
	dl4.printNode();
	dl4.del(3);
	cout << "delete 3,dlist4:";
	dl4.printNode();
	dl4.insert(2);
	cout << "insert 2,dlist4:";
	dl4.printNode();
	dl4.del(4);
	cout << "delete 4,dlist4:";
	dl4.printNode();
	dl4.del(1);
	cout << "delete 1,dlist4:";
	dl4.printNode();


	dl3.insert(2);
	cout << "dlist3:";
	dl3.printNode();
	dl3.sort();
	cout << "dlist3,ascending sort:";
	dl3.printNode();
	cout << "dlist3,descending sort:";
	dl3.sort(1);
	dl3.printNode();



	return 0;
}


