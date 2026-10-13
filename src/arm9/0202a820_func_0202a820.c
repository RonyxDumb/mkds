/* Decompiled C draft; module arm9; ROM address 0202a820. No matching claim. */
#include "types.h"
#include "deps/0202a820_func_0202a820.h"

void func_0202a820(void)

{
  short sVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  ConfigureDispcntDisplay(1,0,0);
  *puRam0202a8d0 = *puRam0202a8d0 & uRam0202a8d4 | uRam0202a8d8;
  *puRam0202a8dc = *puRam0202a8dc & 0xfffc | 2;
  iVar4 = func_02025ebc(*piRam0202a8e0 + 0xdc);
  uVar3 = uRam0202a8e4;
  *puRam0202a8e8 = iVar4 * -0x10000 & uRam0202a8e4;
  iVar4 = iRam0202a8ec;
  piVar2 = piRam0202a8e0;
  *puRam0202a8f0 = *(short *)(*piRam0202a8e0 + iRam0202a8ec) * -0x10000 & uVar3;
  if (*(short *)(*piVar2 + iVar4) != 0) {
    *puRam0202a8d0 = *puRam0202a8d0 & uRam0202a8f4 | uRam0202a8f8;
    *puRam0202a8fc = *puRam0202a8fc & 0xffc0 | 0x3f;
    *puRam0202a900 = *puRam0202a900 & 0xffc0 | 0x27;
    sVar1 = *(short *)(*piVar2 + iVar4);
    *puRam0202a904 = 0xff;
    *puRam0202a908 = sVar1 + 0xc0U & 0xff;
    return;
  }
  *puRam0202a8d0 = *puRam0202a8d0 & uRam0202a8f4;
  return;
}

