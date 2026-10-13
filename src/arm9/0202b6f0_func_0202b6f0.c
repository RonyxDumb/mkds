/* Decompiled C draft; module arm9; ROM address 0202b6f0. No matching claim. */
#include "types.h"
#include "deps/0202b6f0_func_0202b6f0.h"

void func_0202b6f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_r6;
  
  iVar3 = iRam0202b7b4;
  piVar1 = piRam0202b7ac;
  if (*(int *)(*piRam0202b7ac + iRam0202b7b0) != param_1) {
    if (param_1 == 0) {
      iVar4 = 0;
      do {
        iVar2 = *piVar1;
        if ((iVar4 < *(int *)(iVar2 + 0x48)) || (*(int *)(iVar2 + iVar3) != 0)) {
          func_0202cc18(iVar4,1);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
      func_02025f14((int *)(uintptr_t)(*piRam0202b7ac + iRam0202b7b8),2);
      func_02025f14((int *)(uintptr_t)(*piRam0202b7ac + iRam0202b7bc),0);
    }
    else {
      iVar4 = 0;
      iVar3 = 0;
      do {
        iVar2 = *piVar1;
        if ((iVar4 < *(int *)(iVar2 + 0x48)) || (*(int *)(iVar2 + iRam0202b7b4) != 0)) {
          iVar2 = *(int *)(iVar2 + iVar3 + 0x4c);
          if (iVar2 == 0) {
            unaff_r6 = 1;
          }
          else if (iVar2 == 1) {
            unaff_r6 = 2;
          }
          func_0202cc18(iVar4,unaff_r6);
        }
        iVar3 = iVar3 + 0x2c;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
      func_02025f14((int *)(uintptr_t)(*piRam0202b7ac + iRam0202b7b8),0);
      func_02025f14((int *)(uintptr_t)(*piRam0202b7ac + iRam0202b7bc),2);
    }
  }
  *(int *)(*piRam0202b7ac + iRam0202b7b0) = param_1;
  return;
}

