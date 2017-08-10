// testdb.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include<iomanip>
#include"winsock.h"
#include"mysql.h"
#include<string>
#include<direct.h>
#pragma comment(lib,"libmySQL.lib")

using namespace std;

int rt;
MYSQL * m_sqlCon = NULL;
MYSQL_RES * res = NULL;
MYSQL_ROW row;
MYSQL_FIELD *field;

//�������ݿ�
void createDB();

//������
void createTable();

//�������ݣ�pet.txt��
void importDB();

//��������
void insertDB();

//ɾ������
void deleteDB();

//��������
void updateDB();

//��ѯ����
void queryDB();

//ʹ�����ݿ⣨���
void useDB();


int main(){
	m_sqlCon = mysql_init((MYSQL*)0);
	char password[20];
	cout << "����������ݿ��������: ";
	scanf("%s",password);
	if (!mysql_real_connect(m_sqlCon, "localhost", "root", password, "", 3306, NULL, 0))
		cout << "���ݿ����������ʧ��" << endl;
	else{
		cout << "���ݿ���������ӳɹ�" << endl;

		createDB();//�������ݿ�menagerie
		useDB();//ʹ�����ݿ�menagerie
		createTable();//������pet
		importDB();//��������pet.txt
		queryDB();
		insertDB();//����һ����¼
		queryDB();//��ѯ��ǰ��pet�ļ�¼
		updateDB();//�޸ı��м�¼
		queryDB();
		deleteDB();//ɾ�����м�¼
		queryDB();
	}
	mysql_close(m_sqlCon);
	system("pause");

	return 0;
}


//�������ݿ�
void createDB(){
	char tmp[400];
	char DB_name[20] = { "menagerie" };
	sprintf(tmp, "create database %s", DB_name);
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		cout << "�������ݿ�ʧ�ܣ�" << endl;
		const char * str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
	else
		cout << "�������ݿ�" << DB_name << endl;
}

void createTable(){
	char tmp[400];
	char * t_name = "pet";
	sprintf(tmp, "create table %s (name varchar(20),owner varchar(20),species varchar(20),sex char(1),birth date,death date)", t_name);
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		cout << "������ʧ�ܣ�" << endl;
		const char * str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
	else
		cout << "������" << t_name << endl;
}

//�������ݣ�pet.txt��
void importDB(){
	char tmp[400];
	char path[100] = { "./pet.txt" };
	char t_name[20] = { "pet" };
	sprintf(tmp, "load data local infile '%s' into table %s lines terminated by '\r\n'", path, t_name);
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		cout << "��������ʧ�ܣ�" << endl;
		const char *str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
	else
		cout << "�������ݳɹ���" << endl;
}

//��������
void insertDB(){
	char tmp[400];
	sprintf(tmp, "insert into %s values('%s','%s','%s','%s','%s',%s)", "pet", "Slim", "Benny", "snake", "m", "1996-04-29", "NULL");
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		cout << "��������ʧ�ܣ�" << endl;
		const char *str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
	else{
		cout << tmp << endl;
		cout << "�������ݳɹ���" << endl;
	}
}

//ɾ������
void deleteDB(){
	char tmp[400];
	sprintf(tmp, "delete from %s where name='%s'", "pet", "Fang");
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		cout << "ɾ������ʧ�ܣ�" << endl;
		const char * str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
	else{
		cout << tmp << endl;
		cout << "ɾ�����ݳɹ���" << endl;
	}
}

//��������
void updateDB(){
	char tmp[400];
	sprintf(tmp, "update %s set birth = '%s' where name = '%s'", "pet", "1999-09-09", "Slim");
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		cout << "����ʧ�ܣ�" << endl;
		const char * str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
	else{
		cout << tmp << endl;
		cout << "���³ɹ���" << endl;
	}
}

//��ѯ����
void queryDB(){
	char tmp[400];
	sprintf(tmp, "select * from %s", "pet");
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	res = mysql_store_result(m_sqlCon);
	//���������
	while (field = mysql_fetch_field(res)){
		cout << setiosflags(ios::left) << setw(12) << field->name;
	}
	cout << endl;
	//���������¼
	while (row = mysql_fetch_row(res)){
		for (int i = 0; i < mysql_num_fields(res); i++){
			cout << setiosflags(ios::left) << setw(12) << (row[i] == NULL ? "NULL" : row[i]);
		}
		cout << endl;
	}
	mysql_free_result(res);
}

//ʹ�����ݿ⣨���
void useDB(){
	char tmp[400];
	char db_name[20] = { "menagerie" };
	sprintf(tmp, "use %s", db_name);
	rt = mysql_real_query(m_sqlCon, tmp, strlen(tmp));
	if (rt){
		const char * str = mysql_error(m_sqlCon);
		cout << str << endl;
	}
}