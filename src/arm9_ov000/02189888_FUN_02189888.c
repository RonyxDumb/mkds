/* Decompiled C draft; module arm9_ov000; ROM address 02189888. No matching claim. */
#include "types.h"
#include "deps/02189888_FUN_02189888.h"

undefined4 FUN_02189888(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(short *)(param_1 + DAT_021898d0) != 0) && (iVar2 = FUN_0218973c(2), iVar2 != 0)) {
    uVar1 = FUN_02189df8(0);
    *(undefined1 *)(param_1 + DAT_021898d4) = uVar1;
    return 5;
  }
  if (((uint)*(byte *)(param_1 + DAT_021898d8) << 0x18) >> 0x1c == 0) {
    uVar3 = FUN_02189c04(param_1);
    return uVar3;
  }
  return 6;
}

