/* Decompiled C draft; module arm9; ROM address 020062f4. No matching claim. */
#include "types.h"
#include "deps/020062f4_func_020062f4.h"

uint func_020062f4(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(int *)(param_1 + 0xc) + 1;
  if (*(int *)(param_1 + 4) <= (int)uVar3) {
    uVar3 = 0;
  }
  puVar1 = *(uint **)(param_1 + 0x14) + ((int)uVar3 >> 5);
  uVar2 = uVar3 & 0x1f;
  uVar4 = uVar3;
  do {
    if ((*puVar1 & 1 << (uVar2 & 0xff)) == 0) {
      *(uint *)(param_1 + 8) = uVar4;
      return uVar4;
    }
    uVar4 = uVar4 + 1;
    if ((int)uVar4 < *(int *)(param_1 + 4)) {
      uVar2 = uVar2 + 1;
      if (0x1f < (int)uVar2) {
        uVar2 = 0;
        puVar1 = puVar1 + 1;
      }
    }
    else {
      uVar4 = 0;
      uVar2 = 0;
      puVar1 = *(uint **)(param_1 + 0x14);
    }
  } while (uVar4 != uVar3);
  return 0xffffffff;
}

