/* Decompiled C draft; module arm9_ov000; ROM address 02189f64. No matching claim. */
#include "types.h"
#include "deps/02189f64_FUN_02189f64.h"

void FUN_02189f64(int param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(byte *)(param_1 + DAT_02189fcc) < 6) {
    iVar1 = FUN_021884d8();
    param_1 = param_1 + iVar1 * 0x100;
    if ((*(char *)(param_1 + 0xc0) == '\0') &&
       ((uint)*(byte *)(param_1 + 0xcb) +
        (uint)*(byte *)(param_1 + 0xca) +
        (uint)*(byte *)(param_1 + 200) + (uint)*(byte *)(param_1 + 0xc9) != 0)) {
      local_10 = FUN_0218a018((byte *)(uintptr_t)(param_1 + 200));
      local_c = FUN_0218a018((byte *)(uintptr_t)(param_1 + 0xcc));
      FUN_021a8e78(&local_10,&local_c);
    }
  }
  return;
}

