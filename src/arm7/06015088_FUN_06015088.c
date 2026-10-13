/* Decompiled C draft; module arm7; ROM address 06015088. No matching claim. */
#include "types.h"
#include "deps/06015088_FUN_06015088.h"

void FUN_06015088(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  uVar4 = *(uint *)(DAT_06015214 & 0xfffffffc) >> (DAT_06015214 & 3) * 8 |
          *(uint *)(DAT_06015214 & 0xfffffffc) << (DAT_06015214 & 3) * -8 + 0x20;
  piVar5 = (int *)(uVar4 + DAT_06015218);
  FUN_0600ec88();
  if ((*(ushort *)(param_1 + 8) & 2) == 0) {
    *piVar5 = (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) + 1;
    if ((int)((uint)*(ushort *)(param_1 + 0x14) << 0x17) < 0) {
      if ((*(ushort *)(param_1 + 0x24) & 1) == 0) {
        uVar1 = (uint)(piVar5 + 4) & 3;
        uVar2 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        piVar5[4] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
      }
      else {
        uVar1 = (uint)(piVar5 + 5) & 3;
        uVar2 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        piVar5[5] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
      }
    }
    else if ((*(ushort *)(param_1 + 0x18) & 1) == 0) {
      uVar1 = (uint)(piVar5 + 4) & 3;
      uVar2 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      piVar5[4] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
    }
    else {
      uVar1 = (uint)(piVar5 + 5) & 3;
      uVar2 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      piVar5[5] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
    }
  }
  else {
    uVar1 = (uint)(piVar5 + 1) & 3;
    uVar2 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    piVar5[1] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  }
  if ((int)((uint)*(ushort *)(param_1 + 0x14) << 0x11) < 0) {
    uVar1 = (uint)(piVar5 + 6) & 3;
    uVar2 = *(uint *)((uint)(piVar5 + 6) & 0xfffffffc);
    piVar5[6] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  }
  FUN_060125a8(uVar4 + 0x194,param_1 + -0x10);
  *(undefined2 *)
   ((*(uint *)(DAT_06015214 & 0xfffffffc) >> (DAT_06015214 & 3) * 8 |
    *(uint *)(DAT_06015214 & 0xfffffffc) << (DAT_06015214 & 3) * -8 + 0x20) + 0x42c) = 0;
  iVar3 = FUN_0600e8d8(*(undefined2 *)(param_1 + 2));
  if ((iVar3 != 0) && ((*(ushort *)(param_1 + 0x14) & 0x2000) == 0)) {
    FUN_0600eb00(*(undefined2 *)(param_1 + 2));
  }
  if (param_2 != 0) {
    if (*(short *)(uVar4 + 0x19c) == 0) {
      if ((((((uint)*(ushort *)(uVar4 + 0x350) + DAT_0601521c & 0xffff) < 2) &&
           (*(short *)(uVar4 + 0x34c) == 0x40)) && (*(short *)(uVar4 + 0x352) != 0)) &&
         ((iVar3 = FUN_0600e824(*(undefined2 *)(uVar4 + 0x3cc)), iVar3 == 0 &&
          (*(short *)(uVar4 + 0x3d2) == 0)))) {
        FUN_0600ae00(1);
      }
    }
    else {
      FUN_0601536c(0);
    }
  }
  return;
}

