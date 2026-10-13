/* Decompiled C draft; module arm9; ROM address 02026058. No matching claim. */
#include "types.h"
#include "deps/02026058_func_02026058.h"

void func_02026058(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x18;
  G2x_SetBlendAlpha_((uint *)(uintptr_t)(uRam020260c4),0,0x3f,6,10);
  uVar1 = uRam020260d0;
  if ((*(int *)(*piRam020260c8 + 0x6c) != 9) || (*(int *)(*piRam020260c8 + 0x8c) != 2)) {
    iVar2 = 0x19;
  }
  *puRam020260cc = *puRam020260cc & uRam020260d0 | iVar2 << 8;
  *puRam020260d4 = *puRam020260d4 & uVar1 | uRam020260d8;
  *puRam020260dc = *puRam020260dc & 0xfffc | 1;
  if (*(int *)(*piRam020260c8 + iRam020260e0) != 0) {
    func_0202ba14();
  }
  return;
}

