/* Decompiled C draft; module arm9; ROM address 0211c818. No matching claim. */
#include "types.h"
#include "deps/0211c818_func_0211c818.h"

void func_0211c818(void)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  undefined2 uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  int local_58;
  ushort *local_54;
  ushort *local_50;
  ushort *local_4c;
  int local_48;
  ushort *local_44;
  ushort *local_40;
  ushort *local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_24;
  
  piVar1 = piRam0211ca88;
  if (*(int *)(*piRam0211ca78 + 0x20) != 2) {
    local_38 = 0;
    local_54 = puRam0211ca7c;
    local_50 = puRam0211ca80;
    local_4c = puRam0211ca84;
    local_48 = 0;
    local_2c = 0;
    local_24 = 0;
    do {
      iVar10 = func_0211d650();
      if ((iVar10 == 8) &&
         (puVar5 = local_4c, puVar7 = local_50, puVar9 = local_54, iVar10 = local_2c, local_38 == 1)
         ) {
        do {
          *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar9 * 0x40) = 0;
          *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar7 * 0x40) = 0;
          *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40) = 0;
          iVar10 = iVar10 + 1;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar10 < 2);
      }
      else {
        sVar3 = func_020adc64(6 - *(short *)(*piVar1 + local_48 + 0x3c));
        *(short *)(*(int *)(*piVar1 + 0x14) + (uint)*local_50 * 0x40 + 4) = -sVar3;
        uVar4 = func_020adc64(6 - *(short *)(*piVar1 + local_48 + 0x3e));
        *(undefined2 *)(*(int *)(*piVar1 + 0x14) + (uint)local_50[1] * 0x40 + 4) = uVar4;
        local_34 = 0;
        puVar5 = local_4c;
        puVar7 = local_50;
        puVar9 = local_54;
        iVar10 = local_24;
        do {
          iVar8 = *piVar1;
          iVar6 = local_48 + iVar8 + iVar10;
          if (*(short *)(iVar6 + 0x3c) < 1) {
            if ((*(int *)(iVar8 + 0x60) == local_38) && (*(int *)(iVar8 + 0x7c) == 0)) {
              *(undefined4 *)(*(int *)(iVar8 + 0x14) + (uint)*puVar9 * 0x40) = 1;
              *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar7 * 0x40) = 0;
              *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40) = 0;
            }
            else {
              *(undefined4 *)(*(int *)(iVar8 + 0x14) + (uint)*puVar9 * 0x40) = 0;
              *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar7 * 0x40) = 0;
              *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40) = 1;
            }
          }
          else {
            *(short *)(iVar6 + 0x3c) = *(short *)(iVar6 + 0x3c) + -1;
            *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar9 * 0x40) = 0;
            *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar7 * 0x40) = 1;
            *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40) = 0;
          }
          iVar10 = iVar10 + 2;
          puVar9 = puVar9 + 1;
          puVar7 = puVar7 + 1;
          puVar5 = puVar5 + 1;
          local_34 = local_34 + 1;
        } while (local_34 < 2);
      }
      piVar2 = piRam0211ca88;
      local_54 = local_54 + 2;
      local_50 = local_50 + 2;
      local_4c = local_4c + 2;
      local_48 = local_48 + 4;
      local_38 = local_38 + 1;
    } while (local_38 < 5);
    if (*(int *)(*piRam0211ca88 + 0x2c) == 3) {
      iVar10 = 0;
      puVar5 = puRam0211ca84;
      puVar7 = puRam0211ca80;
      puVar9 = puRam0211ca7c;
      do {
        *(undefined4 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar9 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar2 + 0x14) + (uint)puVar9[4] * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar7 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar2 + 0x14) + (uint)puVar7[4] * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar5 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar2 + 0x14) + (uint)puVar5[4] * 0x40) = 0;
        puVar9 = puVar9 + 1;
        puVar7 = puVar7 + 1;
        puVar5 = puVar5 + 1;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 2);
    }
    return;
  }
  local_58 = 0;
  local_44 = puRam0211ca7c;
  local_40 = puRam0211ca80;
  local_3c = puRam0211ca84;
  do {
    iVar10 = 0;
    puVar5 = local_3c;
    puVar7 = local_40;
    puVar9 = local_44;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar9 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar7 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40) = 0;
      puVar9 = puVar9 + 1;
      puVar7 = puVar7 + 1;
      puVar5 = puVar5 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 2);
    local_44 = local_44 + 2;
    local_40 = local_40 + 2;
    local_3c = local_3c + 2;
    local_58 = local_58 + 1;
  } while (local_58 < 5);
  return;
}

