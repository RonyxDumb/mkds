/* Decompiled C draft; module arm9; ROM address 02081060. No matching claim. */
#include "types.h"
#include "deps/02081060_func_02081060.h"

void func_02081060(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
    return;
  }
  uVar2 = (*(uint *)(uRam020810d8 & 0xfffffffc) >> (uRam020810d8 & 3) * 8 |
          *(uint *)(uRam020810d8 & 0xfffffffc) << (uRam020810d8 & 3) * -8 + 0x20) +
          (uint)*(ushort *)(param_1 + 0x74) * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar3 = func_0208b7bc(0x80,uRam020810dc);
    uVar1 = uRam020810d8;
    *(undefined4 *)
     ((*(uint *)(uRam020810d8 & 0xfffffffc) >> (uRam020810d8 & 3) * 8 |
      *(uint *)(uRam020810d8 & 0xfffffffc) << (uRam020810d8 & 3) * -8 + 0x20) +
     (uint)*(ushort *)(param_1 + 0x74) * 4) = uVar3;
    uVar3 = uRam020810e0;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x74) * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    *(char *)(uVar2 + 0x9b) = (char)*(ushort *)(param_1 + 0x74);
    *(undefined4 *)(uVar2 + 0x94) = 0;
    *(undefined4 *)(uVar2 + 0x90) = uVar3;
    return;
  }
  return;
}

