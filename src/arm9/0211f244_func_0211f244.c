/* Decompiled C draft; module arm9; ROM address 0211f244. No matching claim. */
#include "types.h"
#include "deps/0211f244_func_0211f244.h"

void func_0211f244(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  ushort param_6,int param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0xe;
  if ((param_7 != 0) && (param_7 == 1)) {
    uVar1 = 0x1e;
  }
  puVar2 = (undefined4 *)*piRam0211f2a0;
  func_02124748(*(undefined2 *)(iRam0211f2a4 + param_1 * 2),puVar2[1],*puVar2,puVar2[3],param_7,
                param_5,param_3,param_4);
  AllocateReserveTEQSub
            (uVar1,(uint)param_6 << 5,
             *(int *)(*(int *)(*piRam0211f2a0 + 8) + 0xc) +
             (uint)*(ushort *)(iRam0211f2a8 + param_2 * 2) * 0x20,0x20);
  return;
}

