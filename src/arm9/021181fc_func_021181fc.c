/* Decompiled C draft; module arm9; ROM address 021181fc. No matching claim. */
#include "types.h"
#include "deps/021181fc_func_021181fc.h"

void func_021181fc(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  
  piVar1 = piRam021183d8;
  *(undefined4 *)(*piRam021183d8 + 0x34) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  if (*psRam021183dc != 2) {
    uVar8 = (uint)*(ushort *)(*(int *)(*piVar1 + 4) + 6);
    iVar3 = func_020cccb4();
    if ((iVar3 == 0x18) || (iVar3 = func_020cccb4(), piVar1 = piRam021183d8, iVar3 == 0xc)) {
      piVar1 = piRam021183d8;
      iVar6 = 0;
      *(undefined4 *)(*piRam021183d8 + 0x40) = 0;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + iRam021183e0) = 0;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + iRam021183e4) = 0;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 0x86) = 0;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 0x46) = 0;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 6) = 0;
      iVar3 = 0;
      puVar4 = puRam021183e8;
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar4 * 0x40 + 6) = 0;
        piVar2 = piRam021183d8;
        puVar4 = puVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 8);
      iVar6 = 0;
      puVar4 = puRam021183ec;
      do {
        *(undefined2 *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar4 * 0x40 + 6) = 0;
        piVar1 = piRam021183d8;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
        puVar5 = puRam021183f4;
        puVar7 = puRam021183f0;
      } while (iVar3 < 4);
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar7 * 0x40 + 6) = 0;
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uVar8 + *puVar5) * 0x40 + 6) = 0;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar6 < 4);
    }
    else {
      *(undefined4 *)(*piRam021183d8 + 0x40) = 0xffffff40;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + iRam021183e0) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + iRam021183e4) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 0x86) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 0x46) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar1 + 0x18) + 6) = 0xff40;
      iVar3 = 0;
      puVar4 = puRam021183e8;
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar4 * 0x40 + 6) = 0xff40;
        piVar2 = piRam021183d8;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 8);
      iVar3 = 0;
      puVar4 = puRam021183ec;
      do {
        *(undefined2 *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar4 * 0x40 + 6) = 0xff40;
        piVar1 = piRam021183d8;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      iVar3 = 0;
      puVar4 = puRam021183f4;
      puVar5 = puRam021183f0;
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar5 * 0x40 + 6) = 0xff40;
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uVar8 + *puVar4) * 0x40 + 6) = 0xff40;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
    }
    piVar1 = piRam021183d8;
    *(undefined2 *)(*(int *)(*piRam021183d8 + 0x18) + iRam021183e0) = 0xff40;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + 4) = 0xff20;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + 0x44) = 0xe0;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + 0x84) = 0xff20;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + 0xc4) = 0xe0;
    iVar3 = 0;
    puVar4 = puRam021183f8;
    do {
      iVar6 = 0;
      puVar5 = puVar4;
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar5 * 0x40 + 4) = 0xff20;
        piVar2 = piRam021183d8;
        puVar5 = puVar5 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 6);
      puVar4 = puVar4 + 6;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar3 = 4;
    puVar4 = puRam021183fc;
    do {
      iVar6 = 0;
      puVar5 = puVar4;
      do {
        *(undefined2 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar5 * 0x40 + 4) = 0xe0;
        puVar5 = puVar5 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 6);
      puVar4 = puVar4 + 6;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
  }
  return;
}

