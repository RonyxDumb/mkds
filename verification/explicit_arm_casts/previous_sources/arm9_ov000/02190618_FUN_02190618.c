/* Decompiled C draft; module arm9_ov000; ROM address 02190618. No matching claim. */
#include "types.h"
#include "deps/02190618_FUN_02190618.h"

undefined4
FUN_02190618(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_28 [20];
  
  *param_3 = 0;
  if ((4 < param_2[2]) &&
     (puVar1 = (undefined1 *)func_0x02139ffc(*param_2,10), puVar1 != (undefined1 *)0x0)) {
    iVar2 = func_0x0213a038(puVar1 + -5,DAT_021906d8,5);
    if (iVar2 != 0) {
      return 3;
    }
    *puVar1 = 0;
    iVar2 = FUN_021967b4(*param_2,DAT_021906dc,auStack_28,0x10);
    if (iVar2 == 0) {
      return 3;
    }
    uVar3 = func_0x0213bf90(auStack_28);
    *param_4 = uVar3;
    iVar2 = FUN_021967b4(*param_2,DAT_021906e0,auStack_28,0x10);
    if (iVar2 == 0) {
      return 3;
    }
    iVar2 = func_0x0213bf90(auStack_28);
    iVar4 = iVar2 + 1;
    if ((int)(puVar1 + (iVar4 - *param_2)) < param_2[2]) {
      if (puVar1[iVar4] != '\0') {
        return 3;
      }
      *param_3 = puVar1 + 1;
      *param_5 = iVar2;
      param_2[3] = (int)(puVar1 + (iVar4 - *param_2) + 1);
    }
    else {
      *puVar1 = 10;
    }
  }
  return 0;
}

