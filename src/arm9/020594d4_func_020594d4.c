/* Decompiled C draft; module arm9; ROM address 020594d4. No matching claim. */
#include "types.h"
#include "deps/020594d4_func_020594d4.h"

void func_020594d4(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  
  piVar1 = piRam020594fc;
  *(undefined4 *)(*piRam020594fc + iRam02059500) = 0;
  pbVar2 = (byte *)(*piVar1 + iRam02059504);
  *pbVar2 = *pbVar2 & 0xfd;
  iVar3 = *piVar1 + iRam02059508;
  *(undefined2 *)(iVar3 + 0x10) = 0x12;
  *(undefined2 *)(iVar3 + 0x12) = 1;
  return;
}

