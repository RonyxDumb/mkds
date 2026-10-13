/* Decompiled C draft; module arm9; ROM address 02136f14. No matching claim. */
#include "types.h"
#include "deps/02136f14_func_02136f14.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * func_02136f14(int param_1,int param_2,int param_3,uint param_4,uint param_5,int param_6,
                    int param_7)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  int unaff_r8;
  undefined4 uVar11;
  int unaff_r11;
  longlong lVar12;
  int local_48;
  uint local_44;
  
  lVar12 = CONCAT44(param_2,param_1);
  uVar4 = param_4 >> 0x18;
  uVar6 = param_5 >> 8 & 0xff;
  bVar1 = false;
  iVar7 = 0;
  local_44 = param_4 >> 8 & 0xff;
  puVar10 = (uint *)(param_3 + -1);
  uVar2 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
          *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00;
  uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
  *puVar10 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
  if (((param_2 == 0 && param_1 == 0) && (param_7 == 0)) && ((uVar4 == 0 || (uVar6 != 0x6f)))) {
    return puVar10;
  }
  iVar9 = iVar7;
  if (uVar6 < 0x6a) {
    if (uVar6 < 0x69) {
      if (uVar6 < 0x59) {
        iVar9 = 0;
        lVar12 = CONCAT44(param_2,param_1);
        if (uVar6 != 0x58) goto LAB_02137094;
        goto LAB_02137088;
      }
      if (uVar6 != 100) goto LAB_02137094;
    }
    unaff_r11 = 0;
    unaff_r8 = 10;
    lVar12 = CONCAT44(param_2,param_1);
    if (param_2 < 0) {
      bVar1 = true;
      lVar12 = CONCAT44(-(param_2 + (uint)(param_1 != 0)),-param_1);
    }
  }
  else {
    if (uVar6 < 0x70) {
      lVar12 = CONCAT44(param_2,param_1);
      if (uVar6 == 0x6f) {
        unaff_r11 = 0;
        local_44 = 0;
        unaff_r8 = 8;
        lVar12 = CONCAT44(param_2,param_1);
      }
      goto LAB_02137094;
    }
    lVar12 = CONCAT44(param_2,param_1);
    if ((0x78 < uVar6) || (lVar12 = CONCAT44(param_2,param_1), uVar6 < 0x75)) goto LAB_02137094;
    if (uVar6 == 0x75) {
      unaff_r11 = 0;
      local_44 = 0;
      unaff_r8 = 10;
      lVar12 = CONCAT44(param_2,param_1);
      goto LAB_02137094;
    }
    lVar12 = CONCAT44(param_2,param_1);
    if (uVar6 != 0x78) goto LAB_02137094;
LAB_02137088:
    unaff_r11 = 0;
    local_44 = 0;
    unaff_r8 = 0x10;
    iVar9 = iVar7;
    lVar12 = CONCAT44(param_2,param_1);
  }
LAB_02137094:
  do {
    puVar5 = puVar10;
    iVar8 = iVar9;
    uVar11 = (undefined4)((ulonglong)lVar12 >> 0x20);
    local_48 = param_7;
    iVar7 = _ull_mod((int)lVar12,uVar11,unaff_r8,unaff_r11);
    lVar12 = _ll_udiv((int)lVar12,uVar11,unaff_r8,unaff_r11);
    if (iVar7 < 10) {
      uVar3 = iVar7 + 0x30;
    }
    else if (uVar6 == 0x78) {
      uVar3 = iVar7 + 0x57;
    }
    else {
      uVar3 = iVar7 + 0x37;
    }
    puVar10 = (uint *)((int)puVar5 + -1);
    iVar9 = iVar8 + 1;
    uVar2 = uVar3 & 0xff |
            (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
  } while (lVar12 != 0);
  if (((unaff_r11 == 0 && unaff_r8 == 8) && (uVar4 != 0)) &&
     (((*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
       *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xff) != 0x30)) {
    puVar10 = (uint *)((int)puVar5 + -2);
    uVar2 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00 |
            0x30;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
    iVar9 = iVar8 + 2;
  }
  if ((param_4 & 0xff) == 2) {
    local_48 = param_6;
    if ((bVar1) || (local_44 != 0)) {
      local_48 = param_6 + -1;
    }
    if ((unaff_r11 == 0 && unaff_r8 == 0x10) && (uVar4 != 0)) {
      local_48 = local_48 + -2;
    }
  }
  if (iRam02137354 < local_48 + (param_3 - (int)puVar10)) {
    return (uint *)0x0;
  }
  for (; iVar9 < local_48; iVar9 = iVar9 + 1) {
    puVar10 = (uint *)((int)puVar10 + -1);
    uVar2 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00 |
            0x30;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
  }
  if ((unaff_r11 == 0 && unaff_r8 == 0x10) && (uVar4 != 0)) {
    puVar5 = (uint *)((int)puVar10 + -1);
    uVar6 = uVar6 | (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                    *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) &
                    0xffffff00;
    uVar3 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
    *puVar5 = uVar6 >> uVar3 | uVar6 << 0x20 - uVar3;
    puVar10 = (uint *)((int)puVar10 + -2);
    uVar4 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00 |
            0x30;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  }
  if (bVar1) {
    puVar10 = (uint *)((int)puVar10 + -1);
    uVar4 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00 |
            0x2d;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  }
  else if (local_44 == 1) {
    puVar10 = (uint *)((int)puVar10 + -1);
    uVar4 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00 |
            0x2b;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  }
  else if (local_44 == 2) {
    puVar10 = (uint *)((int)puVar10 + -1);
    uVar4 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00 |
            0x20;
    uVar3 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  }
  return puVar10;
}

