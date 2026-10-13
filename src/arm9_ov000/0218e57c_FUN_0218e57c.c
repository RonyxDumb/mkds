/* Decompiled C draft; module arm9_ov000; ROM address 0218e57c. No matching claim. */
#include "types.h"
#include "deps/0218e57c_FUN_0218e57c.h"

undefined4 FUN_0218e57c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_1;
  uVar3 = uVar1 << 8 & DAT_0218e5dc | uVar1 >> 8 & DAT_0218e5e0;
  uVar2 = (uVar1 << 0x18 & DAT_0218e5d8 | uVar3) >> 0x18;
  uVar1 = (uVar3 & 0xff0000) >> 0x10;
  if (uVar2 == 10) {
    return 1;
  }
  if (((uVar2 == 0xac) && (0xf < uVar1)) && (uVar1 < 0x20)) {
    return 1;
  }
  if ((uVar2 == 0xc0) && (uVar1 == 0xa8)) {
    return 1;
  }
  return 0;
}

