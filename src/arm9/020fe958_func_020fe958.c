/* Decompiled C draft; module arm9; ROM address 020fe958. No matching claim. */
#include "types.h"
#include "deps/020fe958_func_020fe958.h"

undefined1 * func_020fe958(undefined4 param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = GetSomeTimeOrDuration();
  uVar1 = uRam020fe9c8 & 3;
  uVar4 = *(uint *)(uRam020fe9c8 & 0xfffffffc);
  *puRam020fe9cc = uVar2;
  if ((*(short *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x724) == 0) ||
     (iVar3 = func_0205ad44(), iVar3 == 0)) {
    func_020fea84(param_1,0,(undefined4)(uintptr_t)(puRam020fe9cc),1);
  }
  else {
    func_0205a858(param_1,0,(undefined4)(uintptr_t)(puRam020fe9cc),1);
  }
  return puRam020fe9cc;
}

