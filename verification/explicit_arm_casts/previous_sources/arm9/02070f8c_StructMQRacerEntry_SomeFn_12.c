/* Decompiled C draft; module arm9; ROM address 02070f8c. No matching claim. */
#include "types.h"
#include "deps/02070f8c_StructMQRacerEntry_SomeFn_12.h"

void StructMQRacerEntry_SomeFn_12(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar6;
  int iVar7;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uVar5;
  
  local_30 = *puRam02071094;
  uStack_2c = puRam02071094[1];
  uStack_28 = puRam02071094[2];
  bVar1 = true;
  iVar2 = GetGlobalHD4();
  uVar5 = iVar2 + 0x24U & 3;
  uVar4 = *(uint *)(iVar2 + 0x24U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((((iRam02071098 < (int)uVar5) && ((int)uVar5 < iRam0207109c)) &&
      (uVar5 = iVar2 + 0x2cU & 3, uVar4 = *(uint *)(iVar2 + 0x2cU & 0xfffffffc),
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20, iRam020710a0 < (int)uVar5)) &&
     ((int)uVar5 < iRam020710a4)) {
    bVar1 = false;
  }
  if (!bVar1) {
    uVar5 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) == 0) {
      uVar3 = 0x52;
    }
    else {
      uVar3 = 0x47;
    }
    func_0208b7bc(uVar3,&local_30);
    return;
  }
  local_38 = *(uint *)(uRam020710a8 & 0xfffffffc) >> (uRam020710a8 & 3) * 8 |
             *(uint *)(uRam020710a8 & 0xfffffffc) << (uRam020710a8 & 3) * -8 + 0x20;
  uVar5 = uRam020710a8 + 4 & 3;
  uVar4 = *(uint *)(uRam020710a8 + 4 & 0xfffffffc);
  local_34 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  local_24 = *puRam020710ac;
  uStack_20 = puRam020710ac[1];
  uStack_1c = puRam020710ac[2];
  uVar5 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  iVar2 = 3;
  puVar6 = &local_24;
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) == 0) {
    iVar2 = 2;
    puVar6 = &local_38;
  }
  iVar7 = 0;
  if (iVar2 != 0) {
    do {
      func_0208b7bc(*puVar6,&local_30);
      iVar7 = iVar7 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar7 < iVar2);
    return;
  }
  return;
}

