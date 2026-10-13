/* Decompiled C draft; module arm9; ROM address 020108bc. No matching claim. */
#include "types.h"
#include "deps/020108bc_Tex0Block_MaybeCopyTexturesToMem.h"

void Tex0Block_MaybeCopyTexturesToMem(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_2 != 0) {
    func_0214c6a8();
  }
  if (*(short *)(param_1 + 0xc) != 0) {
    uVar1 = param_1 + 8U & 3;
    uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar2 = param_1 + 0x14U & 3;
    uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    func_0214c544(param_1 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20),
                  ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam02010990) << 3);
    *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) | 1;
  }
  uVar1 = (uint)*(ushort *)(param_1 + 0x1c) << 3;
  if (*(ushort *)(param_1 + 0x1c) != 0) {
    uVar2 = param_1 + 0x18U & 3;
    uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar3 = param_1 + 0x24U & 3;
    uVar5 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar6 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & uRam02010990;
    uVar2 = uVar6 << 3;
    uVar4 = param_1 + 0x28U & 3;
    uVar7 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    func_0214c544(param_1 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20),uVar2,uVar1);
    func_0214c544(param_1 + (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20),
                  ((uRam02010994 & uVar6 << 3) >> 1) + 0x20000 + ((uVar2 & 0x40000) >> 2),uVar1 >> 1
                 );
    *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) | 1;
  }
  if (param_2 != 0) {
    func_0214c4d4();
    return;
  }
  return;
}

