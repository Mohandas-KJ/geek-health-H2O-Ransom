// This is the definition if the header file that contains the function
// Includes
#include "WaterError.h"

void DisplayError(void){
    system(
        "zenity --error "
        "--title=\"Hydration Error\" "
        "--text=\"Please have a break\nDrink water to continue\""
    );
}