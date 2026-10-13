/* Decompiled C draft; module arm9_ov003; ROM address 021b8990. No matching claim. */
#include "types.h"
#include "deps/021b8990_func_ov003_021b8990.h"

undefined4 func_ov003_021b8990(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar4 = (byte *)(param_1 + 6);
  do {
    uVar2 = func_ov003_021b7c44(*(undefined2 *)(pbVar4 + 2));
    bVar1 = *pbVar4;
    if (bVar1 < 0x22) {
      if (bVar1 < 0x21) {
        if (bVar1 < 0x16) {
          switch(bVar1) {
          case 0x10:
          case 0x11:
          case 0x12:
          case 0x13:
            if (5 < uVar2) {
              return 0xffffffff;
            }
            break;
          case 0x15:
            goto switchD_021b89c4_caseD_15;
          }
        }
        else if (bVar1 == 0x20) goto LAB_021b89fc;
      }
      else {
LAB_021b89fc:
        if (0xd < uVar2) {
          return 0xffffffff;
        }
      }
    }
    else if (bVar1 < 0x24) {
      if ((0x22 < bVar1) || (bVar1 == 0x22)) goto LAB_021b89fc;
    }
    else if (bVar1 == 0x25) {
switchD_021b89c4_caseD_15:
      if (0x21 < uVar2) {
        return 0xffffffff;
      }
    }
    if (bVar1 < 0x22) {
      if (bVar1 < 0x21) {
        if (bVar1 < 0x16) {
          switch(bVar1) {
          case 0x10:
            goto switchD_021b8a3c_caseD_10;
          case 0x11:
            goto switchD_021b8a3c_caseD_11;
          case 0x12:
            goto switchD_021b8a3c_caseD_12;
          case 0x13:
            goto switchD_021b8a3c_caseD_13;
          default:
            goto switchD_021b8a3c_caseD_14;
          case 0x15:
            goto switchD_021b8a3c_caseD_15;
          }
        }
        if (bVar1 != 0x20) {
switchD_021b8a3c_caseD_14:
          return 0xffffffff;
        }
switchD_021b8a3c_caseD_10:
        func_ov003_021b7d90(param_2 + 0x30,pbVar4 + 6,uVar2);
        *(uint *)(param_2 + 4) = uVar2;
      }
      else {
switchD_021b8a3c_caseD_11:
        func_ov003_021b7d90(param_2 + 0x70,pbVar4 + 6,uVar2);
        *(uint *)(param_2 + 4) = uVar2;
      }
    }
    else if (bVar1 < 0x24) {
      if (bVar1 < 0x23) {
        if (bVar1 != 0x22) {
          return 0xffffffff;
        }
switchD_021b8a3c_caseD_12:
        func_ov003_021b7d90(param_2 + 0xb0,pbVar4 + 6,uVar2);
        *(uint *)(param_2 + 4) = uVar2;
      }
      else {
switchD_021b8a3c_caseD_13:
        func_ov003_021b7d90(param_2 + 0xf0,pbVar4 + 6,uVar2);
        *(uint *)(param_2 + 4) = uVar2;
      }
    }
    else {
      if (bVar1 != 0x25) {
        return 0xffffffff;
      }
switchD_021b8a3c_caseD_15:
      if ((uVar2 != 0) && (pbVar4[uVar2 + 5] != 0)) {
        return 0xffffffff;
      }
      func_ov003_021b7d90(param_2 + 8,pbVar4 + 6,uVar2);
    }
    if (*(short *)(pbVar4 + 4) == 0) {
      return 0;
    }
    iVar3 = func_ov003_021b7c44();
    pbVar4 = (byte *)(param_1 + 6 + iVar3);
  } while( true );
}

