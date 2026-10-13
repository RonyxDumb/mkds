/* Decompiled C draft; module arm9; ROM address 0200be00. No matching claim. */
#include "types.h"
#include "deps/0200be00_func_0200be00.h"

void func_0200be00(void)

{
  int *piVar1;
  int iVar2;
  undefined2 local_8;
  undefined2 local_6;
  
  *(undefined2 *)(*piRam0200be3c + 0x1c) = 1;
  iVar2 = func_02143dd0(uRam0200be40);
  piVar1 = piRam0200be3c;
  if (iVar2 != 2) {
    *(undefined2 *)(*piRam0200be3c + 0x1c) = 0;
    if (*(int *)*piVar1 != 0) {
      local_8 = 1;
      local_6 = (undefined2)iVar2;
      (**(code **)*piVar1)(0xff,&local_8);
    }
  }
  return;
}

