/* Decompiled C draft; module arm9; ROM address 0211bf94. No matching claim. */
#include "types.h"
#include "deps/0211bf94_func_0211bf94.h"

void func_0211bf94(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int local_30;
  
  piVar4 = piRam0211c0b8;
  if (*(int *)(*piRam0211c0b8 + 0x78) == 2) {
    uVar8 = 0;
    local_30 = -1;
    piVar9 = piRam0211c0bc;
    do {
      iVar5 = *piVar9;
      bVar2 = false;
      iVar7 = iRam0211c0c0 + iVar5 * 0x5c;
      bVar1 = false;
      if ((*(short *)(iVar7 + 0x4c) == 0) && (bVar1 = bVar2, *(ushort *)(iVar7 + 0x58) < 5)) {
        bVar1 = true;
      }
      bVar3 = false;
      if (((!bVar1) && (bVar3 = bVar2, *(short *)(iVar7 + 0x54) == 0)) &&
         (*(short *)(iVar7 + 0x4c) != 0)) {
        bVar3 = true;
      }
      iVar6 = local_30;
      if (bVar3) {
        iVar6 = func_0201ea84(*(undefined4 *)(*piVar4 + 8),*(undefined2 *)(iVar7 + 0x48),
                              (uint)*(ushort *)(iVar7 + 0x4a) - (int)*(short *)(*piVar4 + 0x58));
      }
      iVar7 = func_020ae408(iVar5,uRam0211c0c4);
      if ((iVar7 == 0) && (iVar6 != 0x11)) {
        iVar5 = func_020ae408(iVar5,uRam0211c0c8);
        if ((iVar5 != 0) || (iVar6 == 0x12)) {
          if (uVar8 == 0) {
            if (iVar6 == 0x12) {
              *(undefined4 *)(*piVar4 + 0x60) = 4;
              *(undefined4 *)(*piVar4 + 0x7c) = 0;
            }
            if ((*(int *)(*piVar4 + 0x7c) == 0) && (*(int *)(*piVar4 + 0x60) == 4)) {
              func_0211d174(0,1);
            }
          }
          else {
            func_0211d174(uVar8 & 0xffff,1);
          }
        }
      }
      else if (uVar8 == 0) {
        if (iVar6 == 0x11) {
          *(undefined4 *)(*piVar4 + 0x60) = 4;
          *(undefined4 *)(*piVar4 + 0x7c) = 0;
        }
        if ((*(int *)(*piVar4 + 0x7c) == 0) && (*(int *)(*piVar4 + 0x60) == 4)) {
          func_0211d174(0,0);
        }
      }
      else {
        func_0211d174(uVar8 & 0xffff,0);
      }
      piVar9 = piVar9 + 1;
      uVar8 = uVar8 + 1;
    } while ((int)uVar8 < 8);
  }
  return;
}

