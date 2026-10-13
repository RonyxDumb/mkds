/* Decompiled C draft; module arm9; ROM address 0204f240. No matching claim. */
#include "types.h"
#include "deps/0204f240_func_0204f240.h"

void func_0204f240(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = uRam0204f300;
  uVar1 = uRam0204f2fc;
  iVar6 = *piRam0204f2f4 + iRam0204f2f8;
  iVar5 = 0;
  iVar4 = iVar6;
  do {
    *(undefined1 *)(iVar4 + 0x34) = 0;
    *(undefined4 *)(iVar4 + 0x74) = 0;
    *(undefined4 *)(iVar4 + 0x78) = 0;
    *(uint *)(iVar4 + 0x84) = *(uint *)(iVar4 + 0x84) & uVar1;
    *(uint *)(iVar4 + 0x84) = *(uint *)(iVar4 + 0x84) & uVar2;
    iVar4 = iVar4 + 0x88;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xc);
  *(int *)(iVar6 + iRam0204f304) = param_2;
  *(undefined4 *)(iVar6 + iRam0204f308) = 0;
  *(undefined4 *)(iVar6 + iRam0204f30c) = 0;
  *(undefined2 *)(iVar6 + iRam0204f310) = 0;
  *(undefined2 *)(iVar6 + iRam0204f314) = 0;
  *(undefined1 *)(iVar6 + iRam0204f318) = 0;
  *(undefined1 *)(iVar6 + iRam0204f31c) = 0xff;
  *(undefined1 *)(iVar6 + iRam0204f320) = 0;
  *(undefined1 *)(iVar6 + iRam0204f324) = 0;
  *(undefined2 *)(iVar6 + iRam0204f328) = 0;
  *(undefined2 *)(iVar6 + iRam0204f32c) = 0xffff;
  *(undefined4 *)(iVar6 + iRam0204f330) = 0;
  if (param_2 == 2) {
    func_0204f33c(param_1);
    func_0204ee64();
    return;
  }
  if (param_2 == 1) {
    uVar3 = Mem_AllocateHeapAligned(param_1,uRam0204f334,0x20);
    *(undefined4 *)(*piRam0204f2f4 + iRam0204f338) = uVar3;
  }
  return;
}

