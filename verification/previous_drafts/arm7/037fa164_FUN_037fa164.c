/* Decompiled C draft; module arm7; ROM address 037fa164. No matching claim. */
#include "types.h"
#include "deps/037fa164_FUN_037fa164.h"

uint * FUN_037fa164(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  uint *puVar6;
  uint uVar4;
  
  puVar1 = param_1;
  puVar6 = (uint *)0x0;
  while ((puVar5 = puVar1, puVar5 != (uint *)0x0 && (puVar5 < param_2))) {
    uVar4 = (uint)(puVar5 + 1) & 3;
    uVar3 = *(uint *)((uint)(puVar5 + 1) & 0xfffffffc);
    puVar6 = puVar5;
    puVar1 = (uint *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  }
  param_2[1] = (uint)puVar5;
  *param_2 = (uint)puVar6;
  if (puVar5 != (uint *)0x0) {
    *puVar5 = (uint)param_2;
    uVar4 = (uint)(param_2 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((uint *)((int)param_2 + uVar4) == puVar5) {
      uVar3 = (uint)(puVar5 + 2) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 2) & 0xfffffffc);
      param_2[2] = uVar4 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      uVar4 = (uint)(puVar5 + 1) & 3;
      uVar3 = *(uint *)((uint)(puVar5 + 1) & 0xfffffffc);
      puVar5 = (uint *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
      param_2[1] = (uint)puVar5;
      if (puVar5 != (uint *)0x0) {
        *puVar5 = (uint)param_2;
      }
    }
  }
  puVar1 = param_2;
  if (puVar6 != (uint *)0x0) {
    puVar6[1] = (uint)param_2;
    uVar4 = (uint)(puVar6 + 2) & 3;
    uVar3 = *(uint *)((uint)(puVar6 + 2) & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    puVar1 = param_1;
    if ((uint *)((int)puVar6 + uVar4) == param_2) {
      uVar3 = (uint)(param_2 + 2) & 3;
      uVar2 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      puVar6[2] = uVar4 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      puVar6[1] = (uint)puVar5;
      if (puVar5 != (uint *)0x0) {
        *puVar5 = (uint)puVar6;
      }
    }
  }
  return puVar1;
}

