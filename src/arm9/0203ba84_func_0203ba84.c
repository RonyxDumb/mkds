/* Decompiled C draft; module arm9; ROM address 0203ba84. No matching claim. */
#include "types.h"
#include "deps/0203ba84_func_0203ba84.h"

void func_0203ba84(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint extraout_r1;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong *local_58;
  uint local_50;
  uint local_4c;
  uint local_44;
  uint local_38;
  int local_30 [3];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar7 = 0;
  bVar1 = *(byte *)(param_1 + 1);
  bVar5 = false;
  piVar4 = (int *)*DAT_0203bc50;
  if (piVar4 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar4;
  }
  if ((iVar2 != 0) && (piVar4[1] != 0xd)) {
    bVar5 = true;
  }
  if (bVar5) {
    local_58 = (longlong *)((int)piVar4 + DAT_0203bc54);
  }
  else {
    iVar2 = Os_GetTick();
    uVar11 = Os_GetTick();
    local_30[0] = iVar2 * 0x1000000 + ((uint)uVar11 >> 8 | (int)((ulonglong)uVar11 >> 0x20) << 0x18)
    ;
    local_30[1] = 0;
    local_30[2] = DAT_0203bc58;
    local_24 = DAT_0203bc5c;
    local_20 = DAT_0203bc60;
    local_1c = 0;
    local_58 = (longlong *)local_30;
  }
  uVar8 = 0;
  do {
    if (uVar8 != 0xc) {
      iVar2 = -1;
      switch(uVar8) {
      case 8:
        iVar2 = 0x14;
        break;
      case 9:
        iVar2 = 0x15;
        break;
      case 10:
        iVar2 = 0x16;
        break;
      case 0xb:
        iVar2 = 0x17;
      }
      if ((iVar2 == -1) || (iVar2 = func_0205fc28(), iVar2 != 0)) {
        uVar7 = uVar7 | 1 << uVar8 & 0xffffU;
      }
    }
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 0xd);
  uVar8 = 0;
  do {
    uVar6 = *(uint *)(param_1 + uVar8 * 4 + 4);
    if ((uVar6 != 0xffffffff) && (((uint)bVar1 & 1 << uVar8) != 0)) {
      uVar7 = uVar7 & ~(1 << (uVar6 & 0xff));
    }
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 8);
  local_50 = 0;
  local_4c = 0xffffffff;
  local_38 = 0;
  local_44 = 0;
  do {
    iVar2 = Math_CountPopulation(uVar7);
    if (((uint)bVar1 & 1 << local_50) == 0) {
      iVar3 = param_1 + local_50 * 4;
      *(undefined4 *)(iVar3 + 4) = 0xffffffff;
      uVar8 = local_44;
      if (iVar2 != 0) {
        lVar12 = Multiply64((int)local_58[1],*(undefined4 *)((int)local_58 + 0xc),(int)*local_58,
                            *(undefined4 *)((int)local_58 + 4));
        *local_58 = lVar12 + local_58[2];
        if (iVar2 == 0) {
          uVar8 = *(uint *)((int)local_58 + 4);
        }
        else {
          Multiply64(*(undefined4 *)((int)local_58 + 4),0,iVar2,0);
          uVar8 = extraout_r1;
        }
      }
      uVar6 = local_38;
      uVar9 = local_44;
      uVar10 = local_4c;
      while ((uVar6 < 0xd && (uVar10 == 0xffffffff))) {
        if ((uVar7 & 1 << uVar6) != 0) {
          if (uVar9 == (uVar8 & 0xffff)) {
            uVar7 = uVar7 & ~(1 << uVar6);
            uVar10 = uVar6;
          }
          else {
            uVar9 = uVar9 + 1 & 0xff;
          }
        }
        uVar6 = uVar6 + 1 & 0xff;
      }
      *(uint *)(iVar3 + 4) = uVar10;
    }
    local_50 = local_50 + 1 & 0xff;
  } while (local_50 < 8);
  return;
}

