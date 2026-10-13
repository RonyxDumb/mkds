/* Decompiled C draft; module arm9; ROM address 02099498. No matching claim. */
#include "types.h"
#include "deps/02099498_Maybe_helper_099498.h"

void Maybe_helper_099498(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,&local_10,1);
  uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar1,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  DrawObject2DBB(param_1,*(uint *)(uRam02099508 & 0xfffffffc) >> (uRam02099508 & 3) * 8 |
                         *(uint *)(uRam02099508 & 0xfffffffc) << (uRam02099508 & 3) * -8 + 0x20,
                 param_2);
  return;
}

