/* Decompiled C draft; module arm9_ov001; ROM address 0219b418. No matching claim. */
#include "types.h"
#include "deps/0219b418_FUN_0219b418.h"

undefined4 * FUN_0219b418(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  puVar2 = (undefined4 *)func_0x02036bec(uVar1,0x2c);
  uVar1 = FUN_0219b4d8(param_2);
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036bec(uVar3,0x74);
  puVar2[5] = uVar3;
  func_0x0207afa8(puVar2[5],uVar1,0x3f);
  func_0x0209b8ac(puVar2,0);
  uVar1 = DAT_0219b474[1];
  puVar4 = DAT_0219b474 + 2;
  *puVar2 = *DAT_0219b474;
  puVar2[1] = uVar1;
  puVar2[2] = *puVar4;
  return puVar2;
}

