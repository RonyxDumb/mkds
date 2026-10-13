/* Decompiled C draft; module arm9_ov001; ROM address 0218dabc. No matching claim. */
#include "types.h"
#include "deps/0218dabc_FUN_0218dabc.h"

void FUN_0218dabc(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + DAT_0218dad4);
  *puVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa4) + DAT_0218dad4);
  *(undefined4 *)(param_1 + DAT_0218dad8) = *puVar1;
  return;
}

