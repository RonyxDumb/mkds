/* Decompiled C draft; module arm9; ROM address 0204f770. No matching claim. */
#include "types.h"
#include "deps/0204f770_func_0204f770.h"

void func_0204f770(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = ((int)((*(ushort *)(*piRam0204f7d4 + iRam0204f7d8) - 1) * 0x10000) >> 0x10) * 0x88;
  iVar1 = *piRam0204f7d4 + iVar3;
  iVar2 = *(int *)(iVar1 + iRam0204f7e0);
  if (iVar2 == 0) {
    iVar2 = Mem_AllocateHeapAligned
                      (*(undefined4 *)(iVar1 + iRam0204f7e4),**(uint **)(iVar1 + iRam0204f7dc) >> 8,
                       0x20);
    **(int **)(*piRam0204f7d4 + iVar3 + iRam0204f7e8) = iVar2;
  }
  DecompressLzss(*(undefined4 *)(*piRam0204f7d4 + iVar3 + iRam0204f7dc),(byte *)(uintptr_t)(iVar2));
  *(uint *)(*piRam0204f7d4 + iRam0204f7ec + iVar3) =
       *(uint *)(*piRam0204f7d4 + iRam0204f7ec + iVar3) & uRam0204f7f0;
  return;
}

