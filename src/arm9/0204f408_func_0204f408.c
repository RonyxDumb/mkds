/* Decompiled C draft; module arm9; ROM address 0204f408. No matching claim. */
#include "types.h"
#include "deps/0204f408_func_0204f408.h"

void func_0204f408(void)

{
  int *piVar1;
  
  piVar1 = piRam0204f450;
  *(undefined4 *)(*piRam0204f450 + 0xc) = 0x29;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  func_02006a10(uRam0204f454);
  piVar1 = piRam0204f450;
  *(undefined2 *)(*piRam0204f450 + iRam0204f458) = 0;
  *(byte *)(*piVar1 + iRam0204f45c) = *(byte *)(*piVar1 + iRam0204f45c) & 0xfe;
  *(ushort *)(*piVar1 + iRam0204f460) = *(ushort *)(*piVar1 + iRam0204f460) | (ushort)uRam0204f464;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  return;
}

