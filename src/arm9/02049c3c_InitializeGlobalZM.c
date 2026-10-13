/* Decompiled C draft; module arm9; ROM address 02049c3c. No matching claim. */
#include "types.h"
#include "deps/02049c3c_InitializeGlobalZM.h"

void InitializeGlobalZM(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = Mem_AllocateHeap(param_1,0x124);
  *puRam02049d44 = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x400,0x20);
  puVar1 = puRam02049d44;
  *(undefined4 *)
   (*(uint *)((uint)puRam02049d44 & 0xfffffffc) >> ((uint)puRam02049d44 & 3) * 8 |
   *(uint *)((uint)puRam02049d44 & 0xfffffffc) << ((uint)puRam02049d44 & 3) * -8 + 0x20) = uVar2;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x10c) = 6;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x110) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x118) = 0xffffffff;
  uVar2 = uRam02049d48;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x11c) = 0;
  uVar3 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar3 + 200) = 0;
  uVar5 = uVar3 + 200 & 3;
  uVar4 = *(uint *)(uVar3 + 200 & 0xfffffffc);
  *(uint *)(uVar3 + 0xc4) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  Os_Thread_Create(uVar5 + 4,uVar2,0,
                   (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                   *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x400,0x400,0xf);
  Os_Thread_WakeUpDirect
            ((*(uint *)((uint)puRam02049d44 & 0xfffffffc) >> ((uint)puRam02049d44 & 3) * 8 |
             *(uint *)((uint)puRam02049d44 & 0xfffffffc) << ((uint)puRam02049d44 & 3) * -8 + 0x20) +
             4);
  puVar1 = puRam02049d44;
  uVar5 = *(uint *)((uint)puRam02049d44 & 0xfffffffc) >> ((uint)puRam02049d44 & 3) * 8 |
          *(uint *)((uint)puRam02049d44 & 0xfffffffc) << ((uint)puRam02049d44 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar5 + 0xcc) = uRam02049d4c;
  *(undefined4 *)(uVar5 + 0xd0) = 0;
  uVar5 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar5 + 0xd8) = uRam02049d50;
  *(undefined4 *)(uVar5 + 0xdc) = 0;
  func_0214f504((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xcc);
  func_0214f4d4((*(uint *)((uint)puRam02049d44 & 0xfffffffc) >> ((uint)puRam02049d44 & 3) * 8 |
                *(uint *)((uint)puRam02049d44 & 0xfffffffc) << ((uint)puRam02049d44 & 3) * -8 + 0x20
                ) + 0xd8);
  return;
}

