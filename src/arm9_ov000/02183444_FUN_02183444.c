/* Decompiled C draft; module arm9_ov000; ROM address 02183444. No matching claim. */
#include "types.h"
#include "deps/02183444_FUN_02183444.h"

void FUN_02183444(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*DAT_021834ac;
  if ((*piVar1 == 8) || (*piVar1 == 0xb)) {
    piVar1[0x12] = piVar1[0x12] + 1;
    if (0x3b < *(int *)(*DAT_021834ac + 0x48)) {
      *(undefined4 *)(*DAT_021834ac + 0x48) = 0;
    }
    iVar2 = *(int *)(*DAT_021834ac + 0x48);
    if (iVar2 < 0x14) {
      func_0x02133068(iVar2 << 0xc,0x14);
      FUN_021834b0();
      return;
    }
    if (iVar2 < 0x28) {
      func_0x02133068((0x28 - iVar2) * 0x1000,0x14);
      FUN_021834b0();
      return;
    }
    FUN_021834b0(0);
  }
  return;
}

