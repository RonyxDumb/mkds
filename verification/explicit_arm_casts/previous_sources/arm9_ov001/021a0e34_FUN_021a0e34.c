/* Decompiled C draft; module arm9_ov001; ROM address 021a0e34. No matching claim. */
#include "types.h"
#include "deps/021a0e34_FUN_021a0e34.h"

void FUN_021a0e34(void)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_18 [8];
  
  piVar1 = DAT_021a0e78;
  *(undefined4 *)(*DAT_021a0e78 + 0xa0) = 1;
  iVar4 = 0;
  do {
    uVar2 = func_0x02029608();
    uVar3 = func_0x0205fd78(uVar2,iVar4 + 1U & 0xff,auStack_18);
    *(uint *)(*piVar1 + 0xa0) = *(uint *)(*piVar1 + 0xa0) & uVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

