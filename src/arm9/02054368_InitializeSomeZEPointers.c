/* Decompiled C draft; module arm9; ROM address 02054368. No matching claim. */
#include "types.h"
#include "deps/02054368_InitializeSomeZEPointers.h"

void InitializeSomeZEPointers(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = Mem_AllocateHeapAligned(param_1,0xf00,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x14) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x40,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x18) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x20,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x1c) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0xc0,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x24) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0xc0,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x28) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x44,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x20) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x400,0x20);
  uVar3 = uRam020545e4;
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x2c) = uVar2;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x30) = 0x1c0;
  uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = Mem_AllocateHeapAligned(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0x20);
  uVar3 = uRam020545e4;
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x34) = uVar2;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x38) = 0x400;
  uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = Mem_AllocateHeapAligned(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x3c) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x820,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x15bc) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x200,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x15c0) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,8,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x15c4) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x40,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x15c8) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x18,0x20);
  uVar3 = uRam020545e4;
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x40) = uVar2;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1664) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x165c) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1658) = 0;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x1c,0x20);
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x7c) = uVar2;
  uVar2 = Mem_AllocateHeap(param_1,0x7800);
  uVar2 = Mem_Exp_Create(uVar2,0x7800,1);
  uVar3 = uRam020545e4;
  *(undefined4 *)
   ((*(uint *)(uRam020545e4 & 0xfffffffc) >> (uRam020545e4 & 3) * 8 |
    *(uint *)(uRam020545e4 & 0xfffffffc) << (uRam020545e4 & 3) * -8 + 0x20) + 0x1d04) = uVar2;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1e24) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1e2c) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1e20) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1e28) = 0;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(byte *)(uVar3 + 0x456) = *(byte *)(uVar3 + 0x456) & 0xfe | 1;
  func_02053d00();
  return;
}

