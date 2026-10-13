/* Decompiled C draft; module arm9_ov001; ROM address 0219e1b0. No matching claim. */
#include "types.h"
#include "deps/0219e1b0_FUN_0219e1b0.h"

void FUN_0219e1b0(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219e1cc;
  *(int *)(*DAT_0219e1cc + 8) = *(int *)(*DAT_0219e1cc + 8) + 1;
  if ((int)(uint)*(ushort *)(DAT_0219e1d0 + 0xe) < *(int *)(*piVar1 + 8)) {
    *(undefined2 *)(*piVar1 + 0x14) = 0;
  }
  return;
}

