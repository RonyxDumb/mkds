/* Decompiled C draft; module arm9_ov000; ROM address 0218af28. No matching claim. */
#include "types.h"
#include "deps/0218af28_FUN_0218af28.h"

undefined4 * FUN_0218af28(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_021a3690(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  uVar2 = FUN_0218e004(8,8,4,DAT_0218af98,DAT_0218af90,DAT_0218af94);
  puVar1[6] = uVar2;
  if (puVar1[6] == 0) {
    FUN_021a3668((undefined4)(uintptr_t)(puVar1));
    return (undefined4 *)0x0;
  }
  *(undefined1 *)(puVar1 + 5) = 0;
  *(undefined1 *)((int)puVar1 + 0x15) = 0;
  puVar1[8] = 0;
  puVar1[7] = 0;
  puVar1[4] = 0;
  *puVar1 = param_2;
  *(undefined2 *)(puVar1 + 1) = param_3;
  puVar1[2] = 0;
  *(undefined2 *)(puVar1 + 3) = 0;
  return puVar1;
}

