/* Decompiled C draft; module arm9; ROM address 0211eb28. No matching claim. */
#include "types.h"
#include "deps/0211eb28_func_0211eb28.h"

void func_0211eb28(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  
  piVar3 = piRam0211ec38;
  *(undefined4 *)(*piRam0211ec38 + 0x30) = 1;
  iVar8 = 0;
  *(undefined4 *)(*piVar3 + 0x34) = 0;
  if (*psRam0211ec3c != 2) {
    iVar5 = *piVar3;
    uVar1 = *(ushort *)(*(int *)(iVar5 + 4) + 6);
    uVar2 = *(ushort *)(*(int *)(iVar5 + 0x10) + 6);
    *(undefined4 *)(iVar5 + 0x3c) = 0xc0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam0211ec40) = 0xc0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam0211ec44) = 0xc0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x86) = 0xc0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x46) = 0xc0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 6) = 0xc0;
    puVar6 = puRam0211ec48;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar6 * 0x40 + 6) = 0xc0;
      piVar4 = piRam0211ec38;
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    iVar8 = 0;
    puVar6 = puRam0211ec50;
    puVar7 = puRam0211ec4c;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x18) + (uint)*puVar7 * 0x40 + 6) = 0xc0;
      *(undefined2 *)(*(int *)(*piVar4 + 0x18) + ((uint)uVar1 + (uint)*puVar6) * 0x40 + 6) = 0xc0;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
    *(undefined4 *)(*piVar4 + 0x40) = 0xffffffe0;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + iRam0211ec40) = 0xffe0;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + iRam0211ec44) = 0xffe0;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0x86) = 0xffe0;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0x46) = 0xffe0;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 6) = 0xffe0;
    piVar3 = piRam0211ec38;
    iVar8 = 0;
    puVar6 = puRam0211ec48;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar6 * 0x40 + 6) = 0xffe0;
      piVar4 = piRam0211ec38;
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    iVar8 = 0;
    puVar6 = puRam0211ec50;
    puVar7 = puRam0211ec4c;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uint)*puVar7 * 0x40 + 6) = 0xffe0;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + ((uint)uVar2 + (uint)*puVar6) * 0x40 + 6) = 0xffe0;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  return;
}

