/* Decompiled C draft; module arm9_ov001; ROM address 02194f20. No matching claim. */
#include "types.h"
#include "deps/02194f20_FUN_02194f20.h"

void FUN_02194f20(void)

{
  int *piVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  
  sVar2 = func_0x020adc64(6 - *(int *)(*DAT_02194fcc + 0x80));
  piVar1 = DAT_02194fcc;
  *(short *)(*(int *)(*DAT_02194fcc + 0x54) + (uint)*DAT_02194fd0 * 0x40 + 4) = -sVar2;
  uVar3 = func_0x020adc64(6 - *(int *)(*piVar1 + 0x84));
  puVar5 = DAT_02194fd0;
  piVar1 = DAT_02194fcc;
  *(undefined2 *)(*(int *)(*DAT_02194fcc + 0x54) + (uint)DAT_02194fd0[1] * 0x40 + 4) = uVar3;
  iVar8 = 0;
  iVar7 = 0;
  puVar6 = DAT_02194fd4;
  do {
    iVar4 = *piVar1 + iVar7;
    if (*(int *)(iVar4 + 0x80) < 1) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*puVar6 * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*puVar5 * 0x40) = 0;
    }
    else {
      *(int *)(iVar4 + 0x80) = *(int *)(iVar4 + 0x80) + -1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*puVar6 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*puVar5 * 0x40) = 1;
    }
    iVar7 = iVar7 + 4;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  return;
}

