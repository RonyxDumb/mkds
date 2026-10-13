/* Decompiled C draft; module arm7; ROM address 0600ace4. No matching claim. */
#include "types.h"
#include "deps/0600ace4_FUN_0600ace4.h"

void FUN_0600ace4(void)

{
  short sVar1;
  uint uVar2;
  
  *DAT_0600ad6c = 0;
  FUN_06009a7c(8);
  *DAT_0600ad70 = 0;
  sVar1 = *(short *)((*(uint *)(DAT_0600ad74 & 0xfffffffc) >> (DAT_0600ad74 & 3) * 8 |
                     *(uint *)(DAT_0600ad74 & 0xfffffffc) << (DAT_0600ad74 & 3) * -8 + 0x20) + 0x5f8
                    );
  if (sVar1 == 2) {
    uVar2 = FUN_06009e98(1);
    FUN_06009e58(1,uVar2 & 0x7f);
    FUN_06009e58(1,uVar2);
    FUN_06009a7c(0x28);
    FUN_06009b04();
  }
  else if (sVar1 == 3) {
    FUN_06009b04();
  }
  return;
}

