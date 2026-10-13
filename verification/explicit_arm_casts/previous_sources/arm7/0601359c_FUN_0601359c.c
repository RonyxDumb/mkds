/* Decompiled C draft; module arm7; ROM address 0601359c. No matching claim. */
#include "types.h"
#include "deps/0601359c_FUN_0601359c.h"

void FUN_0601359c(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  uint uVar2;
  
  thunk_FUN_037fb218(0,param_1,0x2c);
  uVar1 = FUN_0600a450();
  *(undefined2 *)(param_1 + 0x10) = uVar1;
  uVar2 = *(uint *)(DAT_060135f4 & 0xfffffffc) >> (DAT_060135f4 & 3) * 8 |
          *(uint *)(DAT_060135f4 & 0xfffffffc) << (DAT_060135f4 & 3) * -8 + 0x20;
  FUN_0600a8d4(param_1 + 0x18,param_2,uVar2 + 0x324,uVar2 + 0x3a8);
  return;
}

