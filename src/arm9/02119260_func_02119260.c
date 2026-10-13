/* Decompiled C draft; module arm9; ROM address 02119260. No matching claim. */
#include "types.h"
#include "deps/02119260_func_02119260.h"

void func_02119260(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021192c0;
  iVar2 = *DAT_021192c0;
  switch(*(undefined4 *)(iVar2 + 0x40)) {
  case 0:
  case 1:
  case 3:
    iVar2 = func_021277c8();
    if (iVar2 != 0) {
      func_02119a90();
      return;
    }
    break;
  case 2:
    *(int *)(iVar2 + 0x3c) = *(int *)(iVar2 + 0x3c) + 1;
    if ((0xe < *(int *)(*piVar1 + 0x3c)) &&
       ((iVar2 = func_021277c8(), iVar2 != 0 || (iVar2 = func_02127788(), iVar2 != 0)))) {
      func_02119a90();
    }
  }
  return;
}

