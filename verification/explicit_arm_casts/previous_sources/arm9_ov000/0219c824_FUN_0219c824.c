/* Decompiled C draft; module arm9_ov000; ROM address 0219c824. No matching claim. */
#include "types.h"
#include "deps/0219c824_FUN_0219c824.h"

void FUN_0219c824(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219c8cc;
  *(undefined4 *)(*DAT_0219c8cc + 0x34) = 0;
  if (*param_2 == 0) {
    if (*(int *)(*piVar1 + 4) == 2) {
      FUN_0219d558(1,DAT_0219c8d0);
      iVar2 = FUN_0219c8dc();
      if (iVar2 == 0) {
        if (*(int *)(*(int *)(*DAT_0219c8cc + 0x20) + 0x1c) != param_2[1]) {
          FUN_0219c990(6,DAT_0219c8d4);
          return;
        }
        iVar2 = FUN_0219ba20();
        if ((iVar2 == 0) && (iVar2 = FUN_021a2768(param_2[1]), piVar1 = DAT_0219c8cc, iVar2 == 0)) {
          *(undefined4 *)(*DAT_0219c8cc + 4) = 5;
          (**(code **)(*piVar1 + 0x18))(0,param_2[1],*(undefined4 *)(*piVar1 + 0x1c));
          return;
        }
      }
    }
    else if (*(int *)(*piVar1 + 4) == 3) {
      FUN_0218eff8(param_1,param_2[1],0,0,DAT_0219c8d8,0);
      FUN_0219c8dc();
      return;
    }
  }
  else {
    FUN_0219c8dc(*param_2);
  }
  return;
}

