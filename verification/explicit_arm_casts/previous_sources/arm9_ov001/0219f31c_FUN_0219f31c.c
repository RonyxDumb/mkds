/* Decompiled C draft; module arm9_ov001; ROM address 0219f31c. No matching claim. */
#include "types.h"
#include "deps/0219f31c_FUN_0219f31c.h"

undefined4 FUN_0219f31c(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_18 [4];
  
  piVar1 = DAT_0219f378;
  uVar3 = 1;
  iVar4 = 0;
  do {
    uVar2 = func_0x0205fd78((int)*(short *)(*piVar1 + 0x4c) + 1U & 0xff,iVar4 + 1U & 0xff,auStack_18
                           );
    uVar3 = uVar3 & uVar2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  iVar4 = func_0x0205fd78((int)*(short *)(*DAT_0219f378 + 0x4c) + 1U & 0xff,9,auStack_18);
  if ((uVar3 != 0) && (iVar4 == 0)) {
    return 1;
  }
  return 0;
}

