/* Decompiled C draft; module arm9; ROM address 0202ee3c. No matching claim. */
#include "types.h"
#include "deps/0202ee3c_func_0202ee3c.h"

void func_0202ee3c(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam0202ee64;
  for (iVar2 = 0; iVar2 < *(int *)*piVar1; iVar2 = iVar2 + 1) {
    iVar3 = *piVar1;
    *(undefined4 *)
     (*(int *)(iVar3 + 8) + (param_1 + (uint)*(ushort *)(*(int *)(iVar3 + 4) + iVar2 * 2)) * 0x40) =
         param_2;
  }
  return;
}

