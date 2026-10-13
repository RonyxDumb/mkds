/* Decompiled C draft; module arm9_ov001; ROM address 0219c480. No matching claim. */
#include "types.h"
#include "deps/0219c480_FUN_0219c480.h"

void FUN_0219c480(void)

{
  int *piVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  
  piVar1 = DAT_0219c528;
  iVar4 = 0;
  *(undefined4 *)(*DAT_0219c528 + 0x4c) = 0;
  *(undefined4 *)(*piVar1 + 0x50) = 0;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  *(undefined4 *)(*piVar1 + 0x5c) = 0xffffff40;
  puVar3 = DAT_0219c52c;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar3 * 0x40 + 6) = 0xff40;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  *(undefined2 *)(*(int *)(*piVar1 + 0x34) + DAT_0219c530) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar1 + 0x34) + DAT_0219c534) = 0xff40;
  piVar2 = DAT_0219c528;
  uVar5 = (uint)*(ushort *)(*(int *)(*piVar1 + 0x10) + 6);
  iVar4 = 0;
  puVar3 = DAT_0219c538;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x34) + (uVar5 + *puVar3) * 0x40 + 6) = 0xff40;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  *(undefined2 *)(*(int *)(*piVar2 + 0x34) + (uVar5 + 5) * 0x40 + 6) = 0xff40;
  piVar1 = DAT_0219c528;
  iVar4 = 0;
  puVar3 = DAT_0219c540;
  puVar6 = DAT_0219c53c;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar6 * 0x40 + 6) = 0xff40;
    *(undefined2 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar3 * 0x40 + 6) = 0xff40;
    puVar6 = puVar6 + 1;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return;
}

