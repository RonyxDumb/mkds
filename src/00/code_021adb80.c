#include "00/code_021adb80.h"

void func_ov000_021adb80(void) {
    int iVar1;
    iVar1 = *(int *) (*(int *) (((int) (u32) ((unsigned char *) &data_0216ff5c)) + 4) + 0xa4);
    if ((iVar1 != 0) && (*(int *) (iVar1 + 0x60) != 0)) {
        func_ov000_021adc64((u32) (*(u32 *) (iVar1 + 0x5c)), (int) (*(int *) (iVar1 + 0x60)), (u32) (0), (int) (0));
        *(u32 *) (iVar1 + 0x60) = 0;
    }
    return;
}
