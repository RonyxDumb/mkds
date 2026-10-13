/* Decompiled C draft; module arm9_ov001; ROM address 02191488. No matching claim. */
#include "types.h"
#include "deps/02191488_FUN_02191488.h"

/* WARNING: Removing unreachable block (ram,0x021914f8) */

void FUN_02191488(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191538);
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf0),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf4));
  FUN_02188950(param_1,&local_18);
  FUN_02188c90(param_1);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xfc));
  if (*(int *)(*DAT_0219153c + 8) == 4) {
    sVar1 = FUN_02181b54();
    uVar2 = FUN_02181b68(sVar1 + 2);
  }
  else {
    uVar2 = 0;
  }
  iVar3 = FUN_02188220(uVar2);
  if (iVar3 == 0) {
    FUN_02188db8(param_1,DAT_02191544);
  }
  else {
    FUN_02188db8(param_1,DAT_02191540);
  }
  *(undefined4 *)(param_1 + DAT_02191548) = 1;
  FUN_02188200(param_1,DAT_0219154c);
  return;
}

