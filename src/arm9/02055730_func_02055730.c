/* Decompiled C draft; module arm9; ROM address 02055730. No matching claim. */
#include "types.h"
#include "deps/02055730_func_02055730.h"

void func_02055730(undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(uRam02055794 & 0xfffffffc) >> (uRam02055794 & 3) * 8 |
          *(uint *)(uRam02055794 & 0xfffffffc) << (uRam02055794 & 3) * -8 + 0x20;
  uVar1 = *(ushort *)(uVar2 + 0x436);
  if ((uVar1 & 1) != 0) {
    *(ushort *)(uVar2 + 0x436) = uVar1 & 0xfffe;
  }
  if ((*psRam02055798 != 2) && (iVar3 = func_0204fe90(param_1), iVar3 == 0)) {
    func_02055564(param_1);
    return;
  }
  func_0204dd24(param_1);
  return;
}

