/* Decompiled C draft; module arm9; ROM address 02052fa4. No matching claim. */
#include "types.h"
#include "deps/02052fa4_func_02052fa4.h"

undefined4 func_02052fa4(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar2 = Os_DisableIrq();
  if (param_3 == 0) {
    uVar3 = (*(uint *)(uRam0205301c & 0xfffffffc) >> (uRam0205301c & 3) * 8 |
            *(uint *)(uRam0205301c & 0xfffffffc) << (uRam0205301c & 3) * -8 + 0x20) + 0x1d04;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = Mem_AllocateHeapAligned
                      (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2,0xffffffe0);
  }
  else {
    uVar3 = (*(uint *)(uRam0205301c & 0xfffffffc) >> (uRam0205301c & 3) * 8 |
            *(uint *)(uRam0205301c & 0xfffffffc) << (uRam0205301c & 3) * -8 + 0x20) + 0x1d04;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Mem_FreeHeap(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_3);
  }
  Os_RestoreIrq(uVar2);
  return uVar4;
}

