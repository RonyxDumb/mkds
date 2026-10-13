/* Decompiled C draft; module arm9_ov000; ROM address 02197634. No matching claim. */
#include "types.h"
#include "deps/02197634_FUN_02197634.h"

void FUN_02197634(void)

{
  if (*DAT_02197680 != -1) {
    FUN_0218e524(*DAT_02197680,2);
    FUN_0218e53c(*DAT_02197680);
  }
  *DAT_02197680 = -1;
  FUN_02196960();
  if (*DAT_02197684 != 0) {
    FUN_021a3668();
    *DAT_02197684 = 0;
    *DAT_02197688 = 0;
    *DAT_0219768c = 0;
  }
  return;
}

