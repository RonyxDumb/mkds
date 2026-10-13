/* Decompiled C draft; module arm9; ROM address 0202e9f0. No matching claim. */
#include "types.h"
#include "deps/0202e9f0_func_0202e9f0.h"

void func_0202e9f0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = GetDirectInputUnitIndex();
  iVar4 = *piRam0202ec70;
  if (*(int *)(iVar4 + iRam0202ec74) != 0) {
    if (*(int *)(iVar4 + 0x4c) < 3) {
      uVar3 = 0xf;
    }
    else {
      uVar3 = 5;
    }
    *(undefined4 *)(iVar4 + 0x48) = uVar3;
    iVar4 = func_0202ecd4(uVar2,1);
    piVar1 = piRam0202ec70;
    if (iVar4 == 0) {
      iVar4 = *piRam0202ec70;
      iVar7 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(iVar4 + 0x18);
      if (((iVar7 < iVar5) || (iVar5 + 5 <= iVar7)) || (*(int *)(iVar4 + 0x34) <= iVar7 - iVar5)) {
        iVar4 = func_0202ecd4(uVar2,0x40);
        piVar1 = piRam0202ec70;
        if ((((iVar4 == 0) &&
             (iVar4 = *piRam0202ec70, *(int *)(iVar4 + 0x20) != *(int *)(iVar4 + 0x10))) &&
            (*(int *)(iVar4 + 0x50) <= *(int *)(iVar4 + 0x48))) ||
           (iVar4 = *piRam0202ec70, *(int *)(iVar4 + 0x40) < 1)) {
          iVar4 = func_0202ecd4(uVar2,0x80);
          piVar1 = piRam0202ec70;
          if ((((iVar4 == 0) &&
               (iVar4 = *piRam0202ec70, *(int *)(iVar4 + 0x20) != *(int *)(iVar4 + 0x14))) &&
              (*(int *)(iVar4 + 0x54) <= *(int *)(iVar4 + 0x48))) ||
             (iVar4 = *piRam0202ec70, *(int *)(iVar4 + 0x34) + -1 <= *(int *)(iVar4 + 0x40))) {
            iVar4 = func_0202ec7c(uVar2,0xc0);
            if (iVar4 == 0) {
              iVar4 = *piRam0202ec70;
              if ((*(int *)(iVar4 + 0x1c) != *(int *)(iVar4 + 0x10)) &&
                 (*(int *)(iVar4 + 0x1c) != *(int *)(iVar4 + 0x14))) {
                *(undefined4 *)(iVar4 + 0x4c) = 0;
              }
            }
          }
          else {
            if (*(int *)(iVar4 + 0x44) == 4) {
              *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(iVar4 + 0x48);
              iVar4 = *piVar1;
              *(undefined4 *)(*(int *)(iVar4 + 8) + (uint)*(ushort *)(iVar4 + 0x2c) * 0x40) = 0;
              *(undefined4 *)(*piVar1 + iRam0202ec78) = 4;
              uVar2 = func_0202ee68();
              func_0202ee3c(uVar2,1);
              func_0202f120(0,0xffffffff,0xffffffff,0xffffffff);
              iVar4 = *piRam0202ec70;
              uVar2 = func_0202ee68();
              func_0202f120(2,uVar2,(*(int *)(iVar4 + 0x40) - *(int *)(iVar4 + 0x44)) + 5,0xffffffff
                           );
            }
            else {
              *(undefined4 *)(iVar4 + iRam0202ec78) = 2;
            }
            piVar1 = piRam0202ec70;
            *(undefined4 *)(*piRam0202ec70 + 0x54) = 0;
            iVar4 = *piVar1;
            *(int *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + 1;
            iVar4 = *piVar1;
            if (*(int *)(iVar4 + 0x1c) == *(int *)(iVar4 + 0x14)) {
              func_0202ed50(2);
            }
            func_0202ecac(3);
          }
        }
        else {
          if (*(int *)(iVar4 + 0x44) == 0) {
            *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(iVar4 + 0x48);
            *(undefined4 *)(*(int *)(*piVar1 + 8) + (uint)*(ushort *)(*piVar1 + 0x2c) * 0x40) = 0;
            *(undefined4 *)(*piVar1 + iRam0202ec78) = 3;
            func_0202ee3c(*(undefined4 *)(*piVar1 + 0x3c),1);
            func_0202f120(0,0xffffffff,0xffffffff,0xffffffff);
            iVar4 = *piRam0202ec70;
            func_0202f120(2,*(undefined4 *)(iVar4 + 0x3c),
                          (*(int *)(iVar4 + 0x40) - *(int *)(iVar4 + 0x44)) + -1,0xffffffff);
          }
          else {
            *(undefined4 *)(iVar4 + iRam0202ec78) = 1;
          }
          piVar1 = piRam0202ec70;
          *(undefined4 *)(*piRam0202ec70 + 0x50) = 0;
          iVar4 = *piVar1;
          *(int *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + 1;
          iVar4 = *piVar1;
          if (*(int *)(iVar4 + 0x1c) == *(int *)(iVar4 + 0x10)) {
            func_0202ed50(1);
          }
          func_0202ecac(3);
        }
      }
      else {
        *(undefined4 *)(iVar4 + iRam0202ec78) = 5;
        iVar4 = *piVar1;
        *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x20) - *(int *)(iVar4 + 0x18);
        iVar4 = *piVar1;
        uVar6 = (uint)(*(int *)(iVar4 + 0x24) != *(int *)(iVar4 + 0x44));
        *(uint *)(*(int *)(iVar4 + 8) + (uint)*(ushort *)(iVar4 + 0x2c) * 0x40) = uVar6;
        piVar1 = piRam0202ec70;
        *(undefined4 *)(*piRam0202ec70 + 0x38) = 10;
        *(undefined4 *)(*piVar1 + 0x54) = 0;
        *(undefined4 *)(*piVar1 + 0x50) = *(undefined4 *)(*piVar1 + 0x54);
        *(undefined4 *)(*piVar1 + 0x4c) = 0;
        iVar4 = *piVar1;
        *(int *)(iVar4 + 0x40) =
             *(int *)(iVar4 + 0x40) + (*(int *)(iVar4 + 0x24) - *(int *)(iVar4 + 0x44));
        *(undefined4 *)(*piVar1 + 0x44) = *(undefined4 *)(*piVar1 + 0x24);
        func_0202edd0();
        if (uVar6 == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = func_0202edfc();
        }
        func_0202f120(0,0xffffffff,0xffffffff,uVar2);
      }
    }
    else {
      *(undefined4 *)(*piRam0202ec70 + iRam0202ec78) = 5;
      *(undefined4 *)(*piVar1 + 0x24) = *(undefined4 *)(*piVar1 + 0x44);
      *(undefined4 *)(*(int *)(*piVar1 + 8) + (uint)*(ushort *)(*piVar1 + 0x2c) * 0x40) = 0;
      *(undefined4 *)(*piVar1 + 0x38) = 10;
      *(undefined4 *)(*piVar1 + 0x54) = 0;
      *(undefined4 *)(*piVar1 + 0x50) = *(undefined4 *)(*piVar1 + 0x54);
      *(undefined4 *)(*piVar1 + 0x4c) = 0;
      func_0202edd0();
      func_0202f120(0,0xffffffff,0xffffffff,0xffffffff);
    }
  }
  return;
}

