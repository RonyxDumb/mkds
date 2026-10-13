/* Decompiled C draft; module arm9; ROM address 0208fd24. No matching claim. */
#include "types.h"
#include "deps/0208fd24_func_0208fd24.h"

void func_0208fd24(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0208fd7c & 0xfffffffc) >> (uRam0208fd7c & 3) * 8 |
          *(uint *)(uRam0208fd7c & 0xfffffffc) << (uRam0208fd7c & 3) * -8 + 0x20) + 0x60;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    (*(code *)(*(uint *)(uRam0208fd80 & 0xfffffffc) >> (uRam0208fd80 & 3) * 8 |
              *(uint *)(uRam0208fd80 & 0xfffffffc) << (uRam0208fd80 & 3) * -8 + 0x20))();
    return;
  }
  (*(code *)(*(uint *)(uRam0208fd84 & 0xfffffffc) >> (uRam0208fd84 & 3) * 8 |
            *(uint *)(uRam0208fd84 & 0xfffffffc) << (uRam0208fd84 & 3) * -8 + 0x20))();
  return;
}

