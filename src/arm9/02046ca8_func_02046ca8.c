/* Decompiled C draft; module arm9; ROM address 02046ca8. No matching claim. */
#include "types.h"
#include "deps/02046ca8_func_02046ca8.h"

void func_02046ca8(ushort *param_1,uint param_2,undefined1 param_3)

{
  uint uVar1;
  uint uVar2;
  ushort local_8;
  ushort local_6;
  ushort local_4;
  ushort local_2;
  
  local_8 = (ushort)param_2;
  uVar2 = (*(uint *)(uRam02046d78 & 0xfffffffc) >> (uRam02046d78 & 3) * 8 |
          *(uint *)(uRam02046d78 & 0xfffffffc) << (uRam02046d78 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    uVar2 = param_2 & 0xff;
    if (0xbf < uVar2) {
      local_6 = 0;
      local_8 = local_6;
    }
    local_4 = local_8;
    if (uVar2 < 0xc0) {
      local_6 = (ushort)uVar2;
      local_4 = 1;
      local_8 = (ushort)(param_2 >> 8) & 0xff;
    }
    param_1[4] = *param_1;
    param_1[5] = param_1[1];
    param_1[6] = param_1[2];
    param_1[7] = param_1[3];
    *param_1 = local_8;
    param_1[1] = local_6;
    param_1[2] = local_4;
    param_1[3] = local_2;
    if (param_1[2] == 0) {
      if (param_1[8] < 6) {
        param_1[8] = param_1[8] + 1;
      }
    }
    else {
      param_1[8] = 0;
    }
  }
  uVar2 = (*(uint *)(uRam02046d78 & 0xfffffffc) >> (uRam02046d78 & 3) * 8 |
          *(uint *)(uRam02046d78 & 0xfffffffc) << (uRam02046d78 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1e) < 0) {
    *(undefined1 *)(param_1 + 9) = param_3;
  }
  return;
}

