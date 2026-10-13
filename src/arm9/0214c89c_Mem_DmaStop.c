/* Decompiled C draft; module arm9; ROM address 0214c89c. No matching claim. */
#include "types.h"
#include "deps/0214c89c_Mem_DmaStop.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Mem_DmaStop(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = Os_DisableIrq();
  iVar1 = (param_1 * 6 + 5) * 2;
  *(ushort *)(&DAT_040000b0 + iVar1) = *(ushort *)(&DAT_040000b0 + iVar1) & 0xc5ff;
  *(ushort *)(&DAT_040000b0 + iVar1) = *(ushort *)(&DAT_040000b0 + iVar1) & 0x7fff;
  uVar3 = uRam0214c91c;
  uVar2 = uRam0214c918;
  uVar5 = (uint)*(ushort *)(&DAT_040000b0 + iVar1);
  uVar6 = (uint)*(ushort *)(&DAT_040000b0 + iVar1);
  if (param_1 == 0) {
    _DAT_040000b0 = 0;
    *(undefined4 *)(uRam0214c918 + 4) = 0;
    *(uint *)(uVar2 + 8) = uVar3;
    uVar5 = uVar3;
    uVar6 = uVar2;
  }
  Os_RestoreIrq(uVar4,uVar5,uVar6);
  return;
}

