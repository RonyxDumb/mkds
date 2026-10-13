/* Decompiled C draft; module arm9; ROM address 0204f468. No matching claim. */
#include "types.h"
#include "deps/0204f468_func_0204f468.h"

void func_0204f468(void)

{
  int *piVar1;
  
  piVar1 = piRam0204f4b4;
  *(undefined4 *)(*piRam0204f4b4 + 0xc) = 0x28;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  func_02006aac(uRam0204f4b8,0xe,uRam0204f4bc);
  piVar1 = piRam0204f4b4;
  *(undefined2 *)(*piRam0204f4b4 + iRam0204f4c0) = 0;
  *(byte *)(*piVar1 + iRam0204f4c4) = *(byte *)(*piVar1 + iRam0204f4c4) & 0xfe;
  *(ushort *)(*piVar1 + iRam0204f4c8) = *(ushort *)(*piVar1 + iRam0204f4c8) | (ushort)uRam0204f4cc;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  return;
}

