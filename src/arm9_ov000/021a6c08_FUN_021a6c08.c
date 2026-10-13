/* Decompiled C draft; module arm9_ov000; ROM address 021a6c08. No matching claim. */
#include "types.h"
#include "deps/021a6c08_FUN_021a6c08.h"

void FUN_021a6c08(uint param_1)

{
  char extraout_r1;
  int extraout_r1_00;
  uint uVar1;
  char cVar2;
  
  if ((param_1 & 2) == 0) {
    cVar2 = (char)((int)param_1 >> 2) + '\x19';
  }
  else {
    cVar2 = (char)((param_1 << 0x16) >> 0x18);
  }
  uVar1 = (uint)*DAT_021a6c60;
  func_0x02133068(uVar1,0x10);
  *(char *)(DAT_021a6c64 + extraout_r1_00) = cVar2;
  if (0xf < uVar1) {
    func_0x02133068(uVar1 + 1,0x10);
    *DAT_021a6c60 = extraout_r1 + 0x10;
    return;
  }
  *DAT_021a6c60 = *DAT_021a6c60 + 1;
  return;
}

