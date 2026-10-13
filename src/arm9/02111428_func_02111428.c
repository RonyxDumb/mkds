/* Decompiled C draft; module arm9; ROM address 02111428. No matching claim. */
#include "types.h"
#include "deps/02111428_func_02111428.h"

void func_02111428(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0211144c;
  iVar2 = *(int *)(*piRam0211144c + 0x2c);
  if (0 < iVar2) {
    *(int *)(*piRam0211144c + 0x2c) = iVar2 + -1;
    if (*(int *)(*piVar1 + 0x2c) == 0) {
      (**(code **)(*piVar1 + 0x28))();
    }
  }
  return;
}

