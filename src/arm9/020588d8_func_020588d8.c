/* Decompiled C draft; module arm9; ROM address 020588d8. No matching claim. */
#include "types.h"
#include "deps/020588d8_func_020588d8.h"

void func_020588d8(void)

{
  int *piVar1;
  byte *pbVar2;
  
  piVar1 = piRam02058900;
  *(undefined4 *)(*piRam02058900 + iRam02058904) = 0;
  pbVar2 = (byte *)(*piVar1 + iRam02058908);
  *pbVar2 = *pbVar2 & 0xfd;
  *(undefined1 *)(*piVar1 + iRam0205890c) = 0;
  return;
}

