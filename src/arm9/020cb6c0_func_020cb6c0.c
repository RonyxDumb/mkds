/* Decompiled C draft; module arm9; ROM address 020cb6c0. No matching claim. */
#include "types.h"
#include "deps/020cb6c0_func_020cb6c0.h"

void func_020cb6c0(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *DAT_020cb988;
  if (*(int *)(iVar4 + 0xc) != *(int *)(iVar4 + 8)) {
    switch(*(int *)(iVar4 + 0xc)) {
    case 4:
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0x021a1858(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990);
      break;
    case 5:
    case 8:
    case 0xf:
    case 0x15:
      iVar4 = GetPMaybeState_1();
      iVar5 = *DAT_020cb988;
      uVar3 = GetActiveExecutionContextHeapHandle();
      Maybe_select_character_s(uVar3,iVar4 != 0,iVar5 + DAT_020cb98c,iVar5 + DAT_020cb990);
      break;
    case 6:
    case 9:
    case 0x16:
      iVar4 = GetPMaybeState_1();
      iVar5 = *DAT_020cb988;
      uVar3 = GetActiveExecutionContextHeapHandle();
      Maybe_kart_select(uVar3,iVar4 != 0,iVar5 + DAT_020cb98c,iVar5 + DAT_020cb990);
      break;
    case 7:
      uVar3 = GetActiveExecutionContextHeapHandle();
      Maybe_menu(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,0);
      break;
    case 10:
      iVar4 = GetPMaybeState_1();
      if (iVar4 == 0) {
        uVar3 = 0;
      }
      else {
        iVar4 = func_020cae38();
        if (iVar4 == 0) {
          uVar3 = 4;
        }
        else {
          uVar3 = 2;
        }
      }
      iVar4 = *DAT_020cb988;
      uVar2 = GetActiveExecutionContextHeapHandle();
      Maybe_rule(uVar2,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,uVar3);
      break;
    case 0xb:
      iVar4 = GetPMaybeState_1();
      if (iVar4 == 0) {
        uVar3 = 2;
      }
      else {
        iVar4 = func_020cae38();
        if (iVar4 == 0) {
          uVar3 = 4;
        }
        else {
          uVar3 = 3;
        }
      }
      iVar4 = *DAT_020cb988;
      uVar2 = GetActiveExecutionContextHeapHandle();
      Maybe_menu(uVar2,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,uVar3);
      break;
    case 0xc:
    case 0x18:
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0211e958(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990);
      break;
    case 0xd:
      iVar4 = GetPMaybeState_1();
      if (iVar4 == 0) {
        uVar3 = 1;
      }
      else {
        iVar4 = func_020cae38();
        if (iVar4 == 0) {
          uVar3 = 3;
        }
        else {
          uVar3 = 2;
        }
      }
      iVar4 = *DAT_020cb988;
      uVar2 = GetActiveExecutionContextHeapHandle();
      Maybe_ghost(uVar2,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,uVar3);
      break;
    case 0xe:
      iVar4 = GetPMaybeState_1();
      iVar5 = *DAT_020cb988;
      uVar3 = GetActiveExecutionContextHeapHandle();
      Maybe_common_select_game_m_b(uVar3,iVar4 != 0,iVar5 + DAT_020cb98c,iVar5 + DAT_020cb990);
      break;
    case 0x10:
      iVar4 = GetPMaybeState_1();
      if (iVar4 == 0) {
        uVar3 = 1;
      }
      else {
        iVar4 = func_020cae38();
        if (iVar4 == 0) {
          uVar3 = 5;
        }
        else {
          uVar3 = 3;
        }
      }
      iVar4 = *DAT_020cb988;
      uVar2 = GetActiveExecutionContextHeapHandle();
      Maybe_rule(uVar2,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,uVar3);
      break;
    case 0x11:
      iVar4 = GetGlobalCA_from_thumb();
      iVar4 = *(int *)(iVar4 + 0xe4);
      iVar5 = *DAT_020cb988;
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0x0219d2c0(uVar3,iVar4 == 0,iVar5 + DAT_020cb98c,iVar5 + DAT_020cb990);
      break;
    case 0x12:
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0x0219f058(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990);
      break;
    case 0x13:
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0x021a0190(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990);
      break;
    case 0x14:
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0x02198100(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990);
      break;
    case 0x17:
      uVar3 = GetActiveExecutionContextHeapHandle();
      Maybe_menu(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,1);
      break;
    case 0x19:
      uVar3 = GetActiveExecutionContextHeapHandle();
      Maybe_ghost(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990,0);
      break;
    case 0x1a:
      uVar3 = GetActiveExecutionContextHeapHandle();
      func_0x0219bb48(uVar3,iVar4 + DAT_020cb98c,iVar4 + DAT_020cb990);
      break;
    case 0x1d:
      func_020cc744();
    }
    piVar1 = DAT_020cb988;
    switch(*(undefined4 *)(*DAT_020cb988 + 0xc)) {
    case 8:
    case 0xf:
      iVar4 = func_020cccb4();
      piVar1 = DAT_020cb988;
      if (iVar4 == 0xe) {
        *(undefined4 *)(*DAT_020cb988 + DAT_020cb994) = 0;
        *(undefined4 *)(*piVar1 + DAT_020cb998) = 0;
      }
      break;
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x10:
    case 0x11:
      *(undefined4 *)(*DAT_020cb988 + DAT_020cb994) = 0;
      *(undefined4 *)(*piVar1 + DAT_020cb998) = 0;
    }
  }
  return;
}

