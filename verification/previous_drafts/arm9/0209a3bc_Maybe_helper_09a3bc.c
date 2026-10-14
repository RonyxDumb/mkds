/* Decompiled C draft; module arm9; ROM address 0209a3bc. No matching claim. */
#include "types.h"
#include "deps/0209a3bc_Maybe_helper_09a3bc.h"

void Maybe_helper_09a3bc(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_10),1);
  uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar1,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  DrawObject2DBB(param_1,*(uint *)(uRam0209a42c & 0xfffffffc) >> (uRam0209a42c & 3) * 8 |
                         *(uint *)(uRam0209a42c & 0xfffffffc) << (uRam0209a42c & 3) * -8 + 0x20,
                 param_2);
  return;
}

