/* Decompiled C draft; module arm9_ov003; ROM address 021c25e0. No matching claim. */
#include "types.h"
#include "deps/021c25e0_FUN_021c25e0.h"

/* WARNING: Removing unreachable block (ram,0x021c2634) */

void FUN_021c25e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  byte local_10;
  char local_f [7];
  
  FUN_021d0ee0();
  iVar1 = *DAT_021c27a0;
  if ((*(char *)(iVar1 + DAT_021c27a4) == '\0') || (*(char *)(iVar1 + DAT_021c27a8) != '\0')) {
    FUN_021d0e9c(&local_10,local_f);
    if (local_10 < 0x1b) {
      if (local_10 < 0x1a) {
        switch(local_10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
          return;
        case 5:
          goto switchD_021c2642_caseD_5;
        case 0xc:
          if (local_f[0] == '\0') {
            return;
          }
          pcVar3 = *(code **)(*DAT_021c27a0 + DAT_021c27ac);
          if (pcVar3 == (code *)0x0) {
            *(undefined1 *)(*DAT_021c27a0 + DAT_021c27a4) = 1;
            return;
          }
          (*pcVar3)(2);
          return;
        case 0xd:
          if (local_f[0] == '\0') {
            return;
          }
          pcVar3 = *(code **)(*DAT_021c27a0 + DAT_021c27ac);
          if (pcVar3 == (code *)0x0) {
            *(undefined1 *)(*DAT_021c27a0 + DAT_021c27a4) = 1;
            return;
          }
          (*pcVar3)(1);
          return;
        default:
          if (local_10 != 0x17) {
            return;
          }
        case 0x14:
          if (local_f[0] == '\0') {
            return;
          }
          pcVar3 = *(code **)(*DAT_021c27a0 + DAT_021c27ac);
          if (pcVar3 == (code *)0x0) {
            *(undefined1 *)(*DAT_021c27a0 + DAT_021c27a4) = 1;
            return;
          }
          (*pcVar3)(3);
          return;
        }
      }
    }
    else {
      if (0x1d < local_10) {
        if (local_10 == 0x22) {
          FUN_021d34c8(0,param_1);
          FUN_021d2808(DAT_021c27a0);
          return;
        }
        return;
      }
      if (local_10 != 0x1d) {
        return;
      }
    }
    if (local_f[0] != '\0') {
      pcVar3 = *(code **)(*DAT_021c27a0 + DAT_021c27ac);
      if (pcVar3 == (code *)0x0) {
        *(undefined1 *)(*DAT_021c27a0 + DAT_021c27a4) = 1;
        return;
      }
      (*pcVar3)(4);
      return;
    }
  }
  else if (*(code **)(iVar1 + DAT_021c27ac) != (code *)0x0) {
    (**(code **)(iVar1 + DAT_021c27ac))(0);
    return;
  }
  return;
switchD_021c2642_caseD_5:
  if (local_f[0] == '\0') {
    return;
  }
  iVar1 = *DAT_021c27a0 + DAT_021c27b0;
  uVar2 = FUN_021d0e90();
  func_0x0214cffc(uVar2,iVar1,0x16);
  pcVar3 = *(code **)(*DAT_021c27a0 + DAT_021c27ac);
  if (pcVar3 == (code *)0x0) {
    *(undefined1 *)(*DAT_021c27a0 + DAT_021c27a4) = 1;
    return;
  }
  (*pcVar3)(0);
  return;
}

