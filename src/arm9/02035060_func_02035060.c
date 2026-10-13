/* Decompiled C draft; module arm9; ROM address 02035060. No matching claim. */
#include "types.h"
#include "deps/02035060_func_02035060.h"

void func_02035060(void)

{
  short *psVar1;
  undefined2 uVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_28;
  
  psVar1 = psRam0203510c;
  iVar4 = *piRam02035108;
  uVar5 = (uint)*(ushort *)(*(int *)(iVar4 + 0x54) + 6);
  iVar6 = 0;
  local_28 = 0;
  psVar3 = psRam0203510c;
  do {
    func_02025edc((int *)(uintptr_t)(*piRam02035108 + 200 + local_28));
    uVar2 = func_02025ebc(*piRam02035108 + 200 + local_28);
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + (uVar5 + (int)psVar1[(iVar6 + 4) * 4]) * 0x40 + 4) =
         uVar2;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + (uVar5 + (int)*psVar3) * 0x40 + 4) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + (uVar5 + (int)psVar1[(iVar6 + 4) * 4]) * 0x40 + 4)
    ;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + psVar3[3] * 0x40 + 4) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + (uVar5 + (int)*psVar3) * 0x40 + 4);
    if (*(int *)(*piRam02035108 + 0x80) == iVar6) {
      *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam02035110) = uVar2;
    }
    local_28 = local_28 + 0x3c;
    psVar3 = psVar3 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 4);
  return;
}

