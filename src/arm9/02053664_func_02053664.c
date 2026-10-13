/* Decompiled C draft; module arm9; ROM address 02053664. No matching claim. */
#include "types.h"
#include "deps/02053664_func_02053664.h"

void func_02053664(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0214358c(0xf,uRam020536d4,0);
  uVar3 = uRam020536d8;
  *(undefined4 *)
   ((*(uint *)(uRam020536d8 & 0xfffffffc) >> (uRam020536d8 & 3) * 8 |
    *(uint *)(uRam020536d8 & 0xfffffffc) << (uRam020536d8 & 3) * -8 + 0x20) + 0x10) = 0;
  if (iVar2 != 0) {
    return;
  }
  if (*(short *)(param_1 + 2) == 0) {
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x1d00;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
      func_0214358c(1,uRam020536dc);
    }
    func_02053fa8();
    return;
  }
  return;
}

