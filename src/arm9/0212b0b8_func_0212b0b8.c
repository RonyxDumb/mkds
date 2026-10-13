/* Decompiled C draft; module arm9; ROM address 0212b0b8. No matching claim. */
#include "types.h"
#include "deps/0212b0b8_func_0212b0b8.h"

undefined4 func_0212b0b8(void)

{
  int *piVar1;
  int *piVar2;
  
  if (*(int *)(*piRam0212b130 + 0xc) == 0) {
    return 0xffffffff;
  }
  SetBrightness((ushort *)(uintptr_t)(uRam0212b134),0);
  SetBrightness((ushort *)(uintptr_t)(uRam0212b138),0);
  piVar1 = piRam0212b130;
  if ((*puRam0212b13c & 1) != 0) {
    piVar2 = (int *)*piRam0212b130;
    if (piVar2[1] != 0) {
      if (*piVar2 - 4U < 2) {
        *(undefined4 *)(*piRam0212b140 + 0x58) = 1;
        *(undefined4 *)(*piVar1 + 0x10) = 1;
      }
      else if (*piVar2 == 6) {
        *(undefined4 *)(*piRam0212b140 + 0x1c) = 1;
        *(undefined4 *)(*piVar1 + 0x10) = 1;
        func_02120610();
      }
      else {
        piVar2[4] = 0;
      }
    }
  }
  return *(undefined4 *)(*piRam0212b130 + 0x10);
}

