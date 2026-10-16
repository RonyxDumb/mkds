/* Decompiled C draft; module arm7; ROM address 037ff000. No matching claim. */
#include "types.h"
#include "deps/037ff000_FUN_037ff000.h"

bool FUN_037ff000(int param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,char *param_6)

{
  int iVar1;
  char cVar2;
  
  cVar2 = param_6[10];
  if (cVar2 == -1) {
    param_4 = 0xffffffff;
    cVar2 = '\0';
  }
  switch(*param_6) {
  case '\0':
  default:
    iVar1 = 0;
    break;
  case '\x01':
    goto LAB_037ff050;
  case '\x02':
    iVar1 = FUN_037fcd94((byte *)(uintptr_t)(param_1),*(undefined2 *)(param_6 + 2),param_4);
    break;
  case '\x03':
    iVar1 = FUN_037fcd48(param_1,param_4);
    break;
  case '\x04':
LAB_037ff050:
    if (*param_6 == '\x01') {
      iVar1 = FUN_037fefc0(param_5,*(undefined2 *)(param_6 + 4),*(undefined2 *)(param_6 + 2));
    }
    else {
      iVar1 = *(int *)(param_6 + 2);
    }
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_037fcde8(param_1,(undefined4 *)(uintptr_t)(iVar1),iVar1 + 0xc,param_4);
    }
  }
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 8) = param_2;
    *(char *)(param_1 + 5) = param_6[6];
    *(undefined1 *)(param_1 + 9) = param_3;
    FUN_037fcc70(param_1,param_6[7]);
    FUN_037fcc54(param_1,param_6[8]);
    FUN_037fcc4c(param_1,param_6[9]);
    FUN_037fcc30(param_1,cVar2);
    *(char *)(param_1 + 10) = param_6[0xb] + -0x40;
  }
  return iVar1 != 0;
}

