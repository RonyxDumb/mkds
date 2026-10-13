/* Decompiled C draft; module arm9; ROM address 020302a0. No matching claim. */
#include "types.h"
#include "deps/020302a0_func_020302a0.h"

void func_020302a0(void)

{
  GXS_SetGraphicsMode__mkds_303a8(0x16);
  if (*(int *)(*piRam020302ec + 0x38) == 0) {
    GXS_SetGraphicsMode__mkds_3038c(0);
  }
  else {
    GXS_SetGraphicsMode__mkds_3038c(1);
    func_02030364(0x1f,1);
    func_0203033c(7,1);
    func_020302f0(0,0,0xff,*(int *)(*piRam020302ec + 0x38) + 0xc0);
  }
  return;
}

