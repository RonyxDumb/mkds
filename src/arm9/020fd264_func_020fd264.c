/* Decompiled C draft; module arm9; ROM address 020fd264. No matching claim. */
#include "types.h"
#include "deps/020fd264_func_020fd264.h"

void func_020fd264(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  *piRam020fd2e0 = iRam020fd2dc;
  uVar2 = FX_Div(uRam020fd2e4);
  *puRam020fd2e8 = uVar2;
  *puRam020fd2f0 = uRam020fd2ec;
  uVar4 = Multiply64(*piRam020fd2e0,*piRam020fd2e0 >> 0x1f,*(int *)(*piRam020fd2f4 + iRam020fd2f8),
                     *(int *)(*piRam020fd2f4 + iRam020fd2f8) >> 0x1f);
  puVar1 = puRam020fd2fc;
  uVar3 = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
  *puRam020fd2fc = uVar3;
  uVar3 = (int)uVar3 >> 0xc;
  *puVar1 = uVar3;
  *puVar1 = uVar3 * uVar3;
  if (*(int *)(*piRam020fd300 + 0x10) == 0) {
    *puRam020fd304 = 0xb4;
    return;
  }
  if (*(int *)(*piRam020fd300 + 0x10) != 1) {
    *puRam020fd304 = 0x78;
    return;
  }
  *puRam020fd304 = 0x96;
  return;
}

