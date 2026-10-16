/* Decompiled C draft; module arm9; ROM address 020271e8. No matching claim. */
#include "types.h"
#include "deps/020271e8_func_020271e8.h"

void func_020271e8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = iRam02027218;
  iVar2 = *piRam02027214;
  iVar3 = *(int *)(iVar2 + 0x60) * 8;
  func_02025c6c(0x18,(int)*(short *)(iRam02027218 + iVar3),*(undefined4 *)(iVar2 + 0x28));
  func_02025c6c(0x19,(int)*(short *)(iVar1 + iVar3),*(undefined4 *)(iVar2 + 0x28));
  return;
}

