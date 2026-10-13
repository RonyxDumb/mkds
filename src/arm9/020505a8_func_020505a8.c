/* Decompiled C draft; module arm9; ROM address 020505a8. No matching claim. */
#include "types.h"
#include "deps/020505a8_func_020505a8.h"

undefined4 func_020505a8(undefined2 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_c [2];
  
  uVar3 = uRam02050648;
  uVar1 = *(uint *)(uRam02050648 & 0xfffffffc) >> (uRam02050648 & 3) * 8 |
          *(uint *)(uRam02050648 & 0xfffffffc) << (uRam02050648 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar1 + 0x454) & 1) == 0) {
    return 0;
  }
  *(undefined2 *)(iRam0205064c + 4) = 0x18;
  *(ushort *)(uVar1 + 0x454) = *(ushort *)(uVar1 + 0x454) & 0xfffe;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x40;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  local_c[0] = param_1;
  iVar2 = func_02050650(local_c,2,param_2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (iVar2 == 0) {
    uVar3 = *(uint *)(uRam02050648 & 0xfffffffc) >> (uRam02050648 & 3) * 8 |
            *(uint *)(uRam02050648 & 0xfffffffc) << (uRam02050648 & 3) * -8 + 0x20;
    *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) | 1;
    return 0;
  }
  return 1;
}

