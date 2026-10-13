/* Decompiled C draft; module arm7; ROM address 037fe230. No matching claim. */
#include "types.h"
#include "deps/037fe230_FUN_037fe230.h"

void FUN_037fe230(byte *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_037fe270(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  *param_1 = *param_1 & 0xfe;
  return;
}

