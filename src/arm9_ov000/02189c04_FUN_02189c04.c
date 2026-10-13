/* Decompiled C draft; module arm9_ov000; ROM address 02189c04. No matching claim. */
#include "types.h"
#include "deps/02189c04_FUN_02189c04.h"

undefined4 FUN_02189c04(int param_1)

{
  byte bVar1;
  
  *(undefined1 *)(param_1 + DAT_02189c44) = 0;
  bVar1 = *(byte *)(param_1 + DAT_02189c48);
  *(byte *)(param_1 + DAT_02189c48) =
       bVar1 & 0xf | (byte)(((((uint)bVar1 << 0x18) >> 0x1c) + 1 & 0xf) << 4);
  FUN_0218973c();
  *(undefined1 *)(param_1 + DAT_02189c4c) = 1;
  return 3;
}

