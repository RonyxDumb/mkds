/* Decompiled C draft; module arm9_ov000; ROM address 021a0f20. No matching claim. */
#include "types.h"
#include "deps/021a0f20_FUN_021a0f20.h"

void FUN_021a0f20(int param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_1bc [256];
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8;
  undefined1 local_b7;
  undefined1 local_b6;
  char local_b5 [161];
  
  iVar5 = 7;
  local_bc = 8;
  local_bb = 10;
  local_ba = 0x32;
  local_b9 = 0x33;
  local_b8 = 0x34;
  local_b7 = 0x35;
  local_b6 = 0x36;
  if ((*(char *)(*DAT_021a1020 + 0x15) == '\0') || (*(char *)(*DAT_021a1020 + 0x15) == '\x01')) {
    iVar4 = 0;
    pcVar2 = local_b5;
    pcVar3 = DAT_021a1024;
    do {
      if (*pcVar3 != '\0') {
        *pcVar2 = *pcVar3;
        pcVar2 = pcVar2 + 1;
        iVar5 = iVar5 + 1;
      }
      pcVar3 = pcVar3 + 0xc;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x9a);
  }
  iVar4 = *DAT_021a1020;
  switch(*(undefined4 *)(iVar4 + DAT_021a1028)) {
  default:
switchD_021a0f8a_caseD_0:
    FUN_0218b48c(*(undefined4 *)(*DAT_021a1020 + 0xe4));
    iVar4 = 0;
    while( true ) {
      iVar1 = FUN_0218b570(*(undefined4 *)(*DAT_021a1020 + 0xe4),1,0,&local_bc,iVar5,auStack_1bc,
                           0x10);
      if (iVar1 == 0) {
        return;
      }
      if (iVar1 != 2) break;
      iVar4 = iVar4 + 1;
      if (4 < iVar4) {
        return;
      }
    }
    return;
  case 2:
  case 4:
  case 5:
    goto switchD_021a0f8a_caseD_2;
  case 3:
    param_1 = *(int *)(iVar4 + DAT_021a102c);
    if (param_1 == 0) {
      FUN_021a0ed8((undefined4)(uintptr_t)(auStack_1bc),*(undefined4 *)(iVar4 + DAT_021a1030),*(undefined1 *)(iVar4 + 0x16),
                   *(undefined1 *)(iVar4 + 0x15));
      if (*DAT_021a1034 != 0) {
        func_0x0200d9e0(auStack_1bc,DAT_021a1038,DAT_021a103c,auStack_1bc,*DAT_021a1034);
      }
      goto switchD_021a0f8a_caseD_0;
    }
switchD_021a0f8a_caseD_2:
    func_0x0200d9e0(auStack_1bc,DAT_021a1038,DAT_021a1040,DAT_021a1044,param_1);
    *(int *)(*DAT_021a1020 + DAT_021a1048) = param_1;
    goto switchD_021a0f8a_caseD_0;
  }
}

