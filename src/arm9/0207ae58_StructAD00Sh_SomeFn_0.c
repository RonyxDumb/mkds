/* Decompiled C draft; module arm9; ROM address 0207ae58. No matching claim. */
#include "types.h"
#include "deps/0207ae58_StructAD00Sh_SomeFn_0.h"

void StructAD00Sh_SomeFn_0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((*(ushort *)(param_1 + 0x70) & 1) != 0) {
    StructAD00Sh_SomeFn_3(param_1,*(ushort *)(param_1 + 0x6e) & 0xff);
    uVar1 = param_1 + 0x58U & 3;
    uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar1 = iRam0207aec4 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
    StructAD00Sh_SomeFn_4
              (param_1,*(ushort *)(param_1 + 0x6e) & 0xff,*(ushort *)(param_1 + 0x6c) & 0xff);
    uVar1 = param_1 + 0x58U & 3;
    uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar1 = iRam0207aec4 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
    return;
  }
  return;
}

