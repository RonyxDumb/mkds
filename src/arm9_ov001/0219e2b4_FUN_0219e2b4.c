/* Decompiled C draft; module arm9_ov001; ROM address 0219e2b4. No matching claim. */
#include "types.h"
#include "deps/0219e2b4_FUN_0219e2b4.h"

void FUN_0219e2b4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_0219e2e8;
  *(int *)(*DAT_0219e2e8 + 8) = *(int *)(*DAT_0219e2e8 + 8) + 1;
  iVar2 = DAT_0219e2ec;
  iVar3 = *piVar1;
  if ((int)(uint)*(ushort *)(DAT_0219e2ec + 6) < *(int *)(iVar3 + 8)) {
    *(undefined4 *)(iVar3 + 4) = 4;
    *(undefined4 *)(*piVar1 + 8) = 0;
    func_0x020370d4((int)*(short *)(iVar2 + 8));
    FUN_0219e5a0();
  }
  return;
}

