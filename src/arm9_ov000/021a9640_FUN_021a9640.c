/* Decompiled C draft; module arm9_ov000; ROM address 021a9640. No matching claim. */
#include "types.h"
#include "deps/021a9640_FUN_021a9640.h"

void FUN_021a9640(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  int *piVar13;
  uint uVar14;
  
  piVar13 = *(int **)(param_1 + 0xc);
  *(undefined1 *)(*piVar13 + 0x20) = 3;
  *(undefined1 *)(*piVar13 + 0x21) = 0;
  FUN_021a9ca8(*piVar13 + 0x22,0x2e);
  uVar14 = *(uint *)((int)piVar13 + DAT_021a983c);
  iVar1 = func_0x02133068(uVar14 << 1,2);
  puVar2 = (undefined1 *)(*(code *)*DAT_021a9840)(uVar14);
  if (puVar2 == (undefined1 *)0x0) {
    *(undefined1 *)((int)piVar13 + DAT_021a9844) = 9;
    return;
  }
  *puVar2 = 0;
  puVar2[1] = 2;
  FUN_021a9ca8((int)(uintptr_t)(puVar2 + 2),uVar14 - 0x33);
  puVar2[uVar14 - 0x31] = 0;
  func_0x0214d1fc((ushort *)(uintptr_t)(*piVar13 + 0x20),(uint *)(void *)(puVar2 + (uVar14 - 0x30)),0x30);
  iVar3 = (*(code *)*DAT_021a9840)(iVar1 << 3);
  if (iVar3 == 0) {
    (*(code *)*DAT_021a9848)(puVar2);
    *(undefined1 *)((int)piVar13 + DAT_021a9844) = 9;
    return;
  }
  iVar9 = iVar1 * 2;
  iVar4 = iVar3 + iVar9;
  iVar5 = iVar4 + iVar9;
  iVar9 = iVar5 + iVar9;
  FUN_021ac4b8((ushort *)(uintptr_t)(iVar4),(int)(uintptr_t)(puVar2),uVar14,iVar1);
  FUN_021ac4b8((ushort *)(uintptr_t)(iVar5),(int)piVar13 + DAT_021a984c,*(undefined4 *)((int)piVar13 + DAT_021a9850),iVar1)
  ;
  FUN_021ac4b8((ushort *)(uintptr_t)(iVar9),(int)piVar13 + DAT_021a9854,uVar14,iVar1);
  if (*DAT_021a9858 < 0x20) {
    uVar6 = *(undefined4 *)(DAT_021a985c + 4);
    uVar7 = func_0x0200dcd8();
    func_0x0200dce0(uVar6,*DAT_021a9858);
    FUN_021ac7e8((undefined2 *)(uintptr_t)(iVar3),iVar4,iVar5,iVar1,iVar9);
    func_0x0200dce0(uVar6,uVar7);
  }
  else {
    FUN_021ac7e8((undefined2 *)(uintptr_t)(iVar3),iVar4,iVar5,iVar1,iVar9);
  }
  puVar8 = (undefined1 *)(*(code *)*DAT_021a9840)(uVar14 + 0x49);
  if (puVar8 == (undefined1 *)0x0) {
    (*(code *)*DAT_021a9848)(puVar2);
    (*(code *)*DAT_021a9848)(iVar3);
    *(undefined1 *)((int)piVar13 + DAT_021a9844) = 9;
    return;
  }
  *puVar8 = 0x16;
  puVar8[1] = 3;
  puVar8[2] = 0;
  puVar8[3] = (char)(uVar14 + 4 >> 8);
  puVar8[4] = (char)(uVar14 + 4);
  puVar8[5] = 0x10;
  puVar8[6] = (char)(uVar14 >> 0x10);
  puVar8[7] = (char)(uVar14 >> 8);
  puVar12 = puVar8 + 9;
  puVar8[8] = (char)uVar14;
  if ((uVar14 & 1) != 0) {
    iVar1 = func_0x02133068(uVar14,2);
    *puVar12 = (char)*(undefined2 *)(iVar3 + iVar1 * 2);
    puVar12 = puVar8 + 10;
  }
  iVar1 = func_0x02133068(uVar14,2);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    puVar11 = (undefined2 *)(iVar3 + iVar1 * 2);
    do {
      *puVar12 = (char)((ushort)*puVar11 >> 8);
      puVar10 = puVar12 + 1;
      puVar12 = puVar12 + 2;
      *puVar10 = (char)*puVar11;
      puVar11 = puVar11 + -1;
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  FUN_021adcec((int)(uintptr_t)(puVar8),uVar14 + 9,0,0,param_1);
  FUN_021ab728((int)piVar13 + DAT_021a9860,(int)(uintptr_t)(puVar8 + 5),uVar14 + 4);
  FUN_021abca0((int)piVar13 + DAT_021a9864,(int)(uintptr_t)(puVar8 + 5),uVar14 + 4);
  (*(code *)*DAT_021a9848)(puVar8);
  (*(code *)*DAT_021a9848)(iVar3);
  (*(code *)*DAT_021a9848)(puVar2);
  return;
}

