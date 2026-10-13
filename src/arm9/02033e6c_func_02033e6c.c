/* Decompiled C draft; module arm9; ROM address 02033e6c. No matching claim. */
#include "types.h"
#include "deps/02033e6c_func_02033e6c.h"

void func_02033e6c(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  piVar1 = piRam02034014;
  uVar7 = 0;
  iVar6 = *piRam02034014;
  iVar3 = *(int *)(iVar6 + 0xd8);
  if (0 < iVar3) {
    do {
      if ((*(int *)(iVar6 + 0xe0) == 3) || (*(int *)(*piRam02034018 + 0x1c) == 2)) {
        uVar4 = Int32ToInt8(uVar7);
        iVar3 = GetSomeLUMaxIndex();
        iVar6 = Int32ToInt8(uVar4);
        *(uint *)(*piVar1 + uVar7 * 0xc + 0xe8) =
             (uint)*(ushort *)(*piRam0203401c + iVar3 * 0x50 + iVar6 * 10);
      }
      else {
        uVar4 = Int32ToInt8(uVar7);
        iVar3 = GetSomeLUMaxIndex();
        iVar6 = Int32ToInt8(uVar4);
        *(uint *)(*piVar1 + uVar7 * 0xc + 0xe8) =
             (uint)*(byte *)(*piRam0203401c + iVar3 * 0x50 + iVar6 * 10 + 5);
      }
      uVar7 = uVar7 + 1 & 0xffff;
      iVar6 = *piVar1;
      iVar3 = *(int *)(iVar6 + 0xd8);
    } while ((int)uVar7 < iVar3);
  }
  uVar7 = 0;
  if (0 < iVar3) {
    do {
      uVar8 = 0;
      uVar9 = uVar8;
      if (0 < iVar3) {
        do {
          if ((uVar7 != uVar8) &&
             (*(int *)(iVar6 + uVar7 * 0xc + 0xe8) < *(int *)(iVar6 + uVar8 * 0xc + 0xe8))) {
            uVar9 = uVar9 + 1;
          }
          uVar8 = uVar8 + 1 & 0xffff;
        } while ((int)uVar8 < *(int *)(iVar6 + 0xd8));
      }
      *(uint *)(iVar6 + uVar7 * 0xc + 0xe4) = uVar9;
      uVar7 = uVar7 + 1 & 0xffff;
      iVar6 = *piRam02034014;
      iVar3 = *(int *)(iVar6 + 0xd8);
    } while ((int)uVar7 < iVar3);
  }
  piVar2 = piRam02034020;
  piVar1 = piRam02034014;
  iVar5 = *piRam02034018;
  if (*(char *)(iVar5 + 0x58) == '\0') {
    if (*(int *)(iVar5 + 8) == 2) {
      uVar7 = 0;
      if (0 < iVar3) {
        do {
          *(undefined4 *)(iVar6 + uVar7 * 0xc + 0xec) = *(undefined4 *)(*piVar2 + uVar7 * 4 + 0xec);
          uVar7 = uVar7 + 1 & 0xffff;
          iVar6 = *piVar1;
        } while ((int)uVar7 < *(int *)(iVar6 + 0xd8));
        return;
      }
    }
    else {
      uVar7 = 0;
      if (0 < iVar3) {
        do {
          iVar3 = GetSomeRacerPosition(uVar7);
          *(int *)(*piVar1 + uVar7 * 0xc + 0xec) = iVar3 + -1;
          uVar7 = uVar7 + 1 & 0xffff;
        } while ((int)uVar7 < *(int *)(*piVar1 + 0xd8));
      }
    }
    return;
  }
  if ((*(int *)(iVar5 + 8) == 2) && (*(int *)(iVar5 + 0x1c) == 1)) {
    func_02034188();
    return;
  }
  func_02034024();
  return;
}

