/* Decompiled C draft; module arm9_ov000; ROM address 02196870. No matching claim. */
#include "types.h"
#include "deps/02196870_FUN_02196870.h"

undefined4 FUN_02196870(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [20];
  
  puVar3 = (undefined1 *)*param_1;
  iVar1 = func_0x0213a038(param_2,DAT_021968f4,7);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = FUN_021967b4(param_2,DAT_021968f8,auStack_28,0x10);
  if (iVar1 != 0) {
    uVar2 = func_0x0213bf90(auStack_28);
    *(undefined4 *)(puVar3 + DAT_021968fc) = uVar2;
  }
  iVar1 = FUN_021967b4(param_2,DAT_02196900,puVar3,DAT_02196904);
  if (iVar1 == 0) {
    *puVar3 = 0;
  }
  if (param_3 != 0) {
    iVar1 = func_0x02139f70(param_2,DAT_02196908);
    FUN_02190f4c(param_1,4,iVar1 != 0);
  }
  return 1;
}

