/* Decompiled C draft; module arm9; ROM address 020a683c. No matching claim. */
#include "types.h"
#include "deps/020a683c_func_020a683c.h"

void func_020a683c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uStack_50;
  undefined1 auStack_4c [36];
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar3 = param_2 + 0xa8U & 3;
  uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
    return;
  }
  uVar3 = param_2 + 0xe0U & 3;
  uVar2 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 2) {
    if (uVar3 != 3) {
      uStack_50 = 0x1e;
      func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_50),1);
      uVar4 = MaybeGetBBMtxAtPosition(param_2 + 4);
      func_01ff9048(0x19,uVar4,0xc);
      uVar3 = param_2 + 0xa8U & 3;
      uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 0x1000) {
        uStack_28 = uVar3;
        uStack_24 = uVar3;
        uStack_20 = uVar3;
        func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_28),3);
      }
      func_01ff9048(0x1b,param_2 + 0x1c,3);
      iVar1 = (int)(uint)*(ushort *)(iRam020a6974 + (uint)*puRam020a6970 * 2) >> 4;
      MTX_RotY33__from_thumb
                ((undefined4 *)(void *)(auStack_4c),(int)*(short *)(iRam020a6978 + (iVar1 * 2 + 1) * 2),
                 (int)*(short *)(iRam020a6978 + iVar1 * 4));
      func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_4c),9);
      uStack_1c = 0x2000;
      uStack_18 = 0x2000;
      uStack_14 = 0x2000;
      func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_1c),3);
      func_020e5348(8,param_4);
      return;
    }
    return;
  }
  return;
}

