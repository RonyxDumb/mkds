/* Decompiled C draft; module arm9_ov000; ROM address 0218b668. No matching claim. */
#include "types.h"
#include "deps/0218b668_FUN_0218b668.h"

int FUN_0218b668(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,
                undefined4 param_9)

{
  int iVar1;
  
  if ((param_7 == 0) && (*DAT_0218b6ec != 1)) {
    return 0;
  }
  iVar1 = FUN_021a3690(DAT_0218b6f0);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + DAT_0218b6f4) = param_8;
  *(undefined4 *)(iVar1 + DAT_0218b6f8) = param_9;
  *(undefined4 *)(iVar1 + DAT_0218b6fc) = 0;
  FUN_0218cfb8((undefined4 *)(uintptr_t)(iVar1 + 0x4c),param_1,param_2,param_3,param_4,param_7,DAT_0218b700,iVar1);
  FUN_0218acf4((undefined4 *)(uintptr_t)(iVar1),param_5,param_6,param_7,DAT_0218b704,iVar1);
  return iVar1;
}

