// 헤더파일 참조
#include <iostream>
#include <string>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

// define 정의
#define PORT 7777
#define BUFFER_SIZE 1024

using namespace std;

// main문 작성
int main()
{
	// 기본 정의 구조체 및 변수
	WSADATA wsdata; // WSADATA 구조체 인스턴스
	SOCKET serverSocekt, clientSocket; // 변수

	struct sockaddr_in serverAddr, clientAddr; // 구조체 주소 변수

	int clientAddrSize = sizeof(clientAddr); // 구조체 크기 변수

	char buffer[BUFFER_SIZE];

	// winsock 초기화
	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0)
	{
		cerr << "winsock 초기화 오류 :" << WSAGetLastError() << endl;
		return 1;
		// winsock 초기화 실패 오류 출력, 디버깅할 수 있게 WSAGetLastError 사용 마지막 오류코드 반환
	}

	// 소켓 생성
	serverSocekt = socket(AF_INET, SOCK_STREAM, 0);
	
	if (serverSocekt == INVALID_SOCKET)
	{
		cerr << "TCP소켓 생성 실패 오류 : " << WSAGetLastError() << endl;
		WSACleanup(); // winsock 라이브러리 해제 종료
		return 1;
		// tcp 소켓 생성  실패 오류 출력
	}

	// 소켓 정보
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(PORT);

	// 바인드
	if (bind(serverSocekt, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
	{
		cerr << "bind 실패 오류 : " << WSAGetLastError() << endl;

		closesocket(serverSocekt); // bind 실패로 소켓 닫기
		WSACleanup(); // winsock 라이브러리 해제 종료
		return 1;
	}

	// 리슨
	if (listen(serverSocekt, 5) == SOCKET_ERROR)
	{
		cerr << "listen 실패 오류 : " << WSAGetLastError() << endl;

		closesocket(serverSocekt); // bind 실패로 소켓 닫기
		WSACleanup(); // winsock 라이브러리 해제 종료
		return 1;
	}

	// 어셉트
	

	// 데이터 송수신

	// 마무리

}

