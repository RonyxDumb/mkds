/* Decompiled C draft; module arm9; ROM address 021137f4. No matching claim. */
#include "types.h"
#include "deps/021137f4_func_021137f4.h"

void func_021137f4(void)

{
  int *piVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = func_02113f1c();
  sVar2 = func_020adc64(6 - *(int *)(*piRam021138d8 + 0x80));
  piVar1 = piRam021138d8;
  *(short *)(*(int *)(*piRam021138d8 + 0x3c) + (uint)*puRam021138dc * 0x40 + 4) = -sVar2;
  uVar3 = func_020adc64(6 - *(int *)(*piVar1 + 0x84));
  puVar6 = puRam021138dc;
  piVar1 = piRam021138d8;
  *(undefined2 *)(*(int *)(*piRam021138d8 + 0x3c) + (uint)puRam021138dc[1] * 0x40 + 4) = uVar3;
  iVar9 = 0;
  iVar8 = 0;
  puVar7 = puRam021138e0;
  do {
    iVar5 = *piVar1 + iVar8;
    if (*(int *)(iVar5 + 0x80) < 1) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40) = 0;
    }
    else {
      *(int *)(iVar5 + 0x80) = *(int *)(iVar5 + 0x80) + -1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40) = 1;
    }
    iVar8 = iVar8 + 4;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  if (iVar4 == 0) {
    *(undefined4 *)(*(int *)(*piRam021138d8 + 0x3c) + (uint)*puRam021138e0 * 0x40) = 0;
  }
  iVar8 = func_021143b4();
  if (iVar8 <= iVar4 + 5) {
    *(undefined4 *)(*(int *)(*piRam021138d8 + 0x3c) + (uint)puRam021138e0[1] * 0x40) = 0;
  }
  return;
}

