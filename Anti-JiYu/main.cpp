#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "CLI.cpp"
#include "func.cpp"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	if (_initCli() == 1) {
		MessageBox(NULL, L"无法创建控制台", L"错误", MB_ICONERROR);
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
	}
end:
	return 0;
}