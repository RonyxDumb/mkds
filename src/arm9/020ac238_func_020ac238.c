/* Decompiled C draft; module arm9; ROM address 020ac238. No matching claim. */
#include "types.h"
#include "deps/020ac238_func_020ac238.h"

uint func_020ac238(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *piRam020ac280;
  uVar3 = (uint)*(ushort *)(iVar2 + 0x46);
  if ((uVar3 == *(ushort *)(iVar2 + 0x4a) - 1) &&
     (0x1f < *(ushort *)(*(int *)(iVar2 + 0x40) + uVar3 * 2))) {
    return uVar3;
  }
  uVar3 = uVar3 - 1;
  uVar1 = 0;
  if ((-1 < (int)uVar3) && (0x1f < *(ushort *)(*(int *)(iVar2 + 0x40) + uVar3 * 2))) {
    uVar1 = uVar3;
  }
  return uVar1;
}

