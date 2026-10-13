/* Decompiled C draft; module arm9; ROM address 0204f5e4. No matching claim. */
#include "types.h"
#include "deps/0204f5e4_func_0204f5e4.h"

void func_0204f5e4(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = uRam0204f63c;
  uVar1 = uRam0204f638;
  iVar4 = *piRam0204f630 + iRam0204f634;
  iVar5 = 0;
  iVar3 = iVar4;
  do {
    *(undefined1 *)(iVar3 + 0x34) = 0;
    *(undefined4 *)(iVar3 + 0x74) = 0;
    *(undefined4 *)(iVar3 + 0x78) = 0;
    *(uint *)(iVar3 + 0x84) = *(uint *)(iVar3 + 0x84) & uVar1;
    *(uint *)(iVar3 + 0x84) = *(uint *)(iVar3 + 0x84) & uVar2;
    iVar3 = iVar3 + 0x88;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xc);
  *(undefined2 *)(iVar4 + iRam0204f640) = 0xc;
  return;
}

