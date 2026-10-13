/* Decompiled C draft; module arm9_ov001; ROM address 0219c2a4. No matching claim. */
#include "types.h"
#include "deps/0219c2a4_FUN_0219c2a4.h"

void FUN_0219c2a4(void)

{
  int *piVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  
  sVar2 = func_0x020adc64(6 - *(short *)(*DAT_0219c34c + 0x54));
  piVar1 = DAT_0219c34c;
  *(short *)(*(int *)(*DAT_0219c34c + 0x34) + (uint)*DAT_0219c350 * 0x40 + 4) = -sVar2;
  uVar3 = func_0x020adc64(6 - *(short *)(*piVar1 + 0x56));
  puVar5 = DAT_0219c350;
  piVar1 = DAT_0219c34c;
  *(undefined2 *)(*(int *)(*DAT_0219c34c + 0x34) + (uint)DAT_0219c350[1] * 0x40 + 4) = uVar3;
  iVar8 = 0;
  iVar7 = 0;
  puVar6 = DAT_0219c354;
  do {
    iVar4 = *piVar1 + iVar7;
    if (*(short *)(iVar4 + 0x54) < 1) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar6 * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar5 * 0x40) = 0;
    }
    else {
      *(short *)(iVar4 + 0x54) = *(short *)(iVar4 + 0x54) + -1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar6 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)*puVar5 * 0x40) = 1;
    }
    iVar7 = iVar7 + 2;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  return;
}

