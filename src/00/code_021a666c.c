#include "00/code_021a666c.h"

u32 func_ov000_021a666c(void) {
    int iVar1;
    iVar1 = func_ov000_021a5b30();
    if ((*(int *) (iVar1 + ((int) 0x00002270u)) != 0) && (0xc < *(u32 *) (iVar1 + ((int) 0x00002274u)))) {
        return *(u32 *) (*(int *) (iVar1 + ((int) 0x00002270u)) + 4);
    }
    return 0;
}
