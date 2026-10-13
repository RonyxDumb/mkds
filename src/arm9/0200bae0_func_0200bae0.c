/* Decompiled C draft; module arm9; ROM address 0200bae0. No matching claim. */
#include "types.h"
#include "deps/0200bae0_func_0200bae0.h"

void func_0200bae0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0200bb84;
  if (*(int *)(*DAT_0200bb84 + DAT_0200bb88) == 0) {
    *(int *)(*DAT_0200bb84 + DAT_0200bb88) = 1;
    iVar2 = *piVar1;
    switch(*(undefined2 *)(iVar2 + DAT_0200bb8c)) {
    case 0:
      if (*(int *)(iVar2 + DAT_0200bb90) != 0) {
        *(int *)(iVar2 + DAT_0200bb90) = 0;
        return;
      }
      if (*(int *)(iVar2 + DAT_0200bb94) == 0) {
        func_0200bab0();
        return;
      }
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 0xe:
    case 0x13:
      func_0200bd7c();
      return;
    case 5:
    case 7:
    case 8:
    case 9:
      func_0200be00();
      return;
    case 10:
      break;
    case 0xb:
    case 0xc:
      func_0200bab0();
      return;
    default:
      Os_Terminate();
    }
  }
  return;
}

