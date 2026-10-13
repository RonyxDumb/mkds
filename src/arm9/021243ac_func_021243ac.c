/* Decompiled C draft; module arm9; ROM address 021243ac. No matching claim. */
#include "types.h"
#include "deps/021243ac_func_021243ac.h"

undefined4 func_021243ac(int param_1,int param_2,undefined4 param_3,int param_4)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_450 [9];
  int local_42c;
  int local_428;
  uint local_424;
  int local_420;
  int local_41c;
  undefined4 local_418;
  undefined2 local_414 [512];
  
  local_450[0] = param_1;
  local_450[1] = param_3;
  local_450[2] = param_4;
  iVar8 = *(int *)((int)local_450 + iRam02124620 + 4);
  *(undefined4 *)((int)local_450 + iRam02124620 + 0xc) =
       *(undefined4 *)((int)local_450 + iRam02124620 + 0xc);
  *(undefined4 *)((int)local_450 + iRam02124620 + 0x10) =
       *(undefined4 *)((int)local_450 + iRam02124620 + 0x10);
  local_424 = (uint)*(ushort *)(*(int *)((int)local_450 + iRam02124620 + 0xc) + 6);
  *(int *)(*(int *)((int)local_450 + iRam02124620 + 0x10) + iVar8 * 0x40 + 0x38) = param_2;
  local_450[3] = Mem_AllocateHeap(param_1,0x48);
  *(int *)(*(int *)((int)local_450 + iRam02124620 + 0x10) + (local_424 + param_2) * 0x40 + 0x3c) =
       local_450[3];
  puVar2 = (ushort *)func_0201ea58(local_450[1],param_2);
  iVar10 = iRam02124620;
  iVar9 = (local_450[2] + -1 >> 3) + 1;
  local_41c = (*(int *)((int)local_450 + iRam02124620) + -1 >> 3) + 1;
  iVar6 = local_41c * iVar9;
  *(int *)(local_450[3] + 0x34) = iVar6 * 0x20;
  *(int *)(local_450[3] + 0x38) =
       (*(int *)((int)local_450 + iVar10 + 0x14) - iRam02124624 >> 5) - iVar6;
  uVar3 = Mem_AllocateHeap(local_450[0],*(undefined4 *)(local_450[3] + 0x34));
  *(undefined4 *)(local_450[3] + 0x30) = uVar3;
  G2d_Sprite_CreateFrom2(local_450[3],*(undefined4 *)(local_450[3] + 0x30),iVar9,local_41c);
  (**(code **)(local_450[3] + 0x18))(local_450[3],0);
  local_428 = (int)*(char *)((int)puVar2 + 5);
  local_42c = (int)(char)puVar2[2];
  uVar3 = GetLoadedFont_from_thumb(((uint)puVar2[3] << 0x10) >> 0x1c);
  *(int *)(local_450[3] + 0x20) = local_450[3];
  *(undefined4 *)(local_450[3] + 0x24) = uVar3;
  *(int *)(local_450[3] + 0x28) = local_42c;
  *(int *)(local_450[3] + 0x2c) = local_428;
  *(int *)(local_450[3] + 0x3c) = local_450[2];
  iVar10 = iRam02124620;
  *(undefined4 *)(local_450[3] + 0x40) = *(undefined4 *)((int)local_450 + iRam02124620);
  local_450[5] = 0;
  local_450[6] = 0;
  if (iVar8 < (int)local_424) {
    local_450[7] = func_021249f0(iVar8,*(undefined4 *)((int)local_450 + iVar10 + 8),
                                 *(undefined4 *)((int)local_450 + iRam02124620 + 0xc));
    local_450[8] = func_02124ae4(iVar8,*(undefined4 *)((int)local_450 + iRam02124620 + 8),
                                 *(undefined4 *)((int)local_450 + iRam02124620 + 0xc));
  }
  else {
    iVar8 = iVar8 - local_424;
    local_450[7] = func_021240d4(iVar8,local_450[1],
                                 *(undefined4 *)((int)local_450 + iRam02124620 + 0x10),
                                 *(undefined4 *)((int)local_450 + iRam02124620 + 0xc));
    local_450[8] = func_0212418c(iVar8,local_450[1],
                                 *(undefined4 *)((int)local_450 + iRam02124620 + 0x10),
                                 *(undefined4 *)((int)local_450 + iRam02124620 + 0xc));
  }
  uVar4 = ((uint)*puVar2 << 0x12) >> 0x1e;
  if (uVar4 == 1) {
    local_450[5] = iVar9 * -4;
  }
  else if (uVar4 == 2) {
    local_450[5] = iVar9 * -8;
  }
  uVar4 = ((uint)puVar2[1] << 0x12) >> 0x1e;
  if (uVar4 == 1) {
    local_450[6] = local_41c * -4;
  }
  else if (uVar4 == 2) {
    local_450[6] = local_41c * -8;
  }
  local_450[4] = func_02022eb0(&local_418,iVar9,local_41c,local_450[5]);
  puVar5 = (undefined2 *)Mem_AllocateHeap(local_450[0],local_450[4] * 6 + 0x10);
  *puVar5 = (short)local_450[4];
  iVar10 = 0;
  puVar5[1] = 0;
  *(undefined2 **)(puVar5 + 2) = puVar5 + 8;
  puVar5[4] = (short)iVar9 * 4;
  puVar5[5] = (short)(local_41c << 2);
  puVar5[6] = (short)iVar9 * -4;
  puVar5[7] = (short)local_41c * -4;
  if (0 < local_450[4]) {
    puVar7 = &local_418;
    iVar6 = 0;
    local_420 = local_450[7] << 10;
    do {
      *(ushort *)(puVar7 + 1) =
           (ushort)puVar7[1] & (ushort)uRam02124628 | (ushort)(local_450[7] << 10);
      if (local_450[8] == 0) {
        uVar1 = puVar2[3];
        *puVar7 = *puVar7 & uRam02124628;
        *(ushort *)(puVar7 + 1) =
             (ushort)puVar7[1] & (ushort)uRam02124630 |
             (ushort)((((uint)uVar1 << 0x14) >> 0x1c) << 0xc);
      }
      else {
        uVar1 = puVar2[3];
        *puVar7 = *puVar7 & uRam02124628 | uRam0212462c;
        *(ushort *)(puVar7 + 1) =
             (ushort)puVar7[1] & (ushort)uRam02124630 |
             (ushort)((((uint)uVar1 << 0x14) >> 0x1c) << 0xc);
      }
      *puVar7 = *puVar7 & uRam02124634;
      *puVar7 = *puVar7 & uRam02124638;
      *(short *)(*(int *)(puVar5 + 2) + iVar6) = (short)*puVar7;
      *(undefined2 *)(*(int *)(puVar5 + 2) + iVar6 + 2) = *(undefined2 *)((int)puVar7 + 2);
      *(short *)(*(int *)(puVar5 + 2) + iVar6 + 4) = (short)puVar7[1];
      puVar7 = puVar7 + 2;
      iVar6 = iVar6 + 6;
      iVar10 = iVar10 + 1;
    } while (iVar10 < local_450[4]);
  }
  *(undefined2 **)(local_450[3] + 0x44) = puVar5;
  return *(undefined4 *)(local_450[3] + 0x34);
}

