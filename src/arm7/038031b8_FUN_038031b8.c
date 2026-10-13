/* Decompiled C draft; module arm7; ROM address 038031b8. No matching claim. */
#include "types.h"
#include "deps/038031b8_FUN_038031b8.h"

undefined4 FUN_038031b8(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_03803258;
  if (param_1 < 0x10000) {
    *(undefined2 *)(DAT_03803258 + 0x36) = 0;
    *(short *)(iVar1 + 0x34) = -(short)param_1;
    return 1;
  }
  if (param_1 < 0x400000) {
    *(undefined2 *)(DAT_03803258 + 0x36) = 1;
    *(short *)(iVar1 + 0x34) = -(short)(param_1 >> 6);
    return 1;
  }
  if (param_1 < 0x1000000) {
    *(undefined2 *)(DAT_03803258 + 0x36) = 2;
    *(short *)(iVar1 + 0x34) = -(short)(param_1 >> 8);
    return 1;
  }
  if (param_1 < 0x4000000) {
    *(undefined2 *)(DAT_03803258 + 0x36) = 3;
    *(short *)(iVar1 + 0x34) = -(short)(param_1 >> 10);
    return 1;
  }
  return 0;
}

