/* Decompiled C draft; module arm9; ROM address 020f1b10. No matching claim. */
#include "types.h"
#include "deps/020f1b10_func_020f1b10.h"

void func_020f1b10(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,uRam020f1cc0);
  *piRam020f1cc4 = (int)puVar4;
  iVar7 = 0x15;
  puVar10 = puVar4;
  puVar9 = puRam020f1cc8;
  do {
    uVar3 = *puVar9;
    uVar6 = puVar9[1];
    puVar9 = puVar9 + 2;
    *puVar10 = uVar3;
    puVar10[1] = uVar6;
    puVar10 = puVar10 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = puVar4 + 0x2a;
  iVar7 = 0x15;
  puVar10 = puRam020f1ccc;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1cd4);
  iVar7 = 0x15;
  puVar10 = puRam020f1cd0;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1cdc);
  iVar7 = 0x15;
  puVar10 = puRam020f1cd8;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1ce4);
  iVar7 = 0x15;
  puVar10 = puRam020f1ce0;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1cec);
  iVar7 = 0x15;
  puVar10 = puRam020f1ce8;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1cf4);
  iVar7 = 0x15;
  puVar10 = puRam020f1cf0;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1cfc);
  iVar7 = 0x15;
  puVar10 = puRam020f1cf8;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1d04);
  iVar7 = 0x15;
  puVar10 = puRam020f1d00;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1d0c);
  iVar7 = 0x15;
  puVar10 = puRam020f1d08;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1d14);
  iVar7 = 0x15;
  puVar10 = puRam020f1d10;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1d1c);
  iVar7 = 0x15;
  puVar10 = puRam020f1d18;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar9 = (undefined4 *)((int)puVar4 + iRam020f1d24);
  iVar7 = 0x15;
  puVar10 = puRam020f1d20;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar9 = uVar3;
    puVar9[1] = uVar6;
    puVar9 = puVar9 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar4 = (undefined4 *)((int)puVar4 + iRam020f1d2c);
  iVar7 = 0x15;
  puVar10 = puRam020f1d28;
  do {
    uVar3 = *puVar10;
    uVar6 = puVar10[1];
    puVar10 = puVar10 + 2;
    *puVar4 = uVar3;
    puVar4[1] = uVar6;
    iVar8 = iRam020f1d30;
    piVar1 = piRam020f1cc4;
    puVar4 = puVar4 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0;
  do {
    iVar11 = iVar7 * 0xa8;
    uVar3 = func_020f1d40(iVar7);
    *(undefined4 *)(*piVar1 + iVar11 + 0x4c) = uVar3;
    pcVar5 = *(code **)(*piVar1 + iVar11 + 0x58);
    if (pcVar5 == (code *)0x0) {
      uVar3 = *(undefined4 *)(iVar8 + 0x44);
    }
    else {
      uVar3 = (*pcVar5)();
    }
    *(undefined4 *)(*piVar1 + iVar11 + 0xa4) = uVar3;
    piVar2 = piRam020f1cc4;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xe);
  iVar7 = *(int *)(*piRam020f1d34 + 8);
  if (iVar7 == 2) {
    *(undefined4 *)(*piRam020f1cc4 + iRam020f1d38) = 8;
    return;
  }
  if (iVar7 == 4) {
    iVar7 = 0;
    do {
      iVar8 = *piVar2 + iVar7 * 0xa8;
      *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar8 + 8);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0xe);
    return;
  }
  if (iVar7 == 5) {
    *(undefined4 *)(*piRam020f1cc4 + iRam020f1d3c) = 0x20;
    return;
  }
  return;
}

