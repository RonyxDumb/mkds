/* Decompiled C draft; module arm9; ROM address 021431d8. No matching claim. */
#include "types.h"
#include "deps/021431d8_func_021431d8.h"

undefined2 func_021431d8(void)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  
  iVar3 = Wm_GetGlobal();
  iVar4 = Wm_CheckInitialized();
  if (iVar4 != 0) {
    return 0;
  }
  uVar1 = iVar3 + 4U & 3;
  uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,2);
  uVar1 = iVar3 + 4U & 3;
  uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  psVar6 = (short *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  sVar2 = *psVar6;
  if (sVar2 == 9) {
    DC_InvalidateRangeNoClean((int)psVar6 + iRam0214327c,2);
    uVar1 = iVar3 + 4U & 3;
    uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    psVar6 = (short *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
    if (psVar6[0xbf] == 0) {
      return 0;
    }
  }
  else if ((sVar2 != 10) && (sVar2 != 0xb)) {
    return 0;
  }
  DC_InvalidateRangeNoClean((uint)(uintptr_t)(psVar6 + 0x5c),2);
  uVar1 = iVar3 + 4U & 3;
  uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  return *(undefined2 *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0xb8);
}

