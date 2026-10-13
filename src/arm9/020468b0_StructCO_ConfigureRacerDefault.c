/* Decompiled C draft; module arm9; ROM address 020468b0. No matching claim. */
#include "types.h"
#include "deps/020468b0_StructCO_ConfigureRacerDefault.h"

void StructCO_ConfigureRacerDefault
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
               int param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = uRam02046964;
  iVar5 = param_1 * 0x30;
  *(undefined4 *)
   ((*(uint *)(uRam02046964 & 0xfffffffc) >> (uRam02046964 & 3) * 8 |
    *(uint *)(uRam02046964 & 0xfffffffc) << (uRam02046964 & 3) * -8 + 0x20) + iVar5 + 0x250) =
       param_2;
  *(int *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar5 + 600) = param_4;
  *(int *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar5 + 0x264) = param_1;
  uVar2 = uRam02046964;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar5 + 0x254) = param_3;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar5 + 0x25c) = param_5;
  *(int *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar5 + 0x260) = param_6;
  if (param_4 == 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = 3;
  }
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x268) = uVar4;
  *(undefined2 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x26c) = 0;
  if (param_6 != 3) {
    iVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x26c;
    *(ushort *)(iVar3 + iVar5) = *(ushort *)(iVar3 + iVar5) | 1;
  }
  return;
}

