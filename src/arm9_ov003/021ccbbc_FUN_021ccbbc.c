/* Decompiled C draft; module arm9_ov003; ROM address 021ccbbc. No matching claim. */
#include "types.h"
#include "deps/021ccbbc_FUN_021ccbbc.h"

void FUN_021ccbbc(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_8 [2];
  ushort local_6;
  
  FUN_021d2940((undefined2 *)(void *)(auStack_8));
  iVar3 = *DAT_021ccc00;
  bVar1 = *(byte *)(DAT_021ccc04 + (uint)*(byte *)(iVar3 + 0x1b));
  iVar2 = ((uint)local_6 - (uint)*(ushort *)(iVar3 + 0x12)) - (uint)(bVar1 >> 1);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else {
    iVar3 = (uint)*(byte *)(iVar3 + 0x19) - (uint)bVar1;
    if (iVar3 <= iVar2) {
      iVar2 = iVar3;
    }
  }
  FUN_021cca74(iVar2);
  *(undefined1 *)(*DAT_021ccc00 + 0x1d) = 3;
  return;
}

