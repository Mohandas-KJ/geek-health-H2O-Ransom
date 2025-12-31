#ifndef THREAD_ARGS_H
#define THREAD_ARGS_H

#include <windows.h>

typedef struct {
    DWORD sleep_time;
    int dialog_is;
    volatile int running;
} ThreadArgs;

#endif
