/* Decompiled C draft; module arm9; ROM address 0204a798. No matching claim. */
#include "types.h"
#include "deps/0204a798_func_0204a798.h"

/* WARNING: Removing unreachable block (ram,0x0204a8a0) */

void func_0204a798(uint param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  uVar11 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  if ((uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) != 1) {
    return;
  }
  piVar2 = (int *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  uVar11 = (uint)*(ushort *)(param_1 + 4);
  pbVar4 = (byte *)((int)piVar2 + uVar11 * 2 + 4);
  if ((param_2 & 2) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  if ((param_2 & 0x100) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 4;
  }
  if ((param_2 & 0x600) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 8;
  }
  if ((param_2 & 0x10) == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0x10;
  }
  if ((param_2 & 0x20) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0x20;
  }
  if ((param_2 & 0x80) == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0x40;
  }
  uVar1 = param_2 & 0x40;
  bVar12 = uVar1 != 0;
  if (bVar12) {
    uVar1 = 0x80;
  }
  if (!bVar12) {
    uVar1 = 0;
  }
  uVar1 = (param_2 & 1) != 0 | uVar3 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar1;
  bVar12 = false;
  if (((pbVar4[1] == 0) || (bVar12 = *pbVar4 != uVar1, !bVar12)) && (pbVar4[1] == 0xff)) {
    bVar12 = true;
  }
  pbVar5 = pbVar4;
  if (bVar12) {
    if (uRam0204a8fc <= uVar11) {
      *piVar2 = uVar11 << 1;
      *(undefined4 *)(param_1 + 8) = 3;
      DC_SomeClean(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,uRam0204a900);
      return;
    }
    pbVar5 = pbVar4 + 2;
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    pbVar4[3] = 0;
  }
  *pbVar5 = (byte)uVar1;
  pbVar5[1] = pbVar5[1] + 1;
  return;
}

