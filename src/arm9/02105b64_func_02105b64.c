/* Decompiled C draft; module arm9; ROM address 02105b64. No matching claim. */
#include "types.h"
#include "deps/02105b64_func_02105b64.h"

void func_02105b64(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = *(undefined2 *)(iRam02105c3c + param_1 * 2);
  if (*(uint *)(uRam02105c38 & 0xfffffffc) >> (uRam02105c38 & 3) * 8 != 0 ||
      *(uint *)(uRam02105c38 & 0xfffffffc) << (uRam02105c38 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02105c38,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02105c38,0,uVar1);
  if (param_1 != 4) {
    iVar6 = 0;
    iVar5 = iRam02105c40;
    do {
      uVar3 = func_0210d960();
      func_0212c6f0(iVar5,uVar3);
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar6 < 0xc);
    uVar3 = func_0210d960();
    uVar2 = uRam02105c44;
    uVar8 = uRam02105c44 + 0xc & 3;
    uVar7 = *(uint *)(uRam02105c44 + 0xc & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    iVar5 = 0;
    if (0 < (int)(*(uint *)(uRam02105c44 & 0xfffffffc) >> (uRam02105c44 & 3) * 8 |
                 *(uint *)(uRam02105c44 & 0xfffffffc) << (uRam02105c44 & 3) * -8 + 0x20)) {
      do {
        func_0212c6f0(uVar8,uVar3);
        uVar7 = uVar2 + 0x10 & 3;
        uVar4 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
        iVar5 = iVar5 + 1;
        uVar8 = uVar8 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20);
      } while (iVar5 < (int)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20));
    }
    func_0210d9a0(uRam02105c48,4);
    return;
  }
  return;
}

