/* Decompiled C draft; module arm9_ov000; ROM address 02189df8. No matching claim. */
#include "types.h"
#include "deps/02189df8_FUN_02189df8.h"

int FUN_02189df8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_02188584(0x10);
  if (*(ushort *)(iVar1 + DAT_02189e50) == 0) {
    return -1;
  }
  uVar3 = 0;
  uVar2 = 0;
  do {
    if (((uint)*(ushort *)(iVar1 + DAT_02189e50) & 1 << uVar3) != 0) {
      if (uVar2 == param_1) {
        return (int)(char)uVar3;
      }
      uVar2 = uVar2 + 1 & 0xff;
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xd);
  return -1;
}

