/* Decompiled C draft; module arm9_ov003; ROM address 021c1364. No matching claim. */
#include "types.h"
#include "deps/021c1364_FUN_021c1364.h"

void FUN_021c1364(int param_1,uint param_2)

{
  uint *puVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  byte local_28 [4];
  byte local_24;
  byte local_23 [4];
  byte local_1f;
  byte local_1e [4];
  byte local_1a;
  
  local_28[0] = *DAT_021c14e8;
  local_28[1] = DAT_021c14e8[1];
  local_28[2] = DAT_021c14e8[2];
  local_28[3] = DAT_021c14e8[3];
  local_24 = DAT_021c14e8[4];
  local_23[0] = *DAT_021c14ec;
  local_23[1] = DAT_021c14ec[1];
  local_23[2] = DAT_021c14ec[2];
  local_23[3] = DAT_021c14ec[3];
  local_1f = DAT_021c14ec[4];
  local_1e[0] = *DAT_021c14f0;
  local_1e[1] = DAT_021c14f0[1];
  local_1e[2] = DAT_021c14f0[2];
  local_1e[3] = DAT_021c14f0[3];
  local_1a = DAT_021c14f0[4];
  iVar4 = 0;
  if (local_28[param_1] != 0) {
    iVar3 = param_1 * 0xc;
    puVar2 = (ushort *)(DAT_021c14f4 + iVar3);
    do {
      puVar1 = *(uint **)(*DAT_021c14f8 + iVar3 + 0x10);
      *puVar1 = *puVar1 & DAT_021c14fc;
      puVar1 = *(uint **)(*DAT_021c14f8 + iVar3 + 0x10);
      *puVar1 = (*puVar2 & DAT_021c1500) << 0x10 | *puVar1 & DAT_021c1504 | param_2 & 0xff;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
      puVar2 = puVar2 + 2;
    } while (iVar4 < (int)(uint)local_28[param_1]);
  }
  if (param_1 < 4) {
    FUN_021d1ffc(*(undefined4 *)(*DAT_021c14f8 + param_1 * 4),
                 *(undefined2 *)(DAT_021c14f4 + param_1 * 0xc),param_2,
                 *(undefined4 *)(*DAT_021c14f8 + param_1 * 4 + 0x48),2);
  }
  iVar4 = 0;
  if (local_23[param_1] != 0) {
    iVar3 = 0;
    puVar2 = DAT_021c1508;
    do {
      puVar1 = *(uint **)(*DAT_021c14f8 + iVar3 + 0x38);
      *puVar1 = *puVar1 & DAT_021c14fc;
      puVar1 = *(uint **)(*DAT_021c14f8 + iVar3 + 0x38);
      *puVar1 = (*puVar2 & DAT_021c1500) << 0x10 | *puVar1 & DAT_021c1504 | param_2 & 0xff;
      iVar3 = iVar3 + 4;
      puVar2 = puVar2 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)local_23[param_1]);
  }
  iVar4 = 0;
  if (local_1e[param_1] != 0) {
    iVar3 = 0;
    puVar5 = DAT_021c150c;
    do {
      FUN_021d18f0(*(undefined4 *)(*DAT_021c14f8 + iVar3 + 0x40),0xffffffff,0,0);
      FUN_021d17d4(*(undefined4 *)(*DAT_021c14f8 + iVar3 + 0x40),0xffffffff,*puVar5,param_2);
      iVar3 = iVar3 + 4;
      puVar5 = puVar5 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)local_1e[param_1]);
  }
  return;
}

