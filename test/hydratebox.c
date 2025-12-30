// This file is Focused on Learning about the Error message box required for the project
#include <windows.h>

int main(){
      MessageBox(
        NULL,
        "Please have a break\nDrink water to Continue",
        "Hydration error",
        MB_OK|MB_ICONERROR|MB_SYSTEMMODAL
    );
    return 0;
}