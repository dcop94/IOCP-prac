#include <iostream>
#include <string>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib") // ws2_32.lib ���̺귯���� ��ũ

using namespace std;

// define ����
#define PORT 7777 // ����� ��Ʈ ��ȣ
#define BUFFER_SIZE 1024 // ���� ũ��

int main()
{
	WSADATA  wsdata; // Winsock �ʱ�ȭ �� ������ ���� �� ����ü
	SOCKET serverSocket, clientSocket; // �������ϰ� Ŭ���̾�Ʈ ������ ������ ����
	
	if (WSAStartup(MAKEWORD(2, 2), &wsdata, ))
	{
		cerr << "winsock �ʱ�ȭ ���� : " << WSAGetLastError() << endl;
		return 1;
	}
	
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	sockAddr.


	if (bind(serverSocket, (struck sockaddr*)&sockaddr), &)

	if (listen(serverSocket, ))
}























//--- 1ȸ�� --- ����
//// ������� ����
//#include <iostream>
//#include <string>
//#include <WinSock2.h>
//#pragma comment(lib, "ws2_32.lib")
//
//// define ����
//#define PORT 7777
//#define BUFFER_SIZE 1024
//
//using namespace std;
//
//// main�� �ۼ�
//int main()
//{
//	// �⺻ ���� ����ü �� ����
//	WSADATA wsdata; // WSADATA ����ü �ν��Ͻ�
//	SOCKET serverSocekt, clientSocket; 
//	// ���� ��ũ���� ����, serverSockeet�� ���� ������ ���� ���� Ŭ���̾�Ʈ ���� ��û ��� ����, clientSocket�� Ŭ���̾�Ʈ���� ����� ���� ���� Ŭ���̾�Ʈ ������ �����Ǹ� ���
//
//	struct sockaddr_in serverAddr, clientAddr; // ����ü �ּ� ����
//	// sockaddr_in�� ipv4 �ּҸ� �����ϴ� ����ü
//	// serverAddr�� ������ �ּ� ������ �����ϴ� ����, ���� ������ ���ε� �� ip�ּҿ� ��Ʈ��ȣ�� ����
//	// clientAddr�� Ŭ���̾�Ʈ �ּ� ������ �����ϴ� ����, Ŭ���̾�Ʈ ������ �����Ǿ��� �� ���
//
//	int clientAddrSize = sizeof(clientAddr); // ����ü ũ�� ����
//
//	char buffer[BUFFER_SIZE];
//
//	// winsock �ʱ�ȭ
//	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0)
//	{
//		cerr << "winsock �ʱ�ȭ ���� :" << WSAGetLastError() << endl;
//		return 1;
//		// winsock �ʱ�ȭ ���� ���� ���, ������� �� �ְ� WSAGetLastError ��� ������ �����ڵ� ��ȯ
//	}
//
//	// ���� ����
//	serverSocekt = socket(AF_INET, SOCK_STREAM, 0);
//	
//	if (serverSocekt == INVALID_SOCKET)
//	{
//		cerr << "TCP���� ���� ���� ���� : " << WSAGetLastError() << endl;
//		WSACleanup(); // winsock ���̺귯�� ���� ����
//		return 1;
//		// tcp ���� ����  ���� ���� ���
//	}
//
//	// ���� ����
//	serverAddr.sin_family = AF_INET; // IPv4 �ּ� ü�� ���
//	serverAddr.sin_addr.s_addr = INADDR_ANY; // ��� �������̽������� �������
//	serverAddr.sin_port = htons(PORT); // ��Ʈ��ȣ ����(��Ʈ��ũ ����Ʈ ������ ��ȯ)
//
//	// ���ε�
//	if (bind(serverSocekt, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
//	// bind �Լ��� ������ Ư�� ip�ּҿ� ��Ʈ��ȣ�� ���ε�
//	{
//		cerr << "bind ���� ���� : " << WSAGetLastError() << endl;
//
//		closesocket(serverSocekt); // bind ���з� ���� �ݱ�
//		WSACleanup(); // winsock ���̺귯�� ���� ����
//		return 1;
//	}
//
//	// ����
//	if (listen(serverSocekt, 5) == SOCKET_ERROR)
//	// listen �Լ� ���� ������ Ŭ���̾�Ʈ ���� ��û�� ������ �� �ִ� ���·�
//	{
//		cerr << "listen ���� ���� : " << WSAGetLastError() << endl;
//
//		closesocket(serverSocekt); // listen ���з� ���� �ݱ�
//		WSACleanup(); // winsock ���̺귯�� ���� ����
//		return 1;
//	}
//
//	// ���Ʈ
//	clientSocket = accept(serverSocekt, (struct sockaddr*)&clientAddr, &clientAddrSize);
//
//	if (clientSocket == INVALID_SOCKET)
//	{
//		cerr << "accept ���� ���� : " << WSAGetLastError() << endl;
//		closesocket(serverSocekt);
//		WSACleanup();
//		return 1;
//	}
//
//	// ������ �ۼ���
//	int bytesRead; // �о���� ����Ʈ ���� ������ ����
//	
//	// Ŭ���̾�Ʈ�κ��� �����͸� �ݺ������� �����ϰ� �����ϴ� ����
//	while ((bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0)
//	{
//		buffer[bytesRead] = '\0'; // ���ŵ� �����͸� null�� �����Ͽ� ���ڿ��� ó�� 
//		cout << " ���� ������ : " << buffer << endl; // ���ŵ� �����͸� ���
//		send(clientSocket, buffer, bytesRead, 0); // ������ �����͸� Ŭ���̾�Ʈ�� �ٽ� ����(����)
//	}
//
//	// ������
//	closesocket(clientSocket); // Ŭ���̾�Ʈ ���� �ݱ�
//	closesocket(serverSocekt); // ���� ���� �ݱ�
//	WSACleanup(); // winsock ���̺귯�� ����
//
//	return 0;
//}

