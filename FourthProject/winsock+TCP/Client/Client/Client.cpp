// Client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[]){
	SOCKET clientsocket;
	SOCKADDR_IN serveraddr;
	SOCKADDR_IN clientaddr;
	char buf[1024];

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 0), &wsa);	//��ʼ��WS2_32.DLL

	//�����׽���
	if ((clientsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) <= 0){
		printf("�׽���socket����ʧ��!\n");
		return -1;
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9101);
	serveraddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	//��������
	printf("����������...\n");
	if (connect(clientsocket, (SOCKADDR *)&serveraddr, sizeof(serveraddr)) != 0){
		printf("����ʧ��!\n");
		return -1;
	}
	printf("���ӳɹ�!\n");


	while (1){
		//��������
		printf("�����뷢�͸����������ַ�(N��ʾ����):\n");
		scanf_s("%s", buf, 1024);
		if (send(clientsocket, buf, strlen(buf) + 1, 0) <= 0){
			printf("���ʹ���!\n");
		}

		if (buf[0] == 'N')
			break;

		//��������
		while (1){
			if (recv(clientsocket, buf, 1024, 0) <= 0){
				printf("�ر�����!\n");
				closesocket(clientsocket);
			}
			if (buf[0] == 'N')
				break;

			printf("�������Է���������Ϣ: %s\n", buf);
			break;
		}

		if (buf[0] == 'N')
			break;
	}

	//�ر��׽���
	closesocket(clientsocket);
	WSACleanup();    //�ͷ�WS2_32.DLL
	return 0;
}

