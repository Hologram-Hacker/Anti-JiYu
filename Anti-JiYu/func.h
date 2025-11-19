#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <csignal>

void sigexit(int signum);
void funcInit();
int getPidByName(const char* processName);
int killJY();
int hangJY();
int disableScreenControl();