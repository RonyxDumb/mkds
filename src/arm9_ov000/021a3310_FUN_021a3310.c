/* Decompiled C draft; module arm9_ov000; ROM address 021a3310. No matching claim. */
#include "types.h"
#include "deps/021a3310_FUN_021a3310.h"

undefined4 FUN_021a3310(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_20 [12];
  
  puVar1 = (undefined4 *)FUN_021a2fdc(param_2);
  iVar2 = FUN_0219c39c();
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_021a33e4(param_2,param_1);
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *puVar1 = param_3;
  puVar1[3] = 0;
  puVar1[5] = param_4;
  FUN_021a321c((undefined4 *)(void *)(auStack_20),param_1,param_4);
  FUN_021a2f98(param_2,(undefined4)(uintptr_t)(auStack_20),8,1);
  uVar3 = (uint)*(ushort *)(*DAT_021a33d8 + DAT_021a33dc);
  if ((int)param_4 <= (int)(uint)*(ushort *)(*DAT_021a33d8 + DAT_021a33dc)) {
    uVar3 = param_4;
  }
  iVar2 = FUN_021a2d18(param_2);
  if (iVar2 < (int)uVar3) {
    return 1;
  }
  FUN_021a2f98(param_2,param_3,uVar3,1);
  puVar1[3] = puVar1[3] + uVar3;
  if (puVar1[3] == puVar1[5]) {
    if ((*(code **)(*DAT_021a33d8 + DAT_021a33e0) != (code *)0x0) && (param_1 == 1)) {
      (**(code **)(*DAT_021a33d8 + DAT_021a33e0))(puVar1[5],param_2);
    }
    *(undefined1 *)(puVar1 + 7) = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[5] = 0;
  }
  return 1;
}

