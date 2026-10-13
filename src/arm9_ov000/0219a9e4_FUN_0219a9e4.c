/* Decompiled C draft; module arm9_ov000; ROM address 0219a9e4. No matching claim. */
#include "types.h"
#include "deps/0219a9e4_FUN_0219a9e4.h"

void FUN_0219a9e4(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_2 + 0x13) == '\0') {
    FUN_0219aa64((undefined4 *)(uintptr_t)(param_1),param_3);
  }
  if (*(int *)(param_1 + 0x10) < 2) {
    cVar1 = *(char *)(param_2 + 0x13);
    if (cVar1 != '\0') {
      uVar2 = 3;
      if (cVar1 == '\x01') {
        uVar2 = 1;
      }
      else if (cVar1 == '\x02') {
        uVar2 = 2;
      }
      (**(code **)(param_1 + 0x38))(uVar2,0xffffffff,0,*(undefined4 *)(param_1 + 0x3c));
      FUN_0219ac50(*(undefined4 *)(param_1 + 8));
      return;
    }
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0xc);
    *(ushort *)(param_1 + 0x30) =
         *(ushort *)(param_2 + 0x10) >> 8 | *(ushort *)(param_2 + 0x10) << 8 & (ushort)DAT_0219aa60;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x10) = 2;
    (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x3c));
    FUN_0219ade4((int *)(uintptr_t)(param_1));
  }
  return;
}

