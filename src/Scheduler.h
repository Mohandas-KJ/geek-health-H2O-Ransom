#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <windows.h>

DWORD WINAPI ErrorTimer(LPVOID lpParam);
void StartProcess(int n_dialog);

#endif