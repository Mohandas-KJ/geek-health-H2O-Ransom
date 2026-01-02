// This is the main file
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "WaterError.h"
#include "H2Obanner.h"
#include "thread_args.h"
#include "Scheduler.h"

int main(int argc, char *argv[]){

    // ==================== CHILD PROCESS ====================
    if(argc > 1 && strcmp(argv[1],"child") == 0){
        DisplayError();
        return 0;
    }

    // ==================== PARENT PROCESS ====================

    int inp;
    long int interval;
    
    system("cls");

    // The Warm Welcome
    printBanner(); // Print the Banner for a design
    printf("\nWELCOME TO H2O RANSOM!\n");

    // Get User Input
    printf("\nEnter Timer Offset (in min): ");
    if(scanf("%d",&inp) != 1){                                  // Used to evaluate the input given by user
        printf("Invalid Input or Runtime Error Occured!");
        exit(-1);
    }
    
    interval = inp * 60 * 1000;           // Convert the Entered Minute input to milliseconds to pass it as DWORD to Sleep function

    // Passing the Sleep time
    ThreadArgs args;
    args.sleep_time = interval;
    args.running = 1;

    HANDLE hthread;

    hthread = CreateThread(
        NULL,
        0,
        ErrorTimer,
        &args,
        0,NULL
    );

    printf("\nTIMER SET!");
    printf("\nPress q to Exit...\n");

    char usr;

    while ((usr = _getch()) != 'q'){
        // Hello :)
    }

    args.running = 0;

    WaitForSingleObject(hthread,INFINITE);
    CloseHandle(hthread);

    return 0;
}