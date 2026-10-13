/* Decompiled C draft; module arm9; ROM address 02070398. No matching claim. */
#include "types.h"
#include "deps/02070398_func_02070398.h"

undefined4 func_02070398(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (((uVar5 & uRam0207047c) == 0) &&
     (uVar4 = param_1 + 0x7cU & 3, uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x400) == 0)) {
    if (((((uVar5 & 0xc0000) == 0) &&
         (uVar5 = param_1 + 0x4cU & 3, uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
         ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x100) == 0)) &&
        (uVar5 = param_1 + 0x1fcU & 3, uVar4 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc),
        uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0)) &&
       (((uVar5 = param_1 + 0x200U & 3, uVar4 = *(uint *)(param_1 + 0x200U & 0xfffffffc),
         uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0 &&
         (uVar5 = param_1 + 0x204U & 3, uVar4 = *(uint *)(param_1 + 0x204U & 0xfffffffc),
         uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0)) &&
        ((uVar5 = param_1 + 0x274U & 3, uVar4 = *(uint *)(param_1 + 0x274U & 0xfffffffc),
         uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0 &&
         (uVar5 = param_1 + 0x4d0U & 3, uVar4 = *(uint *)(param_1 + 0x4d0U & 0xfffffffc),
         99 < (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))))))) {
      uVar5 = param_1 + 0x8cU & 3;
      uVar4 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
      *(uint *)(param_1 + 0x80) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = param_1 + 0x94U & 3;
      uVar4 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
      *(uint *)(param_1 + 0x88) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    }
    else {
      uVar5 = param_1 + 0x208U & 3;
      uVar4 = *(uint *)(param_1 + 0x208U & 0xfffffffc);
      func_020d5aa0(param_3,param_2,(undefined4 *)(uintptr_t)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20),param_1 + 0x80,0
                   );
    }
    uVar2 = puRam02070480[1];
    uVar3 = puRam02070480[2];
    *(undefined4 *)(param_1 + 0xa4) = *puRam02070480;
    *(undefined4 *)(param_1 + 0xa8) = uVar2;
    *(undefined4 *)(param_1 + 0xac) = uVar3;
    *(undefined4 *)(param_1 + 0x2a4) = 0;
    uVar5 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x1000;
    return 1;
  }
  return 0;
}

