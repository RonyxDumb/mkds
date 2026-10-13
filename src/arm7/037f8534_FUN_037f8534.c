/* Decompiled C draft; module arm7; ROM address 037f8534. No matching claim. */
#include "types.h"
#include "deps/037f8534_FUN_037f8534.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_037f8534(void)

{
  uint uVar1;
  uint uVar2;
  
  if (_DAT_04000208 == 0) {
    return;
  }
  uVar2 = _DAT_04000210 & _DAT_04000214;
  if (uVar2 != 0) {
    for (uVar1 = 0; _DAT_04000214 = uVar2 & 1 << (uVar1 & 0xff), _DAT_04000214 == 0;
        uVar1 = uVar1 + 1) {
    }
    uVar2 = DAT_037f8580 + uVar1 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x037f857c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
    return;
  }
  return;
}

