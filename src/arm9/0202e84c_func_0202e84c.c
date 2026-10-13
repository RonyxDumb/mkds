/* Decompiled C draft; module arm9; ROM address 0202e84c. No matching claim. */
#include "types.h"
#include "deps/0202e84c_func_0202e84c.h"

void func_0202e84c(void)

{
  int *piVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_r1;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int local_24;
  
  iVar4 = func_0202ee68();
  *(int *)(*piRam0202e960 + 0x38) = *(int *)(*piRam0202e960 + 0x38) + -1;
  local_24 = 0;
  for (iVar9 = 0; piVar1 = piRam0202e960, iVar9 < *(int *)*piRam0202e960; iVar9 = iVar9 + 1) {
    iVar8 = local_24;
    do {
      uVar11 = (uint)*(ushort *)(iVar9 * 2 + *(int *)(*piRam0202e960 + 4));
      iVar10 = iVar8 + uVar11;
      _s32_div_f(iVar8 + 1,7);
      sVar2 = func_0202ee20(iVar10,extraout_r1 + uVar11);
      iVar6 = *piRam0202e960;
      iVar10 = *(int *)(iVar6 + 8) + iVar10 * 0x40;
      if (iVar8 == iVar4) {
        *(short *)(iVar10 + 6) = sVar2;
      }
      else {
        uVar3 = ComputeValueInterpolation_from_thumb
                          (1,(int)sVar2,0,*(undefined4 *)(iVar6 + 0x38),
                           *(undefined4 *)(iVar6 + 0x48));
        *(undefined2 *)(iVar10 + 6) = uVar3;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 7);
  }
  if (((int *)*piRam0202e960)[0xe] == 0) {
    for (iVar9 = 0; piVar7 = (int *)*piVar1, iVar9 < *piVar7; iVar9 = iVar9 + 1) {
      iVar8 = 0;
      do {
        iVar6 = *(int *)(*piVar1 + 8) +
                (iVar8 + (uint)*(ushort *)(iVar9 * 2 + *(int *)(*piVar1 + 4))) * 0x40;
        *(short *)(iVar6 + 0xe) = *(short *)(iVar6 + 0xe) + *(short *)(iVar6 + 6);
        *(undefined2 *)(iVar6 + 6) = 0;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 7);
    }
    *(undefined4 *)(piVar7[2] + (uint)*(ushort *)(piVar7 + 0xb) * 0x40) = 1;
    *(int *)(*piVar1 + 0x40) = *(int *)(*piVar1 + 0x40) + -1;
    *(int *)(*piVar1 + 0x3c) = iVar4;
    func_0202f120(1,*(undefined4 *)(*piVar1 + 0x3c),*(int *)(*piVar1 + 0x40) + -1,0xffffffff);
    iVar4 = *piRam0202e960;
    uVar5 = func_0202edfc();
    func_0202f120(0,*(undefined4 *)(iVar4 + 0x3c),*(int *)(iVar4 + 0x40) + -1,uVar5);
    piVar1 = piRam0202e960;
    *(undefined4 *)(*piRam0202e960 + iRam0202e964) = 0;
    func_0202ee3c(*(undefined4 *)(*piVar1 + 0x3c));
  }
  return;
}

