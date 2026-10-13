/* Decompiled C draft; module arm9; ROM address 020fe828. No matching claim. */
#include "types.h"
#include "deps/020fe828_func_020fe828.h"

undefined1 * func_020fe828(undefined4 param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  puRam020fe8a4[1] = 0xff;
  uVar2 = GetSomeTimeOrDuration();
  uVar1 = uRam020fe8a8 & 3;
  uVar4 = *(uint *)(uRam020fe8a8 & 0xfffffffc);
  *puRam020fe8a4 = uVar2;
  if ((*(ushort *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x724) < 2) ||
     (iVar3 = func_0205ad44(), iVar3 == 0)) {
    func_020fea84(param_1,0,(undefined4)(uintptr_t)(puRam020fe8a4),2);
  }
  else {
    func_0205a858(param_1,0,(undefined4)(uintptr_t)(puRam020fe8a4),2);
  }
  return puRam020fe8a4;
}

