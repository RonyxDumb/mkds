/* Decompiled C draft; module arm9; ROM address 020f0154. No matching claim. */
#include "types.h"
#include "deps/020f0154_func_020f0154.h"

undefined4 func_020f0154(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x1fc & 3;
  uVar3 = *(uint *)(param_1 + 0x1fc & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar2 = IsAwardOrStaffRoll();
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = uVar4 + 0x180;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar4 = uVar4 + 0x4c;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x20000000) == 0) {
      uVar4 = param_1 + 0x58 & 3;
      uVar3 = *(uint *)(param_1 + 0x58 & 0xfffffffc);
      if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0xf) {
        uVar4 = param_1 + 0x30 & 3;
        uVar3 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
        if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0x13) {
          if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) {
            *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam020f02b0;
          }
        }
        else {
          *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam020f02ac;
        }
      }
      else {
        *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam020f02a8;
      }
      uVar4 = param_1 + 0x200 & 3;
      uVar3 = *(uint *)(param_1 + 0x200 & 0xfffffffc);
      if ((*(ushort *)(iRam020f02b4 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x5c) &
          0x40) != 0) {
        *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam020f02b8;
      }
      uVar4 = param_1 + 0x200 & 3;
      uVar3 = *(uint *)(param_1 + 0x200 & 0xfffffffc);
      if ((*(ushort *)(iRam020f02b4 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x5c) &
          0x80) != 0) {
        *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam020f02bc;
      }
      return 1;
    }
    return 0;
  }
  return 0;
}

