/* Decompiled C draft; module arm9_ov000; ROM address 021920d8. No matching claim. */
#include "types.h"
#include "deps/021920d8_FUN_021920d8.h"

void FUN_021920d8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int iVar3;
  
  iVar1 = DAT_02192108;
  iVar3 = 0;
  if (0 < param_2) {
    do {
      uVar2 = func_0x021384dc();
      func_0x02133274(uVar2,0x3e);
      *(undefined1 *)(param_1 + iVar3) = *(undefined1 *)(iVar1 + extraout_r1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  *(undefined1 *)(param_1 + iVar3) = 0;
  return;
}

