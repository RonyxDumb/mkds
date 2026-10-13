/* Decompiled C draft; module arm7; ROM address 06008fc8. No matching claim. */
#include "types.h"
#include "deps/06008fc8_FUN_06008fc8.h"

undefined4 FUN_06008fc8(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  thunk_FUN_037f8850(0x1000000);
  if (*(short *)(param_1 + 2) == 0) {
    *param_2 = 0xffffffff;
    *param_1 = param_2;
  }
  else {
    uVar2 = (uint)(param_1 + 1) & 3;
    uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    *param_2 = uVar2;
    *(uint **)(uVar2 + 4) = param_2;
  }
  param_2[1] = 0xffffffff;
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)param_1 + 10);
  *(short *)((int)param_2 + 10) = (short)DAT_0600903c;
  param_1[1] = param_2;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  thunk_FUN_037f888c();
  return 0;
}

