// Server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET serversoc;
	SOCKET clientsoc;
	SOCKADDR_IN serveraddr;
	SOCKADDR_IN clientaddr;
	char buf[1024];
	int len;

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 0), &wsa);	//��ʼ��WS2_32.DLL


	//�����׽���
	if ((serversoc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) <= 0)
	{
		printf("�׽���socket����ʧ��!\n");
		return -1;
	}

	//����Э�飬IP���˿�
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9101);
	serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	len = sizeof(SOCKADDR_IN);

	//���׽���
	if (bind(serversoc, (SOCKADDR *)&serveraddr, sizeof(serveraddr)) != 0)
	{
		printf("�׽��ְ�ʧ��!\n");
		return -1;
	}

	printf("��ʼ����...\n");
	//��������
	if (listen(serversoc, 1) != 0)
	{
		printf("����ʧ��!\n");
		return -1;
	}

	//��������
	if ((clientsoc = accept(serversoc, (SOCKADDR *)&clientaddr, &len)) <= 0)
	{
		printf("��������ʧ��!\n");
		return -1;
	}
	printf("���ӳɹ�\n");

	while (1){
		//��������
		while (1)
		{
			if (recv(clientsoc, buf, 1024, 0) <= 0)
			{
				printf("�ر�����!\n");
				closesocket(clientsoc);
			}

			if (buf[0] == 'N')
				break;

			printf("�������Կͻ��˵���Ϣ: %s\n", buf);
			break;
		}

		if (buf[0] == 'N')
			break;

		//��������
		printf("�����뷢�͸��ͻ��˵��ַ�(N��ʾ����):\n");
		scanf_s("%s", buf, 1024);
		//send to client
		if (send(clientsoc, buf, strlen(buf) + 1, 0) <= 0)
		{
			printf("���ʹ���!\n");
		}

		if (buf[0] == 'N')
			break;
	}
	WSACleanup();     //�ͷ�WS2_32.DLL

	return 0;
}

