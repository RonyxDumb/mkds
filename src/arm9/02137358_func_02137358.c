/* Decompiled C draft; module arm9; ROM address 02137358. No matching claim. */
#include "types.h"
#include "deps/02137358_func_02137358.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * func_02137358(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  int extraout_r1;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int unaff_r8;
  uint uVar8;
  uint uVar9;
  uint local_44;
  
  uVar1 = param_3 >> 0x18;
  uVar4 = param_4 >> 8 & 0xff;
  puVar7 = (uint *)(param_2 + -1);
  local_44 = 0;
  uVar2 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
  uVar8 = (4 - ((uint)puVar7 & 3)) * 8;
  uVar9 = param_3 >> 8 & 0xff;
  *puVar7 = uVar2 >> (uVar8 & 0x1f) | uVar2 << 0x20 - (uVar8 & 0x1f);
  iVar5 = 0;
  if (((param_1 == 0) && (param_6 == 0)) && ((uVar1 == 0 || (uVar8 = uVar1, uVar4 != 0x6f)))) {
    return puVar7;
  }
  iVar6 = iVar5;
  if (uVar4 < 0x6a) {
    if (uVar4 < 0x69) {
      if (uVar4 < 0x59) {
        iVar6 = 0;
        if (uVar4 != 0x58) goto LAB_02137498;
        goto LAB_02137490;
      }
      if (uVar4 != 100) goto LAB_02137498;
    }
    if (param_1 < 0) {
      uVar8 = 1;
    }
    unaff_r8 = 10;
    if (param_1 < 0) {
      param_1 = -param_1;
      local_44 = uVar8;
    }
  }
  else {
    if (uVar4 < 0x70) {
      if (uVar4 == 0x6f) {
        unaff_r8 = 8;
        uVar9 = 0;
      }
      goto LAB_02137498;
    }
    if ((0x78 < uVar4) || (uVar4 < 0x75)) goto LAB_02137498;
    if (uVar4 == 0x75) {
      unaff_r8 = 10;
      uVar9 = 0;
      goto LAB_02137498;
    }
    if (uVar4 != 0x78) goto LAB_02137498;
LAB_02137490:
    unaff_r8 = 0x10;
    uVar9 = 0;
    iVar6 = iVar5;
  }
LAB_02137498:
  do {
    puVar3 = puVar7;
    iVar5 = iVar6;
    MaybeBoundsCheck(param_1,unaff_r8);
    param_1 = MaybeBoundsCheck(param_1,unaff_r8);
    if (extraout_r1 < 10) {
      uVar8 = extraout_r1 + 0x30;
    }
    else if (uVar4 == 0x78) {
      uVar8 = extraout_r1 + 0x57;
    }
    else {
      uVar8 = extraout_r1 + 0x37;
    }
    puVar7 = (uint *)((int)puVar3 + -1);
    uVar2 = uVar8 & 0xff |
            (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
    uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
    iVar6 = iVar5 + 1;
  } while (param_1 != 0);
  if (((unaff_r8 == 8) && (uVar1 != 0)) &&
     (((*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
       *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xff) != 0x30)) {
    puVar7 = (uint *)((int)puVar3 + -2);
    uVar2 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
            0x30;
    uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
    iVar6 = iVar5 + 2;
  }
  if ((param_3 & 0xff) == 2) {
    if ((local_44 != 0) || (param_6 = param_5, uVar9 != 0)) {
      param_6 = param_5 + -1;
    }
    if ((unaff_r8 == 0x10) && (uVar1 != 0)) {
      param_6 = param_6 + -2;
    }
  }
  if (iRam02137708 < param_6 + (param_2 - (int)puVar7)) {
    return (uint *)0x0;
  }
  for (; iVar6 < param_6; iVar6 = iVar6 + 1) {
    puVar7 = (uint *)((int)puVar7 + -1);
    uVar2 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
            0x30;
    uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
  }
  if ((unaff_r8 == 0x10) && (uVar1 != 0)) {
    puVar3 = (uint *)((int)puVar7 + -1);
    uVar4 = uVar4 | (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                    *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) &
                    0xffffff00;
    uVar8 = (4 - ((uint)puVar3 & 3)) * 8 & 0x1f;
    *puVar3 = uVar4 >> uVar8 | uVar4 << 0x20 - uVar8;
    puVar7 = (uint *)((int)puVar7 + -2);
    uVar1 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
            0x30;
    uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar1 >> uVar8 | uVar1 << 0x20 - uVar8;
  }
  if (local_44 == 0) {
    if (uVar9 == 1) {
      puVar7 = (uint *)((int)puVar7 + -1);
      uVar1 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
              *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
              0x2b;
      uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
      *puVar7 = uVar1 >> uVar8 | uVar1 << 0x20 - uVar8;
    }
    else if (uVar9 == 2) {
      puVar7 = (uint *)((int)puVar7 + -1);
      uVar1 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
              *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
              0x20;
      uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
      *puVar7 = uVar1 >> uVar8 | uVar1 << 0x20 - uVar8;
    }
  }
  else {
    puVar7 = (uint *)((int)puVar7 + -1);
    uVar1 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
            0x2d;
    uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar1 >> uVar8 | uVar1 << 0x20 - uVar8;
  }
  return puVar7;
}

