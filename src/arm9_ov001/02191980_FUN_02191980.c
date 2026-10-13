/* Decompiled C draft; module arm9_ov001; ROM address 02191980. No matching claim. */
#include "types.h"
#include "deps/02191980_FUN_02191980.h"

void FUN_02191980(int param_1)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a14),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a18));
  FUN_02188b78(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a1c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a20));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a24),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a28));
  FUN_02188950(param_1,&local_14);
  FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191a30),0,
               (undefined4 *)(uintptr_t)(param_1 + DAT_02191a34),DAT_02191a2c);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xec),DAT_02191a2c);
  *(undefined4 *)(param_1 + DAT_02191a38) = 0;
  return;
}

