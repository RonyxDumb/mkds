/* Decompiled C draft; module arm9; ROM address 0205c800. No matching claim. */
#include "types.h"
#include "deps/0205c800_func_0205c800.h"

void func_0205c800(short param_1,code *param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = uRam0205c894;
  uVar2 = 1;
  do {
    uVar5 = (uint)(ushort)(param_1 + uVar2);
    if (3 < uVar5) {
      uVar5 = uVar5 - 4 & 0xffff;
    }
    uVar3 = func_0x0219bb50();
  } while (((uVar5 == uVar3) ||
           (uVar3 = uVar1 & 3, uVar4 = *(uint *)(uVar1 & 0xfffffffc),
           ((uint)*(byte *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x749) &
           1 << (uVar5 & 0xff)) == 0)) && (uVar2 = uVar2 + 1, uVar5 = 0xffffffff, uVar2 < 5));
  if (uVar5 == 0xffffffff) {
    return;
  }
  (*param_2)(uVar5);
  return;
}

