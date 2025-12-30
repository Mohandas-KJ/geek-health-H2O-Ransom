#include <windows.h>
#include <stdio.h>

// Start main function
int main(int argc, char *argv[]){
    // Open in Child mode
    if(argc > 1 && strcmp(argv[1], "child") == 0){
        MessageBox(
        NULL,                                                 // Parent Window - That is it doesn't depend on any window
        "Please have a break\nDrink water to Continue",      // Message to be displayed
        "Hydration error",                                  // Window Title
        MB_OK|MB_ICONERROR|MB_SYSTEMMODAL                  // flags
    );                                                                      
    return 0;
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si,sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi,sizeof(pi));

    for(int i = 0; i < 12; i++){
        CreateProcess(
            NULL,
            "span_process.exe child",
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

    return 0;
}