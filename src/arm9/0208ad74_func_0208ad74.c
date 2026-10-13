/* Decompiled C draft; module arm9; ROM address 0208ad74. No matching claim. */
#include "types.h"
#include "deps/0208ad74_func_0208ad74.h"

void func_0208ad74(undefined2 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if ((param_2 & 1 << (uVar3 & 0xff)) != 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 4);
  uVar2 = (*(uint *)(uRam0208adc4 & 0xfffffffc) >> (uRam0208adc4 & 3) * 8 |
          *(uint *)(uRam0208adc4 & 0xfffffffc) << (uRam0208adc4 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *param_1 = *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + uVar3 * 2 + 0x18);
  param_1[7] = (short)(1 << (uVar3 & 0xff));
  return;
}

