#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>

inline int killJY() {

	system("taskkill /F /IM StudentMain.exe");
	system(".\\ntsd -c -q -pn StudentMain.exe");

	return 0;
}

inline int disableScreenControl() {

	HWND tgtWndClass = FindWindowW(NULL, L"ÆÁÄ»¹ã²¥");
	
	if (tgtWndClass != NULL) {
		SendMessageW(tgtWndClass, WM_CLOSE, 0, 0);
	}
	else {
		MessageBox(0, L"Î´ÕÒµ½ÆÁÄ»¹ã²¥´°¿Ú", L"´íÎó", MB_ICONERROR);
	}

	return 0;
}