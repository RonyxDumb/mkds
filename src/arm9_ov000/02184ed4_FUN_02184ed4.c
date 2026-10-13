/* Decompiled C draft; module arm9_ov000; ROM address 02184ed4. No matching claim. */
#include "types.h"
#include "deps/02184ed4_FUN_02184ed4.h"

void FUN_02184ed4(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02184f18;
  *(int *)(*DAT_02184f18 + 0xc) = *(int *)(*DAT_02184f18 + 0xc) + 1;
  iVar2 = *piVar1;
  if (9 < *(int *)(iVar2 + 0xc)) {
    *(undefined4 *)(iVar2 + 4) = 5;
    if (*(int *)(*piVar1 + 0x10) == 0xb) {
      func_0x021282c8();
    }
    *(undefined4 *)(*DAT_02184f18 + 0xc) = 0;
    return;
  }
  if (4 < *(int *)(iVar2 + 0xc)) {
    *(undefined4 *)(iVar2 + 0x14) = 1;
  }
  return;
}

