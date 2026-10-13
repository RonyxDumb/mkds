/* Decompiled C draft; module arm9; ROM address 020dee8c. No matching claim. */
#include "types.h"
#include "deps/020dee8c_func_020dee8c.h"

void func_020dee8c(void)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  func_020e55b4();
  iVar4 = IsRaceOptionMenuOn_from_thumb();
  uVar3 = uRam020deefc;
  iVar2 = iRam020deef8;
  puVar1 = puRam020deef4;
  if (iVar4 == 0) {
    *puRam020deef4 = *puRam020deef4 + 0xca;
    MTX_RotY43__from_thumb
              ((undefined4 *)(uintptr_t)(uVar3),(int)*(short *)(iVar2 + ((int)(uint)*puVar1 >> 4) * 4),
               (int)*(short *)(iVar2 + (((int)(uint)*puVar1 >> 4) * 2 + 1) * 2));
    return;
  }
  return;
}

