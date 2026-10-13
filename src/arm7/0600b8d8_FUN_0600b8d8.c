/* Decompiled C draft; module arm7; ROM address 0600b8d8. No matching claim. */
#include "types.h"
#include "deps/0600b8d8_FUN_0600b8d8.h"

undefined4 FUN_0600b8d8(undefined2 *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined2 *)
           ((*(uint *)(DAT_0600b904 & 0xfffffffc) >> (DAT_0600b904 & 3) * 8 |
            *(uint *)(DAT_0600b904 & 0xfffffffc) << (DAT_0600b904 & 3) * -8 + 0x20) + 900);
  do {
    *puVar1 = *param_1;
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x10);
  return 0;
}

