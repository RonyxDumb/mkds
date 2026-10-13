/* Decompiled C draft; module arm9; ROM address 0211ec54. No matching claim. */
#include "types.h"
#include "deps/0211ec54_func_0211ec54.h"

void func_0211ec54(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  
  piVar3 = piRam0211ed64;
  iVar7 = 0;
  *(undefined4 *)(*piRam0211ed64 + 0x30) = 0;
  *(undefined4 *)(*piVar3 + 0x34) = 0;
  if (*psRam0211ed68 != 2) {
    iVar6 = *piVar3;
    uVar1 = *(ushort *)(*(int *)(iVar6 + 4) + 6);
    uVar2 = *(ushort *)(*(int *)(iVar6 + 0x10) + 6);
    *(undefined4 *)(iVar6 + 0x3c) = 0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam0211ed6c) = 0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam0211ed70) = 0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x86) = 0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x46) = 0;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 6) = 0;
    iVar6 = 0;
    puVar5 = puRam0211ed74;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar5 * 0x40 + 6) = 0;
      piVar4 = piRam0211ed64;
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
    iVar7 = 0;
    puVar5 = puRam0211ed7c;
    puVar8 = puRam0211ed78;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x18) + (uint)*puVar8 * 0x40 + 6) = 0;
      *(undefined2 *)(*(int *)(*piVar4 + 0x18) + ((uint)uVar1 + (uint)*puVar5) * 0x40 + 6) = 0;
      puVar8 = puVar8 + 1;
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
    *(undefined4 *)(*piVar4 + 0x40) = 0xffffff40;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + iRam0211ed6c) = 0xff40;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + iRam0211ed70) = 0xff40;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0x86) = 0xff40;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0x46) = 0xff40;
    *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 6) = 0xff40;
    piVar3 = piRam0211ed64;
    puVar5 = puRam0211ed74;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar5 * 0x40 + 6) = 0xff40;
      piVar4 = piRam0211ed64;
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
    iVar7 = 0;
    puVar5 = puRam0211ed7c;
    puVar8 = puRam0211ed78;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uint)*puVar8 * 0x40 + 6) = 0xff40;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + ((uint)uVar2 + (uint)*puVar5) * 0x40 + 6) = 0xff40;
      puVar8 = puVar8 + 1;
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 4);
  }
  return;
}

