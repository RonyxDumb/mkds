/* Decompiled C draft; module arm9; ROM address 020d12e0. No matching claim. */
#include "types.h"
#include "deps/020d12e0_func_020d12e0.h"

void func_020d12e0(void)

{
  short sVar1;
  uint uVar2;
  ushort *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 local_1c;
  undefined4 local_18;
  uint uVar3;
  
  uVar2 = uRam020d13f4;
  *(undefined2 *)
   ((*(uint *)(uRam020d13f4 & 0xfffffffc) >> (uRam020d13f4 & 3) * 8 |
    *(uint *)(uRam020d13f4 & 0xfffffffc) << (uRam020d13f4 & 3) * -8 + 0x20) + 0x410) = 0;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) < 0x21c) {
    uVar7 = (uint)*(ushort *)(uVar3 + 0x410);
    uVar2 = uVar3 + 0xc & 3;
    uVar5 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
    local_18 = 0x60000;
    local_1c = 0x80000;
    puVar6 = (uint *)(uVar3 + 0x10 + uVar7 * 8);
    sVar1 = MaybeMakeOamSlot((int)(uintptr_t)(puVar6),0x80 - uVar7 & 0xffff,
                             (ushort *)(uintptr_t)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20),0,(uint)(uintptr_t)(&local_1c),0,1);
    puVar4 = (ushort *)(uVar3 + 0x410);
    *puVar4 = *puVar4 + sVar1;
    if (uVar7 < *puVar4) {
      do {
        uVar7 = uVar7 + 1;
        *puVar6 = (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                  *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                  0xfffff3ff | 0x400;
        uVar3 = (uint)(puVar6 + 1) & 3;
        uVar2 = *(uint *)((uint)(puVar6 + 1) & 0xfffffffc);
        puVar6[1] = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfffff3ff | 0x400;
        puVar6 = puVar6 + 2;
      } while ((int)uVar7 < (int)(uint)*puVar4);
    }
  }
  Arm_FlushRange((*(uint *)(uRam020d13f4 & 0xfffffffc) >> (uRam020d13f4 & 3) * 8 |
                 *(uint *)(uRam020d13f4 & 0xfffffffc) << (uRam020d13f4 & 3) * -8 + 0x20) + 0x10,
                 0x400);
  uVar3 = *(uint *)(uRam020d13f4 & 0xfffffffc) >> (uRam020d13f4 & 3) * 8 |
          *(uint *)(uRam020d13f4 & 0xfffffffc) << (uRam020d13f4 & 3) * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar3 + 0x410);
  Mem_DmaFill32(3,uVar3 + 0x10 + uVar2 * 8,0xc0,(0x80 - uVar2) * 8);
  return;
}

