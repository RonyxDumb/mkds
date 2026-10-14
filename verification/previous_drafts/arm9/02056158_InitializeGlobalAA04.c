/* Decompiled C draft; module arm9; ROM address 02056158. No matching claim. */
#include "types.h"
#include "deps/02056158_InitializeGlobalAA04.h"

void InitializeGlobalAA04(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = Mem_AllocateHeap(param_1,0x10);
  uVar5 = uRam020561fc & 3;
  uVar4 = *(uint *)(uRam020561fc & 0xfffffffc);
  *piRam02056200 = iVar2;
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0xc;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((uVar5 == 3) || (uVar5 == 5)) {
    uVar3 = Mem_AllocateHeapAligned(param_1,0x400,0x20);
    *(undefined4 *)
     ((*(uint *)((uint)piRam02056200 & 0xfffffffc) >> ((uint)piRam02056200 & 3) * 8 |
      *(uint *)((uint)piRam02056200 & 0xfffffffc) << ((uint)piRam02056200 & 3) * -8 + 0x20) + 4) =
         uVar3;
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  piVar1 = piRam02056200;
  *(undefined2 *)
   ((*(uint *)((uint)piRam02056200 & 0xfffffffc) >> ((uint)piRam02056200 & 3) * 8 |
    *(uint *)((uint)piRam02056200 & 0xfffffffc) << ((uint)piRam02056200 & 3) * -8 + 0x20) + 8) = 0;
  uVar4 = uRam02056204;
  *(undefined1 *)
   ((*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
    *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) + 10) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
    *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) + 0xc) = 0x1000;
  *(undefined4 *)
   (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
   *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) = 0;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) {
    *(undefined4 *)
     (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
     *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) = 0;
  }
  return;
}

