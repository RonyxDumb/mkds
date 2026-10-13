/* Decompiled C draft; module arm9; ROM address 02083ec4. No matching claim. */
#include "types.h"
#include "deps/02083ec4_func_02083ec4.h"

void func_02083ec4(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000) == 0) {
    iVar3 = (uint)*(ushort *)(param_1 + 0x74) * 0x58 +
            (*(uint *)(uRam02083f68 & 0xfffffffc) >> (uRam02083f68 & 3) * 8 |
            *(uint *)(uRam02083f68 & 0xfffffffc) << (uRam02083f68 & 3) * -8 + 0x20);
    uVar2 = iVar3 + 0x20U & 3;
    uVar1 = *(uint *)(iVar3 + 0x20U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      *(undefined1 *)(uVar2 + 0x99) = 1;
      *(undefined4 *)(iVar3 + 0x20) = 0;
    }
    uVar2 = iVar3 + 0x24U & 3;
    uVar1 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      *(undefined1 *)(uVar2 + 0x99) = 1;
      *(undefined4 *)(iVar3 + 0x24) = 0;
    }
    return;
  }
  func_02083a24((uint)*(ushort *)
                       ((*(uint *)(uRam02083f60 & 0xfffffffc) >> (uRam02083f60 & 3) * 8 |
                        *(uint *)(uRam02083f60 & 0xfffffffc) << (uRam02083f60 & 3) * -8 + 0x20) +
                       (uint)*(ushort *)(param_1 + 0x74) * 2) * 0xc + iRam02083f64,1);
  return;
}

