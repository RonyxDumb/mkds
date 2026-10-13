/* Decompiled C draft; module arm9_ov000; ROM address 0219b05c. No matching claim. */
#include "types.h"
#include "deps/0219b05c_FUN_0219b05c.h"

int FUN_0219b05c(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar2 = FUN_0218e5e4();
  iVar1 = DAT_0219b0ac;
  if (iVar2 == 0) {
    return 0;
  }
  iVar6 = 0;
  while( true ) {
    piVar3 = *(int **)(*(int *)(iVar2 + 0xc) + iVar6);
    if (piVar3 == (int *)0x0) {
      return iVar7;
    }
    iVar5 = *piVar3;
    if ((iVar5 != iVar1) && (iVar4 = FUN_0218e57c(), iVar7 = iVar5, iVar4 != 0)) break;
    iVar6 = iVar6 + 4;
  }
  return iVar5;
}

