// This file is Focused on Learning about the Error message box required for the project
// Include the Windows Header File to access WINAPI, WINBOX etc.......
#include <windows.h>

// Start the main function
int main(){
      // This is the function used to display the Error Message
    MessageBox(
        NULL,                                                 // Parent Window - That is it doesn't depend on any window
        "Please have a break\nDrink water to Continue",      // Message to be displayed
        "Hydration error",                                  // Window Title
        MB_OK|MB_ICONERROR|MB_SYSTEMMODAL                  // flags
    );                                                                      
    return 0;
}