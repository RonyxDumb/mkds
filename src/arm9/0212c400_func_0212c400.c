/* Decompiled C draft; module arm9; ROM address 0212c400. No matching claim. */
#include "types.h"
#include "deps/0212c400_func_0212c400.h"

undefined4 func_0212c400(uint param_1,undefined4 param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    return 0;
  }
  if (*(char *)(uVar2 + 0x2d) != '\0') {
    uVar1 = func_02021868(*(undefined1 *)(uVar2 + 0x3c));
    *param_3 = uVar1;
    return 1;
  }
  *param_3 = 0xffff;
  return 1;
}

