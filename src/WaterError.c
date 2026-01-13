// This is the definition if the header file that contains the function
// Includes
#include <stdlib.h>
#include "WaterError.h"

void DisplayError(void){
    system(
        "zenity --error "
        "--title=\"Hydration Error\" "
        "--width=400 "
        "--text=\"Please have a break\nDrink water to continue\" "
        "2>/dev/null"
    );
}