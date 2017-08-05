// protobufcase2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void ListMsg(const lm::helloworld & msg) {
	cout << msg.id() << endl;
	cout << msg.str() << endl;
}

int main(void)
{
	//д��log
	lm::helloworld msg1;
	msg1.set_id(101);
	msg1.set_str("hello");

	// write the new address book back to disk. 
	fstream output("./log", ios::out | ios::trunc | ios::binary);

	if (!msg1.SerializeToOstream(&output)) {
		cerr << "failed to write msg." << endl;
		return -1;
	}
	output.close();


	//�����ڴ棬��Ļ��ʾ
	lm::helloworld msg2;

	fstream input("./log", ios::in | ios::binary);
	if (!msg2.ParseFromIstream(&input)) {
		cerr << "Failed to parse address book." << endl;
		return -1;
	}
	input.close();

	ListMsg(msg2);

	getchar();

	return 0;
}

