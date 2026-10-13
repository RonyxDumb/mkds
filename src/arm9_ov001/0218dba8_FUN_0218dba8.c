/* Decompiled C draft; module arm9_ov001; ROM address 0218dba8. No matching claim. */
#include "types.h"
#include "deps/0218dba8_FUN_0218dba8.h"

void FUN_0218dba8(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  piVar1 = (int *)(param_1 + DAT_0218dc08);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 1) {
    *piVar1 = 0;
    uVar4 = *(int *)(*(int *)(param_1 + 0xa4) + DAT_0218dc0c) - *(int *)(param_1 + DAT_0218dc0c) &
            0xffff;
    if (DAT_0218dc10 < (int)uVar4) {
      uVar4 = uVar4 - DAT_0218dc14;
    }
    uVar3 = *(uint *)(param_1 + DAT_0218dc18);
    uVar5 = -uVar3;
    if (((int)(uVar4 + uVar3) < 0 == SBORROW4(uVar4,-uVar3)) &&
       (uVar5 = uVar3, (int)uVar4 <= (int)uVar3)) {
      uVar5 = uVar4;
    }
    puVar2 = (uint *)(param_1 + DAT_0218dc0c);
    *puVar2 = *(int *)(param_1 + DAT_0218dc0c) + uVar5 & 0xffff;
    *(uint *)(param_1 + DAT_0218dc1c) = *puVar2;
  }
  return;
}

