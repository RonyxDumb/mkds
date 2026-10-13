/* Decompiled C draft; module arm9_ov003; ROM address 021bfce0. No matching claim. */
#include "types.h"
#include "deps/021bfce0_FUN_021bfce0.h"

void FUN_021bfce0(int param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = DAT_021bffa4;
  piVar3 = DAT_021bffa0;
  cVar1 = *(char *)(*DAT_021bffa0 + DAT_021bffa4);
  *(undefined1 *)(*DAT_021bffa0 + DAT_021bffa4) =
       *(undefined1 *)(param_1 + DAT_021bffa8 + cVar1 * 4);
  iVar4 = *piVar3;
  cVar2 = *(char *)(iVar4 + iVar5);
  if ((cVar2 == '.') && (param_1 == 3)) {
    *(char *)(iVar4 + DAT_021bffac) = cVar1;
    goto LAB_021bff90;
  }
  if ((cVar2 == '3') && ((param_1 == 1 || (param_1 == 3)))) {
    *(char *)(iVar4 + DAT_021bffac) = cVar1;
    goto LAB_021bff90;
  }
  if ((cVar2 == '4') && ((param_1 == 1 || (param_1 == 3)))) {
    if (cVar1 != 0x2e) {
      *(char *)(iVar4 + DAT_021bffac) = cVar1;
    }
    goto LAB_021bff90;
  }
  if (cVar2 == -1) {
    if ((*(char *)(iVar4 + DAT_021bffac) == '#') || (*(char *)(iVar4 + DAT_021bffac) == '2')) {
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x23;
    }
    else {
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x22;
    }
    goto LAB_021bff90;
  }
  if (cVar2 != -2) {
    if (cVar2 != -3) {
      if (cVar2 != -4) {
        if (cVar2 != -5) goto LAB_021bff90;
        iVar5 = (int)*(char *)(iVar4 + DAT_021bffac);
        if (0x23 < iVar5) {
          if (iVar5 < 0x2b) {
            if (0x29 < iVar5) {
switchD_021bff16_caseD_7:
              *(undefined1 *)(iVar4 + DAT_021bffa4) = 7;
              goto LAB_021bff90;
            }
            if (iVar5 == 0x29) goto switchD_021bff16_caseD_6;
          }
          else if ((iVar5 < 0x33) && (0x2b < iVar5)) {
            if (iVar5 == 0x2c) goto switchD_021bff16_caseD_9;
            if (iVar5 == 0x2d) goto switchD_021bff16_caseD_a;
            if (iVar5 == 0x32) goto LAB_021bff82;
          }
          goto switchD_021bff16_caseD_0;
        }
        if (0x22 < iVar5) {
LAB_021bff82:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x32;
          goto LAB_021bff90;
        }
        if (iVar5 < 0xc) {
          switch(iVar5) {
          case 6:
switchD_021bff16_caseD_6:
            *(undefined1 *)(iVar4 + DAT_021bffa4) = 6;
            goto LAB_021bff90;
          case 7:
            goto switchD_021bff16_caseD_7;
          case 9:
switchD_021bff16_caseD_9:
            *(undefined1 *)(iVar4 + DAT_021bffa4) = 9;
            goto LAB_021bff90;
          case 10:
switchD_021bff16_caseD_a:
            *(undefined1 *)(iVar4 + DAT_021bffa4) = 10;
            goto LAB_021bff90;
          case 0xb:
switchD_021bff16_caseD_b:
            *(undefined1 *)(iVar4 + DAT_021bffa4) = 0xb;
            goto LAB_021bff90;
          }
        }
        else if (iVar5 == 0x22) goto switchD_021bff16_caseD_b;
switchD_021bff16_caseD_0:
        *(undefined1 *)(iVar4 + DAT_021bffa4) = 8;
        goto LAB_021bff90;
      }
      iVar5 = (int)*(char *)(iVar4 + DAT_021bffac);
      if (0x26 < iVar5) {
        if (iVar5 < 0x29) {
          if (0x27 < iVar5) {
switchD_021bfe98_caseD_5:
            *(undefined1 *)(iVar4 + DAT_021bffa4) = 5;
            goto LAB_021bff90;
          }
          if (iVar5 == 0x27) goto switchD_021bfe98_caseD_4;
        }
        else if (iVar5 == 0x31) {
switchD_021bfe98_caseD_0:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 0;
          goto LAB_021bff90;
        }
        goto switchD_021bfe98_caseD_2;
      }
      if (0x25 < iVar5) {
switchD_021bfe98_caseD_3:
        *(undefined1 *)(iVar4 + DAT_021bffa4) = 3;
        goto LAB_021bff90;
      }
      if (iVar5 < 6) {
        switch(iVar5) {
        case 0:
          goto switchD_021bfe98_caseD_0;
        case 1:
          goto switchD_021bfe98_caseD_1;
        default:
switchD_021bfe98_caseD_2:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 2;
          goto LAB_021bff90;
        case 3:
          goto switchD_021bfe98_caseD_3;
        case 4:
switchD_021bfe98_caseD_4:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 4;
          goto LAB_021bff90;
        case 5:
          goto switchD_021bfe98_caseD_5;
        }
      }
      if (iVar5 != 0x24) goto switchD_021bfe98_caseD_2;
switchD_021bfe98_caseD_1:
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 1;
      goto LAB_021bff90;
    }
    iVar5 = (int)*(char *)(iVar4 + DAT_021bffac);
    if (0x23 < iVar5) {
      if (iVar5 < 0x2b) {
        if (0x29 < iVar5) {
switchD_021bfdfc_caseD_7:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x2a;
          goto LAB_021bff90;
        }
        if (iVar5 == 0x29) goto switchD_021bfdfc_caseD_6;
      }
      else if ((iVar5 < 0x33) && (0x2b < iVar5)) {
        if (iVar5 == 0x2c) goto switchD_021bfdfc_caseD_9;
        if (iVar5 == 0x2d) goto switchD_021bfdfc_caseD_a;
        if (iVar5 == 0x32) goto switchD_021bfdfc_caseD_b;
      }
      goto switchD_021bfdfc_caseD_0;
    }
    if (iVar5 < 0x23) {
      if (iVar5 < 0xc) {
        switch(iVar5) {
        case 6:
switchD_021bfdfc_caseD_6:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x29;
          goto LAB_021bff90;
        case 7:
          goto switchD_021bfdfc_caseD_7;
        case 9:
switchD_021bfdfc_caseD_9:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x2c;
          goto LAB_021bff90;
        case 10:
switchD_021bfdfc_caseD_a:
          *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x2d;
          goto LAB_021bff90;
        case 0xb:
          goto switchD_021bfdfc_caseD_b;
        }
      }
      else if (iVar5 == 0x22) goto switchD_021bfdfc_caseD_b;
switchD_021bfdfc_caseD_0:
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x2b;
    }
    else {
switchD_021bfdfc_caseD_b:
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x2e;
    }
    goto LAB_021bff90;
  }
  iVar5 = (int)*(char *)(iVar4 + DAT_021bffac);
  if (0x26 < iVar5) {
    if (iVar5 < 0x29) {
      if (0x27 < iVar5) {
switchD_021bfd7e_caseD_5:
        *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x28;
        goto LAB_021bff90;
      }
      if (iVar5 == 0x27) goto switchD_021bfd7e_caseD_4;
    }
    else if (iVar5 == 0x31) {
switchD_021bfd7e_caseD_0:
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x31;
      goto LAB_021bff90;
    }
    goto switchD_021bfd7e_caseD_2;
  }
  if (0x25 < iVar5) {
switchD_021bfd7e_caseD_3:
    *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x26;
    goto LAB_021bff90;
  }
  if (iVar5 < 6) {
    switch(iVar5) {
    case 0:
      goto switchD_021bfd7e_caseD_0;
    case 1:
      goto switchD_021bfd7e_caseD_1;
    default:
switchD_021bfd7e_caseD_2:
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x25;
      goto LAB_021bff90;
    case 3:
      goto switchD_021bfd7e_caseD_3;
    case 4:
switchD_021bfd7e_caseD_4:
      *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x27;
      goto LAB_021bff90;
    case 5:
      goto switchD_021bfd7e_caseD_5;
    }
  }
  if (iVar5 != 0x24) goto switchD_021bfd7e_caseD_2;
switchD_021bfd7e_caseD_1:
  *(undefined1 *)(iVar4 + DAT_021bffa4) = 0x24;
LAB_021bff90:
  FUN_021bffb0();
  FUN_021cdc10(8);
  return;
}

