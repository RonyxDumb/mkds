/* Decompiled C draft; module arm9_ov000; ROM address 02182cb8. No matching claim. */
#include "types.h"
#include "deps/02182cb8_FUN_02182cb8.h"

void FUN_02182cb8(void)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_02182d20;
  *(int *)(*DAT_02182d20 + 0x10) = *(int *)(*DAT_02182d20 + 0x10) + 1;
  sVar3 = func_0x020ae4c0(1,DAT_02182d24,0,*(undefined4 *)(*piVar1 + 0x10),10);
  piVar1 = DAT_02182d20;
  iVar5 = 0;
  iVar4 = 0;
  do {
    if (iVar5 == 0) {
      *(short *)(*piVar1 + iVar4 + 0x14) = sVar3;
    }
    else {
      *(short *)(*piVar1 + iVar4 + 0x14) = -sVar3;
    }
    piVar2 = DAT_02182d20;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  if (9 < *(int *)(*DAT_02182d20 + 0x10)) {
    *(undefined4 *)(*DAT_02182d20 + 4) = 3;
    *(undefined4 *)(*piVar2 + 0x10) = 0;
    func_0x02128374();
  }
  return;
}

