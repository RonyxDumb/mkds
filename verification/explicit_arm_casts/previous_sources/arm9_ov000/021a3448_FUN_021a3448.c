/* Decompiled C draft; module arm9_ov000; ROM address 021a3448. No matching claim. */
#include "types.h"
#include "deps/021a3448_FUN_021a3448.h"

undefined4 FUN_021a3448(int param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  longlong lVar4;
  uint local_18;
  uint local_14;
  
  if ((DAT_021a34f8[1] == 0 && *DAT_021a34f8 == 0) && (DAT_021a34f8[3] == 0 && DAT_021a34f8[2] == 0)
     ) {
    if (DAT_021a34f8[5] == 0 && DAT_021a34f8[4] == 0) {
      func_0x0200fe58(&local_18);
      lVar4 = func_0x0200f5ac();
      puVar1 = DAT_021a34f8;
      uVar2 = local_14 << 8;
      local_14 = (uint)((ulonglong)lVar4 >> 8);
      local_18 = (local_18 >> 0x18 | uVar2) & DAT_021a34fc | (uint)(lVar4 << 0x18);
      *DAT_021a34f8 = local_18;
      puVar1[1] = local_14;
      uVar2 = DAT_021a3504;
      puVar1[2] = DAT_021a3500;
      puVar1[3] = uVar2;
      puVar1[4] = DAT_021a3508;
      puVar1[5] = 0;
    }
  }
  lVar4 = func_0x02133048(DAT_021a34f8[2],DAT_021a34f8[3],*DAT_021a34f8,DAT_021a34f8[1]);
  uVar3 = (undefined4)((ulonglong)(lVar4 + *(longlong *)(DAT_021a34f8 + 4)) >> 0x20);
  *(longlong *)DAT_021a34f8 = lVar4 + *(longlong *)(DAT_021a34f8 + 4);
  if (param_1 != 0) {
    func_0x02133048(uVar3,0,param_1,0);
    uVar3 = extraout_r1;
  }
  return uVar3;
}

