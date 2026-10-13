/* Decompiled C draft; module arm9; ROM address 0211c14c. No matching claim. */
#include "types.h"
#include "deps/0211c14c_func_0211c14c.h"

void func_0211c14c(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  int iVar10;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  piVar3 = piRam0211c450;
  if (*(int *)(*piRam0211c44c + 0x20) == 2) {
    iVar2 = 0;
    *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + iRam0211c454) = 0;
    *(undefined4 *)(*(int *)(*piVar3 + 0x14) + iRam0211c458) = 0;
    iVar10 = 0;
    puVar6 = puRam0211c45c;
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar6 * 0x40) = 0;
      piVar1 = piRam0211c450;
      puVar6 = puVar6 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
    puVar6 = puRam0211c45c;
    puVar8 = puRam0211c464;
    puVar9 = puRam0211c460;
    if (*(int *)(*piVar3 + 0x78) != 2) {
      do {
        *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar9 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar8 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)puVar6[2] * 0x40) = 0;
        iVar10 = iVar10 + 1;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      } while (iVar10 < 2);
      return;
    }
    local_38 = 0;
    puVar6 = puRam0211c460;
    puVar9 = puRam0211c45c;
    do {
      piVar3 = (int *)*piRam0211c468;
      if (*piVar3 == 2) {
        uVar5 = (uint)*(ushort *)((int)piVar3 + iRam0211c46c);
      }
      else {
        uVar5 = 0;
      }
      iVar2 = func_0211d44c(*(undefined2 *)((int)piVar3 + iRam0211c470 + ((uVar5 << 0x10) >> 0xd)));
      if (iVar2 == 0) {
        *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + (uint)*puVar6 * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + (uint)*puVar8 * 0x40) = 1;
      }
      else {
        *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + (uint)*puVar6 * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + (uint)*puVar8 * 0x40) = 0;
      }
      iVar2 = *piRam0211c450 + local_38;
      if (*(short *)(iVar2 + 0x54) < 1) {
        *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + (uint)puVar9[2] * 0x40) = 0;
      }
      else {
        *(short *)(iVar2 + 0x54) = *(short *)(iVar2 + 0x54) + -1;
        *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + (uint)puVar9[2] * 0x40) = 1;
      }
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
      local_38 = local_38 + 2;
      puVar9 = puVar9 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 2);
    return;
  }
  iVar2 = *piRam0211c450;
  if (*(int *)(iVar2 + 0x74) == 2) {
    iVar10 = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x14) + iRam0211c454) = 0;
    *(undefined4 *)(*(int *)(*piVar3 + 0x14) + iRam0211c458) = 0;
    puVar6 = puRam0211c45c;
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar6 * 0x40) = 0;
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 2);
  }
  else {
    if ((*(int *)(iVar2 + 0x60) == 3) && (*(int *)(iVar2 + 0x7c) == 0)) {
      *(undefined4 *)(*(int *)(iVar2 + 0x14) + iRam0211c454) = 1;
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + iRam0211c458) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + 0x14) + iRam0211c454) = 0;
      *(undefined4 *)(*(int *)(*piRam0211c450 + 0x14) + iRam0211c458) = 1;
    }
    piVar3 = piRam0211c450;
    iVar10 = 0;
    iVar2 = 0;
    puVar6 = puRam0211c45c;
    do {
      iVar7 = *piVar3;
      iVar4 = iVar7 + iVar2;
      if (*(short *)(iVar4 + 0x50) < 1) {
        *(undefined4 *)(*(int *)(iVar7 + 0x14) + (uint)*puVar6 * 0x40) = 0;
      }
      else {
        *(short *)(iVar4 + 0x50) = *(short *)(iVar4 + 0x50) + -1;
        *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar6 * 0x40) = 1;
      }
      iVar2 = iVar2 + 2;
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 2);
  }
  piVar3 = piRam0211c450;
  if (*(int *)(*piRam0211c450 + 0x78) != 2) {
    iVar2 = 0;
    puVar6 = puRam0211c45c;
    puVar8 = puRam0211c464;
    puVar9 = puRam0211c460;
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar9 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar8 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)puVar6[2] * 0x40) = 0;
      puVar9 = puVar9 + 1;
      puVar8 = puVar8 + 1;
      puVar6 = puVar6 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
    return;
  }
  local_30 = 0;
  local_34 = 0;
  local_2c = 0;
  puVar6 = puRam0211c460;
  puVar8 = puRam0211c464;
  puVar9 = puRam0211c45c;
  do {
    iVar2 = *piVar3;
    if ((*(int *)(iVar2 + 0x60) == 4) && (*(int *)(iVar2 + 0x7c) == 0)) {
      piVar1 = (int *)*piRam0211c468;
      uVar5 = local_2c;
      if (*piVar1 == 2) {
        uVar5 = (uint)*(ushort *)((int)piVar1 + iRam0211c46c);
      }
      iVar2 = func_0211d44c(*(undefined2 *)((int)piVar1 + iRam0211c470 + ((uVar5 << 0x10) >> 0xd)));
      if (iVar2 == 0) {
        *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar6 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar8 * 0x40) = 1;
      }
      else {
        *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar6 * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar8 * 0x40) = 0;
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + 0x14) + (uint)*puVar6 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)*puVar8 * 0x40) = 1;
    }
    iVar2 = *piVar3 + local_34;
    if (*(short *)(iVar2 + 0x54) < 1) {
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)puVar9[2] * 0x40) = 0;
    }
    else {
      *(short *)(iVar2 + 0x54) = *(short *)(iVar2 + 0x54) + -1;
      *(undefined4 *)(*(int *)(*piVar3 + 0x14) + (uint)puVar9[2] * 0x40) = 1;
    }
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
    local_34 = local_34 + 2;
    puVar9 = puVar9 + 1;
    local_30 = local_30 + 1;
  } while (local_30 < 2);
  return;
}

