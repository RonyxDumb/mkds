/* Decompiled C draft; module arm9; ROM address 0212c8a4. No matching claim. */
#include "types.h"
#include "deps/0212c8a4_func_0212c8a4.h"

void func_0212c8a4(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  iVar2 = iRam0212c914;
  uVar4 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  iVar6 = 0;
  if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 1) {
    return;
  }
  do {
    uVar7 = (uint)*(byte *)(param_1 + iVar6 + 0x4c);
    uVar3 = param_1 + 0x3cU & 3;
    uVar5 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
    uVar4 = iVar2 + uVar7 * 8 + 4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = Maybe_helper_0218f4((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
                                (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20));
    SND_SetChannelVolume(1 << uVar7,uVar4 & 0xff,(int)uVar4 >> 8);
    uVar4 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    iVar6 = iVar6 + 1;
  } while (iVar6 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20));
  return;
}

