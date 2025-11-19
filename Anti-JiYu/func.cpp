#define _CRT_SECURE_NO_WARNINGS
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <csignal>
#include "func.h"

bool exitFlag = false;

void sigexit(int signum) {
	exitFlag = true;
	MessageBox(0,L"",L"",0);
	return;
}

void funcInit() {
	std::signal(SIGINT, sigexit);
	std::signal(SIGTERM, sigexit);
	return;
}

int getPidByName(const char* processName)
{
	HANDLE hSnapshot;
	PROCESSENTRY32 lppe;
	BOOL Found;
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	lppe.dwSize = sizeof(PROCESSENTRY32);
	Found = Process32First(hSnapshot, &lppe);
	char mProce[MAX_PATH] = "";
	int pid = -1;
	while (Found)
	{
		strcpy_s(mProce, processName);
		strcat_s(mProce, ".exe");
		if (strcmp(mProce, (const char*)(lppe.szExeFile)) == 0)//进程名比较  
		{
			Found = TRUE;
			pid = lppe.th32ProcessID;
			break;
		}
		Found = Process32Next(hSnapshot, &lppe);//得到下一个进程  
	}
	CloseHandle(hSnapshot);
	return pid;
}

int killJY() {

	system("taskkill /F /IM StudentMain.exe");
	system(".\\ntsd.exe -c -q -pn StudentMain.exe");

	return 0;
}

int hangJY() {
	HANDLE jiYuHandle = OpenThread(THREAD_ALL_ACCESS, false, getPidByName("StudentMain.exe"));		//有待测试
	if (jiYuHandle == NULL) {
		MessageBox(NULL, L"未找到极域进程", L"提示", MB_ICONINFORMATION);
		return 0;
	}
	DWORD lastSuspendCount = 0;
	lastSuspendCount = SuspendThread(jiYuHandle);
	if (lastSuspendCount == -1) {
		MessageBox(NULL, L"无法挂起线程", L"错误", MB_ICONERROR);
		std::cout << "错误：无法挂起线程\n";
	}
	else {
		std::cout << "已挂起极域进程，线程的上一个挂起计数：" << lastSuspendCount << "\n";
	}
	return 0;
}

int disableScreenControl() {
	HWND tgtWndClass = NULL;
	std::cout << "开始阻止屏幕广播，按CONTROL - C停止";
	while (1) {
		tgtWndClass = FindWindowW(NULL, L"屏幕广播");
		if (tgtWndClass != NULL) {
			SendMessageW(tgtWndClass, WM_CLOSE, 0, 0);
			std::cout << "已向屏幕广播窗口发送关闭消息\n";
		}
		else {
			continue;
		}
		if (exitFlag) {
			break;
		}
	}
	MessageBox(NULL, L"停止控制", L"错误", MB_ICONERROR);
	return 0;
}