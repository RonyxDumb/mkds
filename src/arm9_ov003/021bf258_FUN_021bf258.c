/* Decompiled C draft; module arm9_ov003; ROM address 021bf258. No matching claim. */
#include "types.h"
#include "deps/021bf258_FUN_021bf258.h"

void FUN_021bf258(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)*(byte *)(DAT_021bf2c0 + (uint)*(byte *)(*DAT_021bf2bc + 0x17));
  uVar1 = *(ushort *)(DAT_021bf2c4 + 2);
  uVar2 = DAT_021bf2c8[1];
  FUN_021d17d4(*(undefined4 *)(*DAT_021bf2bc + 8),0xffffffff,*DAT_021bf2c8,param_1);
  iVar4 = 0;
  if (uVar5 != 0) {
    iVar3 = 0;
    do {
      FUN_021d17d4(*(undefined4 *)(*DAT_021bf2bc + iVar3),0xffffffff,
                   *(undefined2 *)
                    (DAT_021bf2c4 +
                    (uint)*(byte *)(iVar4 + DAT_021bf2cc + (uint)*(byte *)(*DAT_021bf2bc + 0x17) * 2
                                   ) * 4),(param_1 + (uint)uVar1) - (uint)uVar2);
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar5);
  }
  return;
}

