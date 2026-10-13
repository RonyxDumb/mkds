/* Decompiled C draft; module arm9_ov000; ROM address 0218ab18. No matching claim. */
#include "types.h"
#include "deps/0218ab18_FUN_0218ab18.h"

void FUN_0218ab18(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = func_0x02139f70(param_3,DAT_0218ab8c);
  FUN_0218b148(param_2,param_3);
  if (iVar2 != 0) {
    bVar1 = *(byte *)(param_2 + 0x14);
    if ((bVar1 & 4) == 0) {
      *(byte *)(param_2 + 0x14) = bVar1 | 0x42;
    }
    else {
      *(byte *)(param_2 + 0x14) = bVar1 | 0x41;
    }
    *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) & 0xf3;
    iVar2 = FUN_0218e8c4();
    *(int *)(param_2 + 0x1c) = iVar2 - *(int *)(param_2 + 0x1c);
    FUN_0218ae68((int *)(uintptr_t)(param_1 + 8),param_2);
    (**(code **)(param_1 + 0x44))(param_1,0,param_2,*(undefined4 *)(param_1 + 0x48));
  }
  return;
}

