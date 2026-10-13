/* Decompiled C draft; module arm9_ov000; ROM address 02194af4. No matching claim. */
#include "types.h"
#include "deps/02194af4_FUN_02194af4.h"

undefined4 FUN_02194af4(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + DAT_02194b34) = 0;
  *(undefined4 *)(iVar3 + DAT_02194b38) = 0;
  iVar1 = FUN_0218e0e0(0x1c,4,DAT_02194b40,DAT_02194b44,DAT_02194b3c);
  piVar2 = (int *)(iVar3 + DAT_02194b48);
  *piVar2 = iVar1;
  if (*piVar2 != 0) {
    return 1;
  }
  return 0;
}

