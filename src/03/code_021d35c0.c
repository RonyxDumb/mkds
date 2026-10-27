#include "03/code_021d35c0.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d2eb8.h"

void func_ov003_021d35c0(void) {
    int iVar3;
    int iVar2;
    iVar3 = 0;
    iVar2 = 0;
    do {
        func_ov003_021d2eb8(*(void **) (*(u8 **) data_ov003_021da32c + iVar2 + 8));
        func_ov003_021d1d4c(*(void **) (*(u8 **) data_ov003_021da32c + iVar2));
        iVar2 = iVar2 + 0x3c;
        iVar3 = iVar3 + 1;
    } while (2 > iVar3);
    func_ov003_021d2808(((int *) ((u32) (&data_ov003_021da32c))));
    return;
}
