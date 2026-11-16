#include "Main/Menu/menu_counter.h"

void MenuIncrementCounterSaturating(int *counterAddress) {
    u32 counterValue;
    counterValue = *(u32 *) counterAddress;
    if ((s32) counterValue < 0x7fffffff) {
        *counterAddress = counterValue + 1;
    }
}
