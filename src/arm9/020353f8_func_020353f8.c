/* Decompiled C draft; module arm9; ROM address 020353f8. No matching claim. */
#include "types.h"
#include "deps/020353f8_func_020353f8.h"

void func_020353f8(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = func_02025ebc(*piRam020354b8 + 0x90);
  uVar1 = uRam020354bc;
  *puRam020354c0 = iVar2 << 0x10 & uRam020354bc;
  *puRam020354c4 = iVar2 * -0x10000 & uVar1;
  uVar1 = uRam020354cc;
  if (iVar2 != 0) {
    *puRam020354c8 = *puRam020354c8 & uRam020354cc | uRam020354d0;
    *puRam020354d4 = *puRam020354d4 & 0xffc0 | 0x3f;
    *puRam020354d8 = *puRam020354d8 & 0xffc0 | 0x2e;
    *puRam020354dc = 0xff;
    *puRam020354e4 = (short)iVar2 * -0x100 & (ushort)uRam020354e0 | 0xc0;
    *puRam020354e8 = *puRam020354e8 & uRam020354cc | uRam020354d0;
    *puRam020354ec = *puRam020354ec & 0xffc0 | 0x3f;
    *puRam020354f0 = *puRam020354f0 & 0xffc0 | 0x27;
    *puRam020354f4 = 0xff;
    *puRam020354f8 = (short)iVar2 + 0xc0U & 0xff;
    return;
  }
  *puRam020354c8 = *puRam020354c8 & uRam020354cc;
  *puRam020354e8 = *puRam020354e8 & uVar1;
  return;
}

