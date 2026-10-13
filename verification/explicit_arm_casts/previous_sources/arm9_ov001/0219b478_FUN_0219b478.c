/* Decompiled C draft; module arm9_ov001; ROM address 0219b478. No matching claim. */
#include "types.h"
#include "deps/0219b478_FUN_0219b478.h"

undefined4 * FUN_0219b478(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  puVar2 = (undefined4 *)func_0x02036bec(uVar1,0x2c);
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  uVar1 = FUN_0219b4d8(param_2);
  puVar2[6] = uVar1;
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  uVar1 = func_0x02036bec(uVar1,0x6c);
  puVar2[4] = uVar1;
  func_0x02084e28(puVar2[4],puVar2[6]);
  func_0x0209b8ac(puVar2,0);
  uVar1 = DAT_0219b4d4[1];
  puVar3 = DAT_0219b4d4 + 2;
  *puVar2 = *DAT_0219b4d4;
  puVar2[1] = uVar1;
  puVar2[2] = *puVar3;
  return puVar2;
}

