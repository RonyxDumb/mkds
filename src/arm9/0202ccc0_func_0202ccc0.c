/* Decompiled C draft; module arm9; ROM address 0202ccc0. No matching claim. */
#include "types.h"
#include "deps/0202ccc0_func_0202ccc0.h"

void func_0202ccc0(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = func_02025ebc(*piRam0202cd8c + 0xcc);
  uVar1 = uRam0202cd90;
  *puRam0202cd94 = iVar2 << 0x10 & uRam0202cd90;
  *puRam0202cd98 = iVar2 * -0x10000 & uVar1;
  *puRam0202cd9c = *puRam0202cd9c & 0xfffc | 1;
  uVar1 = uRam0202cda4;
  if (iVar2 != 0) {
    *puRam0202cda0 = *puRam0202cda0 & uRam0202cda4 | uRam0202cda8;
    *puRam0202cdac = *puRam0202cdac & 0xffc0 | 0x3f;
    *puRam0202cdb0 = *puRam0202cdb0 & 0xffc0 | 0x2e;
    *puRam0202cdb4 = 0xff;
    *puRam0202cdbc = (short)iVar2 * -0x100 & (ushort)uRam0202cdb8 | 0xc0;
    *puRam0202cdc0 = *puRam0202cdc0 & uRam0202cda4 | uRam0202cda8;
    *puRam0202cdc4 = *puRam0202cdc4 & 0xffc0 | 0x3f;
    *puRam0202cdc8 = *puRam0202cdc8 & 0xffc0 | 0x27;
    *puRam0202cdcc = 0xff;
    *puRam0202cdd0 = (short)iVar2 + 0xc0U & 0xff;
    return;
  }
  *puRam0202cda0 = *puRam0202cda0 & uRam0202cda4;
  *puRam0202cdc0 = *puRam0202cdc0 & uVar1;
  return;
}

