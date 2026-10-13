/* Decompiled C draft; module arm9_ov003; ROM address 021c0154. No matching claim. */
#include "types.h"
#include "deps/021c0154_FUN_021c0154.h"

void FUN_021c0154(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  byte local_28 [4];
  byte local_24;
  byte local_23 [4];
  byte local_1f;
  byte local_1e [4];
  byte local_1a;
  
  local_28[0] = *DAT_021c02ec;
  local_28[1] = DAT_021c02ec[1];
  local_28[2] = DAT_021c02ec[2];
  local_28[3] = DAT_021c02ec[3];
  local_24 = DAT_021c02ec[4];
  local_23[0] = *DAT_021c02f0;
  local_23[1] = DAT_021c02f0[1];
  local_23[2] = DAT_021c02f0[2];
  local_23[3] = DAT_021c02f0[3];
  local_1f = DAT_021c02f0[4];
  local_1e[0] = *DAT_021c02f4;
  local_1e[1] = DAT_021c02f4[1];
  local_1e[2] = DAT_021c02f4[2];
  local_1e[3] = DAT_021c02f4[3];
  local_1a = DAT_021c02f4[4];
  iVar5 = 0;
  if (local_28[param_2] != 0) {
    iVar3 = param_2 * 0x30;
    puVar2 = (ushort *)(DAT_021c02f8 + iVar3);
    do {
      puVar1 = *(uint **)(*DAT_021c02fc + iVar3 + 0x30);
      *puVar1 = *puVar1 & DAT_021c0300;
      puVar1 = *(uint **)(*DAT_021c02fc + iVar3 + 0x30);
      *puVar1 = (*puVar2 & DAT_021c0304) << 0x10 | *puVar1 & DAT_021c0308 | param_3 & 0xff;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 4;
      puVar2 = puVar2 + 2;
    } while (iVar5 < (int)(uint)local_28[param_2]);
  }
  if (param_2 < 4) {
    FUN_021d1ffc(*(undefined4 *)(param_2 * 4 + *DAT_021c02fc + param_1 * 0x10),
                 *(undefined2 *)(DAT_021c02f8 + param_2 * 0x30),param_3,
                 *(undefined4 *)(*DAT_021c02fc + param_2 * 4 + DAT_021c030c),2);
  }
  iVar5 = func_0x02147cd8(param_2 + 3,4);
  iVar3 = 0;
  if (local_23[param_2] != 0) {
    iVar5 = iVar5 * 4;
    uVar4 = *(ushort *)(DAT_021c0310 + iVar5) & DAT_021c0304;
    do {
      puVar1 = *(uint **)(iVar5 + *DAT_021c02fc + 0xec);
      *puVar1 = *puVar1 & DAT_021c0300;
      puVar1 = *(uint **)(iVar5 + *DAT_021c02fc + 0xec);
      *puVar1 = uVar4 * 0x10000 | *puVar1 & DAT_021c0308 | param_3 & 0xff;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)local_23[param_2]);
  }
  iVar5 = 0;
  if (local_1e[param_2] != 0) {
    iVar3 = 0;
    puVar6 = DAT_021c0314;
    do {
      FUN_021d18f0(*(undefined4 *)(*DAT_021c02fc + iVar3 + 0xfc),0xffffffff,0,0);
      FUN_021d17d4(*(undefined4 *)(*DAT_021c02fc + iVar3 + 0xfc),0xffffffff,*puVar6,param_3);
      iVar3 = iVar3 + 4;
      puVar6 = puVar6 + 2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)local_1e[param_2]);
  }
  return;
}

