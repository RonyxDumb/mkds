/* Decompiled C draft; module arm9; ROM address 020fb35c. No matching claim. */
#include "types.h"
#include "deps/020fb35c_func_020fb35c.h"

void func_020fb35c(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x800000;
  puVar1 = puRam020fb460;
  *(undefined4 *)(param_1 + 0x100) = 0;
  uVar3 = puVar1[1];
  uVar6 = puVar1[2];
  *(undefined4 *)(param_1 + 0x68) = *puVar1;
  *(undefined4 *)(param_1 + 0x6c) = uVar3;
  *(undefined4 *)(param_1 + 0x70) = uVar6;
  func_020f9160(param_1);
  uVar3 = MaybeRecreateExplosionInstance(1,param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x2b0) = uVar3;
  uVar4 = param_1 + 0x2b0U & 3;
  uVar2 = *(uint *)(param_1 + 0x2b0U & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    *(undefined4 *)(uVar4 + 0x9c) = 0x1000;
    *(undefined4 *)(uVar4 + 0xa0) = 0x1000;
    *(undefined4 *)(uVar4 + 0xa4) = 0x1000;
  }
  func_020f91fc(param_1,0xdf);
  if (((*(uint *)(uRam020fb464 & 0xfffffffc) >> (uRam020fb464 & 3) * 8 |
       *(uint *)(uRam020fb464 & 0xfffffffc) << (uRam020fb464 & 3) * -8 + 0x20) & 1) != 0) {
    func_02108ea0(0);
    uVar2 = GetSomeSndPlayer();
    uVar4 = iRam020fb468 + 0xcU & 3;
    uVar5 = *(uint *)(iRam020fb468 + 0xcU & 0xfffffffc);
    if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar2,0,0xe0);
    }
  }
  uVar4 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  func_02073fb0((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x3fffffe0,0x1000);
  return;
}

