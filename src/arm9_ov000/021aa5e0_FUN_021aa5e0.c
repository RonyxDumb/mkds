/* Decompiled C draft; module arm9_ov000; ROM address 021aa5e0. No matching claim. */
#include "types.h"
#include "deps/021aa5e0_FUN_021aa5e0.h"

void FUN_021aa5e0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_48;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  char local_30;
  undefined1 auStack_2f [27];
  
  if (*(short *)((int)param_1 + 6) == 4) {
    local_48 = 0x10;
    local_44 = 0x10;
    local_40 = 0;
  }
  else if (*(short *)((int)param_1 + 6) == 5) {
    local_48 = 0x14;
    local_44 = 0x10;
    local_40 = 0;
  }
  iVar1 = (local_40 + local_48 + local_44) * 2;
  iVar6 = 0;
  if (0 < iVar1) {
    local_38 = 0;
    local_34 = 0;
    do {
      iVar4 = (int)param_1 + DAT_021aa798;
      FUN_021abd2c((undefined4 *)(uintptr_t)(iVar4));
      local_30 = (char)iVar6 + 'A';
      iVar5 = local_34;
      if (0 < iVar6 + 1) {
        do {
          FUN_021abca0(iVar4,(int)(uintptr_t)(&local_30),1);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar6 + 1);
      }
      FUN_021abca0(iVar4,*param_1 + 0x20,0x30);
      FUN_021abca0(iVar4,(int)(uintptr_t)(param_1 + 10),0x20);
      FUN_021abca0(iVar4,(int)(uintptr_t)(param_1 + 2),0x20);
      FUN_021abc4c(iVar4,(undefined4)(uintptr_t)(auStack_2f));
      iVar5 = (int)param_1 + DAT_021aa79c;
      FUN_021ab7b4((undefined4 *)(uintptr_t)(iVar5));
      FUN_021ab728(iVar5,*param_1 + 0x20,0x30);
      FUN_021ab728(iVar5,(int)(uintptr_t)(auStack_2f),0x14);
      FUN_021ab6d4(iVar5,(int)param_1 + local_38 + 0x48);
      local_38 = local_38 + 0x10;
      iVar6 = iVar6 + 1;
    } while (local_38 < iVar1);
  }
  if (*(char *)((int)param_1 + DAT_021aa7a0) == '\0') {
    param_1[0x24] = (int)(param_1 + 0x12);
    param_1[0x25] = param_1[0x24] + local_48 * 2;
    param_1[0x26] = param_1[0x25] + local_44 * 2;
    piVar2 = (int *)((int)param_1 + DAT_021aa7a4);
    *piVar2 = (int)(param_1 + 0x12) + local_48;
    piVar3 = (int *)((int)param_1 + DAT_021aa7a8);
    *piVar3 = *piVar2 + local_48 + local_44;
    *(int *)((int)param_1 + DAT_021aa7ac) = *piVar3 + local_44 + local_40;
  }
  else {
    piVar2 = (int *)((int)param_1 + DAT_021aa7a4);
    *piVar2 = (int)(param_1 + 0x12);
    piVar3 = (int *)((int)param_1 + DAT_021aa7a8);
    *piVar3 = *piVar2 + local_48 * 2;
    *(int *)((int)param_1 + DAT_021aa7ac) = *piVar3 + local_44 * 2;
    param_1[0x24] = (int)(param_1 + 0x12) + local_48;
    param_1[0x25] = param_1[0x24] + local_48 + local_44;
    param_1[0x26] = param_1[0x25] + local_44 + local_40;
  }
  FUN_021ac434((undefined1 *)(uintptr_t)((int)param_1 + DAT_021aa7b0),*(undefined4 *)((int)param_1 + DAT_021aa7a8),0x10);
  FUN_021ac434((undefined1 *)(void *)(param_1 + 0x27),param_1[0x25],0x10);
  return;
}

