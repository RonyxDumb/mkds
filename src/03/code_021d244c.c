#include "03/code_021d244c.h"
#include "03/code_021d1d4c.h"

void func_ov003_021d244c(void) {
    int iVar4;
    int iVar3;
    int iVar2;
    iVar2 = ((u32) 0x0000078cu);
    iVar4 = 0;
    iVar3 = 0;
    do {
        func_ov003_021d1490(*(u32 *) (*(u8 **) data_ov003_021da2c4 + iVar3 + iVar2));
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    func_ov003_021d1d4c(*(void **) (*(u8 **) data_ov003_021da2c4 + 0x788));
    func_ov003_021d2808(((int *) ((u32) (&data_ov003_021da2c4))));
    return;
}
