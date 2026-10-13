/* Decompiled C draft; module arm9; ROM address 02119e88. No matching claim. */
#include "types.h"
#include "deps/02119e88_func_02119e88.h"

void func_02119e88(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [36];
  
  if (*psRam0211a060 != 2) {
    iVar3 = *piRam0211a064;
    iVar1 = GetSelectedCup_from_thumb();
    uVar2 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(*piRam0211a064 + 0x28),
                       *(undefined2 *)
                        (*(short *)(iVar3 + 0x50) * 2 +
                        iRam0211a06c + *(int *)(iRam0211a068 + iVar1 * 4) * 8));
    func_0212426c(0,0,*(undefined4 *)(*piRam0211a064 + 8),uVar2,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x1c));
    iVar3 = *piRam0211a064;
    iVar1 = GetSelectedCup_from_thumb();
    uVar2 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(*piRam0211a064 + 0x28),
                       *(undefined2 *)
                        (*(short *)(iVar3 + 0x50) * 2 +
                        iRam0211a06c + *(int *)(iRam0211a068 + iVar1 * 4) * 8));
    func_0212426c(0,1,*(undefined4 *)(*piRam0211a064 + 8),uVar2,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x1c));
    iVar1 = GetSelectedCup_from_thumb();
    iVar1 = func_02060228(*(undefined4 *)
                           (*(short *)(*piRam0211a064 + 0x50) * 4 +
                           iRam0211a070 + *(int *)(iRam0211a068 + iVar1 * 4) * 0x10),0);
    if (iVar1 == 0) {
      iVar1 = *piRam0211a064;
      func_02124224(0,3,*(undefined4 *)(iVar1 + 8),uRam0211a074,*(undefined4 *)(iVar1 + 4),
                    *(undefined4 *)(iVar1 + 0x1c),9);
    }
    else {
      iVar1 = GetSelectedCup_from_thumb();
      func_02060134(*(undefined4 *)
                     (*(short *)(*piRam0211a064 + 0x50) * 4 +
                     iRam0211a070 + *(int *)(iRam0211a068 + iVar1 * 4) * 0x10),0,auStack_34);
      func_02116b80(auStack_34,auStack_30);
      iVar1 = *piRam0211a064;
      func_02124224(0,3,*(undefined4 *)(iVar1 + 8),auStack_30,*(undefined4 *)(iVar1 + 4),
                    *(undefined4 *)(iVar1 + 0x1c),9);
    }
    iVar1 = GetSelectedCup_from_thumb();
    iVar1 = func_02060228(*(undefined4 *)
                           (*(short *)(*piRam0211a064 + 0x50) * 4 +
                           iRam0211a070 + *(int *)(iRam0211a068 + iVar1 * 4) * 0x10),5);
    if (iVar1 == 0) {
      iVar1 = *piRam0211a064;
      func_02124224(0,5,*(undefined4 *)(iVar1 + 8),uRam0211a078,*(undefined4 *)(iVar1 + 4),
                    *(undefined4 *)(iVar1 + 0x1c),9);
    }
    else {
      iVar1 = GetSelectedCup_from_thumb();
      func_02060134(*(undefined4 *)
                     (*(short *)(*piRam0211a064 + 0x50) * 4 +
                     iRam0211a070 + *(int *)(iRam0211a068 + iVar1 * 4) * 0x10),5,auStack_34);
      func_02116b80(auStack_34,auStack_30);
      iVar1 = *piRam0211a064;
      func_02124224(0,5,*(undefined4 *)(iVar1 + 8),auStack_30,*(undefined4 *)(iVar1 + 4),
                    *(undefined4 *)(iVar1 + 0x1c),9);
    }
    iVar1 = GetSelectedCup_from_thumb();
    func_020d0efc(*(undefined4 *)
                   (*(short *)(*piRam0211a064 + 0x50) * 4 +
                   iRam0211a070 + *(int *)(iRam0211a068 + iVar1 * 4) * 0x10));
    *(undefined4 *)(*piRam0211a064 + 0x60) = 1;
  }
  return;
}

