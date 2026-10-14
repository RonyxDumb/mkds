/* Decompiled C draft; module arm9; ROM address 0214f264. No matching claim. */
#include "types.h"
#include "deps/0214f264_func_0214f264.h"

uint func_0214f264(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0214f2a8(param_1,uRam0214f2a0,0);
  *(int *)(iRam0214f2a4 + 0xc) = iVar2;
  if (iVar2 == 0) {
    func_0214eed8();
  }
  uVar1 = iRam0214f2a4 + 0xcU & 3;
  uVar3 = *(uint *)(iRam0214f2a4 + 0xcU & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

