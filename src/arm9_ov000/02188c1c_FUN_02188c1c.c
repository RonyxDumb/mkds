/* Decompiled C draft; module arm9_ov000; ROM address 02188c1c. No matching claim. */
#include "types.h"
#include "deps/02188c1c_FUN_02188c1c.h"

undefined4 FUN_02188c1c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_02188584(0x10);
  if (((((*(byte *)(iVar1 + DAT_02188ca4) & 0xf) == 0) ||
       ((*(byte *)(iVar1 + DAT_02188ca4) & 0xf) == 4)) &&
      (((int)(uint)*(ushort *)(param_1 + 0x2c) >> 4 & 1U) == 1)) &&
     (iVar2 = FUN_0218a658(param_1 + 0xc), iVar2 == 1)) {
    return 6;
  }
  if ((((*(byte *)(iVar1 + DAT_02188ca4) & 0xf) == 0) ||
      ((*(byte *)(iVar1 + DAT_02188ca4) & 0xf) == 5)) &&
     ((((int)(uint)*(ushort *)(param_1 + 0x2c) >> 4 & 1U) == 1 &&
      (iVar1 = FUN_0218a6c8(param_1 + 0xc), iVar1 == 1)))) {
    return 7;
  }
  return 0xffffffff;
}

