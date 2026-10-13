/* Decompiled C draft; module arm9; ROM address 02128ca0. No matching claim. */
#include "types.h"
#include "deps/02128ca0_func_02128ca0.h"

void func_02128ca0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = iRam02128cf4;
  iVar4 = 0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar5 = *piRam02128cf8;
    if (*(int *)(iVar5 + iVar3 + 0x14) == 0) {
      *(undefined4 *)
       (*(int *)(iVar5 + *(int *)(iVar5 + 4) * 8 + 0x78) +
       (uint)*(byte *)(iVar2 + iVar1 + *(int *)(iVar5 + 4) * 6) * 0x40) = 0;
    }
    else {
      *(undefined4 *)
       (*(int *)(iVar5 + *(int *)(iVar5 + 4) * 8 + 0x78) +
       (uint)*(byte *)(iVar2 + iVar1 + *(int *)(iVar5 + 4) * 6) * 0x40) = 1;
    }
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return;
}

