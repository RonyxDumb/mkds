/* Decompiled C draft; module arm9; ROM address 020aca24. No matching claim. */
#include "types.h"
#include "deps/020aca24_func_020aca24.h"

void func_020aca24(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 local_18 [8];
  
  puVar3 = local_18;
  iVar2 = 5;
  puVar4 = DAT_020aca9c;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (param_1 != 0) {
    switch(*(undefined4 *)(*DAT_020acaa0 + 0x54)) {
    default:
      SetSystemContextOverlayState(0);
      break;
    case 1:
      SetSystemContextOverlayState(2);
      func_020acaa4(0);
      break;
    case 2:
      SetSystemContextOverlayState(3);
    }
    *(undefined2 *)(param_1 + 4) = local_18[*(int *)(*DAT_020acaa0 + 0x54)];
    func_02105e98();
  }
  return;
}

