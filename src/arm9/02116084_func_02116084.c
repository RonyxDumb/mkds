/* Decompiled C draft; module arm9; ROM address 02116084. No matching claim. */
#include "types.h"
#include "deps/02116084_func_02116084.h"

void func_02116084(void)

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
  
  iVar4 = func_02116870();
  sVar2 = func_020adc64(6 - *(int *)(*piRam02116168 + 0x90));
  piVar1 = piRam02116168;
  *(short *)(*(int *)(*piRam02116168 + 0x3c) + (uint)*puRam0211616c * 0x40 + 4) = -sVar2;
  uVar3 = func_020adc64(6 - *(int *)(*piVar1 + 0x94));
  puVar6 = puRam0211616c;
  piVar1 = piRam02116168;
  *(undefined2 *)(*(int *)(*piRam02116168 + 0x3c) + (uint)puRam0211616c[1] * 0x40 + 4) = uVar3;
  iVar9 = 0;
  iVar8 = 0;
  puVar7 = puRam02116170;
  do {
    iVar5 = *piVar1 + iVar8;
    if (*(int *)(iVar5 + 0x90) < 1) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40) = 0;
    }
    else {
      *(int *)(iVar5 + 0x90) = *(int *)(iVar5 + 0x90) + -1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40) = 1;
    }
    iVar8 = iVar8 + 4;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  if (iVar4 == 0) {
    *(undefined4 *)(*(int *)(*piRam02116168 + 0x3c) + (uint)*puRam02116170 * 0x40) = 0;
  }
  iVar8 = func_021143b4();
  if (iVar8 <= iVar4 + 5) {
    *(undefined4 *)(*(int *)(*piRam02116168 + 0x3c) + (uint)puRam02116170[1] * 0x40) = 0;
  }
  return;
}

