/* Decompiled C draft; module arm9; ROM address 02050320. No matching claim. */
#include "types.h"
#include "deps/02050320_func_02050320.h"

undefined4 func_02050320(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_14 [2];
  undefined4 local_10;
  
  uVar3 = uRam020503c4;
  uVar1 = *(uint *)(uRam020503c4 & 0xfffffffc) >> (uRam020503c4 & 3) * 8 |
          *(uint *)(uRam020503c4 & 0xfffffffc) << (uRam020503c4 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar1 + 0x454) & 1) == 0) {
    return 0;
  }
  *(undefined2 *)(iRam020503c8 + 4) = 0x18;
  *(ushort *)(uVar1 + 0x454) = *(ushort *)(uVar1 + 0x454) & 0xfffe;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x40;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  local_14[0] = param_1;
  local_10 = param_3;
  iVar2 = func_02050650(local_14,8,param_2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (iVar2 == 0) {
    uVar3 = *(uint *)(uRam020503c4 & 0xfffffffc) >> (uRam020503c4 & 3) * 8 |
            *(uint *)(uRam020503c4 & 0xfffffffc) << (uRam020503c4 & 3) * -8 + 0x20;
    *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) | 1;
    return 0;
  }
  return 1;
}

