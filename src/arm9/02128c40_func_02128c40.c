/* Decompiled C draft; module arm9; ROM address 02128c40. No matching claim. */
#include "types.h"
#include "deps/02128c40_func_02128c40.h"

void func_02128c40(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = iRam02128c98;
  iVar4 = 0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar5 = *piRam02128c9c;
    if (*(int *)(iVar5 + iVar3 + 0x1c) == 0) {
      *(undefined4 *)
       (*(int *)(iVar5 + *(int *)(iVar5 + 4) * 8 + 0x78) +
       (uint)*(byte *)(iVar2 + iVar1 + *(int *)(iVar5 + 4) * 6 + 1) * 0x40) = 1;
    }
    else {
      *(undefined4 *)
       (*(int *)(iVar5 + *(int *)(iVar5 + 4) * 8 + 0x78) +
       (uint)*(byte *)(iVar2 + iVar1 + *(int *)(iVar5 + 4) * 6 + 1) * 0x40) = 0;
    }
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return;
}

