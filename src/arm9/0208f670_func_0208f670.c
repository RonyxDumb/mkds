/* Decompiled C draft; module arm9; ROM address 0208f670. No matching claim. */
#include "types.h"
#include "deps/0208f670_func_0208f670.h"

void func_0208f670(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0208f6c8 & 0xfffffffc) >> (uRam0208f6c8 & 3) * 8 |
          *(uint *)(uRam0208f6c8 & 0xfffffffc) << (uRam0208f6c8 & 3) * -8 + 0x20) + 0x60;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3) {
    (*(code *)(*(uint *)(uRam0208f6cc & 0xfffffffc) >> (uRam0208f6cc & 3) * 8 |
              *(uint *)(uRam0208f6cc & 0xfffffffc) << (uRam0208f6cc & 3) * -8 + 0x20))();
    return;
  }
  (*(code *)(*(uint *)(uRam0208f6d0 & 0xfffffffc) >> (uRam0208f6d0 & 3) * 8 |
            *(uint *)(uRam0208f6d0 & 0xfffffffc) << (uRam0208f6d0 & 3) * -8 + 0x20))();
  return;
}

