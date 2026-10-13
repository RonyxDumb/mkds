/* Decompiled C draft; module arm9; ROM address 020a1e40. No matching claim. */
#include "types.h"
#include "deps/020a1e40_func_020a1e40.h"

void func_020a1e40(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (*(uint *)(uRam020a1ee0 & 0xfffffffc) >> (uRam020a1ee0 & 3) * 8 |
          *(uint *)(uRam020a1ee0 & 0xfffffffc) << (uRam020a1ee0 & 3) * -8 + 0x20) + 0x3b4;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (-1 < (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
    return;
  }
  iVar1 = GetDriverEntry();
  uVar3 = iVar1 + 0x180U & 3;
  uVar2 = *(uint *)(iVar1 + 0x180U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = param_2 + 0x44U & 3;
    uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (((uVar3 != 0) && (uVar3 != 1)) && (uVar3 != 9)) {
      return;
    }
    if ((*(ushort *)(param_2 + 0x78) & 0x8000) == 0) {
      *(ushort *)
       (param_1 * 0x70 +
        (*(uint *)(uRam020a1ee0 & 0xfffffffc) >> (uRam020a1ee0 & 3) * 8 |
        *(uint *)(uRam020a1ee0 & 0xfffffffc) << (uRam020a1ee0 & 3) * -8 + 0x20) + 0x44) =
           *(ushort *)(param_2 + 0x78) & 0xff;
      return;
    }
    return;
  }
  return;
}

