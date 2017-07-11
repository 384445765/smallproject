/*
 * first.h
 *
 *  Created on: 2017��7��10��
 *      Author: xiaoquan
 */

#ifndef FIRST_H_
#define FIRST_H_

#include<ostream>
/*��Ŀ1����д�ݹ麯��char *itostr (int n,char *string)��
 *�ú���������nת��Ϊʮ���Ʊ�ʾ���ַ���������ʾ��ʹ�õݹ鷽����*/
char *itostr(int n,char *string);
char *itostr(long long n);//���ڵݹ�

/*��Ŀ2������ʵ���ַ�����CNString*/
class CNString{
private:
	char *str;
	int len;
public:
	CNString();
	CNString(const char*st);
	CNString(const CNString &s);

	char *strcpy_s(char*s1,const char *s2);

	CNString& operator=(const CNString &s);
	CNString operator+(const CNString &s);
	char operator[](const int n);
	bool operator<(const CNString &s);
	bool operator>(const CNString &s);
	bool operator==(const CNString &s);

	friend std::ostream& operator<<(std::ostream & os,const CNString &s);

	~CNString();
};



//��Ŀ3������˫��������
struct dNode{
	int key;
	dNode * pre;
	dNode * next;
	dNode():key(0),pre(NULL),next(NULL){}
	dNode(int nkey):key(nkey),pre(NULL),next(NULL){}
};//����˫������Ľڵ�

class dlist{
private:
	dNode * head;//����ͷ
	dNode * tail;//����β
	int len;//������
public:
	dlist();
	dlist(dlist & dl);
	void insert(dNode & Node);
	void insert(int nkey);
	void sort(const int index = 0);
	int search(dNode & Node);
	bool del(int nk);
	bool del(dNode & Node);

	void printNode() const;
	~dlist();
};

//��Ŀ4����������������
struct sNode{
	int key;
	sNode *next;
	sNode():key(0),next(NULL){}
	sNode(int nkey):key(nkey),next(NULL){}
};
class slist{
private:
	sNode *head;
	int len;
public:
	slist();
	slist(slist & sl);

	void insert(int nk);
	void insert(sNode & Node);
	int search(sNode & Node);
	void del(int nk);
	void del(sNode & Node);
	void sort(const int index = 0);

	void printNode() const;
	~slist();
};






#endif /* FIRST_H_ */
