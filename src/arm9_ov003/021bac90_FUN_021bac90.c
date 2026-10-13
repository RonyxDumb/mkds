/* Decompiled C draft; module arm9_ov003; ROM address 021bac90. No matching claim. */
#include "types.h"
#include "deps/021bac90_FUN_021bac90.h"

void FUN_021bac90(undefined2 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined2 *)0x0) {
    switch(*param_1) {
    default:
      if ((code *)*DAT_021bb020 != (code *)0x0) {
        (*(code *)*DAT_021bb020)(1,0);
      }
      break;
    case 1:
      if (param_1[1] == 0) {
        iVar1 = *DAT_021bb01c;
        if (iVar1 == 4) {
          *DAT_021bb01c = 3;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(6);
            return;
          }
        }
        else if (iVar1 == 6) {
          iVar1 = func_0x021a61c4(*DAT_021bb024,*DAT_021bb028,*DAT_021bb02c);
          if (iVar1 != 3) {
            *DAT_021bb01c = 3;
            if ((code *)*DAT_021bb020 != (code *)0x0) {
              (*(code *)*DAT_021bb020)(2,0);
              return;
            }
          }
        }
        else if ((iVar1 == 8) &&
                (iVar1 = func_0x021a5e84(*DAT_021bb030,*DAT_021bb034,*DAT_021bb038), iVar1 != 3)) {
          *DAT_021bb01c = 3;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(2,0);
            return;
          }
        }
      }
      else {
        *DAT_021bb01c = 1;
        if ((code *)*DAT_021bb020 != (code *)0x0) {
          (*(code *)*DAT_021bb020)(2);
          return;
        }
      }
      break;
    case 2:
      if (param_1[1] == 0) {
        if (*DAT_021bb01c == 2) {
          func_0x021a6428();
          *DAT_021bb01c = 0;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(0x14);
            return;
          }
        }
      }
      else {
        *DAT_021bb01c = 3;
        if ((code *)*DAT_021bb020 != (code *)0x0) {
          (*(code *)*DAT_021bb020)(2);
          return;
        }
      }
      break;
    case 3:
      if (param_1[1] == 0) {
        if (*DAT_021bb01c == 6) {
          *DAT_021bb01c = 5;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(8);
            return;
          }
        }
      }
      else {
        *DAT_021bb01c = 3;
        if ((code *)*DAT_021bb020 != (code *)0x0) {
          (*(code *)*DAT_021bb020)(9);
          return;
        }
      }
      break;
    case 4:
      if (param_1[1] == 0) {
        iVar1 = *DAT_021bb01c;
        if (iVar1 == 4) {
          *DAT_021bb01c = 3;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(10);
            return;
          }
        }
        else if (iVar1 == 6) {
          iVar1 = func_0x021a61c4(*DAT_021bb024,*DAT_021bb028,*DAT_021bb02c);
          if (iVar1 != 3) {
            *DAT_021bb01c = 3;
            if ((code *)*DAT_021bb020 != (code *)0x0) {
              (*(code *)*DAT_021bb020)(2,0);
              return;
            }
          }
        }
        else if (iVar1 == 2) {
          iVar1 = func_0x021a61e4();
          if (iVar1 != 3) {
            *DAT_021bb01c = 3;
            if ((code *)*DAT_021bb020 != (code *)0x0) {
              (*(code *)*DAT_021bb020)(2,0);
              return;
            }
          }
        }
        else if ((iVar1 == 8) &&
                (iVar1 = func_0x021a5e84(*DAT_021bb030,*DAT_021bb034,*DAT_021bb038), iVar1 != 3)) {
          *DAT_021bb01c = 3;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(2,0);
            return;
          }
        }
      }
      else {
        *DAT_021bb01c = 3;
        if ((code *)*DAT_021bb020 != (code *)0x0) {
          (*(code *)*DAT_021bb020)(0xb);
          return;
        }
      }
      break;
    case 5:
      if (param_1[1] == 0) {
        if (*DAT_021bb01c == 8) {
          *DAT_021bb01c = 7;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(0xc);
            return;
          }
        }
      }
      else {
        *DAT_021bb01c = 3;
        if ((code *)*DAT_021bb020 != (code *)0x0) {
          (*(code *)*DAT_021bb020)(0xd);
          return;
        }
      }
      break;
    case 6:
      if (param_1[1] == 0) {
        iVar1 = *DAT_021bb01c;
        if (iVar1 == 4) {
          *DAT_021bb01c = 3;
          if ((code *)*DAT_021bb020 != (code *)0x0) {
            (*(code *)*DAT_021bb020)(0xe);
            return;
          }
        }
        else if (iVar1 == 6) {
          iVar1 = func_0x021a61c4(*DAT_021bb024,*DAT_021bb028,*DAT_021bb02c);
          if (iVar1 != 3) {
            *DAT_021bb01c = 3;
            if ((code *)*DAT_021bb020 != (code *)0x0) {
              (*(code *)*DAT_021bb020)(2,0);
              return;
            }
          }
        }
        else if (iVar1 == 2) {
          iVar1 = func_0x021a61e4();
          if (iVar1 != 3) {
            *DAT_021bb01c = 3;
            if ((code *)*DAT_021bb020 != (code *)0x0) {
              (*(code *)*DAT_021bb020)(2,0);
              return;
            }
          }
        }
        else {
          if (iVar1 != 8) {
            *DAT_021bb01c = 3;
            return;
          }
          iVar1 = func_0x021a5e84(*DAT_021bb030,*DAT_021bb034,*DAT_021bb038);
          if (iVar1 != 3) {
            *DAT_021bb01c = 3;
            if ((code *)*DAT_021bb020 != (code *)0x0) {
              (*(code *)*DAT_021bb020)(2,0);
              return;
            }
          }
        }
      }
      else {
        *DAT_021bb01c = 3;
        if ((code *)*DAT_021bb020 != (code *)0x0) {
          (*(code *)*DAT_021bb020)(0xf);
          return;
        }
      }
      break;
    case 7:
      if ((*DAT_021bb01c == 5) && ((code *)*DAT_021bb020 != (code *)0x0)) {
        (*(code *)*DAT_021bb020)(5);
        return;
      }
    }
  }
  return;
}

