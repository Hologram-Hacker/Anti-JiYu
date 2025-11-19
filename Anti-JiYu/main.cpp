#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "func.h"
#include "CLI.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nShowCmd) {
	funcInit();
	if (_initCli() == 1) {
		return 0;
	}
	while (1) {
		switch (_startCli()) {
		case 1:
			killJY();
			break;
		case 2:
			hangJY();
			break;
		case 3:
			disableScreenControl();
			break;
		case 4:
			FreeConsole();
			goto end;
		}
		system("pause > nul");
		system("cls");
	}
end:
	return 0;
}