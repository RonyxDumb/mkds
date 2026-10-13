/* Decompiled C draft; module arm9_ov000; ROM address 02196f8c. No matching claim. */
#include "types.h"
#include "deps/02196f8c_FUN_02196f8c.h"

void FUN_02196f8c(undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4,
                 undefined4 param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 local_28 [20];
  
  iVar5 = 0;
  puVar3 = local_28;
  iVar2 = 0x10;
  puVar4 = DAT_02197010;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*DAT_02197014 != -1) {
    iVar5 = FUN_02197220(param_1,param_2);
  }
  if (iVar5 < 1) {
    FUN_02197634();
    *DAT_0219701c = DAT_02197018;
    FUN_021971ec(local_28,0xf);
    if (param_4 != (code *)0x0) {
      (*param_4)(param_3,0,0,local_28,param_5);
      return;
    }
  }
  else {
    FUN_02197020(0,param_3,0,0,0,param_4,param_5);
  }
  return;
}

