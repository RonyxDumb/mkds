/* Decompiled C draft; module arm9; ROM address 020dea50. No matching claim. */
#include "types.h"
#include "deps/020dea50_func_020dea50.h"

undefined1 func_020dea50(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_2 + 0x7cU & 3;
  uVar3 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x400000) == 0) {
    bVar2 = false;
    *(undefined2 *)(param_1 + 0xa4) = 0;
    uVar1 = uRam020deb28;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020deb24;
    uVar3 = uVar1 & 3;
    uVar4 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = param_1 + 0x78U & 3;
    uVar6 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    uVar4 = (uint)*(ushort *)(param_2 + 0x74) * 0x30 +
            (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    uVar3 = uVar4 + 0x70 & 3;
    uVar5 = *(uint *)(uVar4 + 0x70 & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    if ((uVar3 < 4) && (uVar4 = 1, (1 << (uVar3 & 0xff) & 0xdU) != 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      uVar4 = (uint)*(ushort *)(param_1 + 0xf2);
    }
    if (!bVar2) {
      uVar4 = (uint)*(ushort *)(param_1 + 0xf4);
    }
    func_020deb2c(param_1 + 4,param_2,uVar4,(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 3);
    uVar1 = param_1 + 0xf8U & 3;
    uVar3 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) ||
       (uVar1 = param_1 + 0x9cU & 3, uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc),
       *(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x32) != 0)) {
      *(undefined2 *)(param_1 + 0xa4) = 0x80;
      func_020d2398(param_1);
    }
    return *param_4;
  }
  return 0;
}

