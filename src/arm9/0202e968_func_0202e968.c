/* Decompiled C draft; module arm9; ROM address 0202e968. No matching claim. */
#include "types.h"
#include "deps/0202e968_func_0202e968.h"

void func_0202e968(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = piRam0202e9a4;
  *(int *)(*piRam0202e9a4 + 0x44) = *(int *)(*piRam0202e9a4 + 0x44) + 1;
  *(int *)(*piVar1 + 0x40) = *(int *)(*piVar1 + 0x40) + 1;
  func_0202edd0();
  uVar2 = func_0202edfc();
  func_0202f120(0,0xffffffff,0xffffffff,uVar2);
  *(undefined4 *)(*piRam0202e9a4 + iRam0202e9a8) = 0;
  return;
}

