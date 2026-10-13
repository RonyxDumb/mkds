/* Decompiled C draft; module arm9_ov001; ROM address 02196cd0. No matching claim. */
#include "types.h"
#include "deps/02196cd0_FUN_02196cd0.h"

void FUN_02196cd0(void)

{
  int *piVar1;
  short sVar2;
  undefined2 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  sVar2 = func_0x020adc64(6 - *(int *)(*DAT_02196d6c + 0x78));
  piVar1 = DAT_02196d6c;
  *(short *)(*(int *)(*DAT_02196d6c + 0x3c) + (uint)*DAT_02196d70 * 0x40 + 4) = -sVar2;
  uVar3 = func_0x020adc64(6 - *(int *)(*piVar1 + 0x7c));
  puVar5 = DAT_02196d70;
  piVar1 = DAT_02196d6c;
  *(undefined2 *)(*(int *)(*DAT_02196d6c + 0x3c) + (uint)DAT_02196d70[1] * 0x40 + 4) = uVar3;
  iVar9 = 0;
  iVar6 = 0;
  puVar4 = DAT_02196d74;
  do {
    iVar8 = *piVar1 + iVar6;
    iVar7 = *(int *)(iVar8 + 0x78);
    if (iVar7 < 1) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar4 * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar5 * 0x40) = 0;
    }
    else {
      *(int *)(iVar8 + 0x78) = iVar7 + -1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar4 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar5 * 0x40) = 1;
    }
    iVar6 = iVar6 + 4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  return;
}

