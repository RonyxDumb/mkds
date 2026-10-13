/* Decompiled C draft; module arm9; ROM address 0205b778. No matching claim. */
#include "types.h"
#include "deps/0205b778_func_0205b778.h"

void func_0205b778(undefined4 param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = (uint)(param_2 + 4) & 3;
  uVar7 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  iVar6 = (*param_2 & 3) * 0x88;
  uVar8 = *(uint *)(uRam0205b81c & 0xfffffffc) >> (uRam0205b81c & 3) * 8 |
          *(uint *)(uRam0205b81c & 0xfffffffc) << (uRam0205b81c & 3) * -8 + 0x20;
  uVar5 = uVar8 + 0x104 + iVar6;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0xffffff;
  bVar3 = param_2[7];
  if ((*(short *)(uVar8 + 0xe) != 4) && (*(short *)(uVar8 + 0xe) != 5)) {
    return;
  }
  if ((uVar5 != 0) && (((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) & 0xffffff) <= uVar5)) {
    return;
  }
  bVar4 = *(byte *)(uVar8 + iRam0205b820 + iVar6);
  if (-1 < (int)((uint)bVar4 << 0x1f)) {
    *(byte *)(uVar8 + iRam0205b820 + iVar6) = bVar4 & 0xfe | 1;
  }
  Mem_CpuCopy8(param_2 + 4,uVar8 + 0x104 + iVar6,bVar3);
  return;
}

