// This is the definition file of Scheduler.h
// Imports
#include <windows.h>
#include "Scheduler.h"
#include "thread_args.h"

// Threaded Timer
DWORD WINAPI ErrorTimer(LPVOID lpParam){

    ThreadArgs *args = (ThreadArgs *)lpParam;
    //Starting a While loop

    while (args->running)
    {

        DWORD elapsed = 0;
        DWORD step = 200;

        while (args->running && elapsed < args->sleep_time)
        {
            Sleep(step);
            elapsed += step;
        }

        if(!args->running){
                break;
        }
        
        StartProcess();

        args->n_alert += 1;
    }
    
}

// For starting a parent process
void StartProcess(void){

    //The setter and setters
    STARTUPINFO si;             // This gives the configuration to windows for launching the application
    PROCESS_INFORMATION pi;     // This is used to get the information back from Windows like PID, SID etc....

    // Allocate Zero in the Memory location si and pi
    ZeroMemory(&si,sizeof(si)); 
    si.cb = sizeof(si);
    ZeroMemory(&pi,sizeof(pi));

    for(int i = 0; i < 12; i++){
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