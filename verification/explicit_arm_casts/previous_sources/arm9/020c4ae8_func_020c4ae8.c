/* Decompiled C draft; module arm9; ROM address 020c4ae8. No matching claim. */
#include "types.h"
#include "deps/020c4ae8_func_020c4ae8.h"

void func_020c4ae8(void)

{
  short sVar1;
  uint uVar2;
  uint uVar4;
  undefined4 local_14;
  undefined4 local_10;
  uint uVar3;
  
  uVar2 = uRam020c4bac;
  *(undefined2 *)
   ((*(uint *)(uRam020c4bac & 0xfffffffc) >> (uRam020c4bac & 3) * 8 |
    *(uint *)(uRam020c4bac & 0xfffffffc) << (uRam020c4bac & 3) * -8 + 0x20) + 0x418) = 0;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 + 0xc & 3;
  uVar2 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
  local_14 = 0x80000;
  local_10 = 0x60000;
  sVar1 = MaybeMakeOamSlot(uVar3 + 0x18 + (uint)*(ushort *)(uVar3 + 0x418) * 8,
                           0x80 - *(ushort *)(uVar3 + 0x418) & 0xffff,
                           uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,0,&local_14,0,1);
  uVar2 = uRam020c4bac;
  *(short *)(uVar3 + 0x418) = *(short *)(uVar3 + 0x418) + sVar1;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  Arm_FlushRange((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x18,0x400);
  uVar4 = *(uint *)(uRam020c4bac & 0xfffffffc) >> (uRam020c4bac & 3) * 8 |
          *(uint *)(uRam020c4bac & 0xfffffffc) << (uRam020c4bac & 3) * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar4 + 0x418);
  Mem_DmaFill32(3,uVar4 + 0x18 + uVar2 * 8,0xc0,(0x80 - uVar2) * 8);
  return;
}

