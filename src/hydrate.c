// This is the main file
#include <stdio.h>
#include <windows.h>
#include "WaterError.h"
#include "H2Obanner.h"

int main(){
    int inp;
    long int interval;
    
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
    printf("%ld",interval);               // Testing Statement (Works Fine!)

    return 0;
}