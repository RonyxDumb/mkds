/* Decompiled C draft; module arm9; ROM address 0214d168. No matching claim. */
#include "types.h"
#include "deps/0214d168_Mem_CpuFill8.h"

void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return;
  }
  if (((uint)param_1 & 1) != 0) {
    *(ushort *)((int)param_1 + -1) = *(ushort *)((int)param_1 + -1) & 0xff | (ushort)(param_2 << 8);
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
  }
  if (1 < param_3) {
    uVar3 = param_2 | param_2 << 8;
    puVar1 = param_1;
    if (((uint)param_1 & 2) != 0) {
      puVar1 = (uint *)((int)param_1 + 2);
      *(ushort *)param_1 = (ushort)uVar3;
      param_3 = param_3 - 2;
      if (param_3 == 0) {
        return;
      }
    }
    param_2 = uVar3 | uVar3 << 0x10;
    if ((param_3 & 0xfffffffc) != 0) {
      puVar4 = (uint *)((param_3 & 0xfffffffc) + (int)puVar1);
      puVar2 = puVar1;
      do {
        puVar1 = puVar2 + 1;
        *puVar2 = param_2;
        puVar2 = puVar1;
      } while (puVar1 < puVar4);
    }
    param_1 = puVar1;
    if ((param_3 & 2) != 0) {
      param_1 = (uint *)((int)puVar1 + 2);
      *(ushort *)puVar1 = (ushort)uVar3;
    }
  }
  if ((param_3 & 1) == 0) {
    return;
  }
  *(ushort *)param_1 = (ushort)param_2 & 0xff | (ushort)*param_1 & 0xff00;
  return;
}

