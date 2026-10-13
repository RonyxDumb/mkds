/* Decompiled C draft; module arm9; ROM address 020115c8. No matching claim. */
#include "types.h"
#include "deps/020115c8_func_020115c8.h"

undefined4 func_020115c8(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 0;
  do {
    uVar2 = *(ushort *)(param_3 * 2 + param_2 + 0x1a);
    if ((uVar2 & 0x100) != 0) {
      uVar1 = param_2 + 0xc & 3;
      uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc);
      (*(code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))(param_1,param_2,uVar2 & 0xff);
      uVar3 = 1;
    }
    uVar1 = param_2 + 0x10 & 3;
    uVar4 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
    param_2 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  } while (param_2 != 0);
  return uVar3;
}

