/* Decompiled C draft; module arm9_ov000; ROM address 02191180. No matching claim. */
#include "types.h"
#include "deps/02191180_FUN_02191180.h"

undefined4 FUN_02191180(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(int *)(param_2 + 8) != 0) && (*(int *)(iVar1 + DAT_021911fc) == 0)) {
    FUN_021a3668(*(undefined4 *)(*(int *)(param_2 + 8) + 8));
    *(undefined4 *)(*(int *)(param_2 + 8) + 8) = 0;
    FUN_021a3668(*(undefined4 *)(*(int *)(param_2 + 8) + 0xc));
    *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = 0;
    FUN_021a3668(*(undefined4 *)(param_2 + 8));
    *(undefined4 *)(param_2 + 8) = 0;
  }
  FUN_021a3668(*(undefined4 *)(param_2 + 0x10));
  *(undefined4 *)(param_2 + 0x10) = 0;
  FUN_021a3668(*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  if ((*(int *)(param_2 + 0xc) != 0) &&
     ((*(int *)(iVar1 + DAT_021911fc) != 1 || (*(int *)(param_2 + 8) != 0)))) {
    return 1;
  }
  FUN_021948f8(param_1,param_2);
  return 0;
}

