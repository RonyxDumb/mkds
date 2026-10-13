/* Decompiled C draft; module arm7; ROM address 0601262c. No matching claim. */
#include "types.h"
#include "deps/0601262c_FUN_0601262c.h"

undefined4 FUN_0601262c(int param_1,int param_2)

{
  uint uVar1;
  
  *(undefined2 *)(param_2 + 2) = 1;
  *(short *)(param_1 + 0xc) = (short)DAT_06012688;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(param_1 + 0x16);
  FUN_0600ecf4();
  uVar1 = *(uint *)(DAT_0601268c & 0xfffffffc) >> (DAT_0601268c & 3) * 8 |
          *(uint *)(DAT_0601268c & 0xfffffffc) << (DAT_0601268c & 3) * -8 + 0x20;
  FUN_06009040(uVar1 + 0x200,uVar1 + 0x194,param_1);
  FUN_0601536c(0);
  return 0;
}

