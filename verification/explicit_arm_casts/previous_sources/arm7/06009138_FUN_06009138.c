/* Decompiled C draft; module arm7; ROM address 06009138. No matching claim. */
#include "types.h"
#include "deps/06009138_FUN_06009138.h"

int FUN_06009138(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  int unaff_r4;
  uint uVar3;
  
  uVar1 = *(uint *)(DAT_060091d8 & 0xfffffffc) >> (DAT_060091d8 & 3) * 8 |
          *(uint *)(DAT_060091d8 & 0xfffffffc) << (DAT_060091d8 & 3) * -8 + 0x20;
  if (param_2 == 0) {
    unaff_r4 = 0;
  }
  else {
    uVar3 = uVar1 + 0x17c & 3;
    uVar2 = *(uint *)(uVar1 + 0x17c & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      uVar3 = uVar1 + 0x180 & 3;
      uVar4 = *(uint *)(uVar1 + 0x180 & 0xfffffffc);
      uVar2 = uVar1 + 0x184 & 3;
      uVar1 = *(uint *)(uVar1 + 0x184 & 0xfffffffc);
      unaff_r4 = thunk_FUN_037fa04c(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                                    uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    }
    else if (uVar3 == 1) {
      uVar3 = uVar1 + 0x180 & 3;
      uVar1 = *(uint *)(uVar1 + 0x180 & 0xfffffffc);
      unaff_r4 = (*(code *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20))(param_2 + 0xc);
    }
    if (unaff_r4 == 0) {
      unaff_r4 = 0;
    }
    else {
      *(short *)(unaff_r4 + 10) = (short)DAT_060091dc;
      *(undefined2 *)(unaff_r4 + 8) = 0;
      FUN_06008f34(param_1,unaff_r4);
    }
  }
  return unaff_r4;
}

