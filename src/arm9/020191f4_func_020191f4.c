/* Decompiled C draft; module arm9; ROM address 020191f4. No matching claim. */
#include "types.h"
#include "deps/020191f4_func_020191f4.h"

void func_020191f4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  code *pcVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar3;
  
  uVar2 = param_1 + 0x40U & 3;
  uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar1 = param_1 + 0x2cU & 3;
  uVar4 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar2 = uVar7 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  pcVar5 = (code *)0x0;
  func_02019df8((uint)*(byte *)(uVar2 + 0x47) * 0x14 +
                (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20));
  switch(((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) << 0x1a) >> 0x1e) {
  case 0:
    pcVar5 = DAT_020192c8;
    break;
  case 1:
    pcVar5 = DAT_020192cc;
    break;
  case 2:
    pcVar5 = DAT_020192d0;
    break;
  case 3:
    pcVar5 = DAT_020192d4;
  }
  uVar7 = uVar7 + 8;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  pcVar6 = DAT_020192d8;
  if (-1 < (int)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) << 0x14)) {
    pcVar6 = DAT_020192dc;
  }
  if (uVar7 == 0) {
    return;
  }
  do {
    uVar2 = param_1 + 0x2cU & 3;
    uVar1 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    (*pcVar6)((uint)*(byte *)(uVar7 + 0x2c) * 0x14 +
              (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20));
    (*pcVar5)(param_1,uVar7);
    uVar7 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  } while (uVar7 != 0);
  return;
}

