/* Decompiled C draft; module arm9_ov001; ROM address 02198878. No matching claim. */
#include "types.h"
#include "deps/02198878_FUN_02198878.h"

void FUN_02198878(void)

{
  int *piVar1;
  uint uVar2;
  
  if (*(int *)(*DAT_021988f8 + 0x3c) == 0) {
    *DAT_021988fc =
         *DAT_021988fc & DAT_02198904 | ((*DAT_021988fc & DAT_02198900) >> 8 & 0xfffffffd) << 8;
  }
  else {
    *DAT_021988fc = *DAT_021988fc & DAT_02198904 | ((*DAT_021988fc & DAT_02198900) >> 8 | 2) << 8;
  }
  func_0x0214a40c((uint *)(uintptr_t)(DAT_02198908),0,2,6,10);
  uVar2 = DAT_0219890c;
  piVar1 = DAT_021988f8;
  *DAT_02198910 = *(short *)(*DAT_021988f8 + 0x24) * -0x10000 & DAT_0219890c;
  *DAT_02198914 = *(short *)(*piVar1 + 0x24) * -0x10000 & uVar2;
  return;
}

