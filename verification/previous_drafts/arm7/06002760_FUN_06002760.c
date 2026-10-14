/* Decompiled C draft; module arm7; ROM address 06002760. No matching claim. */
#include "types.h"
#include "deps/06002760_FUN_06002760.h"

undefined2 * FUN_06002760(undefined2 *param_1,int param_2)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x100;
  param_1[7] = 0x18;
  thunk_FUN_037fb230(param_2,param_1 + 8,0x30);
  *(undefined2 *)(param_2 + 2) = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  *(undefined2 *)(param_2 + 8) = 0;
  *(undefined2 *)(param_2 + 10) = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  *(undefined2 *)(param_2 + 0x10) = 0;
  *(undefined2 *)(param_2 + 0x12) = 0;
  *(undefined2 *)(param_2 + 0x14) = 0;
  *(undefined2 *)(param_2 + 0x16) = 0;
  *(undefined2 *)(param_2 + 0x24) = 0;
  *(undefined2 *)(param_2 + 0x26) = 0;
  *(undefined2 *)(param_2 + 0x28) = 0;
  *(undefined2 *)(param_2 + 0x2a) = 0;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 2;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

