/* Decompiled C draft; module arm9; ROM address 020a6e70. No matching claim. */
#include "types.h"
#include "deps/020a6e70_func_020a6e70.h"

void func_020a6e70(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  uint uVar7;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar8;
  
  uVar2 = uRam020a6f90;
  uVar11 = 0;
  uVar10 = (uint)*(byte *)((*(uint *)(uRam020a6f90 & 0xfffffffc) >> (uRam020a6f90 & 3) * 8 |
                           *(uint *)(uRam020a6f90 & 0xfffffffc) << (uRam020a6f90 & 3) * -8 + 0x20) +
                          0x3d0);
  if (uVar10 != 0) {
    do {
      uVar8 = uVar2 & 3;
      uVar7 = *(uint *)(uVar2 & 0xfffffffc);
      uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      if (uVar11 == (int)*(char *)(uVar8 + 0x62)) {
        uVar8 = (uVar11 & 0xffff) * 0x30 + uVar8 + 0x70;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        bVar6 = false;
        if ((uVar8 < 4) && ((1 << (uVar8 & 0xff) & 0xdU) != 0)) {
          bVar6 = true;
        }
        if (!bVar6) goto LAB_020a6edc;
      }
      else {
LAB_020a6edc:
        GetDriverEntry(uVar11 & 0xffff);
        func_020ac5e4();
      }
      uVar11 = uVar11 + 1;
    } while ((int)uVar11 < (int)uVar10);
  }
  uVar2 = uRam020a6f90;
  if (param_1 == 0) {
    return;
  }
  iVar9 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar9) {
      return;
    }
    uVar10 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar9 * 4;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
    if (uVar10 == 0) break;
    *(undefined4 *)(uVar10 + 0xa4) = 1;
    uVar11 = uVar10 + 0x9c & 3;
    uVar8 = *(uint *)(uVar10 + 0x9c & 0xfffffffc);
    if (*(short *)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x28) != 0) {
      uVar11 = uVar2 & 3;
      uVar8 = *(uint *)(uVar2 & 0xfffffffc);
      bVar1 = *(byte *)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x3d0);
      iVar3 = func_020a1238();
      iVar4 = func_020a119c();
      if (iVar3 + iVar4 < (int)(bVar1 + 1)) {
        uVar5 = IsNotStaffRoll();
        func_020a5744(uVar10 + 4,iVar9,uVar5);
        *(undefined4 *)(uVar10 + 0xa0) = 1;
      }
    }
    iVar9 = iVar9 + 1;
  }
  return;
}

