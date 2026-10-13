/* Decompiled C draft; module arm9_ov000; ROM address 02189f00. No matching claim. */
#include "types.h"
#include "deps/02189f00_FUN_02189f00.h"

undefined4 FUN_02189f00(void)

{
  int iVar1;
  int iVar2;
  uint local_18 [4];
  
  iVar1 = FUN_021a5bfc();
  iVar2 = FUN_02188584(0x10);
  if (iVar1 != 1) {
    return 1;
  }
  local_18[0] = (uint)*(byte *)(iVar2 + DAT_02189f5c);
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  FUN_0218973c();
  iVar1 = FUN_021a629c((undefined4)(uintptr_t)(local_18),DAT_02189f60);
  if ((iVar1 != 1) && (iVar1 < 4)) {
    return 2;
  }
  FUN_02188508(1);
  return 0x11;
}

