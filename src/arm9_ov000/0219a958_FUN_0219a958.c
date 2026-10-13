/* Decompiled C draft; module arm9_ov000; ROM address 0219a958. No matching claim. */
#include "types.h"
#include "deps/0219a958_FUN_0219a958.h"

void FUN_0219a958(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (1 < *(int *)(param_1 + 0x10)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_3 + 4);
    *(ushort *)(param_1 + 0x30) =
         *(ushort *)(param_3 + 2) >> 8 | *(ushort *)(param_3 + 2) << 8 & (ushort)DAT_0219a9dc;
    *(undefined1 *)(param_1 + 0x32) = 1;
    if (*(char *)(param_2 + 0x12) == '\0') {
      FUN_0219ade4();
      return;
    }
    if (*(int *)(param_1 + 0x10) == 2) {
      if (*(char *)(param_1 + 0x33) == '\0') {
        FUN_0219ade4();
      }
      *(undefined4 *)(param_1 + 0x10) = 3;
      iVar1 = FUN_0218e8c4();
      *(int *)(param_1 + 0x28) = iVar1 + DAT_0219a9e0;
      if (*(int *)(param_1 + 4) != -1) {
        (**(code **)(param_1 + 0x38))
                  (0,*(int *)(param_1 + 4),param_3,*(undefined4 *)(param_1 + 0x3c));
        return;
      }
    }
    else if (*(char *)(param_2 + 0x13) == '\0') {
      FUN_0219ade4();
    }
  }
  return;
}

