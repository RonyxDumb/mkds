/* Decompiled C draft; module arm9_ov000; ROM address 02196e50. No matching claim. */
#include "types.h"
#include "deps/02196e50_FUN_02196e50.h"

void FUN_02196e50(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,code *param_7,undefined4 param_8,undefined4 param_9)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *local_25c;
  undefined1 local_254 [63];
  undefined1 auStack_215 [513];
  
  puVar4 = local_254;
  iVar3 = 0x3f;
  puVar5 = DAT_02196f74;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *DAT_02196f7c = DAT_02196f78;
  FUN_021971ec(local_254,0x3e);
  if ((param_3 == 0) || (param_3 == 2)) {
    if (param_7 != (code *)0x0) {
      (*param_7)(param_1,param_2,param_3,param_4,0,0,param_8);
      return;
    }
  }
  else {
    iVar3 = func_0x02135014(auStack_215,local_254,param_2,param_3,param_4,param_9,param_1,param_6);
    iVar2 = iVar3 + param_6;
    if (iVar2 < DAT_02196f80) {
      func_0x02134eb8(auStack_215 + iVar3,param_5,param_6);
      local_25c = auStack_215;
    }
    else {
      local_25c = (undefined1 *)FUN_021a3690(iVar2 + DAT_02196f84);
      func_0x02134eb8(local_25c,auStack_215,iVar3);
      func_0x02134eb8(local_25c + iVar3,param_5,param_6);
    }
    if (*DAT_02196f88 != -1) {
      iVar3 = FUN_02197220(local_25c,iVar2);
    }
    if (iVar3 < 1) {
      FUN_02197634();
      if (param_7 != (code *)0x0) {
        (*param_7)(param_1,param_2,param_3,param_4,0,0,param_8);
      }
    }
    else {
      FUN_02197020(2,param_1,param_2,param_3,param_4,param_7,param_8);
    }
    if (local_25c != auStack_215) {
      FUN_021a3668();
    }
  }
  return;
}

