/* Decompiled C draft; module arm9; ROM address 02053e74. No matching claim. */
#include "types.h"
#include "deps/02053e74_func_02053e74.h"

void func_02053e74(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  iVar8 = (*(uint *)(uRam02053f90 & 0xfffffffc) >> (uRam02053f90 & 3) * 8 |
          *(uint *)(uRam02053f90 & 0xfffffffc) << (uRam02053f90 & 3) * -8 + 0x20) + iRam02053f94;
  *(undefined1 *)(iVar8 + 0x60) = 0;
  *(undefined1 *)(iVar8 + 0x68) = 0;
  uVar4 = 0;
  do {
    iVar9 = 0;
    do {
      iVar1 = iVar9 * 2;
      iVar9 = iVar9 + 1;
      *(undefined2 *)(iVar1 + iVar8 + iVar10 * 8) = 0;
      uVar7 = uRam02053f90;
    } while (iVar9 < 3);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 8);
  uVar5 = *(uint *)(uRam02053f90 & 0xfffffffc) >> (uRam02053f90 & 3) * 8 |
          *(uint *)(uRam02053f90 & 0xfffffffc) << (uRam02053f90 & 3) * -8 + 0x20;
  *(ushort *)(uVar5 + 0x454) = *(ushort *)(uVar5 + 0x454) & 0xffef;
  uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  *(ushort *)(uVar5 + 0x454) = *(ushort *)(uVar5 + 0x454) | 8;
  iVar8 = iRam02053f98;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  if (uVar7 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  }
  if (uVar5 == 1) {
    uVar4 = uVar7 + 0x18 & 3;
    uVar5 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
    uVar4 = (uint)*(ushort *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xc);
  }
  else if (uVar5 == 2) {
    uVar4 = uVar7 + 0x24 & 3;
    uVar5 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
    uVar4 = (uint)*(ushort *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x48);
  }
  uVar5 = 0;
  if (uVar7 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  }
  if (uVar6 == 1) {
    uVar5 = uVar7 + 0x18 & 3;
    uVar6 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
    uVar5 = (uint)*(ushort *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0xc);
  }
  else if (uVar6 == 2) {
    uVar5 = uVar7 + 0x24 & 3;
    uVar6 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
    uVar5 = (uint)*(ushort *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x48);
  }
  *(uint *)(uVar7 + 0x1eb8) = uVar5 + uVar4 * 0x400;
  uVar2 = uRam02053f9c;
  iVar8 = uVar7 + iVar8;
  *(undefined4 *)(iVar8 + 4) = 0;
  uVar3 = uRam02053fa0;
  *(undefined4 *)(iVar8 + 8) = uVar2;
  uVar2 = uRam02053fa4;
  *(undefined4 *)(iVar8 + 0xc) = uVar3;
  *(undefined4 *)(iVar8 + 0x10) = uVar2;
  *(undefined4 *)(iVar8 + 0x14) = 0;
  return;
}

