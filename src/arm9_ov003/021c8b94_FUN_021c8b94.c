/* Decompiled C draft; module arm9_ov003; ROM address 021c8b94. No matching claim. */
#include "types.h"
#include "deps/021c8b94_FUN_021c8b94.h"

void FUN_021c8b94(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = func_0x02147d30(*DAT_021c8c08,0x1d);
  FUN_021d2060(*(undefined4 *)(*DAT_021c8c0c + 0x14),0);
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    FUN_021c8a60(iVar3,iVar2);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar2 < 5);
  FUN_021cc9c0(*(int *)(*DAT_021c8c0c + 8) + (uint)*(ushort *)(DAT_021c8c10 + iVar1 * 2) * 2,0,0x1e,
               0x13);
  iVar3 = 0;
  do {
    FUN_021c8974(iVar1,iVar3);
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar3 < 5);
  FUN_021cc9fc();
  FUN_021d1fd0(*(undefined4 *)(*DAT_021c8c0c + 0x14));
  FUN_021c85a0();
  return;
}

