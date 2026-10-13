/* Decompiled C draft; module arm9; ROM address 0204e128. No matching claim. */
#include "types.h"
#include "deps/0204e128_func_0204e128.h"

void func_0204e128(void)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  piVar1 = piRam0204e198;
  if (*(char *)(*piRam0204e198 + iRam0204e19c) == '\0') {
    func_02050e60(5);
    return;
  }
  *(undefined4 *)(*piRam0204e198 + 0xc) = 0x18;
  bVar3 = 1;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  cVar2 = '\0';
  *(undefined1 *)(*piVar1 + iRam0204e1a0) = 0;
  *(byte *)(*piVar1 + iRam0204e1a4) = *(byte *)(*piVar1 + iRam0204e1a4) | 1;
  do {
    iVar4 = func_02007d50(bVar3,2);
    if (iVar4 == 1) {
      cVar2 = cVar2 + '\x01';
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x10);
  if (cVar2 == '\0') {
    *(byte *)(*piRam0204e198 + iRam0204e1a4) = *(byte *)(*piRam0204e198 + iRam0204e1a4) & 0xfe;
  }
  return;
}

