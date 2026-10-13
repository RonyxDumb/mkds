/* Decompiled C draft; module arm9; ROM address 02024000. No matching claim. */
#include "types.h"
#include "deps/02024000_func_02024000.h"

void func_02024000(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                  int param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  if ((param_4 == 8) && (param_5 == 8)) {
    Mem_CpuFastMemorySet(param_6,param_1,param_7 << 3);
    return;
  }
  if (param_7 == 4) {
    uVar6 = 0x20 - (param_2 * 4 + param_4 * 4);
    uVar1 = (0xffffffffU >> (param_2 * 4 & 0xffU)) << (uVar6 + param_2 * 4 & 0xff);
    puVar4 = (uint *)(param_1 + param_3 * 4);
    puVar8 = puVar4;
    if (puVar4 < puVar4 + param_5) {
      do {
        puVar5 = puVar8 + 1;
        *puVar8 = param_6 & uVar1 >> (uVar6 & 0xff) |
                  (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                  *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                  ~(uVar1 >> (uVar6 & 0xff));
        puVar8 = puVar5;
      } while (puVar5 < puVar4 + param_5);
      return;
    }
    return;
  }
  uVar1 = param_2 * 8;
  iVar2 = -(uVar1 + param_4 * 8);
  uVar3 = iVar2 + 0x40;
  uVar6 = 0xffffffff >> (uVar1 & 0xff);
  if (uVar3 < 0x20) {
    uVar6 = uVar6 << (uVar1 & 0xff);
  }
  else {
    uVar7 = iVar2 + 0x20;
    uVar6 = (uVar6 << (uVar1 + uVar7 & 0xff)) >> (uVar7 & 0xff);
  }
  puVar8 = (uint *)(param_1 + param_3 * 8);
  uVar7 = -1 << (uVar3 & 0xff);
  if (uVar1 < 0x20) {
    uVar7 = uVar7 >> (uVar3 & 0xff);
  }
  else {
    uVar7 = (uVar7 >> ((uVar1 - 0x20) + uVar3 & 0xff)) << (uVar1 - 0x20 & 0xff);
  }
  puVar4 = puVar8 + param_5 * 2;
  if (puVar8 < puVar4) {
    do {
      *puVar8 = param_6 & uVar6 |
                (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & ~uVar6;
      uVar1 = (uint)(puVar8 + 1) & 3;
      uVar3 = *(uint *)((uint)(puVar8 + 1) & 0xfffffffc);
      puVar8[1] = param_6 & uVar7 | (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & ~uVar7;
      puVar8 = puVar8 + 2;
    } while (puVar8 < puVar4);
    return;
  }
  return;
}

