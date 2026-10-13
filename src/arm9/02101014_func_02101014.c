/* Decompiled C draft; module arm9; ROM address 02101014. No matching claim. */
#include "types.h"
#include "deps/02101014_func_02101014.h"

uint func_02101014(int param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  iVar5 = ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0xffff) * 0x210 +
          (*(uint *)(uRam02101164 & 0xfffffffc) >> (uRam02101164 & 3) * 8 |
          *(uint *)(uRam02101164 & 0xfffffffc) << (uRam02101164 & 3) * -8 + 0x20);
  uVar8 = iVar5 + 0x30U & 3;
  uVar3 = *(uint *)(iVar5 + 0x30U & 0xfffffffc);
  uVar3 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  uVar8 = iVar5 + 0x1fcU & 3;
  uVar7 = *(uint *)(iVar5 + 0x1fcU & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if ((uVar3 == 0x13) ||
     (uVar7 = iVar5 + 0x50U & 3, uVar6 = *(uint *)(iVar5 + 0x50U & 0xfffffffc),
     uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0)) {
    return 0xf;
  }
  if (uVar3 == 0x10) {
    return 0xf;
  }
  uVar7 = param_1 + 0x144U & 3;
  uVar6 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 == 0 && uVar6 << uVar7 * -8 + 0x20 == 0) {
    uVar7 = uVar8 + 0x180 & 3;
    uVar6 = *(uint *)(uVar8 + 0x180 & 0xfffffffc);
    bVar2 = true;
    bVar1 = true;
    if (((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < 4) &&
       (uVar7 = uVar8 + 0x7c & 3, uVar6 = *(uint *)(uVar8 + 0x7c & 0xfffffffc),
       ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & uRam02101168) == 0)) {
      bVar1 = false;
    }
    if ((!bVar1) &&
       (uVar7 = uVar8 + 0x4c & 3, uVar6 = *(uint *)(uVar8 + 0x4c & 0xfffffffc),
       ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & uRam0210116c) == 0)) {
      bVar2 = false;
    }
    uVar7 = uVar8 + 0x4c & 3;
    uVar6 = *(uint *)(uVar8 + 0x4c & 0xfffffffc);
    if (!bVar2 && ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x40) == 0) {
      uVar7 = param_1 + 0x74U & 3;
      uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000000) == 0) {
        func_020f413c((undefined4 *)(uintptr_t)(iVar5 + 0x30),(uint *)(uintptr_t)(param_1 + 0x154),(uint *)(uintptr_t)(param_1 + 0x158));
      }
      else {
        *(uint *)(param_1 + 0x154) = uVar3;
        uVar6 = uRam02101170;
        uVar3 = iVar5 + 0x38U & 3;
        uVar7 = *(uint *)(iVar5 + 0x38U & 0xfffffffc);
        *(uint *)(param_1 + 0x158) = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
        uVar3 = param_1 + 0x140U & 3;
        uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
        uVar7 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        func_0205a5b0(*(undefined1 *)
                       ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
                       ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0xff)));
      }
      StructMQRacerEntry_SomeFn_10(uVar8);
      uVar8 = param_1 + 0x154U & 3;
      uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
      uVar8 = (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) * 0x1c +
              (*(uint *)(uRam02101174 & 0xfffffffc) >> (uRam02101174 & 3) * 8 |
              *(uint *)(uRam02101174 & 0xfffffffc) << (uRam02101174 & 3) * -8 + 0x20) + 8;
      uVar3 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      return uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
    }
    return 0xf;
  }
  return 0xf;
}

