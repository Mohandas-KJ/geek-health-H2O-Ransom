// This is the main file
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "WaterError.h"
#include "H2Obanner.h"
#include "thread_args.h"
#include "Scheduler.h"

// Display the Total Runtime
void DisplayRuntime(DWORD start){
    DWORD end = GetTickCount();  // Get the Ending Time from the system
    DWORD Total = end - start;

    // Seconds Conversion
    DWORD tot_Seconds = Total / 1000;

    DWORD Hour = tot_Seconds / 3600;      // Calculate Hour from Seconds
    DWORD Minutes = (tot_Seconds % 3600) / 60;   // Calculate Minute from Seconds
    DWORD Seconds = tot_Seconds / 60;  // Calculate Remaining Seconds

    printf("- Runtime: %02lu:%02lu:%02lu\n",Hour,Minutes,Seconds);

}

int main(int argc, char *argv[]){

    // ==================== CHILD PROCESS ====================
    if(argc > 1 && strcmp(argv[1],"child") == 0){
        DisplayError();
        return 0;
    }

    // ==================== PARENT PROCESS ====================

    DWORD start = GetTickCount();

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
    ThreadArgs args;               // Structure Init
    args.sleep_time = interval;    // The sleep interval
    args.n_alert = 0;              // Number of Alerts made to user
    args.dialog_shown = 0;         // For Storing how many dialogs shown
    args.dialog_n = 12;            // The Number of dialogs to show (Default = 12)
    args.running = 1;              // Flag for Graceful control

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

    printf("Session Summary:\n");
    DisplayRuntime(start);
    printf("- Alerts Triggered: %d\n- Dialogs Shown: %d\n",args.n_alert,args.dialog_shown);

    WaitForSingleObject(hthread,INFINITE);
    CloseHandle(hthread);

    return 0;
}