/* Decompiled C draft; module arm9; ROM address 0202e72c. No matching claim. */
#include "types.h"
#include "deps/0202e72c_func_0202e72c.h"

void func_0202e72c(void)

{
  int *piVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int extraout_r1;
  undefined4 extraout_r1_00;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_20;
  
  *(int *)(*piRam0202e844 + 0x38) = *(int *)(*piRam0202e844 + 0x38) + -1;
  local_20 = 0;
  for (iVar8 = 0; piVar1 = piRam0202e844, iVar8 < *(int *)*piRam0202e844; iVar8 = iVar8 + 1) {
    iVar7 = local_20;
    do {
      uVar10 = (uint)*(ushort *)(iVar8 * 2 + *(int *)(*piRam0202e844 + 4));
      iVar9 = iVar7 + uVar10;
      _s32_div_f(iVar7 + 6,7);
      sVar2 = func_0202ee20(iVar9,extraout_r1 + uVar10);
      iVar5 = *piRam0202e844;
      iVar9 = *(int *)(iVar5 + 8) + iVar9 * 0x40;
      if (iVar7 == *(int *)(iVar5 + 0x3c)) {
        *(short *)(iVar9 + 6) = sVar2;
      }
      else {
        uVar3 = ComputeValueInterpolation_from_thumb
                          (1,(int)sVar2,0,*(undefined4 *)(iVar5 + 0x38),
                           *(undefined4 *)(iVar5 + 0x48));
        *(undefined2 *)(iVar9 + 6) = uVar3;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 7);
  }
  if (((int *)*piRam0202e844)[0xe] == 0) {
    for (iVar8 = 0; piVar6 = (int *)*piVar1, iVar8 < *piVar6; iVar8 = iVar8 + 1) {
      iVar7 = 0;
      do {
        iVar5 = *(int *)(*piVar1 + 8) +
                (iVar7 + (uint)*(ushort *)(iVar8 * 2 + *(int *)(*piVar1 + 4))) * 0x40;
        *(short *)(iVar5 + 0xe) = *(short *)(iVar5 + 0xe) + *(short *)(iVar5 + 6);
        *(undefined2 *)(iVar5 + 6) = 0;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 7);
    }
    *(undefined4 *)(piVar6[2] + (uint)*(ushort *)(piVar6 + 0xb) * 0x40) = 1;
    *(int *)(*piVar1 + 0x40) = *(int *)(*piVar1 + 0x40) + 1;
    func_0202f120(1,*(undefined4 *)(*piVar1 + 0x3c),*(int *)(*piVar1 + 0x40) + 1,0xffffffff);
    iVar8 = *piRam0202e844;
    _s32_div_f(*(int *)(iVar8 + 0x3c) + 1,7);
    *(undefined4 *)(iVar8 + 0x3c) = extraout_r1_00;
    iVar8 = *piRam0202e844;
    uVar4 = func_0202edfc();
    func_0202f120(0,*(undefined4 *)(iVar8 + 0x3c),*(int *)(iVar8 + 0x40) + -1,uVar4);
    *(undefined4 *)(*piRam0202e844 + iRam0202e848) = 0;
    uVar4 = func_0202ee68();
    func_0202ee3c(uVar4,0);
  }
  return;
}

