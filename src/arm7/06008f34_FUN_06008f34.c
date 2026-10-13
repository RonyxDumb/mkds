/* Decompiled C draft; module arm7; ROM address 06008f34. No matching claim. */
#include "types.h"
#include "deps/06008f34_FUN_06008f34.h"

undefined4 FUN_06008f34(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(ushort *)((int)param_2 + 10) == DAT_06008fc4) {
    if ((short)param_2[2] == 0) {
      thunk_FUN_037f8850(0x1000000);
      if (*(short *)(param_1 + 2) == 0) {
        *param_2 = 0xffffffff;
        *param_1 = param_2;
      }
      else {
        uVar3 = (uint)(param_1 + 1) & 3;
        uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        *param_2 = uVar3;
        *(uint **)(uVar3 + 4) = param_2;
      }
      param_2[1] = 0xffffffff;
      *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)param_1 + 10);
      param_1[1] = param_2;
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
      thunk_FUN_037f888c();
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

