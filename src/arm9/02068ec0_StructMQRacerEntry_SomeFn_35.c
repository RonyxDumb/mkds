/* Decompiled C draft; module arm9; ROM address 02068ec0. No matching claim. */
#include "types.h"
#include "deps/02068ec0_StructMQRacerEntry_SomeFn_35.h"

bool StructMQRacerEntry_SomeFn_35(int param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar4;
  bool bVar5;
  uint uVar3;
  
  bVar5 = false;
  if (param_2 == 0) {
    uVar3 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((uVar3 & uRam02069034) == 0) {
      bVar5 = true;
    }
  }
  else {
    uVar3 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    bVar5 = (uVar3 & 0x800000) == 0;
  }
  if (bVar5 != false) {
    if ((uVar3 & 0x4000000) == 0) {
      func_020858ac(*(undefined2 *)(param_1 + 0x74));
      uVar3 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x4000000;
    }
    uVar3 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x20;
    if (*(short *)(param_1 + 0x2c8) != -1) {
      uVar1 = func_020d5344();
      *(undefined2 *)(param_1 + 0x2c8) = uVar1;
    }
    if (*(short *)(param_1 + 0x2ca) != -1) {
      uVar1 = func_020d5344();
      *(undefined2 *)(param_1 + 0x2ca) = uVar1;
    }
    uVar3 = (*(uint *)(uRam02069038 & 0xfffffffc) >> (uRam02069038 & 3) * 8 |
            *(uint *)(uRam02069038 & 0xfffffffc) << (uRam02069038 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (((((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 2) && (param_2 == 0)) &&
        (DriverContext_MaybeQueuePlaySfx(param_1,0xd3,0x7f,0),
        uVar3 = (*(uint *)(uRam02069038 & 0xfffffffc) >> (uRam02069038 & 3) * 8 |
                *(uint *)(uRam02069038 & 0xfffffffc) << (uRam02069038 & 3) * -8 + 0x20) + 0x18,
        uVar2 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
        uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0)) &&
       (((*(uint *)(uRam0206903c & 0xfffffffc) >> (uRam0206903c & 3) * 8 |
         *(uint *)(uRam0206903c & 0xfffffffc) << (uRam0206903c & 3) * -8 + 0x20) & 1) != 0)) {
      func_02108ea0(0);
      uVar2 = GetSomeSndPlayer();
      uVar3 = iRam02069040 + 0xcU & 3;
      uVar4 = *(uint *)(iRam02069040 + 0xcU & 0xfffffffc);
      if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar2,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar2,0,0x4c);
      }
    }
    *(undefined2 *)(param_1 + 0x3c8) = 0;
    StructMQRacerEntry_SomeFn_16(param_1);
  }
  return bVar5;
}

