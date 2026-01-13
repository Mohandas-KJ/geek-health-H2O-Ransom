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

    //The setter and setters
    STARTUPINFO si;             // This gives the configuration to windows for launching the application
    PROCESS_INFORMATION pi;     // This is used to get the information back from Windows like PID, SID etc....

    // Allocate Zero in the Memory location si and pi
    ZeroMemory(&si,sizeof(si)); 
    si.cb = sizeof(si);
    ZeroMemory(&pi,sizeof(pi));

    for(int i = 0; i < n_dialog; i++){
        CreateProcess(
            NULL,
            "hydrate.exe child",
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi
        );
    }
}