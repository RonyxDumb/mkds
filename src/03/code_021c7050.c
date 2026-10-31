#include "03/code_021c7050.h"

void func_ov003_021c7050(void) {
    int iVar6;
    int iVar5;
    int iVar4;
    int iVar3;
    u8 uVar2;
    u8 cVar1;
    iVar6 = 0;
    iVar3 = 0;
    do {
        iVar5 = (int) data_ov003_021da1fc + 8 + iVar3;
        iVar4 = 0;
        do {
            cVar1 = *(s8 *) (iVar5 + iVar4);
            if (((cVar1 != '0') && (cVar1 != ' ')) && (cVar1 != '\0')) {
                break;
            }
            if (iVar4 == 2) {
                uVar2 = 0x30;
            } else {
                uVar2 = 0x20;
            }
            *(u8 *) (iVar5 + iVar4) = uVar2;
            iVar4 = iVar4 + 1;
        } while (iVar4 < 3);
        iVar3 = iVar3 + 3;
        iVar6 = iVar6 + 1;
        if (4 <= iVar6) {
            func_ov003_021c71a0();
            return;
        }
    } while (1);
}
