/* Decompiled C draft; module arm9_ov000; ROM address 021a9868. No matching claim. */
#include "types.h"
#include "deps/021a9868_FUN_021a9868.h"

void FUN_021a9868(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int *piVar9;
  
  piVar9 = *(int **)(param_1 + 0xc);
  puVar1 = (undefined1 *)(*(code *)*DAT_021a9974)(0x98);
  if (puVar1 == (undefined1 *)0x0) {
    *(undefined1 *)((int)piVar9 + DAT_021a9978) = 9;
    return;
  }
  puVar1[9] = 3;
  puVar1[10] = 0;
  uVar2 = FUN_021ab5bc();
  *(char *)(piVar9 + 2) = (char)((uint)uVar2 >> 0x18);
  *(char *)((int)piVar9 + 9) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)piVar9 + 10) = (char)((uint)uVar2 >> 8);
  *(char *)((int)piVar9 + 0xb) = (char)uVar2;
  FUN_021a9ca8(piVar9 + 3,0x1c);
  func_0x0214d1fc(piVar9 + 2,puVar1 + 0xb,0x20);
  iVar3 = FUN_021ab63c(*(undefined4 *)(param_1 + 0x1c),*(undefined2 *)(param_1 + 0x18));
  *piVar9 = iVar3;
  if (*piVar9 == 0) {
    puVar7 = puVar1 + 0x2c;
    puVar1[0x2b] = 0;
  }
  else {
    puVar1[0x2b] = 0x20;
    func_0x0214d1fc(*piVar9,puVar1 + 0x2c);
    puVar7 = puVar1 + 0x4c;
  }
  uVar6 = 0;
  *puVar7 = 0;
  puVar7[1] = 4;
  puVar5 = DAT_021a997c;
  puVar7 = puVar7 + 2;
  do {
    puVar4 = puVar7;
    *puVar4 = (char)((ushort)*puVar5 >> 8);
    puVar4[1] = (char)*puVar5;
    puVar5 = puVar5 + 1;
    uVar6 = uVar6 + 1;
    puVar7 = puVar4 + 2;
  } while (uVar6 < 2);
  puVar4[2] = 1;
  puVar4[3] = 0;
  puVar4 = puVar4 + (4 - (int)puVar1);
  puVar8 = puVar4 + -5;
  *puVar1 = 0x16;
  puVar1[1] = 3;
  puVar1[2] = 0;
  puVar1[3] = (char)((uint)puVar8 >> 8);
  puVar1[4] = (char)puVar8;
  puVar1[5] = 1;
  puVar7 = puVar4 + -9;
  puVar1[6] = (char)((uint)puVar7 >> 0x10);
  puVar1[7] = (char)((uint)puVar7 >> 8);
  puVar1[8] = (char)puVar7;
  FUN_021adcec(puVar1,puVar4,0,0,param_1);
  FUN_021ab728((int)piVar9 + DAT_021a9980,puVar1 + 5,puVar8);
  FUN_021abca0((int)piVar9 + DAT_021a9984,puVar1 + 5,puVar8);
  (*(code *)*DAT_021a9988)(puVar1);
  return;
}

