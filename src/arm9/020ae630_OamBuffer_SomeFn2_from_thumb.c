/* Decompiled C draft; module arm9; ROM address 020ae630. No matching claim. */
#include "types.h"
#include "deps/020ae630_OamBuffer_SomeFn2_from_thumb.h"

void OamBuffer_SomeFn2_from_thumb(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    uVar1 = *(ushort *)(param_1 + iRam020ae6a0);
    Arm_FlushRange();
    for (iVar2 = 0; iVar2 < (int)(0x80 - (uint)uVar1); iVar2 = iVar2 + 1) {
      iVar3 = ((uint)uVar1 + iVar2) * 8;
      *(uint *)(param_1 + iVar3) = *(uint *)(param_1 + iVar3) & uRam020ae6a4 | uRam020ae6a8;
      *(undefined1 *)(param_1 + iVar3) = 0xe0;
    }
  }
  if (param_2 != 0) {
    uVar1 = *(ushort *)(param_2 + iRam020ae6a0);
    Arm_FlushRange(param_2);
    for (iVar2 = 0; iVar2 < (int)(0x80 - (uint)uVar1); iVar2 = iVar2 + 1) {
      iVar3 = ((uint)uVar1 + iVar2) * 8;
      *(uint *)(param_2 + iVar3) = *(uint *)(param_2 + iVar3) & uRam020ae6a4 | uRam020ae6a8;
      *(undefined1 *)(param_2 + iVar3) = 0xe0;
    }
  }
  return;
}

