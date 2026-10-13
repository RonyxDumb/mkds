/* Decompiled C draft; module arm9; ROM address 020597d0. No matching claim. */
#include "types.h"
#include "deps/020597d0_func_020597d0.h"

void func_020597d0(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *piRam0205981c;
  if (*(int *)(iVar1 + 4) != 0xb) {
    func_020559ec(param_1,param_3,param_4);
    return;
  }
  uVar2 = 1 << (param_3 & 0xff);
  if ((*(byte *)(iVar1 + iRam02059820) & uVar2) == 0) {
    Mem_CpuCopy8(param_1,iVar1 + iRam02059824 + iRam02059828 * param_3,0x14);
    *(byte *)(*piRam0205981c + iRam02059820) =
         *(byte *)(*piRam0205981c + iRam02059820) | (byte)uVar2;
  }
  return;
}

