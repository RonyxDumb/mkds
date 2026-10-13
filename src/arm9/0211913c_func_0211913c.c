/* Decompiled C draft; module arm9; ROM address 0211913c. No matching claim. */
#include "types.h"
#include "deps/0211913c_func_0211913c.h"

void func_0211913c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02119200;
  iVar2 = *DAT_02119200;
  switch(*(undefined4 *)(iVar2 + 0x40)) {
  case 0:
  case 1:
  case 3:
    iVar2 = func_021277ac();
    if (iVar2 != 0) {
      iVar2 = func_02127794();
      if (iVar2 != -1) {
        if (iVar2 == 0) {
          func_02119e50();
          *(undefined4 *)(*DAT_02119200 + 0x6c) = 1;
          func_021199f8();
          return;
        }
        if (iVar2 != 1) {
          return;
        }
      }
      func_02119bdc();
      return;
    }
    break;
  case 2:
    *(int *)(iVar2 + 0x3c) = *(int *)(iVar2 + 0x3c) + 1;
    if ((0xe < *(int *)(*piVar1 + 0x3c)) && (iVar2 = func_021277ac(), iVar2 != 0)) {
      iVar2 = func_02127794();
      if (iVar2 != -1) {
        if (iVar2 == 0) {
          func_02119e50();
          *(undefined4 *)(*DAT_02119200 + 0x6c) = 1;
          func_021199f8();
          if (*DAT_02119204 != 2) {
            return;
          }
          func_0211f378();
          return;
        }
        if (iVar2 != 1) {
          return;
        }
      }
      func_02119bdc();
    }
  }
  return;
}

