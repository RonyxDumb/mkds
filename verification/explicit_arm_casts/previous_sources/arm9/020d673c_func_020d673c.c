/* Decompiled C draft; module arm9; ROM address 020d673c. No matching claim. */
#include "types.h"
#include "deps/020d673c_func_020d673c.h"

void func_020d673c(void)

{
  int iVar1;
  
  iVar1 = GetSomeTimeOrDuration();
  iVar1 = (int)((uint)(iVar1 << 0x19) >> 0x10) >> 4;
  MTX_RotY33__from_thumb
            ((*(uint *)(uRam020d678c & 0xfffffffc) >> (uRam020d678c & 3) * 8 |
             *(uint *)(uRam020d678c & 0xfffffffc) << (uRam020d678c & 3) * -8 + 0x20) + 0x2c,
             (int)*(short *)(iRam020d6790 + iVar1 * 4),
             (int)*(short *)(iRam020d6790 + (iVar1 * 2 + 1) * 2));
  return;
}

