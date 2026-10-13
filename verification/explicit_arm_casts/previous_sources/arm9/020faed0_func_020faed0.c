/* Decompiled C draft; module arm9; ROM address 020faed0. No matching claim. */
#include "types.h"
#include "deps/020faed0_func_020faed0.h"

void func_020faed0(int param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_28;
  uint local_24;
  uint local_20;
  
  uVar5 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if ((((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x2000) != 0) &&
     (iVar2 = func_020f91c4(param_1,uRam020fb030), iVar2 != 0)) {
    return;
  }
  uVar5 = param_1 + 0x68U & 3;
  uVar3 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
  local_28 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x6cU & 3;
  uVar3 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  local_24 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  sVar1 = *(short *)(param_1 + 0xd8);
  local_20 = local_28;
  if (sVar1 != 0x1f) {
    uVar5 = (*(uint *)(uRam020fb034 & 0xfffffffc) >> (uRam020fb034 & 3) * 8 |
            *(uint *)(uRam020fb034 & 0xfffffffc) << (uRam020fb034 & 3) * -8 + 0x20) + 4;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = 0;
    if (*(char *)(uVar5 + 0x18) != '\0') {
      do {
        func_02013468(uVar5,uVar3,sVar1);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(byte *)(uVar5 + 0x18));
    }
  }
  uVar5 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x80000) == 0) {
    uVar5 = param_1 + 0xd0U & 3;
    uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    iVar2 = param_1 + 0x94;
    *(int *)(param_1 + 0xb8) =
         (int)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) >> 4;
    uVar5 = uVar4 + 4 & 3;
    uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc);
    *(int *)(param_1 + 0xbc) = (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 4;
    uVar5 = uVar4 + 8 & 3;
    uVar3 = *(uint *)(uVar4 + 8 & 0xfffffffc);
    *(int *)(param_1 + 0xc0) = (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 4;
  }
  else {
    iVar2 = func_020ed98c(param_1,param_2);
  }
  func_020ea8a8(*(uint *)(uRam020fb034 & 0xfffffffc) >> (uRam020fb034 & 3) * 8 |
                *(uint *)(uRam020fb034 & 0xfffffffc) << (uRam020fb034 & 3) * -8 + 0x20,iVar2,
                &local_28,0x1f);
  if (*(short *)(param_1 + 0xd8) == 0x1f) {
    return;
  }
  uVar4 = 0;
  uVar5 = (*(uint *)(uRam020fb034 & 0xfffffffc) >> (uRam020fb034 & 3) * 8 |
          *(uint *)(uRam020fb034 & 0xfffffffc) << (uRam020fb034 & 3) * -8 + 0x20) + 4;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if (*(char *)(uVar5 + 0x18) == '\0') {
    return;
  }
  do {
    func_02013468(uVar5,uVar4,0x1f);
    uVar4 = uVar4 + 1;
  } while (uVar4 < *(byte *)(uVar5 + 0x18));
  return;
}

