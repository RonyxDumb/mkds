/* Decompiled C draft; module arm9; ROM address 020fe00c. No matching claim. */
#include "types.h"
#include "deps/020fe00c_func_020fe00c.h"

void func_020fe00c(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20 | 0x800000;
  puVar1 = puRam020fe110;
  *(undefined4 *)(param_1 + 0x100) = 0;
  uVar3 = puVar1[1];
  uVar5 = puVar1[2];
  *(undefined4 *)(param_1 + 0x68) = *puVar1;
  *(undefined4 *)(param_1 + 0x6c) = uVar3;
  *(undefined4 *)(param_1 + 0x70) = uVar5;
  func_020f9160(param_1);
  uVar3 = MaybeRecreateExplosionInstance(0,param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x138) = uVar3;
  uVar3 = uRam020fe114;
  uVar6 = param_1 + 0x138U & 3;
  uVar2 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    *(undefined4 *)(uVar6 + 0x9c) = uRam020fe114;
    *(undefined4 *)(uVar6 + 0xa0) = uVar3;
    *(undefined4 *)(uVar6 + 0xa4) = uVar3;
  }
  func_020f91fc(param_1,0xe4);
  if (((*(uint *)(uRam020fe118 & 0xfffffffc) >> (uRam020fe118 & 3) * 8 |
       *(uint *)(uRam020fe118 & 0xfffffffc) << (uRam020fe118 & 3) * -8 + 0x20) & 1) != 0) {
    func_02108ea0(0);
    uVar2 = GetSomeSndPlayer();
    uVar6 = iRam020fe11c + 0xcU & 3;
    uVar4 = *(uint *)(iRam020fe11c + 0xcU & 0xfffffffc);
    if (uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) {
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
  uVar6 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  func_02073fb0((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x3fffffe0,0x1000);
  return;
}

