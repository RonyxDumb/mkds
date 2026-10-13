/* Decompiled C draft; module arm9; ROM address 0204e0bc. No matching claim. */
#include "types.h"
#include "deps/0204e0bc_func_0204e0bc.h"

void func_0204e0bc(void)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  piVar1 = piRam0204e11c;
  *(undefined4 *)(*piRam0204e11c + 0xc) = 0x19;
  bVar3 = 1;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  *(byte *)(*piVar1 + iRam0204e120) = *(byte *)(*piVar1 + iRam0204e120) | 2;
  cVar2 = '\0';
  *(undefined1 *)(*piVar1 + iRam0204e124) = 0;
  do {
    iVar4 = func_02007d50(bVar3,3);
    if (iVar4 == 1) {
      cVar2 = cVar2 + '\x01';
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x10);
  if (cVar2 == '\0') {
    *(byte *)(*piRam0204e11c + iRam0204e120) = *(byte *)(*piRam0204e11c + iRam0204e120) & 0xfd;
  }
  return;
}

