// Server_socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;
#pragma comment(lib, "Ws2_32.lib")
#define DEF_PORT 48018


int main()
{
	SOCKET client_socket, server_socket;
	struct sockaddr_in server, client;

	//Creazione socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		cout << "Errore nella creazione della socket!" << endl;
		return server_socket;
	}

	//Preparazione struttura sockaddr_in
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(DEF_PORT);

	//Assegnazione indirizzo ip alla socket
	if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
		cout << "Bind fallito!" << endl;
		return 1;
	}
	return 0;
}

