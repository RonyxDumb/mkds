/* Decompiled C draft; module arm9; ROM address 0210bafc. No matching claim. */
#include "types.h"
#include "deps/0210bafc_func_0210bafc.h"

uint func_0210bafc(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0210bb64 + param_2 * 0x20 + param_3 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uRam0210bb68;
  if (uVar2 != 0) {
    uVar2 = uVar2 + param_1 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  if (uVar1 == uRam0210bb68) {
    uVar2 = (uint)*(ushort *)(param_3 * 2 + iRam0210bb6c + param_2 * 0x10);
    if (uVar2 == 0xe) {
      uVar2 = uRam0210bb68;
    }
    uVar1 = uRam0210bb68;
    if (uVar2 != uRam0210bb68) {
      uVar1 = (uint)*(ushort *)(uVar2 * 2 + param_1 * 0x1a + iRam0210bb70);
    }
    return uVar1;
  }
  return uVar1 & 0xffff;
}

