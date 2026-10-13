/* Decompiled C draft; module arm9; ROM address 02047104. No matching claim. */
#include "types.h"
#include "deps/02047104_CreateGlobal59C4.h"

void CreateGlobal59C4(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = Mem_AllocateHeap(param_1,0x40);
  piVar1 = piRam02047174;
  *piRam02047174 = iVar2;
  uVar3 = iVar2 + 0x30U & 3;
  uVar4 = *(uint *)(iVar2 + 0x30U & 0xfffffffc);
  *(uint *)(iVar2 + 0x30) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0xfffffffe;
  uVar5 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x30;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0x30) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffffd;
  uVar5 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x30;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0x30) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffffb;
  uVar5 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x30;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0x30) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffff7;
  *(undefined4 *)
   ((*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
    *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) + 0x3c) = 0;
  InitializeBalloonHardware();
  return;
}

