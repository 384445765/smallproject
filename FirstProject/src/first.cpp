/*
 * first.cpp
 *
 *  Created on: 2017��7��10��
 *      Author: xiaoquan
 */

#include"first.h"
#include<stack>
#include<climits>
#include<iostream>
//�ݹ�ʵ��

//����
char *itostr(int n,char *string){
	if(n < 0){
		n = -n;
		*string = '-';
		string++;
	}
	if(n / 10 != 0)
		string  = itostr(n/10,string);
	*string = n % 10 + '0';
	string++;
	*string = '\0';
	return string;
}


//char *itostr(int n,char *string){
//	long long ln = n;
//	int i = 0;
//	if(ln == 0){
//		string[0] = '0';
//		i++;
//	}else if(ln < 0){
//		ln = -ln;
//		string[0] = '-';
//		i++;
//	}//�Ƿ�Ϊ��
//	char * st = itostr(ln);
//	int j = 0;
//	while(st[j] != '\0'){
//		string[i] = st[j];
//		i++;
//		j++;
//	}
//	string[i] = '\0';
//	return string;
//}
//char *itostr(long long n){
//	char * res = new char[11];
//	res[0] = '\0';
//	if(n == 0)
//		return res;
//	else{
//		res = itostr(n/10);
//		int i = 0;
//		while(res[i] != '\0'){
//			i++;
//		}
//		res[i] = n%10 + '0';
//		res[i+1] = '\0';
//		return res;
//	}
//}


/*�ǵݹ�ʵ��*/
/*char *itostr(int n,char *string){
	//stringָ��������
	int i = 0;
	long long ln = n;//���������ת��Ϊ��������С����ת���ᳬ�磬���Զ���һ����������ʱ����ln
	if(ln == 0){//Ϊ�����
		string[0] = '0';
		i++;
	}else if(ln < 0){
		ln = -ln;
		string[0] = '-';
		i++;
	}
	std::stack<char> st;
	while(ln != 0){
		st.push(ln%10+'0');
		ln /= 10;
	}
	while(!st.empty()){
		*(string+i) = st.top();
		st.pop();
		i++;
	}
	*(string+i) = '\0';
	return string;
}
*/

////////////////////////////////////////////////////////////////

