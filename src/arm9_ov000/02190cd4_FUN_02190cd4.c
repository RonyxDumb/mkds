/* Decompiled C draft; module arm9_ov000; ROM address 02190cd4. No matching claim. */
#include "types.h"
#include "deps/02190cd4_FUN_02190cd4.h"

undefined4 FUN_02190cd4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_1c;
  int local_18;
  
  iVar2 = DAT_02190d98;
  iVar6 = *param_1;
  if (param_2 != 0) {
    iVar3 = *(int *)(iVar6 + DAT_02190d98);
    piVar5 = (int *)(iVar6 + DAT_02190d9c);
    local_18 = *piVar5;
    *(int *)(iVar6 + DAT_02190d98) = 0;
    *piVar5 = 0;
    iVar2 = 0;
    iVar4 = iVar3;
    while (iVar1 = iVar2, iVar2 = iVar3, iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0x14);
      if ((*(int *)(iVar2 + 0x10) == param_2) || (*(int *)(iVar2 + 0xc) == 1)) {
        local_1c = iVar3;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 0x14) = iVar3;
          local_1c = iVar4;
        }
        if (local_18 == iVar2) {
          local_18 = iVar1;
        }
        FUN_02190da0(param_1);
        iVar2 = iVar1;
        iVar4 = local_1c;
      }
    }
    if (*(int *)(iVar6 + DAT_02190d98) == 0) {
      *(int *)(iVar6 + DAT_02190d98) = iVar4;
      *(int *)(iVar6 + DAT_02190d9c) = local_18;
    }
    else {
      piVar5 = (int *)(iVar6 + DAT_02190d9c);
      *(int *)(*piVar5 + 0x14) = iVar4;
      *piVar5 = local_18;
    }
    return 0;
  }
  iVar4 = *(int *)(iVar6 + DAT_02190d98);
  while (iVar4 != 0) {
    *(undefined4 *)(iVar6 + iVar2) = 0;
    *(undefined4 *)(iVar6 + DAT_02190d9c) = 0;
    while (iVar4 != 0) {
      iVar4 = *(int *)(iVar4 + 0x14);
      FUN_02190da0(param_1);
    }
    iVar4 = *(int *)(iVar6 + iVar2);
  }
  return 0;
}

