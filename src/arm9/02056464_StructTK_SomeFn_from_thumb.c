/* Decompiled C draft; module arm9; ROM address 02056464. No matching claim. */
#include "types.h"
#include "deps/02056464_StructTK_SomeFn_from_thumb.h"

void StructTK_SomeFn_from_thumb(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  byte *pbVar3;
  
  Mem_CpuCopy8((ushort *)(uintptr_t)(*(int *)*piRam0205654c + 0xc),(uint *)(uintptr_t)(param_1),0x14);
  piVar1 = piRam0205654c;
  if (((*(byte *)(((int *)*piRam0205654c)[1] + 4) & 1) == 0) ||
     ((int)((uint)*(byte *)(*(int *)*piRam0205654c + 0x31) << 0x1c) < 0)) {
    *(undefined1 *)(param_1 + iRam02056550) = 0;
    Mem_CpuFill8((uint *)(uintptr_t)(param_1 + 0x14),0,uRam02056554);
  }
  else {
    *(undefined1 *)(param_1 + iRam02056550) = 1;
    Mem_CpuCopy8((ushort *)(uintptr_t)(*(int *)(*piVar1 + 4) + 8),(uint *)(uintptr_t)(param_1 + 0x14),uRam02056554);
  }
  Mem_CpuCopy8((ushort *)(uintptr_t)(*(int *)*piRam0205654c + 0x20),(uint *)(uintptr_t)(param_1 + iRam02056558),4);
  piVar1 = piRam02056560;
  pbVar3 = (byte *)(param_1 + iRam0205655c);
  *pbVar3 = *pbVar3 & 0xf0 | (byte)*(undefined4 *)*piRam02056560 & 0xf;
  *pbVar3 = *pbVar3 & 0xf | (byte)((*(uint *)(*piVar1 + 4) & 0xf) << 4);
  *(undefined2 *)(param_1 + iRam02056564) = *(undefined2 *)(*(int *)*piRam0205654c + 0x24);
  uVar2 = GetWorstStarRank_from_thumb();
  *(undefined1 *)(param_1 + iRam02056568) = uVar2;
  if (*psRam0205656c == 2) {
    Mem_CpuFill8((uint *)(uintptr_t)(param_1 + iRam02056570),0,0xc);
    return;
  }
  PlayerProfileInfo_CopyFriendCode_from_thumb(*(int *)*piRam0205654c + 0x4c,(undefined4 *)(uintptr_t)(param_1 + iRam02056570));
  return;
}

