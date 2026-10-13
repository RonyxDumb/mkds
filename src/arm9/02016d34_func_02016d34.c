/* Decompiled C draft; module arm9; ROM address 02016d34. No matching claim. */
#include "types.h"
#include "deps/02016d34_func_02016d34.h"

void func_02016d34(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  uint uStack_28;
  uint local_24;
  uint local_20;
  uint uStack_1c;
  uint local_18;
  uint uStack_14;
  uint uVar8;
  
  puVar6 = &local_40;
  puVar5 = &local_40;
  local_40 = *puRam02016f1c;
  local_3c = puRam02016f1c[1];
  local_38 = puRam02016f1c[2];
  local_34 = puRam02016f1c[3];
  local_30 = puRam02016f1c[4];
  uStack_2c = puRam02016f1c[5];
  uStack_28 = puRam02016f1c[6];
  local_24 = puRam02016f1c[7];
  local_20 = puRam02016f1c[8];
  uStack_1c = puRam02016f1c[9];
  local_18 = puRam02016f1c[10];
  uStack_14 = puRam02016f1c[0xb];
  uVar1 = iRam02016f20 + 0x10U & 3;
  uVar7 = *(uint *)(iRam02016f20 + 0x10U & 0xfffffffc);
  uVar8 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  uVar7 = iRam02016f20 + 0xcU & 3;
  uVar3 = *(uint *)(iRam02016f20 + 0xcU & 0xfffffffc);
  uVar1 = uVar8 >> 1;
  uVar7 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - (uVar8 + (uVar8 >> 1));
  uVar3 = 0;
  do {
    if ((((uVar3 == 0) || (uVar3 == 2)) && (uVar4 = *puVar6, uVar4 != 0)) && (uVar8 != 0)) {
      if (uVar8 < uVar4) {
        uVar4 = uVar8;
      }
      puVar6[2] = puVar6[2] + uVar4;
      uVar8 = uVar8 - uVar4;
      *puVar6 = *puVar6 - uVar4;
    }
    uVar3 = uVar3 + 1;
    puVar6 = puVar6 + 3;
  } while (uVar3 < 4);
  local_34 = local_34 - uVar1;
  uVar3 = 0;
  do {
    uVar8 = *puVar5;
    if ((uVar8 != 0) && (uVar7 != 0)) {
      if (uVar7 < uVar8) {
        uVar8 = uVar7;
      }
      puVar5[1] = puVar5[1] + uVar8;
      uVar7 = uVar7 - uVar8;
      *puVar5 = *puVar5 - uVar8;
    }
    uVar3 = uVar3 + 1;
    puVar5 = puVar5 + 3;
  } while (uVar3 < 4);
  func_02016d28((undefined4 *)(uintptr_t)(iRam02016f20));
  func_02016d28((undefined4 *)(uintptr_t)(uRam02016f24));
  uVar7 = iRam02016f20 + 0x18U & 3;
  uVar4 = *(uint *)(iRam02016f20 + 0x18U & 0xfffffffc);
  uVar3 = iRam02016f20 + 0x14U & 3;
  uVar8 = *(uint *)(iRam02016f20 + 0x14U & 0xfffffffc);
  uVar2 = func_02016cd8(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20,
                        (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) >> 4);
  *(undefined4 *)(iRam02016f20 + 8) = uVar2;
  if (local_38 != 0) {
    func_02016c64(uRam02016f24,uRam02016f28,0);
  }
  if (local_3c != 0) {
    func_02016c64(iRam02016f20,uRam02016f28,local_38);
  }
  if (local_20 != 0) {
    func_02016c64(uRam02016f24,uRam02016f28,0x40000);
  }
  if (local_24 != 0) {
    func_02016c64(iRam02016f20,uRam02016f28,local_20 + 0x40000);
  }
  if (local_18 != 0) {
    func_02016c64(iRam02016f20,uRam02016f28,0x60000);
  }
  if (local_30 != 0) {
    func_02016c64(iRam02016f20,uRam02016f28,uVar1 + 0x20000);
    return;
  }
  return;
}

