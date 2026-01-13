#define _POSIX_C_SOURCE 199309L
// This is the main file
#include <stdio.h>
#include <unistd.h>  // linux
#include <time.h>    // linux
#include <pthread.h>  //linux
#include <stdlib.h>
#include <string.h>
#include "WaterError.h"
#include "H2Obanner.h"
#include "thread_args.h"
#include "Scheduler.h"

// Display the Total Runtime
void DisplayRuntime(struct timespec start){
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);  // Get Clock end time!

    // Interval Calculation
    long tot_Seconds = end.tv_sec - start.tv_sec;

    int Hour = tot_Seconds / 3600;      // Calculate Hour from Seconds
    int Minutes = (tot_Seconds % 3600) / 60;   // Calculate Minute from Seconds
    int Seconds = tot_Seconds / 60;  // Calculate Remaining Seconds

    printf("- Runtime: %02d:%02d:%02d\n",Hour,Minutes,Seconds);

}

int main(int argc, char *argv[]){

    // ==================== CHILD PROCESS ====================
    if(argc > 1 && strcmp(argv[1],"child") == 0){
        DisplayError();
        return 0;
    }

    // ==================== PARENT PROCESS ====================

    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int inp;
    long int interval;
    
    system("clear");  // linux

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

    pthread_t thread;       // linux
    pthread_create(&thread, NULL, ErrorTimer, &args);   // linux

    printf("\nTIMER SET!");
    printf("\nPress q to Exit...\n");

    char usr;

    while ((usr = getchar()) != 'q'){
        // Hello :)
    }

    args.running = 0;

    printf("Session Summary:\n");
    DisplayRuntime(start);
    printf("- Alerts Triggered: %d\n- Dialogs Shown: %d\n",args.n_alert,args.dialog_shown);

    pthread_join(thread, NULL); // linux

    return 0;
}