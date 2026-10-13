/* Decompiled C draft; module arm9_ov000; ROM address 021a88a8. No matching claim. */
#include "types.h"
#include "deps/021a88a8_FUN_021a88a8.h"

undefined4 FUN_021a88a8(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar2 = func_0x0200fca0();
  puVar1 = DAT_021a88e0;
  uVar5 = *DAT_021a88e0;
  uVar4 = DAT_021a88e0[1];
  *DAT_021a88e0 = 0;
  puVar1[1] = 0;
  uVar3 = FUN_021acef8(param_1);
  puVar1 = DAT_021a88e0;
  *DAT_021a88e0 = uVar5;
  puVar1[1] = uVar4;
  func_0x0200fcb4(uVar2);
  return uVar3;
}

