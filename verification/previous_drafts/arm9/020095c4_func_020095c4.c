/* Decompiled C draft; module arm9; ROM address 020095c4. No matching claim. */
#include "types.h"
#include "deps/020095c4_func_020095c4.h"

void func_020095c4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam020095f0;
  if (*(char *)(iRam020095f0 + 0xc) == '\x02') {
    iVar2 = *(int *)(iRam020095f0 + 4);
    if (*(char *)(iVar2 + iRam020095f4) == '\0') {
      *(undefined1 *)(iRam020095f0 + 0x10) = 9;
      *(int *)(iVar1 + 8) = iVar2;
    }
    else {
      *(undefined1 *)(iRam020095f0 + 0x10) = 4;
      *(int *)(iVar1 + 8) = iVar2 + iRam020095f8;
    }
    *(undefined1 *)(iRam020095f0 + 0xc) = 3;
  }
  return;
}

