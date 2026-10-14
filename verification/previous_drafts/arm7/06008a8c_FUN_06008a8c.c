/* Decompiled C draft; module arm7; ROM address 06008a8c. No matching claim. */
#include "types.h"
#include "deps/06008a8c_FUN_06008a8c.h"

void FUN_06008a8c(int param_1,int param_2)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(DAT_06008b40 & 0xfffffffc) >> (DAT_06008b40 & 3) * 8 |
          *(uint *)(DAT_06008b40 & 0xfffffffc) << (DAT_06008b40 & 3) * -8 + 0x20;
  thunk_FUN_037f8850(DAT_06008b44);
  iVar4 = uVar5 + 0xbc + param_2 * 8;
  if (*(short *)(iVar4 + 2) == 0) {
    *(undefined2 *)(iVar4 + 2) = 1;
    uVar1 = DAT_06008b48;
    *(short *)(uVar5 + 0xbc + param_2 * 8) = (short)DAT_06008b48;
    uVar3 = (uint)*(ushort *)(uVar5 + param_1 * 2 + 8);
    uVar2 = (undefined2)param_2;
    if (uVar3 == uVar1) {
      *(undefined2 *)(uVar5 + param_1 * 2) = uVar2;
    }
    else {
      *(undefined2 *)(uVar5 + uVar3 * 8 + 0xbc) = uVar2;
    }
    *(undefined2 *)(uVar5 + param_1 * 2 + 8) = uVar2;
    if (param_1 < (int)(uint)*(ushort *)(uVar5 + 0x10)) {
      *(short *)(uVar5 + 0x10) = (short)param_1;
    }
  }
  thunk_FUN_037f888c();
  if ((param_1 != 3) && (*(short *)(uVar5 + 0x12) == 3)) {
    uVar5 = (*(uint *)(DAT_06008b40 & 0xfffffffc) >> (DAT_06008b40 & 3) * 8 |
            *(uint *)(DAT_06008b40 & 0xfffffffc) << (DAT_06008b40 & 3) * -8 + 0x20) + 0x308;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    thunk_FUN_037f9854(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,0,0);
  }
  return;
}

