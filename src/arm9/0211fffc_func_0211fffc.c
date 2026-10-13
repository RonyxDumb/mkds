/* Decompiled C draft; module arm9; ROM address 0211fffc. No matching claim. */
#include "types.h"
#include "deps/0211fffc_func_0211fffc.h"

undefined4 func_0211fffc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar2 = Os_DisableIrq();
  uVar3 = *(uint *)(uRam02120040 & 0xfffffffc) >> (uRam02120040 & 3) * 8 |
          *(uint *)(uRam02120040 & 0xfffffffc) << (uRam02120040 & 3) * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = Mem_AllocateHeapAligned(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2,param_3);
  Os_RestoreIrq(uVar2);
  return uVar4;
}

