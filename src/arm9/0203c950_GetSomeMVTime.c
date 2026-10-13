/* Decompiled C draft; module arm9; ROM address 0203c950. No matching claim. */
#include "types.h"
#include "deps/0203c950_GetSomeMVTime.h"

void GetSomeMVTime(undefined1 *param_1,undefined1 *param_2,undefined2 *param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0203c988 & 0xfffffffc) >> (uRam0203c988 & 3) * 8 |
          *(uint *)(uRam0203c988 & 0xfffffffc) << (uRam0203c988 & 3) * -8 + 0x20;
  *param_1 = *(undefined1 *)(uVar1 + 10);
  *param_2 = *(undefined1 *)(uVar1 + 0xb);
  *param_3 = *(undefined2 *)(uVar1 + 8);
  return;
}

