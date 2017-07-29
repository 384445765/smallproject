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
/*�������ܣ�������nת�����ַ�������
 * stringӦ����ǰ�����㹻�����ڴ�*/
char *itostr(int n,char *string);
/*������n������������-2^31~2^31-1��Χ��ת�����ַ�������*/
char *itostr(long long n);//���ڵݹ�

/*��Ŀ2������ʵ���ַ�����CNString*/
class CNString{
private:
	char *str;//ָ���ַ�����һ���ַ�
	int len;//�ַ������ȣ��������ַ�'\0'��
public:
	/*Ĭ�Ϲ��캯��*/
	CNString();
	/*���캯��*/
	CNString(const char*st);
	/*���ƹ��캯��*/
	CNString(const CNString &s);

	/*�ַ������ƺ��������ַ���s2���Ƶ�s1,
	 * ������ָ����ַ����ĵ�һ���ַ���ָ��
	 * �ַ���s1�����㹻��*/
	char *strcpy_s(char*s1,const char *s2);

	/*����=����*/
	CNString& operator=(const CNString &s);
	/*����+����*/
	CNString operator+(const CNString &s);
	char operator[](const int n);
	bool operator<(const CNString &s);
	bool operator>(const CNString &s);
	bool operator==(const CNString &s);

	size_t size(){
		return len;
	}

	/*�������<<����
	 * �������os������ַ���s��
	 * �����������*/
	friend std::ostream& operator<<(std::ostream & os,const CNString &s);

	/*��������*/
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

	/*��˫������ĩβ����ڵ�Node*/
	void insert(dNode & Node);

	/*��˫������ĩβ������nkeyΪkey�Ľڵ�*/
	void insert(int nkey);

	/*��������Ĭ��Ϊ����index = 0��
	 * ����index = 1������*/
	void sort(const int index = 0);

	/*�����������Ƿ��нڵ�Node
	 * ���ҵ������ؽڵ�Node�������е�һ�γ��ֵ�λ��
	 * ��û���ҵ�������0*/
	int search(dNode & Node);

	/*ɾ��������keyΪnk��һ���ڵ㣬������true
	 * ��ɾ��ʧ�ܣ��򷵻�false*/
	bool del(int nk);

	/*ɾ����������Node������key��ͬ��һ���ڵ�
	 * ������true,���򷵻�false*/
	bool del(dNode & Node);

	/*��ӡ�����нڵ��������*/
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

	/*������ĩβ������nkeyΪkey�Ľڵ�*/
	void insert(int nk);

	/*������ĩβ����ڵ�Node*/
	void insert(sNode & Node);

	/*�����������Ƿ��нڵ�Node
	 * ���ҵ������ؽڵ�Node�������е�һ�γ��ֵ�λ��
	 * ��û���ҵ�������0*/
	int search(sNode & Node);

	/*ɾ��������keyΪnk��һ���ڵ㣬������true
	 * ��ɾ��ʧ�ܣ��򷵻�false*/
	void del(int nk);

	/*ɾ����������Node������key��ͬ��һ���ڵ�
	 * ������true,���򷵻�false*/
	void del(sNode & Node);

	/*��������Ĭ��Ϊ����index = 0��
	 * ����index = 1������*/
	void sort(const int index = 0);

	/*��ӡ�����нڵ��������*/
	void printNode() const;

	~slist();
};
#endif /* FIRST_H_ */
