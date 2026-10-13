/* Decompiled C draft; module arm9_ov000; ROM address 02197594. No matching claim. */
#include "types.h"
#include "deps/02197594_FUN_02197594.h"

void FUN_02197594(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_13c [36];
  undefined1 auStack_118 [260];
  
  puVar4 = local_13c;
  iVar3 = 0x24;
  puVar5 = DAT_021975e8;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *DAT_021975f0 = DAT_021975ec;
  FUN_021971ec((int)(uintptr_t)(local_13c),0x23);
  uVar2 = func_0x02135014(auStack_118,local_13c,param_2,param_3,param_1);
  FUN_02196f8c((undefined4)(uintptr_t)(auStack_118),uVar2,param_1,param_4,param_5);
  return;
}

