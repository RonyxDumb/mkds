/* Decompiled C draft; module arm9; ROM address 020adb04. No matching claim. */
#include "types.h"
#include "deps/020adb04_Title_CopyFunctionList_from_thumb.h"

void Title_CopyFunctionList_from_thumb(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = piRam020adb30;
  iVar1 = iRam020adb2c;
  iVar4 = 0;
  do {
    iVar3 = iVar4 * 8;
    *(undefined4 *)(*piVar2 + iVar3 + 0x14) = *(undefined4 *)(iVar1 + iVar3);
    *(undefined4 *)(*piVar2 + iVar3 + 0x18) = *(undefined4 *)(iVar1 + iVar3 + 4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  return;
}

