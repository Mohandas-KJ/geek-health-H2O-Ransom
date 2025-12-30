// This File focus on creating Span error windows using THREAD in Windows
#include <windows.h>

// Create a thread function
DWORD WINAPI show_error(LPVOID lpParam){
    MessageBox(
        NULL,                                                 // Parent Window - That is it doesn't depend on any window
        "Please have a break\nDrink water to Continue",      // Message to be displayed
        "Hydration error",                                  // Window Title
        MB_OK|MB_ICONERROR|MB_SYSTEMMODAL                  // flags
    );                                                                      
    return 0;
}

// Main Function
int main(){
    HANDLE thread[12];  // We're gonna Create 12 windows, so 12 threads. It gives the complete control over them  

    for(int i = 0; i < 12; i++){
        thread[i] = CreateThread(
            NULL,
            0,
            show_error,
            NULL,
            0,
            NULL
        );
    }

    WaitForMultipleObjects(12,thread,TRUE,INFINITE);

    return 0;

}