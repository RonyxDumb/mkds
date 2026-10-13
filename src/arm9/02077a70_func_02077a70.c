/* Decompiled C draft; module arm9; ROM address 02077a70. No matching claim. */
#include "types.h"
#include "deps/02077a70_func_02077a70.h"

undefined4 func_02077a70(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_r5;
  
  iVar2 = _s32_div_f(param_2 & 0xffff,3);
  *param_1 = iVar2;
  if (7 < *param_1) {
    switch(*param_1) {
    case 8:
      unaff_r5 = 0x14;
      break;
    case 9:
      unaff_r5 = 0x15;
      break;
    case 10:
      unaff_r5 = 0x16;
      break;
    case 0xb:
      unaff_r5 = 0x17;
    }
    iVar2 = CheckSavedSecretFlag_from_thumb(unaff_r5);
    if (iVar2 == 0) {
      iVar2 = 0;
      *param_1 = -1;
      piVar1 = DAT_02077b14;
      do {
        iVar3 = func_0205fd2c(*(undefined4 *)(*piVar1 + DAT_02077b18),iVar2,param_2);
        if (iVar3 != 0) {
          *param_1 = iVar2;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 8);
      if (*param_1 == -1) {
        return 0;
      }
      return 1;
    }
  }
  uVar4 = func_0205fd2c(*(undefined4 *)(*DAT_02077b14 + DAT_02077b18),*param_1,param_2);
  return uVar4;
}