//��CNString����
CNString::CNString(){
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

CNString::CNString(const char*st){
	len = 0;
	while(st[len] != '\0'){len++;}
	str = new char[len+1];
	for(int i = 0;i <= len;i++)
		str[i] = st[i];
}

CNString::CNString(const CNString &s){
	len = s.len;
	str = new char[len+1];//�����µ��ڴ�
	strcpy_s(str,s.str);//����
}

char *CNString::strcpy_s(char*s1,const char *s2){
	int i = 0;
	while(s2[i] != '\0'){
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];//����'\0';
	return s1;
}


CNString& CNString::operator=(const CNString &s){
	if(*this == s)//��ֵ������
		return *this;
	delete []str;//�ͷžɵ��ڴ�
	len = s.len;
	str = new char[len+1];//�����µ��ڴ�
	strcpy_s(str,s.str);//����
	return *this;
}
CNString CNString::operator+(const CNString &s){
	len += s.len;
	char *res = new char[len+1];
	int i = 0,j = 0;
	while(str[i] != '\0'){
		res[i] = str[i];
		i++;
	}
	while(s.str[j] != '\0'){
		res[i] = s.str[j];
		i++;
		j++;
	}
	res[i] = '\0';
	delete []str;
	str = new char[len+1];
	i = 0;
	while(i <= len){
		str[i] = res[i];
		i++;
	}

	return *this;
}
char CNString::operator[](const int n){
	return str[n];
}
bool CNString::operator<(const CNString &s){
	int minlen = (len <= s.len ? len : s.len);
	for(int i = 0;i < minlen;i++){
		if(str[i] < s.str[i])
			return true;
		else if(str[i] > s.str[i])
			return false;
	}
	return false;
}
bool CNString::operator>(const CNString &s){
	return ~(*this < s);
}
bool CNString::operator==(const CNString &s){
	if(len != s.len)
		return false;
	int i = 0;
	while(i < len){
		if(str[i] != s.str[i])
			return false;
		i++;
	}
	return true;
}

std::ostream& operator<<(std::ostream & os,const CNString &s){
	os << s.str;
	return os;
}

CNString::~CNString(){
	delete []str;
}

////////////////////////////////////////////////////////////////

//˫������dlistʵ��
dlist::dlist(){
	head = NULL;
	tail = NULL;
	len = 0;
}
dlist::dlist(dlist & dl){
	len = dl.len;
	head = new dNode();//����һ����ͷ�ڵ�
	tail = head;
	dNode * temp = dl.head;
	for(int i = 0;i < len;i++){
		dNode *tp = new dNode(temp->key);//���½����ڵ�
		tail->next = tp;
		tp->pre = tail;
		tail = tail->next;
		temp = temp->next;
	}
	temp = head->next;
	delete head;
	head = temp;
}
void dlist::insert(dNode & Node){
	dNode * tp = new dNode(Node.key);
	if(tail == NULL){
		head = tp;
		tail = tp;
	}else{
		tail->next = tp;
		tp->pre = tail;
		tail = tail->next;
	}
	len++;
}

void dlist::insert(int nkey){
	dNode tp(nkey);
	this->insert(tp);
}

void dlist::sort(const int index){
	//Ĭ��index = 0��Ϊ����
	if(len < 2)//С��2���ڵ㲻������ֱ�����
		return;

	dNode *h,*p,*temp;
	h = NULL;
	if(index == 0){
		while(head != NULL){
			if(h == NULL){
				h = head;
				head = head->next;
				h->next = NULL;
				h->pre = NULL;
			}else if(h->key > head->key){
				temp = head;
				head = head->next;
				temp->next = h;
				temp->pre = NULL;
				h->pre = temp;
				h = temp;
			}else{
				temp = h;
				while(temp->next != NULL && temp->next->key < head->key){
					temp = temp->next;
				}
				p = temp->next;//����temp ��p֮��
				temp->next = head;
				temp->next->pre = temp;

				head = head->next;

				temp->next->next = p;
				if(p!=NULL)
					p->pre = temp->next;
			}
		}
	}else if(index == 1){
		while(head != NULL){
			if(h == NULL){
				h = head;
				head = head->next;
				h->next = NULL;
				h->pre = NULL;
			}else if(h->key < head->key){
				temp = head;
				head = head->next;
				temp->next = h;
				temp->pre = NULL;
				h->pre = temp;
				h = temp;
			}else{
				temp = h;
				while(temp->next != NULL && temp->next->key > head->key){
					temp = temp->next;
				}
				p = temp->next;//����temp ��p֮��
				temp->next = head;
				temp->next->pre = temp;

				head = head->next;

				temp->next->next = p;
				if(p!=NULL)
					p->pre = temp->next;
			}
		}
	}
	head = h;
}
int dlist::search(dNode & Node){
	int nindex = 0;
	dNode * tp = head;
	for(;nindex < len;nindex++){
		if(tp->key == Node.key)
			return (nindex+1);//���ҵ����������λ��
		tp = tp->next;
	}
	return 0;//û���ҵ�
}

bool dlist::del(int nk){
	dNode tn(nk);
	if(this->del(tn))
		return true;
	else
		return false;
}

bool dlist::del(dNode & Node){
	int index = this->search(Node);
	dNode * tp;
	if(index){//�ҵ�
		if(len == 1){
			delete head;
			head = NULL;
			tail = NULL;
			len--;
		}else{
			if(index == 1){//ɾ��ͷ���
				tp = head->next;
				tp->pre = NULL;
				delete head;
				head = tp;
				len--;
			}else if(index == len){//ɾ��β�ڵ�
				tp = tail->pre;
				tp->next = NULL;
				delete tail;
				tail = tp;
				len--;
			}else{
				tp = head;
				for(int i=1;i < index;i++){
					tp = tp->next;//�ҵ������ж�Ӧ�Ľڵ�
				}
				tp->pre->next = tp->next;
				tp->next->pre = tp->pre;
				delete tp;
				len--;
			}
		}
		return true;
	}
	return false;
}

void dlist::printNode() const{
	dNode *tp = head;
	int i = 1;
	std::cout << "node: ";
	while( tp != NULL){
		std::cout << tp->key;
		if(i == len)
			std::cout << "\n";
		else
			std::cout << "->";
		i++;
		tp = tp->next;
	}
}


dlist::~dlist(){
	dNode *st;
	while(head != NULL){
		st = head->next;
		delete head;
		head = st;
	}
}

////////////////////////////////////////////////////////////////
//����4����������
slist::slist(){
	head = NULL;
	len = 0;
}

slist::slist(slist & sl){
	len = sl.len;
	head = new sNode();//����һ����ͷ�ڵ�
	sNode * temp = sl.head;
	sNode *p = head;
	while(temp != NULL){
		sNode *tp = new sNode(temp->key);//���½����ڵ�
		p->next = tp;
		p = p->next;
		temp = temp->next;
	}
	temp = head->next;
	delete head;
	head = temp;
}

void slist::insert(int nk){
	sNode st(nk);
	this->insert(st);
}
void slist::insert(sNode & Node){
	//��������
	sNode * st = new sNode(Node.key);
	if(head == NULL){
		head = st;
	}else{
		sNode * sp = head;
		while(sp->next != NULL)
			sp = sp->next;//Ѱ�����һ���ڵ�
		sp->next = st;
	}
	len++;
}

int slist::search(sNode & Node){
	int index = 0;
	sNode * tp = head;
	while(tp != NULL){
		if(tp->key == Node.key){
			return index+1;//�ҵ�������λ��
		}
		tp = tp->next;
		index++;
	}
	return 0;//û���ҵ�
}

void slist::del(int nk){
	sNode ts(nk);
	this->del(ts);
}

void slist::del(sNode & Node){
	int index = this->search(Node);
	if(index){
		len--;
		sNode * tp;
		if(index == 1){
			tp = head->next;
			delete head;
			head = tp;
			return;
		}
		tp = head;
		for(int i = 1;i < index-1;i++)//Ѱ�ұ�ɾ�ڵ�ǰһ���ڵ�
			tp = tp->next;
		sNode *tdel = tp->next;
		tp->next = tdel->next;
		delete tdel;
	}
}
void slist::sort(const int index){
	if(len < 2)
		return;

	sNode *h,*p,*temp;
	h = NULL;
	if(index == 0){
		while(head != NULL){
			if(h == NULL){
				h = head;
				head = head->next;
				h->next = NULL;
			}else if(h->key > head->key){
				temp = head;
				head = head->next;
				temp->next = h;
				h = temp;
			}else{
				temp = h;
				while(temp->next != NULL && temp->next->key < head->key){
					temp = temp->next;
				}
				p = temp->next;
				temp->next = head;
				head = head->next;
				temp->next->next = p;
			}
		}
	}else if(index == 1){
		while(head != NULL){
			if(h == NULL){
				h = head;
				head = head->next;
				h->next = NULL;
			}else if(h->key < head->key){
				temp = head;
				head = head->next;
				temp->next = h;
				h = temp;
			}else{
				temp = h;
				while(temp->next != NULL && temp->next->key > head->key){
					temp = temp->next;
				}
				p = temp->next;
				temp->next = head;
				head = head->next;
				temp->next->next = p;
			}
		}
	}
	head = h;
}

void slist::printNode() const{
	sNode *tp = head;
	int i = 1;
	std::cout << "node: ";
	while( tp != NULL){
		std::cout << tp->key;
		if(i == len)
			std::cout << "\n";
		else
			std::cout << "->";
		i++;
		tp = tp->next;
	}
}
slist::~slist(){
	sNode *st;
	while(head != NULL){
		st = head->next;
		delete head;
		head = st;
	}
}


