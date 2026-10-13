/* Decompiled C draft; module arm9; ROM address 021171a0. No matching claim. */
#include "types.h"
#include "deps/021171a0_func_021171a0.h"

void func_021171a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  ushort param_5,int param_6)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0x12;
  if (param_6 == 0) {
    uVar1 = 0xe;
  }
  else if (param_6 == 1) {
    uVar1 = 0x1e;
  }
  param_1 = param_1 * 0xc;
  puVar2 = (undefined4 *)*piRam02117208;
  func_02124748(*(undefined2 *)(iRam0211720c + param_1),puVar2[1],*puVar2,puVar2[5],param_6,param_4,
                param_2,param_3);
  AllocateReserveTEQSub
            (uVar1,(uint)param_5 << 5,
             *(int *)(*(int *)(*piRam02117208 + *(int *)(iRam02117210 + param_1) * 4 + 8) + 0xc) +
             (uint)*(ushort *)(iRam02117214 + param_1) * 0x20,0x20);
  return;
}

