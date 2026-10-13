/* Decompiled C draft; module arm9_ov001; ROM address 021811c8. No matching claim. */
#include "types.h"
#include "deps/021811c8_func_ov001_021811c8.h"

void func_ov001_021811c8(void)

{
  int *piVar1;
  
  piVar1 = piRam021811fc;
  if (*(int *)(*piRam021811fc + 0xc) == 0) {
    *(undefined4 *)(*piRam021811fc + 0x10) = 1;
    *(undefined4 *)(*piVar1 + 0xc) = 1;
    *(undefined4 *)(*piVar1 + 0x14) = 0;
    piVar1 = (int *)*piVar1;
    func_0x0214d0a8(piVar1[8],piVar1[9],*piVar1 * *piVar1);
  }
  return;
}

