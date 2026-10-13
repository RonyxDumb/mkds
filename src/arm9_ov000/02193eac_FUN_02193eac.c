/* Decompiled C draft; module arm9_ov000; ROM address 02193eac. No matching claim. */
#include "types.h"
#include "deps/02193eac_FUN_02193eac.h"

undefined4 * FUN_02193eac(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  puVar1 = (undefined4 *)FUN_021a3690(0x40);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  func_0x02134de0(puVar1,0,0x40);
  *puVar1 = 100;
  puVar1[1] = param_3;
  puVar1[2] = 0xffffffff;
  puVar1[3] = param_2;
  iVar2 = FUN_0218e320();
  puVar1[4] = iVar2 + DAT_02193f0c;
  puVar1[0xf] = *(undefined4 *)(iVar4 + DAT_02193f10);
  uVar3 = FUN_0218dc94(0x18,0,DAT_02193f14);
  puVar1[0xe] = uVar3;
  *(undefined4 **)(iVar4 + DAT_02193f10) = puVar1;
  return puVar1;
}

