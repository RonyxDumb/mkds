/* Decompiled C draft; module arm9_ov000; ROM address 021ac37c. No matching claim. */
#include "types.h"
#include "deps/021ac37c_FUN_021ac37c.h"

void FUN_021ac37c(undefined1 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar2 = 0;
  if (param_3 >> 2 != 0) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = (char)((uint)uVar1 >> 0x18);
      param_1[1] = (char)((uint)uVar1 >> 0x10);
      param_1[2] = (char)((uint)uVar1 >> 8);
      puVar3 = param_1 + 3;
      param_1 = param_1 + 4;
      *puVar3 = (char)uVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3 >> 2);
  }
  return;
}

