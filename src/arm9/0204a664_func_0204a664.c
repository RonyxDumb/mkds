/* Decompiled C draft; module arm9; ROM address 0204a664. No matching claim. */
#include "types.h"
#include "deps/0204a664_func_0204a664.h"

uint func_0204a664(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) != 2) {
    return 0;
  }
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(param_1 + 4);
  if ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) <= uVar2) {
    *(undefined4 *)(param_1 + 8) = 0;
    return 0;
  }
  bVar1 = *(byte *)(uVar4 + 4 + uVar2 * 2);
  if ((bVar1 & 2) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  if ((bVar1 & 4) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0x100;
  }
  if ((bVar1 & 8) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x600;
  }
  if ((bVar1 & 0x10) == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0x10;
  }
  if ((bVar1 & 0x20) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0x20;
  }
  if ((bVar1 & 0x80) == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0x40;
  }
  uVar3 = bVar1 & 0x40;
  bVar11 = (bVar1 & 0x40) != 0;
  if (bVar11) {
    uVar3 = 0x80;
  }
  if (!bVar11) {
    uVar3 = 0;
  }
  *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
  if ((ushort)*(byte *)(uVar4 + 4 + uVar2 * 2 + 1) <= *(ushort *)(param_1 + 6)) {
    *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return (bVar1 & 1) != 0 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar3;
}

