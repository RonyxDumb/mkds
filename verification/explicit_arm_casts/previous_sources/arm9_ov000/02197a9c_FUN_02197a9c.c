/* Decompiled C draft; module arm9_ov000; ROM address 02197a9c. No matching claim. */
#include "types.h"
#include "deps/02197a9c_FUN_02197a9c.h"

undefined1 * FUN_02197a9c(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_98 [132];
  
  iVar2 = func_0x0213a434(param_2);
  iVar3 = func_0x0213a434(param_1);
  if (0x7f < iVar2 + iVar3 + 0x14U) {
    iVar2 = 0x1d;
    puVar5 = param_3;
    puVar6 = DAT_02197b00;
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar5 = uVar1;
      puVar5 = puVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    return param_3;
  }
  func_0x02135014(auStack_98,DAT_02197b04,param_2,param_1);
  uVar4 = func_0x0213a434(auStack_98);
  FUN_0218e0fc(auStack_98,uVar4,param_3);
  return param_3;
}

