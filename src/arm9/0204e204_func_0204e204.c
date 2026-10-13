/* Decompiled C draft; module arm9; ROM address 0204e204. No matching claim. */
#include "types.h"
#include "deps/0204e204_func_0204e204.h"

bool func_0204e204(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  ushort *puVar4;
  
  piVar2 = piRam0204e294;
  bVar1 = false;
  if (*psRam0204e290 == 2) {
    iVar3 = *(int *)(*piRam0204e294 + 0xc);
    if (iVar3 == 0) {
      puVar4 = (ushort *)(*piRam0204e294 + iRam0204e298);
      *puVar4 = *puVar4 | 0x40;
      *(undefined4 *)(*piVar2 + 4) = 1;
      func_020536e0();
    }
    else if (iVar3 == 1) {
      bVar1 = true;
    }
  }
  else {
    iVar3 = *(int *)(*piRam0204e294 + 0xc);
    if (iVar3 == 0) {
      puVar4 = (ushort *)(*piRam0204e294 + iRam0204e298);
      *puVar4 = *puVar4 | 0x40;
      *(undefined4 *)(*piVar2 + 4) = 1;
      func_020536e0();
    }
    else if (iVar3 == 1) {
      func_0204e4d8();
    }
    else if (iVar3 == 0x1c) {
      func_0204e498();
      bVar1 = true;
    }
  }
  if (bVar1) {
    *(undefined4 *)(*piRam0204e294 + 4) = 3;
  }
  return bVar1;
}

