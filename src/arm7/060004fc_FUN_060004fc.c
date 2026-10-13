/* Decompiled C draft; module arm7; ROM address 060004fc. No matching claim. */
#include "types.h"
#include "deps/060004fc_FUN_060004fc.h"

undefined4 FUN_060004fc(char *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_06000574 + 0x54cU & 3;
  uVar1 = *(uint *)(DAT_06000574 + 0x54cU & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((((*param_1 == *(char *)(uVar2 + 0xdc)) && (param_1[1] == *(char *)(uVar2 + 0xdd))) &&
      (param_1[2] == *(char *)(uVar2 + 0xde))) &&
     (((param_1[3] == *(char *)(uVar2 + 0xdf) && (param_1[4] == *(char *)(uVar2 + 0xe0))) &&
      (param_1[5] == *(char *)(uVar2 + 0xe1))))) {
    return 1;
  }
  return 0;
}

