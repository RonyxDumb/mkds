/* Decompiled C draft; module arm9; ROM address 02119c20. No matching claim. */
#include "types.h"
#include "deps/02119c20_func_02119c20.h"

void func_02119c20(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  ushort *puVar8;
  ushort *puVar9;
  
  piVar3 = piRam02119d54;
  *(undefined4 *)(*piRam02119d54 + 0x38) = 0;
  *(undefined4 *)(*piVar3 + 0x3c) = 0;
  if (*psRam02119d58 != 2) {
    iVar5 = func_020cccb4();
    piVar3 = piRam02119d54;
    if (iVar5 != 0x1a) {
      uVar7 = (uint)*(ushort *)(*(int *)(*piRam02119d54 + 4) + 6);
      *(undefined4 *)(*piRam02119d54 + 0x44) = 0xffffff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 0x86) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 0x46) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + iRam02119d5c) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 0xc6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + iRam02119d60) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + uVar7 * 0x40 + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar7 + 1) * 0x40 + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar7 + 2) * 0x40 + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar7 + 3) * 0x40 + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar7 + 4) * 0x40 + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar7 + 5) * 0x40 + 6) = 0xff40;
    }
    iVar5 = func_020cccb4();
    piVar3 = piRam02119d54;
    if (iVar5 == 0x1a) {
      uVar6 = 0xffffff20;
    }
    else {
      uVar6 = 0xffffffe0;
    }
    uVar1 = *(ushort *)(*(int *)(*piRam02119d54 + 0x10) + 6);
    *(undefined4 *)(*piRam02119d54 + 0x48) = uVar6;
    uVar2 = (undefined2)uVar6;
    *(undefined2 *)(*(int *)(*piVar3 + 0x20) + iRam02119d64) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x20) + iRam02119d68) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x20) + 0x86) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x20) + 0x46) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x20) + 6) = uVar2;
    iVar5 = 0;
    puVar8 = puRam02119d6c;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x20) + (uint)*puVar8 * 0x40 + 6) = uVar2;
      piVar4 = piRam02119d54;
      puVar8 = puVar8 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
    iVar5 = 0;
    puVar8 = puRam02119d74;
    puVar9 = puRam02119d70;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + (uint)*puVar9 * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + ((uint)uVar1 + (uint)*puVar8) * 0x40 + 6) = uVar2;
      puVar9 = puVar9 + 1;
      puVar8 = puVar8 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  return;
}

