/* Decompiled C draft; module arm9; ROM address 020fe71c. No matching claim. */
#include "types.h"
#include "deps/020fe71c_func_020fe71c.h"

undefined1 * func_020fe71c(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = puRam020fe798;
  puRam020fe798[1] = param_3;
  puVar2[2] = param_2;
  uVar3 = GetSomeTimeOrDuration();
  uVar1 = uRam020fe79c & 3;
  uVar5 = *(uint *)(uRam020fe79c & 0xfffffffc);
  *puRam020fe798 = uVar3;
  if ((*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x724) < 3) ||
     (iVar4 = func_0205ad44(), iVar4 == 0)) {
    func_020fea84(param_1,3,(undefined4)(uintptr_t)(puRam020fe798),3);
  }
  else {
    func_0205a858(param_1,3,(undefined4)(uintptr_t)(puRam020fe798),3);
  }
  return puRam020fe798;
}

