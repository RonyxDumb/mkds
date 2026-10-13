/* Decompiled C draft; module arm9_ov003; ROM address 021bea3c. No matching claim. */
#include "types.h"
#include "deps/021bea3c_FUN_021bea3c.h"

void FUN_021bea3c(undefined2 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined2 *)0x0) {
    switch(*param_1) {
    default:
      if ((code *)*DAT_021bee20 != (code *)0x0) {
        (*(code *)*DAT_021bee20)(1,0);
      }
      break;
    case 1:
      if (param_1[1] == 0) {
        iVar1 = *DAT_021beddc;
        if (iVar1 == 4) {
          *DAT_021beddc = 3;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(6);
            return;
          }
        }
        else if (iVar1 == 6) {
          iVar1 = func_0x021a61c4(*DAT_021bede4,*DAT_021bede8,*DAT_021bedec);
          if (iVar1 != 3) {
            *DAT_021beddc = 3;
            if ((code *)*DAT_021bede0 != (code *)0x0) {
              (*(code *)*DAT_021bede0)(2,0);
              return;
            }
          }
        }
        else if ((iVar1 == 8) &&
                (iVar1 = func_0x021a5e84(*DAT_021bedf0,*DAT_021bedf4,*DAT_021bedf8), iVar1 != 3)) {
          *DAT_021beddc = 3;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(2,0);
            return;
          }
        }
      }
      else {
        *DAT_021beddc = 1;
        if ((code *)*DAT_021bede0 != (code *)0x0) {
          (*(code *)*DAT_021bede0)(2);
          return;
        }
      }
      break;
    case 2:
      if (param_1[1] == 0) {
        if (*DAT_021beddc == 2) {
          func_0x021a6428();
          *DAT_021beddc = 0;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(0x14);
            return;
          }
        }
      }
      else {
        *DAT_021beddc = 3;
        if ((code *)*DAT_021bede0 != (code *)0x0) {
          (*(code *)*DAT_021bede0)(2);
          return;
        }
      }
      break;
    case 3:
      if (param_1[1] == 0) {
        if (*DAT_021beddc == 6) {
          *DAT_021beddc = 5;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(8);
            return;
          }
        }
      }
      else {
        *DAT_021beddc = 3;
        if ((code *)*DAT_021bede0 != (code *)0x0) {
          (*(code *)*DAT_021bede0)(9);
          return;
        }
      }
      break;
    case 4:
      if (param_1[1] == 0) {
        iVar1 = *DAT_021beddc;
        if (iVar1 == 4) {
          *DAT_021beddc = 3;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(10);
            return;
          }
        }
        else if (iVar1 == 6) {
          iVar1 = func_0x021a61c4(*DAT_021bede4,*DAT_021bede8,*DAT_021bedec);
          if (iVar1 != 3) {
            *DAT_021beddc = 3;
            if ((code *)*DAT_021bede0 != (code *)0x0) {
              (*(code *)*DAT_021bede0)(2,0);
              return;
            }
          }
        }
        else if (iVar1 == 2) {
          iVar1 = func_0x021a61e4();
          if (iVar1 != 3) {
            *DAT_021beddc = 3;
            if ((code *)*DAT_021bede0 != (code *)0x0) {
              (*(code *)*DAT_021bede0)(2,0);
              return;
            }
          }
        }
        else if ((iVar1 == 8) &&
                (iVar1 = func_0x021a5e84(*DAT_021bedf0,*DAT_021bedf4,*DAT_021bedf8), iVar1 != 3)) {
          *DAT_021beddc = 3;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(2,0);
            return;
          }
        }
      }
      else {
        *DAT_021beddc = 3;
        if ((code *)*DAT_021bede0 != (code *)0x0) {
          (*(code *)*DAT_021bede0)(0xb);
          return;
        }
      }
      break;
    case 5:
      if (param_1[1] == 0) {
        if (*DAT_021beddc == 8) {
          *DAT_021beddc = 7;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(0xc);
            return;
          }
        }
      }
      else {
        *DAT_021beddc = 3;
        if ((code *)*DAT_021bede0 != (code *)0x0) {
          (*(code *)*DAT_021bede0)(0xd);
          return;
        }
      }
      break;
    case 6:
      if (param_1[1] == 0) {
        iVar1 = *DAT_021beddc;
        if (iVar1 == 4) {
          *DAT_021beddc = 3;
          if ((code *)*DAT_021bede0 != (code *)0x0) {
            (*(code *)*DAT_021bede0)(0xe);
            return;
          }
        }
        else if (iVar1 == 6) {
          iVar1 = func_0x021a61c4(*DAT_021bede4,*DAT_021bede8,*DAT_021bedec);
          if (iVar1 != 3) {
            *DAT_021beddc = 3;
            if ((code *)*DAT_021bede0 != (code *)0x0) {
              (*(code *)*DAT_021bede0)(2,0);
              return;
            }
          }
        }
        else if (iVar1 == 2) {
          iVar1 = func_0x021a61e4();
          if (iVar1 != 3) {
            *DAT_021beddc = 3;
            if ((code *)*DAT_021bede0 != (code *)0x0) {
              (*(code *)*DAT_021bede0)(2,0);
              return;
            }
          }
        }
        else if (iVar1 == 8) {
          iVar1 = func_0x021a5e84(*DAT_021bedf0,*DAT_021bedf4,*DAT_021bedf8);
          if (iVar1 != 3) {
            *DAT_021beddc = 3;
            if ((code *)*DAT_021bede0 != (code *)0x0) {
              (*(code *)*DAT_021bede0)(2,0);
              return;
            }
          }
        }
        else if (iVar1 == 7) {
          *DAT_021beddc = 3;
          return;
        }
      }
      else {
        *DAT_021beddc = 3;
        if ((code *)*DAT_021bede0 != (code *)0x0) {
          (*(code *)*DAT_021bede0)(0xf);
          return;
        }
      }
      break;
    case 7:
      if ((*DAT_021beddc == 5) && ((code *)*DAT_021bede0 != (code *)0x0)) {
        (*(code *)*DAT_021bede0)(5);
        return;
      }
      break;
    case 8:
      if ((code *)*DAT_021bede0 != (code *)0x0) {
        (*(code *)*DAT_021bede0)(4);
        return;
      }
      break;
    case 9:
      *DAT_021beddc = 0;
      if ((code *)*DAT_021bede0 != (code *)0x0) {
        (*(code *)*DAT_021bede0)(3);
        return;
      }
    }
  }
  return;
}

