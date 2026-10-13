/* Decompiled C draft; module arm9_ov001; ROM address 0219ac98. No matching claim. */
#include "types.h"
#include "deps/0219ac98_FUN_0219ac98.h"

void FUN_0219ac98(void)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_18;
  
  iVar6 = 7;
  iVar5 = 0;
  local_18 = 0;
  iVar4 = local_18;
  do {
    iVar2 = func_0x02060440(iVar5,iVar4);
    if (iVar2 == 0) {
      iVar6 = 0;
    }
    else {
      iVar2 = func_0x02060364(iVar5,iVar4);
      if (iVar2 < iVar6) {
        iVar6 = iVar2;
      }
    }
    piVar1 = DAT_0219ad0c;
    iVar4 = iVar4 + 1;
  } while ((iVar4 < 4) || (iVar5 = iVar5 + 1, iVar4 = local_18, iVar5 < 8));
  iVar4 = 0;
  puVar3 = DAT_0219ad08;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar3 * 0x40) = 0;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  if (4 < iVar6) {
    *(undefined4 *)(*(int *)(*piVar1 + 0x18) + (uint)DAT_0219ad08[iVar6 + -5] * 0x40) = 1;
  }
  return;
}

