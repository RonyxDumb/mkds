/* Decompiled C draft; module arm9; ROM address 0202b618. No matching claim. */
#include "types.h"
#include "deps/0202b618_func_0202b618.h"

void func_0202b618(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = piRam0202b694;
  iVar3 = *piRam0202b694;
  if (*(int *)(iVar3 + iRam0202b698) != param_1) {
    if (param_1 == 0) {
      for (iVar3 = *(int *)(iVar3 + 0x48); iVar3 < 8; iVar3 = iVar3 + 1) {
        func_0202cb2c(iVar3);
      }
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x48);
      if (iVar3 < 8) {
        iVar4 = iVar3 * 0x2c;
        do {
          if (*(int *)(*piVar1 + iRam0202b69c) == 0) {
            uVar2 = 0;
          }
          else if (*(int *)(*piVar1 + iVar4 + 0x4c) == 1) {
            uVar2 = 3;
          }
          else {
            uVar2 = 0;
          }
          func_0202cc44(iVar3,uVar2);
          func_0202cb68(iVar3);
          iVar4 = iVar4 + 0x2c;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 8);
      }
    }
  }
  *(int *)(*piRam0202b694 + iRam0202b698) = param_1;
  return;
}

