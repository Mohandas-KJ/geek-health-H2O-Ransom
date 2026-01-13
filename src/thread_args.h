#ifndef THREAD_ARGS_H
#define THREAD_ARGS_H

typedef struct {
    unsigned long sleep_time;
    int dialog_n;
    int dialog_shown;
    volatile int running;
    int n_alert;
} ThreadArgs;

#endif
