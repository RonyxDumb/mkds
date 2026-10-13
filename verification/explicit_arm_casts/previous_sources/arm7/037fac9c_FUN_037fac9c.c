/* Decompiled C draft; module arm7; ROM address 037fac9c. No matching claim. */
#include "types.h"
#include "deps/037fac9c_FUN_037fac9c.h"

void FUN_037fac9c(undefined4 *param_1,int param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_037faf70();
  if ((param_1 == (undefined4 *)0x0) ||
     (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0)) {
    FUN_037fb000();
  }
  uVar1 = *DAT_037fad30;
  iVar3 = FUN_037fa920((uint)uVar1);
  param_1[7] = 1;
  *(short *)(param_1 + 4) = (short)param_2;
  if (param_2 <= (int)(uint)uVar1) {
    iVar3 = iVar3 + 1;
  }
  param_1[3] = iVar3;
  *(undefined2 *)((int)param_1 + 0x12) = param_3;
  *param_1 = param_4;
  param_1[1] = param_5;
  param_1[9] = 0;
  FUN_037fae5c(param_1);
  FUN_037faf84(uVar2);
  return;
}

