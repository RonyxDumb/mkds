/* Decompiled C draft; module arm9; ROM address 0211ffb0. No matching claim. */
#include "types.h"
#include "deps/0211ffb0_func_0211ffb0.h"

void func_0211ffb0(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    uVar2 = Os_DisableIrq();
    uVar3 = *(uint *)(uRam0211fff8 & 0xfffffffc) >> (uRam0211fff8 & 3) * 8 |
            *(uint *)(uRam0211fff8 & 0xfffffffc) << (uRam0211fff8 & 3) * -8 + 0x20;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Mem_FreeHeap(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2);
    Os_RestoreIrq(uVar2);
    return;
  }
  return;
}

