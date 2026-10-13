/* Decompiled C draft; module arm9; ROM address 0202e6c4. No matching claim. */
#include "types.h"
#include "deps/0202e6c4_func_0202e6c4.h"

void func_0202e6c4(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (*(int *)(*piRam0202e71c + 0x38) == 10) {
    *(undefined4 *)(*piRam0202e71c + iRam0202e720) = 1;
  }
  piVar1 = piRam0202e71c;
  *(int *)(*piRam0202e71c + 0x38) = *(int *)(*piRam0202e71c + 0x38) + -1;
  if (*(int *)(*piVar1 + 0x38) == 0) {
    uVar2 = func_0202edfc();
    func_0202f120(0,0xffffffff,0xffffffff,uVar2);
    piVar1 = piRam0202e71c;
    *(undefined4 *)(*(int *)(*piRam0202e71c + 8) + (uint)*(ushort *)(*piRam0202e71c + 0x2c) * 0x40)
         = 1;
    *(undefined4 *)(*piVar1 + iRam0202e724) = 0;
    *(undefined4 *)(*piVar1 + iRam0202e728) = 1;
  }
  return;
}

