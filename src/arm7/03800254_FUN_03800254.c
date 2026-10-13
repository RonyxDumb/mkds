/* Decompiled C draft; module arm7; ROM address 03800254. No matching claim. */
#include "types.h"
#include "deps/03800254_FUN_03800254.h"

void FUN_03800254(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 local_8;
  char local_7 [7];
  
  uVar2 = (*(uint *)(DAT_0380033c & 0xfffffffc) >> (DAT_0380033c & 3) * 8 |
          *(uint *)(DAT_0380033c & 0xfffffffc) << (DAT_0380033c & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == DAT_03800340) &&
     (*(uint *)((uint)DAT_03800344 & 0xfffffffc) >> ((uint)DAT_03800344 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_03800344 & 0xfffffffc) << ((uint)DAT_03800344 & 3) * -8 + 0x20 == 0)) {
    local_8 = 5;
    FUN_038006f0(2);
    FUN_03800538((int)(uintptr_t)(&local_8),0,1,DAT_03800348);
    FUN_03800538(0,(int)(uintptr_t)(local_7),1,DAT_0380034c);
    FUN_03800610(0,0);
    if (local_7[0] != '\0') {
      FUN_038003fc();
      local_8 = 1;
      local_7[0] = '\0';
      FUN_038006f0(2);
      FUN_03800538((int)(uintptr_t)(&local_8),0,1,DAT_03800348);
      FUN_03800538((int)(uintptr_t)(local_7),0,1,DAT_03800348);
      FUN_03800610(0,0);
    }
    *DAT_03800344 = 1;
  }
  return;
}

