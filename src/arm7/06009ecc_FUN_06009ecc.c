/* Decompiled C draft; module arm7; ROM address 06009ecc. No matching claim. */
#include "types.h"
#include "deps/06009ecc_FUN_06009ecc.h"

void FUN_06009ecc(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(DAT_06009f5c & 0xfffffffc) >> (DAT_06009f5c & 3) * 8 |
          *(uint *)(DAT_06009f5c & 0xfffffffc) << (DAT_06009f5c & 3) * -8 + 0x20;
  FUN_060099bc();
  FUN_0600983c();
  FUN_0600a970(0x20);
  *(undefined2 *)(uVar2 + 1000) = 0;
  *(undefined2 *)(uVar2 + 0x356) = 0;
  *DAT_06009f60 = 0;
  *DAT_06009f64 = 0;
  *DAT_06009f68 = 0;
  *DAT_06009f6c = 0;
  *DAT_06009f70 = 0;
  *DAT_06009f74 = 0;
  if (*(short *)(uVar2 + 0x350) == 1) {
    FUN_06014228();
  }
  uVar1 = (undefined2)DAT_06009f78;
  *DAT_06009f7c = uVar1;
  *DAT_06009f80 = uVar1;
  FUN_06014464();
  FUN_06008cec();
  return;
}

