/* Decompiled C draft; module arm9_ov003; ROM address 021cec00. No matching claim. */
#include "types.h"
#include "deps/021cec00_FUN_021cec00.h"

void FUN_021cec00(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_28;
  undefined1 auStack_20 [4];
  int local_1c [2];
  
  iVar1 = FUN_021d1970();
  iVar3 = 0;
  if (0 < iVar1) {
    local_28 = 0;
    do {
      FUN_021d1770(param_1,iVar3,(uint *)(void *)(auStack_20),local_1c);
      uVar2 = DAT_021cec4c;
      if ((param_2 <= local_1c[0]) && (local_1c[0] < 0xc0)) {
        uVar2 = local_28;
      }
      FUN_021d18f0(param_1,iVar3,uVar2,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

