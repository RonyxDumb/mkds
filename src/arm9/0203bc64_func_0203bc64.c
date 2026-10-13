/* Decompiled C draft; module arm9; ROM address 0203bc64. No matching claim. */
#include "types.h"
#include "deps/0203bc64_func_0203bc64.h"

void func_0203bc64(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint extraout_r1;
  bool bVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  longlong lVar13;
  uint local_64;
  longlong *local_60;
  int local_5c;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_34;
  int local_2c [3];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  bVar2 = *param_1;
  bVar7 = false;
  piVar6 = (int *)*puRam0203be34;
  if (piVar6 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar6;
  }
  if ((iVar3 != 0) && (piVar6[1] != 0xd)) {
    bVar7 = true;
  }
  if (bVar7) {
    local_60 = (longlong *)((int)piVar6 + iRam0203be38);
  }
  else {
    iVar3 = Os_GetTick();
    uVar12 = Os_GetTick();
    local_2c[0] = iVar3 * 0x1000000 + ((uint)uVar12 >> 8 | (int)((ulonglong)uVar12 >> 0x20) << 0x18)
    ;
    local_2c[1] = 0;
    local_2c[2] = uRam0203be3c;
    local_20 = uRam0203be40;
    local_1c = uRam0203be44;
    local_18 = 0;
    local_60 = (longlong *)local_2c;
  }
  local_64 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_34 = 0;
  local_4c = 0;
  do {
    local_5c = -1;
    iVar3 = *(int *)(param_1 + local_64 * 4 + 4);
    if (((uint)bVar2 & 1 << local_64) == 0) {
      pbVar1 = param_1 + local_64 * 4 + 0x24;
      pbVar1[0] = 0xff;
      pbVar1[1] = 0xff;
      pbVar1[2] = 0xff;
      pbVar1[3] = 0xff;
      iVar9 = iVar3 * 3;
      uVar10 = local_4c;
      uVar11 = local_4c;
      do {
        iVar4 = func_0205fc98(*(undefined4 *)(param_1 + 0x44),iVar3,uVar11 + iVar9);
        if (iVar4 != 0) {
          uVar10 = uVar10 | 1 << uVar11 & 0xffU;
        }
        uVar11 = uVar11 + 1 & 0xff;
      } while (uVar11 < 3);
      uVar11 = local_48;
      do {
        if (((((uint)bVar2 & 1 << uVar11) != 0) &&
            (iVar4 = *(int *)(param_1 + uVar11 * 4 + 0x24),
            iVar4 + iVar3 * -3 < 0 == SBORROW4(iVar4,iVar9))) &&
           (iVar4 + (iVar3 + 1) * -3 < 0 != SBORROW4(iVar4,(iVar3 + 1) * 3))) {
          uVar10 = uVar10 & ~(1 << (iVar4 + iVar3 * -3 & 0xffU));
        }
        uVar11 = uVar11 + 1 & 0xff;
      } while (uVar11 < 8);
      uVar11 = local_44;
      if (uVar10 == 0) {
        do {
          iVar4 = func_0205fc98(*(undefined4 *)(param_1 + 0x44),iVar3,uVar11 + iVar9);
          if (iVar4 != 0) {
            uVar10 = uVar10 | 1 << uVar11 & 0xffU;
          }
          uVar11 = uVar11 + 1 & 0xff;
        } while (uVar11 < 3);
      }
      iVar3 = Math_CountPopulation(uVar10);
      uVar11 = local_40;
      if (iVar3 != 0) {
        lVar13 = Multiply64((int)local_60[1],*(undefined4 *)((int)local_60 + 0xc),(int)*local_60,
                            *(undefined4 *)((int)local_60 + 4));
        *local_60 = lVar13 + local_60[2];
        if (iVar3 == 0) {
          uVar11 = *(uint *)((int)local_60 + 4);
        }
        else {
          Multiply64(*(undefined4 *)((int)local_60 + 4),0,iVar3,0);
          uVar11 = extraout_r1;
        }
      }
      uVar5 = local_34;
      uVar8 = local_34;
      while ((uVar5 < 3 && (local_5c == -1))) {
        if ((uVar10 & 1 << uVar5) != 0) {
          if (uVar8 == (uVar11 & 0xffff)) {
            local_5c = uVar5 + iVar9;
          }
          else {
            uVar8 = uVar8 + 1 & 0xff;
          }
        }
        uVar5 = uVar5 + 1 & 0xff;
      }
      *(int *)(param_1 + local_64 * 4 + 0x24) = local_5c;
    }
    local_64 = local_64 + 1 & 0xff;
  } while (local_64 < 8);
  return;
}

