/* Decompiled C draft; module arm9; ROM address 02058a40. No matching claim. */
#include "types.h"
#include "deps/02058a40_func_02058a40.h"

void func_02058a40(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*piRam02058a90;
  if (piVar2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *piVar2;
  }
  if ((iVar1 == 1) && ((*(ushort *)((int)piVar2 + iRam02058a94) & 1) != 0)) {
    iVar1 = func_02050320(2,*(undefined1 *)(*piRam02058a90 + 0x87),
                          *(undefined1 *)(*piRam02058a90 + iRam02058a98));
    if (iVar1 != 0) {
      iVar1 = *piRam02058a90 + iRam02058a9c;
      *(undefined2 *)(iVar1 + 0x10) = 1;
      *(undefined2 *)(iVar1 + 0x12) = 1;
    }
  }
  return;
}

