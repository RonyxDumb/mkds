/* Decompiled C draft; module arm9; ROM address 0210a5a8. No matching claim. */
#include "types.h"
#include "deps/0210a5a8_DriverContext_CreateSub450_1.h"

void DriverContext_CreateSub450_1(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) == 0) {
    *(undefined4 *)(param_1 + 0x2c) = uRam0210a628;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = uRam0210a624;
  }
  *(undefined4 *)(param_1 + 0x30) = uRam0210a62c;
  iVar3 = GetCurrentSceneId();
  if ((iVar3 != 2) &&
     ((uint)*(ushort *)(param_1 + 0x74) ==
      (int)*(char *)((*(uint *)(uRam0210a630 & 0xfffffffc) >> (uRam0210a630 & 3) * 8 |
                     *(uint *)(uRam0210a630 & 0xfffffffc) << (uRam0210a630 & 3) * -8 + 0x20) + 0x62)
     )) {
    *(undefined4 *)(param_2 + 0x3c) = uRam0210a638;
    return;
  }
  *(undefined4 *)(param_2 + 0x3c) = uRam0210a634;
  return;
}

