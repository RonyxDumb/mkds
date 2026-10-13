/* Decompiled C draft; module arm9_ov000; ROM address 0219735c. No matching claim. */
#include "types.h"
#include "deps/0219735c_FUN_0219735c.h"

undefined4 FUN_0219735c(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_dc [33];
  undefined1 local_bb [44];
  undefined1 auStack_8f [131];
  
  puVar4 = local_bb;
  iVar3 = 0x2c;
  puVar5 = DAT_0219740c;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *DAT_02197410 = 99;
  iVar3 = FUN_021970fc();
  if (iVar3 == 0) {
    FUN_0218e53c(*DAT_02197414);
    return 5;
  }
  uVar2 = func_0x0213a434();
  uVar2 = FUN_021971c8(iVar3,uVar2);
  uVar2 = func_0x02135014(auStack_8f,DAT_02197418,uVar2,DAT_0219741c);
  FUN_0218e0fc(auStack_8f,uVar2,auStack_dc);
  *DAT_02197424 = DAT_02197420;
  FUN_021971ec(local_bb,0x2b);
  uVar2 = func_0x02135014(auStack_8f,local_bb,DAT_02197428,auStack_dc,param_2);
  iVar3 = FUN_02197220(auStack_8f,uVar2);
  if (iVar3 < 1) {
    FUN_0218e53c(*DAT_02197414);
    return 3;
  }
  return 0;
}

