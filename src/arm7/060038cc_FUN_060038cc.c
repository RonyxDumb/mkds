/* Decompiled C draft; module arm7; ROM address 060038cc. No matching claim. */
#include "types.h"
#include "deps/060038cc_FUN_060038cc.h"

undefined4 FUN_060038cc(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)(param_1 + 10);
  if (uVar1 == 0) {
    return 0;
  }
  if (uVar1 < 0x21) {
    iVar2 = 0;
    while( true ) {
      if ((int)uVar1 <= iVar2) {
        return 0;
      }
      if (*(char *)(param_1 + iVar2 + 0xc) != '\0') break;
      iVar2 = iVar2 + 1;
    }
    return 1;
  }
  return 0;
}

