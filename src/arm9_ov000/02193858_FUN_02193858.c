/* Decompiled C draft; module arm9_ov000; ROM address 02193858. No matching claim. */
#include "types.h"
#include "deps/02193858_FUN_02193858.h"

void FUN_02193858(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*param_2 == 3) {
    iVar2 = param_2[1];
    piVar1 = (int *)(*param_1 + DAT_021938c0);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      func_0x0213442c(DAT_021938c4,DAT_021938c8,0,0xb6);
    }
    FUN_0218e524(*(undefined4 *)(iVar2 + 4),2);
    FUN_0218e53c(*(undefined4 *)(iVar2 + 4));
    FUN_021a3668(*(undefined4 *)(iVar2 + 0x18));
    *(undefined4 *)(iVar2 + 0x18) = 0;
    FUN_021a3668(*(undefined4 *)(iVar2 + 8));
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  FUN_021a3668(param_2[1]);
  param_2[1] = 0;
  FUN_021a3668((undefined4)(uintptr_t)(param_2));
  return;
}

