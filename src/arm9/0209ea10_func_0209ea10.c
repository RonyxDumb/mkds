/* Decompiled C draft; module arm9; ROM address 0209ea10. No matching claim. */
#include "types.h"
#include "deps/0209ea10_func_0209ea10.h"

undefined1 func_0209ea10(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_4;
  uVar2 = param_1 + (uint)*(ushort *)(param_2 + 0x74) * 4 + 0x19c4;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    uVar2 = param_2 + 0x29cU & 3;
    uVar3 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((uVar2 == 1) || (uVar2 == 3)) {
      uVar2 = param_1 + 0x78U & 3;
      uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(uint *)(param_1 + 0x78) =
           uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 |
           *(uint *)(uRam0209ea8c & 0xfffffffc) >> (uRam0209ea8c & 3) * 8 |
           *(uint *)(uRam0209ea8c & 0xfffffffc) << (uRam0209ea8c & 3) * -8 + 0x20;
    }
    func_020d26f8(param_1,param_2);
  }
  *(undefined4 *)(param_1 + (uint)*(ushort *)(param_2 + 0x74) * 4 + 0x19c4) = 0xb;
  return uVar1;
}

