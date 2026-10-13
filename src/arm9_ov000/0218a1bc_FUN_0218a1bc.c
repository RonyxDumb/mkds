/* Decompiled C draft; module arm9_ov000; ROM address 0218a1bc. No matching claim. */
#include "types.h"
#include "deps/0218a1bc_FUN_0218a1bc.h"

undefined4 FUN_0218a1bc(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_021a8ed4();
  if (iVar1 == 0) {
    lVar3 = func_0x0200f5ac();
    lVar3 = lVar3 - CONCAT44(*(undefined4 *)(param_1 + DAT_0218a23c),
                             *(undefined4 *)(param_1 + DAT_0218a238));
    uVar2 = (uint)lVar3;
    uVar4 = func_0x02132e40(uVar2 * 0x40,(int)((ulonglong)lVar3 >> 0x20) * 0x40 | uVar2 >> 0x1a,
                            DAT_0218a240,0);
    uVar2 = (uint)((ulonglong)uVar4 >> 0x20);
    if (uVar2 != 0 || uVar2 < (9 < (uint)uVar4)) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + DAT_0218a244) * 4 + DAT_0218a248) = 1;
      return 0xb;
    }
    return 0xc;
  }
  FUN_02189f64(param_1);
  if (((uint)*(byte *)(param_1 + DAT_0218a234) << 0x1a) >> 0x1e == 1) {
    return 0xf;
  }
  return 0xd;
}

