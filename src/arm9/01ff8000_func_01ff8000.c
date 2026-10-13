/* Decompiled C draft; module arm9; ROM address 01ff8000. No matching claim. */
#include "types.h"
#include "deps/01ff8000_func_01ff8000.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_01ff8000(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (_DAT_04000208 == 0) {
    return;
  }
  uVar3 = _DAT_04000210 & _DAT_04000214;
  if (uVar3 != 0) {
    do {
      iVar2 = LZCOUNT(uVar3);
      uVar3 = uVar3 & ~(0x80000000U >> iVar2);
    } while (uVar3 != 0);
    _DAT_04000214 = 0x80000000 >> iVar2;
    uVar3 = iRam01ff8050 + (0x1f - iVar2) * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x01ff804c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))();
    return;
  }
  return;
}

