/* Decompiled C draft; module arm9_ov003; ROM address 021d197c. No matching claim. */
#include "types.h"
#include "deps/021d197c_FUN_021d197c.h"

void FUN_021d197c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  uVar2 = DAT_021d19d0;
  uVar1 = DAT_021d19cc;
  puVar4 = *(uint **)(param_1 + 8);
  iVar3 = 0;
  if (*(char *)(param_1 + 0xc) != '\0') {
    do {
      *puVar4 = *puVar4 & uVar1 | uVar2;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 2;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0xc));
  }
  FUN_021d2e90(param_1);
  FUN_021d1d0c(*(undefined4 *)
                (*DAT_021d19d4 +
                 DAT_021d19d8 * (uint)((uint)(*DAT_021d19d4 + DAT_021d19d8) <= param_1) +
                DAT_021d19dc),param_1);
  return;
}

