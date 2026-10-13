/* Decompiled C draft; module arm9; ROM address 02129ea4. No matching claim. */
#include "types.h"
#include "deps/02129ea4_func_02129ea4.h"

void func_02129ea4(void)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int local_88;
  int local_84;
  int local_80;
  ushort *local_7c;
  int local_78;
  int local_74;
  byte *local_70;
  int local_6c;
  int local_68;
  byte *local_64;
  int local_60;
  int local_5c;
  byte *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  ushort local_2c [2];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [8];
  
  piVar2 = piRam0212a1b4;
  local_88 = 0;
  local_80 = 0;
  local_7c = local_2c;
  local_78 = 0;
  local_74 = iRam0212a194;
  local_70 = pbRam0212a198;
  local_6c = iRam0212a19c;
  local_68 = iRam0212a1a0;
  local_64 = pbRam0212a1a4;
  local_60 = iRam0212a1a8;
  local_5c = iRam0212a1ac;
  local_58 = pbRam0212a1b0;
  local_38 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  do {
    *local_7c = *(ushort *)(*(int *)(*piVar2 + local_80 + 0x9c) + 6);
    local_84 = 0;
    local_54 = 0;
    local_50 = 0;
    do {
      uVar5 = (undefined2)uRam0212a1b8;
      if ((local_88 == 1) || (*(short *)(*piVar2 + 0x70) == 0xc)) {
        uVar5 = *(undefined2 *)(local_54 + local_80 + *piVar2 + 0x86);
      }
      if (*local_70 != 0) {
        iVar4 = local_44;
        do {
          *(undefined2 *)
           (*(int *)(local_78 + local_50 + *piVar2 + 0x74) +
            (uint)*(byte *)(local_74 + iVar4) * 0x40 + 6) = uVar5;
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*local_70);
      }
      if (*local_64 != 0) {
        iVar4 = local_40;
        do {
          *(undefined2 *)
           (*(int *)(local_78 + local_50 + *piVar2 + 0x74) +
            (uint)*(byte *)(local_6c + iVar4) * 0x40 + 6) = uVar5;
          *(undefined2 *)
           ((uint)*(byte *)(local_68 + iVar4) * 0x40 +
            *(int *)(local_78 + local_50 + *piVar2 + 0x74) + (uint)*local_7c * 0x40 + 6) = uVar5;
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*local_64);
      }
      uVar5 = *(undefined2 *)(*piVar2 + 0x84);
      iVar4 = local_38;
      iVar8 = local_3c;
      iVar6 = local_60;
      do {
        do {
          *(undefined2 *)
           (*(int *)(local_78 + local_50 + *piVar2 + 0x74) + (uint)*(byte *)(iVar6 + iVar4) * 0x40 +
           6) = uVar5;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 3);
        *(undefined2 *)
         ((uint)*(byte *)(local_5c + iVar8) * 0x40 +
          *(int *)(local_78 + local_50 + *piVar2 + 0x74) + (uint)*local_7c * 0x40 + 6) = uVar5;
        iVar6 = iVar6 + 3;
        iVar8 = iVar8 + 1;
        iVar4 = local_38;
      } while (iVar8 < 2);
      sVar1 = *(short *)(*piVar2 + 0x84);
      func_020ab848(local_28,local_24,local_20,local_1c);
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)*local_58 * 0x40 + 0xc) =
           MKDS_SLICE_2(local_28,0);
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)*local_58 * 0x40 + 0xe) =
           sVar1 + MKDS_SLICE_2(local_24,0) + 0x28;
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)local_58[1] * 0x40 + 0xc) =
           MKDS_SLICE_2(local_28,0);
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)local_58[1] * 0x40 + 0xe) =
           sVar1 + (short)MKDS_SLICE_4(local_1c,0) + 0x28;
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)local_58[2] * 0x40 + 0xc) =
           MKDS_SLICE_2(local_20,0);
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)local_58[2] * 0x40 + 0xe) =
           sVar1 + MKDS_SLICE_2(local_24,0) + 0x28;
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)local_58[3] * 0x40 + 0xc) =
           MKDS_SLICE_2(local_20,0);
      *(short *)(*(int *)(local_50 + local_78 + *piVar2 + 0x74) + (uint)local_58[3] * 0x40 + 0xe) =
           sVar1 + (short)MKDS_SLICE_4(local_1c,0) + 0x28;
      piVar3 = piRam0212a1b4;
      local_54 = local_54 + 2;
      local_50 = local_50 + 4;
      local_84 = local_84 + 1;
    } while (local_84 < 2);
    local_80 = local_80 + 4;
    local_7c = local_7c + 1;
    local_78 = local_78 + 8;
    local_74 = local_74 + 1;
    local_70 = local_70 + 1;
    local_6c = local_6c + 0xc;
    local_68 = local_68 + 0xc;
    local_64 = local_64 + 1;
    local_60 = local_60 + 6;
    local_5c = local_5c + 2;
    local_58 = local_58 + 4;
    local_88 = local_88 + 1;
  } while (local_88 < 2);
  iVar4 = 0;
  local_4c = 0;
  iVar8 = 0;
  do {
    uVar5 = (undefined2)uRam0212a1b8;
    if ((*(int *)(*piVar3 + 4) == 1) && (local_4c == 1)) {
      uVar5 = *(undefined2 *)(*piVar3 + 0x84);
    }
    iVar6 = 0;
    pbVar7 = pbRam0212a1bc;
    do {
      *(undefined2 *)(*(int *)(iVar4 + *piVar3 + 0x7c) + (uint)*pbVar7 * 0x40 + 6) = uVar5;
      pbVar7 = pbVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 10);
    uVar5 = (undefined2)uRam0212a1b8;
    if (*(int *)(*piVar3 + 4) == 1) {
      uVar5 = *(undefined2 *)(*piVar3 + iVar8 + 0x8a);
    }
    iVar6 = 0;
    pbVar7 = pbRam0212a1c0;
    do {
      *(undefined2 *)(*(int *)(iVar4 + *piVar3 + 0x7c) + (uint)*pbVar7 * 0x40 + 6) = uVar5;
      pbVar7 = pbVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 6);
    iVar4 = iVar4 + 4;
    iVar8 = iVar8 + 2;
    local_4c = local_4c + 1;
  } while (local_4c < 2);
  return;
}

