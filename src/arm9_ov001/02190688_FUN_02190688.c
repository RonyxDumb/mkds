/* Decompiled C draft; module arm9_ov001; ROM address 02190688. No matching claim. */
#include "types.h"
#include "deps/02190688_FUN_02190688.h"

/* WARNING: Removing unreachable block (ram,0x021906b4) */
/* WARNING: Removing unreachable block (ram,0x021906d8) */

undefined4 FUN_02190688(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = func_0x0207a974((short)*(char *)(*DAT_0219078c + 0x62));
  if (*(int *)(*DAT_0219078c + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_0219078c + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar5 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar5 = 0;
  }
  if (*(int *)(param_1 + 0xa8) == 4) {
    iVar6 = FUN_021871f8(uVar4,3);
    if (iVar6 != 0) {
      *(undefined4 *)(param_1 + 0xa8) = 5;
      FUN_02187218(param_1,3,DAT_02190790);
      FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02190794),DAT_02190798);
      FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar3 + 0x80));
      FUN_02191ecc(uVar4);
      FUN_02191f70(uVar5);
    }
  }
  else {
    iVar6 = FUN_021871f8(uVar5,3);
    if (iVar6 != 0) {
      *(undefined4 *)(param_1 + 0xa8) = 4;
      FUN_02187218(param_1,3,DAT_02190790);
      FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02190794),DAT_02190798);
      FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar3 + 0x80));
      FUN_02191f70(uVar4);
      FUN_02191ecc(uVar5);
    }
  }
  return 0;
}

