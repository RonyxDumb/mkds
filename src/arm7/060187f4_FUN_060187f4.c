/* Decompiled C draft; module arm7; ROM address 060187f4. No matching claim. */
#include "types.h"
#include "deps/060187f4_FUN_060187f4.h"

void FUN_060187f4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(DAT_06018840 & 0xfffffffc) >> (DAT_06018840 & 3) * 8 |
          *(uint *)(DAT_06018840 & 0xfffffffc) << (DAT_06018840 & 3) * -8 + 0x20) + 0x314;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  thunk_FUN_038015ac(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  FUN_060188a4();
  thunk_FUN_03804bbc(param_1,param_2,param_3);
  uVar2 = (*(uint *)(DAT_06018840 & 0xfffffffc) >> (DAT_06018840 & 3) * 8 |
          *(uint *)(DAT_06018840 & 0xfffffffc) << (DAT_06018840 & 3) * -8 + 0x20) + 0x314;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  thunk_FUN_03801540(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

