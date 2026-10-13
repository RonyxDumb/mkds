/* Decompiled C draft; module arm9; ROM address 020b3410. No matching claim. */
#include "types.h"
#include "deps/020b3410_func_020b3410.h"

void func_020b3410(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (*(uint *)(uRam020b3578 & 0xfffffffc) >> (uRam020b3578 & 3) * 8 |
          *(uint *)(uRam020b3578 & 0xfffffffc) << (uRam020b3578 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  if ((int)uVar4 < -0x15) {
    return;
  }
  if ((int)uVar4 < 200) {
    if ((((uVar4 == 0) || (uVar4 == 0x3c)) || (uVar4 == 0x78)) &&
       (((*(uint *)(uRam020b357c & 0xfffffffc) >> (uRam020b357c & 3) * 8 |
         *(uint *)(uRam020b357c & 0xfffffffc) << (uRam020b357c & 3) * -8 + 0x20) & 1) != 0)) {
      func_02108ea0(0);
      uVar2 = GetSomeSndPlayer();
      uVar1 = iRam020b3580 + 0xcU & 3;
      uVar3 = *(uint *)(iRam020b3580 + 0xcU & 0xfffffffc);
      if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar2,0,0x27);
      }
    }
    if ((uVar4 == 0xaf) &&
       (((*(uint *)(uRam020b357c & 0xfffffffc) >> (uRam020b357c & 3) * 8 |
         *(uint *)(uRam020b357c & 0xfffffffc) << (uRam020b357c & 3) * -8 + 0x20) & 1) != 0)) {
      func_02108ea0(0);
      uVar2 = GetSomeSndPlayer();
      uVar1 = iRam020b3580 + 0xcU & 3;
      uVar3 = *(uint *)(iRam020b3580 + 0xcU & 0xfffffffc);
      if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar2,0,0x28);
      }
    }
    if (uVar4 == 0xffffffeb) {
      func_02089ef4(0);
    }
    if (uVar4 == 0xb4) {
      func_02089ef4(1);
      return;
    }
    return;
  }
  return;
}

