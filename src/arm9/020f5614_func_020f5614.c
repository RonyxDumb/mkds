/* Decompiled C draft; module arm9; ROM address 020f5614. No matching claim. */
#include "types.h"
#include "deps/020f5614_func_020f5614.h"

void func_020f5614(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  if (1 < param_2 - 1U) {
    return;
  }
  uVar1 = *(ushort *)(param_3 + 0x78);
  uVar4 = param_1 + 0x228U & 3;
  uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar1 & 0x8000) == 0) {
    uVar2 = uVar1 & 0xff;
  }
  else {
    uVar2 = 8;
  }
  if (uVar4 == 0) {
    return;
  }
  uVar4 = uVar4 + 0x1fc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar2 != *(ushort *)(uVar4 + 0x74)) {
    return;
  }
  uVar3 = param_3 + 0x74U & 3;
  uVar5 = *(uint *)(param_3 + 0x74U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if ((uVar3 & 0x1000) == 0) {
    if ((uVar3 & 0x2000) == 0) {
      return;
    }
    if ((uVar1 & 0x1000) == 0) {
      return;
    }
    uVar3 = param_3 + 0x11cU & 3;
    uVar5 = *(uint *)(param_3 + 0x11cU & 0xfffffffc);
    if (0x77 < (int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20)) {
      return;
    }
  }
  uVar3 = uVar4 + 0x3cc & 3;
  uVar5 = *(uint *)(uVar4 + 0x3cc & 0xfffffffc);
  StructMQRacerEntry_SomeFn_66(uVar4,uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  return;
}

