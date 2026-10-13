/* Decompiled C draft; module arm9; ROM address 020080e8. No matching claim. */
#include "types.h"
#include "deps/020080e8_func_020080e8.h"

int func_020080e8(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  
  puVar6 = (undefined2 *)(param_1 + 0xc);
  iVar3 = 0;
  if (param_2 != 0) {
    uVar4 = 0;
    do {
      *(int *)(param_1 + uVar4 * 4) = iVar3;
      iVar3 = iVar3 + *(int *)(param_2 + uVar4 * 0x10 + 0x14);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    uVar4 = 0;
    *puVar6 = 0;
    do {
      iVar5 = param_2 + 0xc + uVar4 * 0x10;
      iVar3 = *(int *)(iVar5 + 8);
      sVar2 = MaybeBoundsCheck(iVar3 + *(int *)(*piRam02008180 + iRam02008184) + -1);
      sVar1 = puVar6[uVar4];
      iVar3 = func_02007f38(uVar4,*(undefined4 *)(iVar5 + 4),iVar3);
      if (iVar3 == 0) {
        return 0;
      }
      if (uVar4 < 2) {
        puVar6[uVar4 + 1] = sVar1 + sVar2;
      }
      else {
        *(short *)(param_1 + 0x12) = sVar1 + sVar2;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    iVar3 = 1;
  }
  return iVar3;
}

