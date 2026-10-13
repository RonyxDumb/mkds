/* Decompiled C draft; module arm9; ROM address 0211cea8. No matching claim. */
#include "types.h"
#include "deps/0211cea8_func_0211cea8.h"

undefined4 func_0211cea8(void)

{
  int iVar1;
  int iVar2;
  
  if (((*(int *)(*DAT_0211cfcc + 0x60) == 0) && (*(int *)(*DAT_0211cfcc + 0x68) == 3)) &&
     (iVar1 = CheckSecretFlag(0x10), iVar1 == 0)) {
    return 0;
  }
  iVar1 = *DAT_0211cfcc;
  switch(*(undefined4 *)(iVar1 + 0x2c)) {
  case 0:
    if ((*(int *)(iVar1 + 0x60) == 1) && (*(int *)(iVar1 + 0x6c) == 0)) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x60) == 4) && (*(int *)(iVar1 + 0x78) == 2)) {
      return 0;
    }
    break;
  case 1:
    iVar2 = *(int *)(iVar1 + 0x60);
    if ((iVar2 == 1) && (*(int *)(iVar1 + 0x6c) == 0)) {
      return 0;
    }
    if ((iVar2 == 3) && (*(int *)(iVar1 + 0x74) == 1)) {
      return 0;
    }
    if ((iVar2 == 4) && (*(int *)(iVar1 + 0x78) == 2)) {
      return 0;
    }
    break;
  case 2:
    if ((*(int *)(iVar1 + 0x60) == 4) && (*(int *)(iVar1 + 0x78) == 1)) {
      return 0;
    }
    break;
  case 3:
    if ((*(int *)(iVar1 + 0x60) == 3) && (*(int *)(iVar1 + 0x74) == 1)) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x60) == 4) && (*(int *)(iVar1 + 0x78) == 1)) {
      return 0;
    }
    break;
  case 4:
    if ((*(int *)(iVar1 + 0x60) == 4) && (*(int *)(iVar1 + 0x78) == 1)) {
      return 0;
    }
    break;
  case 5:
    if ((*(int *)(iVar1 + 0x60) == 3) && (*(int *)(iVar1 + 0x74) == 1)) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x60) == 4) && (*(int *)(iVar1 + 0x78) == 1)) {
      return 0;
    }
  }
  return 1;
}

