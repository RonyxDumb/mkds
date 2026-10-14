/* Decompiled C draft; module arm9; ROM address 02093754. No matching claim. */
#include "types.h"
#include "deps/02093754_func_02093754.h"

undefined1 func_02093754(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_4;
  uVar3 = param_1 + (uint)*(ushort *)(param_2 + 0x74) * 4 + 0xd4;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) &&
     (iVar2 = func_020d26f8(), iVar2 != 0)) {
    uVar3 = param_1 + 0x78U & 3;
    uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(uint *)(param_1 + 0x78) =
         uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 |
         *(uint *)(uRam020937b4 & 0xfffffffc) >> (uRam020937b4 & 3) * 8 |
         *(uint *)(uRam020937b4 & 0xfffffffc) << (uRam020937b4 & 3) * -8 + 0x20;
    *(undefined4 *)(param_1 + (uint)*(ushort *)(param_2 + 0x74) * 4 + 0xd4) = 0x1f;
  }
  return uVar1;
}

