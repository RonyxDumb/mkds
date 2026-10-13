/* Decompiled C draft; module arm9; ROM address 02034244. No matching claim. */
#include "types.h"
#include "deps/02034244_func_02034244.h"

void func_02034244(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = func_02025ebc(*piRam02034304 + iRam02034308);
  uVar1 = uRam0203430c;
  *puRam02034310 = iVar2 << 0x10 & uRam0203430c;
  *puRam02034314 = iVar2 * -0x10000 & uVar1;
  uVar1 = uRam0203431c;
  if (iVar2 != 0) {
    *puRam02034318 = *puRam02034318 & uRam0203431c | uRam02034320;
    *puRam02034324 = *puRam02034324 & 0xffc0 | 0x3f;
    *puRam02034328 = *puRam02034328 & 0xffc0 | 0x2e;
    *puRam0203432c = 0xff;
    *puRam02034334 = (short)iVar2 * -0x100 & (ushort)uRam02034330 | 0xc0;
    *puRam02034338 = *puRam02034338 & uRam0203431c | uRam02034320;
    *puRam0203433c = *puRam0203433c & 0xffc0 | 0x3f;
    *puRam02034340 = *puRam02034340 & 0xffc0 | 0x27;
    *puRam02034344 = 0xff;
    *puRam02034348 = (short)iVar2 + 0xc0U & 0xff;
    return;
  }
  *puRam02034318 = *puRam02034318 & uRam0203431c;
  *puRam02034338 = *puRam02034338 & uVar1;
  return;
}

