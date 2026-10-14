/* Decompiled C draft; module arm9; ROM address 02010804. No matching claim. */
#include "types.h"
#include "deps/02010804_Tex0Block_MaybeCopyPaletteToMem.h"

void Tex0Block_MaybeCopyPaletteToMem(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    func_0214c48c();
  }
  uVar1 = param_1 + 0x38U & 3;
  uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar2 = param_1 + 0x2cU & 3;
  uVar4 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  SomeDmaCopy_0(param_1 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20),
                ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & uRam0201086c) << 3,
                (uint)*(ushort *)(param_1 + 0x30) << 3);
  *(ushort *)(param_1 + 0x32) = *(ushort *)(param_1 + 0x32) | 1;
  if (param_2 != 0) {
    func_0214c3c0();
    return;
  }
  return;
}

