/* Decompiled C draft; module arm9; ROM address 020392c8. No matching claim. */
#include "types.h"
#include "deps/020392c8_func_020392c8.h"

void func_020392c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined2 *puVar6;
  uint uVar5;
  
  uVar2 = iRam02039374 + 0x14U & 3;
  uVar4 = *(uint *)(iRam02039374 + 0x14U & 0xfffffffc);
  uVar5 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = iRam02039374 + 8U & 3;
  uVar4 = *(uint *)(iRam02039374 + 8U & 0xfffffffc);
  puVar6 = (undefined2 *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  uVar2 = iRam02039374 + 4U & 3;
  uVar4 = *(uint *)(iRam02039374 + 4U & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < (int)puVar6 + uVar5) {
    return;
  }
  if (uVar5 == 1) {
    uVar2 = 1;
    uVar4 = 1;
    uVar5 = 0;
    do {
      if ((uVar2 & 0xffff & (uint)*(ushort *)(iRam02039374 + 0x18)) != 0) {
        if ((uVar2 & 0xffff & param_1) != 0) {
          uVar5 = uVar5 | uVar4;
        }
        uVar3 = (undefined1)uVar5;
        uVar1 = uVar4 & 0x7f;
        uVar4 = uVar1 << 1;
        if (uVar1 == 0) break;
      }
      uVar3 = (undefined1)uVar5;
      uVar2 = uVar2 << 1;
    } while (uVar2 < 0x10000);
    *(undefined1 *)puVar6 = uVar3;
  }
  else {
    *puVar6 = (short)param_1;
  }
  func_02039378(1,1);
  uVar2 = iRam02039374 + 8U & 3;
  uVar4 = *(uint *)(iRam02039374 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = iRam02039374 + 0xcU & 3;
  uVar4 = *(uint *)(iRam02039374 + 0xcU & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < uVar5) {
    *(uint *)(iRam02039374 + 0xc) = uVar5;
  }
  return;
}

