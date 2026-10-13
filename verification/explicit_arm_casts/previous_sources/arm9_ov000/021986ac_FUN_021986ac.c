/* Decompiled C draft; module arm9_ov000; ROM address 021986ac. No matching claim. */
#include "types.h"
#include "deps/021986ac_FUN_021986ac.h"

undefined4 FUN_021986ac(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) < 5) {
    bVar1 = false;
    if (*(int *)(param_1 + 0x10) == 0) {
      if (*(int *)(param_1 + 0xc) < 4) {
        if (DAT_02198710 < (uint)(param_2 - *(int *)(param_1 + 0x1c))) {
          bVar1 = true;
        }
      }
    }
    else if (*(uint *)(param_1 + 0x20) != 0) {
      if (*(uint *)(param_1 + 0x20) < (uint)(param_2 - *(int *)(param_1 + 0x1c))) {
        bVar1 = true;
      }
    }
    if (bVar1) {
      FUN_02198b8c(param_1);
      FUN_02198514(param_1);
      iVar2 = FUN_021982f4(param_1,6,0,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

