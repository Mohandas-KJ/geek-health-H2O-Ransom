// This File is written to test Simple Timer in C using Sleep keyword
#include <windows.h>
#include <stdio.h>

int main(){

    int count = 0;

    while (1)
    {   
        if(count == 2){
            printf("Search Successful!\n");
            return NULL;
        }
        printf("Try %d: Searching......\n",count+1);
        count++;
        Sleep(0.50 * 60 * 1000);
    }
    
    return 0;
}