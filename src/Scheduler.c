// This is the definition file of Scheduler.h
// Imports
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Scheduler.h"
#include "thread_args.h"

// Threaded Timer
void *ErrorTimer(void *lpParam){

    ThreadArgs *args = (ThreadArgs *)lpParam;
    //Starting a While loop

    while (args->running)
    {

        unsigned long elapsed = 0;
        unsigned long step = 200;

        while (args->running && elapsed < args->sleep_time)
        {
            usleep(step * 1000);
            elapsed += step;
        }

        if(!args->running){
                break;
        }
        
        StartProcess(args->dialog_n);
        args->dialog_shown += args->dialog_n;
        args->n_alert += 1;
    }
    
}

// For starting a parent process
void StartProcess(int n_dialog){

    for(int i = 0; i < n_dialog; i++){
        pid_t pid = fork();

        if(pid == 0){
            //Start the Child Process
            execlp("./hydrate","hydrate","child",NULL);
            _exit(1); // exit on failed execution
        }
    }
}