/* Decompiled C draft; module arm7; ROM address 037ff508. No matching claim. */
#include "types.h"
#include "deps/037ff508_FUN_037ff508.h"

void FUN_037ff508(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(DAT_037ff560 + param_1 * 0x40);
  if (*(char *)(DAT_037ff560 + param_1 * 0x40) != '\0') {
    FUN_037fa564(puVar1 + 0x14);
    *puVar1 = 0;
  }
  *(undefined4 *)(puVar1 + 4) = param_2;
  *(undefined4 *)(puVar1 + 8) = param_3;
  *(undefined4 *)(puVar1 + 0xc) = param_4;
  *(undefined4 *)(puVar1 + 0x10) = param_5;
  puVar1[1] = param_6;
  return;
}

