/* Decompiled C draft; module arm9; ROM address 0204ebb8. No matching claim. */
#include "types.h"
#include "deps/0204ebb8_func_0204ebb8.h"

undefined4
func_0204ebb8(int param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4,
             undefined1 *param_5,undefined1 *param_6,undefined1 *param_7,undefined2 *param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = func_0204ff14();
  iVar2 = iRam0204ec24;
  piVar1 = piRam0204ec20;
  if (iVar3 == 0) {
    return 0;
  }
  param_1 = param_1 * 8;
  *param_3 = *(undefined1 *)(*(int *)(*piRam0204ec20 + iRam0204ec24) + param_1);
  *param_4 = *(undefined1 *)(*(int *)(*piVar1 + iVar2) + param_1 + 1);
  *param_5 = *(undefined1 *)(*(int *)(*piVar1 + iVar2) + param_1 + 2);
  *param_6 = *(undefined1 *)(*(int *)(*piVar1 + iVar2) + param_1 + 3);
  *param_7 = *(undefined1 *)(*(int *)(*piVar1 + iVar2) + param_1 + 4);
  *param_8 = *(undefined2 *)(*(int *)(*piVar1 + iVar2) + param_1 + 6);
  return 1;
}

