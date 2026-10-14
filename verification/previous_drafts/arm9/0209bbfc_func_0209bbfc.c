/* Decompiled C draft; module arm9; ROM address 0209bbfc. No matching claim. */
#include "types.h"
#include "deps/0209bbfc_func_0209bbfc.h"

uint func_0209bbfc(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    iVar2 = 0;
    while ((iVar2 < (int)(uint)*(ushort *)(param_1 + 4) &&
           (uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar2 * 4,
           uVar1 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
           uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20, uVar3 != 0))) {
      if ((*(ushort *)(uVar3 + 2) & 0x100) != 0) {
        func_020d233c(uVar3);
        return uVar3;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return 0;
}

