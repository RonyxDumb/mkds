/* Decompiled C draft; module arm9_ov003; ROM address 021bd4cc. No matching claim. */
#include "types.h"
#include "deps/021bd4cc_FUN_021bd4cc.h"

undefined4 FUN_021bd4cc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  int local_1c;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_3) {
    local_1c = 0;
    do {
      iVar1 = (int)*(char *)(param_2 + iVar3);
      if (iVar1 < 100) {
        if (0x62 < iVar1) goto LAB_021bd558;
        if (0x61 < iVar1) {
          if (iVar1 != 0x62) {
            return 0;
          }
          goto LAB_021bd558;
        }
        if (0x60 < iVar1) goto LAB_021bd558;
        switch(iVar1) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
          iVar2 = iVar2 + iVar1 + -0x30;
          break;
        default:
          goto switchD_021bd508_caseD_3a;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
          iVar2 = iVar2 + iVar1 + -0x37;
        }
      }
      else {
        if (iVar1 < 0x66) {
          if ((iVar1 < 0x65) && (iVar1 != 100)) {
switchD_021bd508_caseD_3a:
            return 0;
          }
        }
        else if (iVar1 != 0x66) {
          return 0;
        }
LAB_021bd558:
        iVar2 = iVar2 + iVar1 + -0x57;
      }
      func_0x02133068(iVar3,2);
      if (extraout_r1 == 0) {
        iVar2 = iVar2 << 4;
      }
      else {
        iVar1 = func_0x02133068(iVar3,2);
        *(char *)(param_1 + iVar1) = (char)iVar2;
        iVar2 = local_1c;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  return 1;
}

