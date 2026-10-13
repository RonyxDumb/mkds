/* Decompiled C draft; module arm9; ROM address 0200b72c. No matching claim. */
#include "types.h"
#include "deps/0200b72c_func_0200b72c.h"

undefined4 func_0200b72c(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = func_02143280();
  iVar2 = iRam0200b790;
  piVar1 = piRam0200b78c;
  if ((uVar3 != uRam0200b788) && (uVar3 != 0)) {
    *(short *)(*piRam0200b78c + iRam0200b790) = *(short *)(*piRam0200b78c + iRam0200b790) + 1;
    do {
      *(short *)(*piVar1 + iVar2) = *(short *)(*piVar1 + iVar2) + 1;
      if (0x10 < *(ushort *)(*piVar1 + iVar2)) {
        *(undefined2 *)(*piVar1 + iVar2) = 1;
      }
    } while ((uVar3 & 1 << (*(ushort *)(*piVar1 + iVar2) - 1 & 0xff)) == 0);
    return 1;
  }
  return 0;
}

