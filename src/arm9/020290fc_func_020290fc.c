/* Decompiled C draft; module arm9; ROM address 020290fc. No matching claim. */
#include "types.h"
#include "deps/020290fc_func_020290fc.h"

int func_020290fc(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = -1;
  iVar5 = *piRam020291b4;
  uVar2 = GetDirectInputUnitIndex();
  if (*(int *)(*piRam020291b4 + iRam020291b8) == 0) {
    iVar3 = func_02028774();
    if (iVar3 != 0) {
      uVar4 = func_0202874c(uVar2);
      uVar2 = func_02028724(uVar2);
      iVar6 = func_020291c4(uVar4,uVar2,*(undefined4 *)(iVar5 + 0x74));
      piVar1 = piRam020291b4;
      *(undefined4 *)(*piRam020291b4 + iRam020291b8) = 1;
      *(undefined4 *)(*piVar1 + iRam020291c0) = 0;
    }
  }
  else {
    iVar3 = func_020291f0();
    piVar1 = piRam020291b4;
    if (iVar3 == 0) {
      *(undefined4 *)(*piRam020291b4 + iRam020291b8) = 0;
      *(undefined4 *)(*piVar1 + iRam020291c0) = 0;
    }
    else {
      uVar4 = func_0202874c(uVar2);
      uVar2 = func_02028724(uVar2);
      iVar5 = func_020291c4(uVar4,uVar2,*(undefined4 *)(iVar5 + 0x74));
      piVar1 = piRam020291b4;
      iVar3 = *piRam020291b4;
      if (iVar5 == *(int *)(iVar3 + iRam020291bc)) {
        *(int *)(iVar3 + iRam020291c0) = *(int *)(iVar3 + iRam020291c0) + 1;
        iVar6 = iVar5;
      }
      else {
        *(undefined4 *)(iVar3 + iRam020291b8) = 0;
        *(undefined4 *)(*piVar1 + iRam020291c0) = 0;
      }
    }
  }
  return iVar6;
}

