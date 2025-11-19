#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>
#include "CLI.h"

int _initCli() {
    if (!AllocConsole()) {
        DWORD err = GetLastError();
        if (err != ERROR_ACCESS_DENIED) {
            return 1;
        }
        else {
            MessageBox(NULL, L"控制台已存在，继续使用现有控制台", L"信息", MB_ICONINFORMATION);
        }
    }

    FILE* f;

    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr);
    freopen_s(&f, "CONIN$", "r", stdin);

    return 0;
}

int _startCli() {
    register unsigned short choice = 0;
    std::cout << "极域反制 ver 0.8 beta\n\n";
    std::cout << "[1]结束极域\n[2]挂起极域\n[3]禁止屏幕控制\n[4]退出\n>";
    std::cin >> choice;
    std::cin.clear();
    switch (choice) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    default:
        std::cout << "请输入正确选项";
        break;
    }
    return 0;
}