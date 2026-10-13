/* Decompiled C draft; module arm9_ov000; ROM address 02184354. No matching claim. */
#include "types.h"
#include "deps/02184354_FUN_02184354.h"

void FUN_02184354(void)

{
  func_0x0210895c();
  *DAT_02184390 =
       *DAT_02184390 & DAT_02184398 | ((*DAT_02184390 & DAT_02184394) >> 8 & 0xfffffff7) << 8;
  *DAT_0218439c = *DAT_0218439c & 0x43 | (ushort)DAT_021843a0;
  *DAT_021843a4 = 0;
  return;
}

