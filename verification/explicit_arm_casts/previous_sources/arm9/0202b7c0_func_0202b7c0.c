/* Decompiled C draft; module arm9; ROM address 0202b7c0. No matching claim. */
#include "types.h"
#include "deps/0202b7c0_func_0202b7c0.h"

void func_0202b7c0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  func_02025f14(*DAT_0202b86c + DAT_0202b870,2);
  func_02025f14(*DAT_0202b86c + DAT_0202b874,2);
  func_02025f14(*DAT_0202b86c + DAT_0202b878,2);
  iVar2 = DAT_0202b87c;
  piVar1 = DAT_0202b86c;
  switch(param_1) {
  case 0:
  case 1:
    iVar3 = 0;
    do {
      if ((iVar3 < *(int *)(*piVar1 + 0x48)) || (*(int *)(*piVar1 + iVar2) != 0)) {
        func_0202cc18(iVar3,1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    return;
  case 2:
    func_02025f14(*DAT_0202b86c + DAT_0202b880,2);
    return;
  case 3:
    iVar2 = 0;
    do {
      func_0202cb2c(iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    *(undefined4 *)(*DAT_0202b86c + DAT_0202b884) = 1;
  }
  return;
}

