/* Decompiled C draft; module arm9_ov001; ROM address 0219e310. No matching claim. */
#include "types.h"
#include "deps/0219e310_FUN_0219e310.h"

void FUN_0219e310(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = DAT_0219e344;
  *(int *)(*DAT_0219e344 + 8) = *(int *)(*DAT_0219e344 + 8) + 1;
  iVar2 = DAT_0219e348;
  piVar3 = (int *)*piVar1;
  if ((int)(uint)*(ushort *)(DAT_0219e348 + *piVar3 * 2) < piVar3[2]) {
    piVar3[1] = 2;
    *(undefined4 *)(*piVar1 + 8) = 0;
    func_0x02036f10((int)*(short *)(iVar2 + 4));
  }
  return;
}

