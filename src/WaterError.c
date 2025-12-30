// This is the definition if the header file that contains the function
// Includes
#include <windows.h>
#include "WaterError.h"

void DisplayError(void){
    MessageBox(
        NULL,
        "Please have a break\nDrink water to continue",
        "Hydration Error",
        MB_OK | MB_ICONERROR | MB_SYSTEMMODAL
    );
}