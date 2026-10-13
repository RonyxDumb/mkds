/* Decompiled C draft; module arm9; ROM address 020fe4c0. No matching claim. */
#include "types.h"
#include "deps/020fe4c0_func_020fe4c0.h"

undefined1 * func_020fe4c0(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  puVar3 = (undefined1 *)func_020fecdc();
  if (param_2 == 0) {
    return puVar3;
  }
  if (param_3 != 0) {
    uVar1 = param_2 + 0x44U & 3;
    uVar5 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
    uVar6 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    uVar2 = GetSomeTimeOrDuration();
    uVar1 = uRam020fe564 & 3;
    uVar5 = *(uint *)(uRam020fe564 & 0xfffffffc);
    *puRam020fe568 = uVar2;
    if ((*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x724) < 0x12) ||
       (iVar4 = func_0205ad44(), iVar4 == 0)) {
      func_020fea84(uVar6,1,(undefined4)(uintptr_t)(puRam020fe568),0x12);
    }
    else {
      func_0205a858(uVar6,1,(undefined4)(uintptr_t)(puRam020fe568),0x12);
    }
    return puRam020fe568;
  }
  return puVar3;
}

