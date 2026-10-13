/* Decompiled C draft; module arm9; ROM address 0214f1b0. No matching claim. */
#include "types.h"
#include "deps/0214f1b0_func_0214f1b0.h"

uint func_0214f1b0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0214f1f4(uRam0214f1ec,0);
  *(int *)(iRam0214f1f0 + 0xc) = iVar2;
  if (iVar2 == 0) {
    func_0214eed8();
  }
  uVar1 = iRam0214f1f0 + 0xcU & 3;
  uVar3 = *(uint *)(iRam0214f1f0 + 0xcU & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

