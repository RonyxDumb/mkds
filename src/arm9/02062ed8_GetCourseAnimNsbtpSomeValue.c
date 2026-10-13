/* Decompiled C draft; module arm9; ROM address 02062ed8. No matching claim. */
#include "types.h"
#include "deps/02062ed8_GetCourseAnimNsbtpSomeValue.h"

int GetCourseAnimNsbtpSomeValue(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(iRam02062ef4 + 0x20) == 0) {
    iVar3 = -1;
  }
  else {
    uVar1 = iRam02062ef4 + 0x14U & 3;
    uVar2 = *(uint *)(iRam02062ef4 + 0x14U & 0xfffffffc);
    iVar3 = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 0xc;
  }
  return iVar3;
}

