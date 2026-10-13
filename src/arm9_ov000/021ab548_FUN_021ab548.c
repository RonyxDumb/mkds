/* Decompiled C draft; module arm9_ov000; ROM address 021ab548. No matching claim. */
#include "types.h"
#include "deps/021ab548_FUN_021ab548.h"

undefined4 FUN_021ab548(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = *(int *)(param_1 + DAT_021ab58c);
  if (0 < iVar5) {
    puVar2 = *(undefined4 **)(param_1 + DAT_021ab590);
    puVar3 = puVar2;
    do {
      iVar1 = func_0x0213a074(*(undefined4 *)*puVar3,param_2);
      if (iVar1 == 0) {
        return puVar2[iVar4];
      }
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  return 0;
}

