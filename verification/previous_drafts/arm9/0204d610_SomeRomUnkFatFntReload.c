/* Decompiled C draft; module arm9; ROM address 0204d610. No matching claim. */
#include "types.h"
#include "deps/0204d610_SomeRomUnkFatFntReload.h"

uint SomeRomUnkFatFntReload(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_30 [8];
  
  uVar3 = Fs_FindArchiveByMountName(uRam0204d6e4,3);
  Fs_Archive_UnloadFatFnt();
  Fs_Archive_SetExtraFileOperationHandler(uVar3,uRam0204d6e8,0xffffffff);
  uVar6 = param_1 + 4;
  uVar5 = *(uint *)(param_1 & 0xfffffffc);
  iVar4 = 0;
  do {
    local_30[iVar4 * 2] = uVar6 + 4;
    local_30[iVar4 * 2 + 1] =
         *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
         *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    iVar1 = iVar4 * 2;
    iVar2 = iVar4 * 2;
    iVar4 = iVar4 + 1;
    uVar6 = local_30[iVar2] + (local_30[iVar1 + 1] + 0x1f & 0xffffffe0);
  } while (iVar4 < 4);
  Fs_Archive_LoadFromFatFnt
            (uVar3,0,local_30[0],local_30[1],local_30[2],local_30[3],uRam0204d6ec,uRam0204d6f0);
  func_020050c0(0,local_30[4],local_30[5]);
  func_020050c0(1,local_30[6],local_30[7]);
  return uVar5 >> (param_1 & 3) * 8 | uVar5 << (param_1 & 3) * -8 + 0x20;
}

