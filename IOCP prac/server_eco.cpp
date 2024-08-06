// ������� ����
#include <iostream>
#include <string>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

// define ����
#define PORT 7777
#define BUFFER_SIZE 1024

using namespace std;

// main�� �ۼ�
int main()
{
	// �⺻ ���� ����ü �� ����
	WSADATA wsdata; // WSADATA ����ü �ν��Ͻ�
	SOCKET serverSocekt, clientSocket; // ����

	struct sockaddr_in serverAddr, clientAddr; // ����ü �ּ� ����

	int clientAddrSize = sizeof(clientAddr); // ����ü ũ�� ����

	char buffer[BUFFER_SIZE];

	// winsock �ʱ�ȭ
	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0)
	{
		cerr << "winsock �ʱ�ȭ ���� :" << WSAGetLastError() << endl;
		return 1;
		// winsock �ʱ�ȭ ���� ���� ���, ������� �� �ְ� WSAGetLastError ��� ������ �����ڵ� ��ȯ
	}

	// ���� ����
	serverSocekt = socket(AF_INET, SOCK_STREAM, 0);
	
	if (serverSocekt == INVALID_SOCKET)
	{
		cerr << "TCP���� ���� ���� ���� : " << WSAGetLastError() << endl;
		WSACleanup(); // winsock ���̺귯�� ���� ����
		return 1;
		// tcp ���� ����  ���� ���� ���
	}

	// ���� ����
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);

	// ���ε�
	if (bind(serverSocekt, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
	{
		cerr << "bind ���� ���� : " << WSAGetLastError() << endl;

		closesocket(serverSocekt); // bind ���з� ���� �ݱ�
		WSACleanup(); // winsock ���̺귯�� ���� ����
		return 1;
	}

	// ����
	if (listen(serverSocekt, 5) == SOCKET_ERROR)
	{
		cerr << "listen ���� ���� : " << WSAGetLastError() << endl;

		closesocket(serverSocekt); // bind ���з� ���� �ݱ�
		WSACleanup(); // winsock ���̺귯�� ���� ����
		return 1;
	}

	// ���Ʈ
	

	// ������ �ۼ���

	// ������

}

