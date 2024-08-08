#include <iostream>
#include <string>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib") // ws2_32.lib 라이브러리를 링크

using namespace std;

// define 정의
#define PORT 7777 // 사용할 포트 번호
#define BUFFER_SIZE 1024 // 버퍼 크기

int main()
{
	WSADATA  wsdata; // Winsock 초기화 후 정보를 저장 할 구조체
	SOCKET serverSocket, clientSocket; // 서버소켓과 클라이언트 소켓을 저장할 변수
	
	if (WSAStartup(MAKEWORD(2, 2), &wsdata, ))
	{
		cerr << "winsock 초기화 오류 : " << WSAGetLastError() << endl;
		return 1;
	}
	
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	sockAddr.


	if (bind(serverSocket, (struck sockaddr*)&sockaddr), &)

	if (listen(serverSocket, ))
}























//--- 1회차 --- 정리
//// 헤더파일 참조
//#include <iostream>
//#include <string>
//#include <WinSock2.h>
//#pragma comment(lib, "ws2_32.lib")
//
//// define 정의
//#define PORT 7777
//#define BUFFER_SIZE 1024
//
//using namespace std;
//
//// main문 작성
//int main()
//{
//	// 기본 정의 구조체 및 변수
//	WSADATA wsdata; // WSADATA 구조체 인스턴스
//	SOCKET serverSocekt, clientSocket; 
//	// 소켓 디스크럽터 저장, serverSockeet은 서버 소켓을 위한 변수 클라이언트 연결 요청 대기 수락, clientSocket은 클라이언트와의 통신을 위한 변수 클라이언트 연결이 수락되면 사용
//
//	struct sockaddr_in serverAddr, clientAddr; // 구조체 주소 변수
//	// sockaddr_in은 ipv4 주소를 저장하는 구조체
//	// serverAddr은 서버의 주소 정보를 저장하는 변수, 서버 소켓이 바인드 될 ip주소와 포트번호를 저장
//	// clientAddr은 클라이언트 주소 정보를 저장하는 변수, 클라이언트 연결이 수락되었을 때 사용
//
//	int clientAddrSize = sizeof(clientAddr); // 구조체 크기 변수
//
//	char buffer[BUFFER_SIZE];
//
//	// winsock 초기화
//	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0)
//	{
//		cerr << "winsock 초기화 오류 :" << WSAGetLastError() << endl;
//		return 1;
//		// winsock 초기화 실패 오류 출력, 디버깅할 수 있게 WSAGetLastError 사용 마지막 오류코드 반환
//	}
//
//	// 소켓 생성
//	serverSocekt = socket(AF_INET, SOCK_STREAM, 0);
//	
//	if (serverSocekt == INVALID_SOCKET)
//	{
//		cerr << "TCP소켓 생성 실패 오류 : " << WSAGetLastError() << endl;
//		WSACleanup(); // winsock 라이브러리 해제 종료
//		return 1;
//		// tcp 소켓 생성  실패 오류 출력
//	}
//
//	// 소켓 정보
//	serverAddr.sin_family = AF_INET; // IPv4 주소 체계 사용
//	serverAddr.sin_addr.s_addr = INADDR_ANY; // 모든 인터페이스에서의 연결허용
//	serverAddr.sin_port = htons(PORT); // 포트번호 설정(네트워크 바이트 순서로 변환)
//
//	// 바인드
//	if (bind(serverSocekt, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
//	// bind 함수는 소켓을 특정 ip주소와 포트번호에 바인드
//	{
//		cerr << "bind 실패 오류 : " << WSAGetLastError() << endl;
//
//		closesocket(serverSocekt); // bind 실패로 소켓 닫기
//		WSACleanup(); // winsock 라이브러리 해제 종료
//		return 1;
//	}
//
//	// 리슨
//	if (listen(serverSocekt, 5) == SOCKET_ERROR)
//	// listen 함수 서버 소켓을 클라이언트 연결 요청을 수신할 수 있는 상태로
//	{
//		cerr << "listen 실패 오류 : " << WSAGetLastError() << endl;
//
//		closesocket(serverSocekt); // listen 실패로 소켓 닫기
//		WSACleanup(); // winsock 라이브러리 해제 종료
//		return 1;
//	}
//
//	// 어셉트
//	clientSocket = accept(serverSocekt, (struct sockaddr*)&clientAddr, &clientAddrSize);
//
//	if (clientSocket == INVALID_SOCKET)
//	{
//		cerr << "accept 실패 오류 : " << WSAGetLastError() << endl;
//		closesocket(serverSocekt);
//		WSACleanup();
//		return 1;
//	}
//
//	// 데이터 송수신
//	int bytesRead; // 읽어들인 바이트 수를 저장할 변수
//	
//	// 클라이언트로부터 데이터를 반복적으로 수신하고 에코하는 루프
//	while ((bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0)
//	{
//		buffer[bytesRead] = '\0'; // 수신된 데이터를 null로 종료하여 문자열로 처리 
//		cout << " 수신 데이터 : " << buffer << endl; // 수신된 데이터를 출력
//		send(clientSocket, buffer, bytesRead, 0); // 동일한 데이터를 클라이언트에 다시 전송(에코)
//	}
//
//	// 마무리
//	closesocket(clientSocket); // 클라이언트 소켓 닫기
//	closesocket(serverSocekt); // 서버 소켓 닫기
//	WSACleanup(); // winsock 라이브러리 해제
//
//	return 0;
//}

