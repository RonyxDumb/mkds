/* Decompiled C draft; module arm9_ov001; ROM address 021a1b08. No matching claim. */
#include "types.h"
#include "deps/021a1b08_FUN_021a1b08.h"

void FUN_021a1b08(void)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar4 = FUN_021a1ba0();
  if (iVar4 != 0) {
    iVar4 = *DAT_021a1b94;
    if (*(int *)(iVar4 + 0x3c) == 7) {
      *(short *)(iVar4 + 0x40) = (short)*(undefined4 *)(iVar4 + 0x34);
      FUN_021a1bf8();
    }
    else {
      uVar3 = func_0x02116d10(7 - *(int *)(iVar4 + 0x3c),0);
      piVar1 = DAT_021a1b94;
      iVar4 = 0;
      puVar5 = DAT_021a1b98;
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40 + 6) = uVar3;
        piVar2 = DAT_021a1b94;
        puVar5 = puVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 6);
      iVar4 = 0;
      puVar5 = DAT_021a1b9c;
      do {
        *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar5 * 0x40 + 6) = uVar3;
        puVar5 = puVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    }
    *(int *)(*DAT_021a1b94 + 0x3c) = *(int *)(*DAT_021a1b94 + 0x3c) + -1;
    return;
  }
  iVar4 = *DAT_021a1b94;
  if (*(int *)(iVar4 + 0x34) != (int)*(short *)(iVar4 + 0x40)) {
    *(undefined4 *)(iVar4 + 0x3c) = 7;
  }
  return;
}

