/* Decompiled C draft; module arm9; ROM address 02001d30. No matching claim. */
#include "types.h"
#include "deps/02001d30_LoadLogoScreenGraphics.h"

void LoadLogoScreenGraphics
               (uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = find_buf_fn_from_thumb(param_3);
  Gfx_ReadPalette((int *)(uintptr_t)(param_1),uVar1);
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 0xc;
  uVar3 = uVar5 & 3;
  uVar2 = *(uint *)(uVar5 & 0xfffffffc);
  uVar4 = uVar4 + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  DC_SomeClean(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,
               uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  if (param_2 == 0) {
    uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar5 = uVar4 + 0xc;
    uVar3 = uVar5 & 3;
    uVar2 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = uVar4 + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    CopyPaletteBottom(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0,
                      uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  else {
    uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar5 = uVar4 + 0xc;
    uVar3 = uVar5 & 3;
    uVar2 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = uVar4 + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    CopyPaletteTop(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0,
                   uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  uVar1 = find_buf_fn_from_thumb(param_4);
  Gfx_ReadCharGraphics((int *)(uintptr_t)(param_1 + 4),uVar1);
  uVar5 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 + 0x14;
  uVar3 = uVar5 & 3;
  uVar2 = *(uint *)(uVar5 & 0xfffffffc);
  uVar4 = uVar4 + 0x10;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  DC_SomeClean(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,
               uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  if (param_2 == 0) {
    uVar5 = param_1 + 4 & 3;
    uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 + 0x14;
    uVar3 = uVar5 & 3;
    uVar2 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = uVar4 + 0x10;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    CopyBgData_Bg1_Bottom
              (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0,
               uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  else {
    uVar5 = param_1 + 4 & 3;
    uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 + 0x14;
    uVar3 = uVar5 & 3;
    uVar2 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = uVar4 + 0x10;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    CopyBgData_Bg1_Top(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0,
                       uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  uVar1 = find_buf_fn_from_thumb(param_5);
  MaybeReadScreenBlock_0((int *)(uintptr_t)(param_1 + 8),uVar1);
  uVar5 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar3 + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  DC_SomeClean(uVar3 + 0xc,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  if (param_2 != 0) {
    uVar5 = param_1 + 8 & 3;
    uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 + 8;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    TEQSub_Fn9Impl(uVar3 + 0xc,0,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    return;
  }
  uVar5 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar3 + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  TEQSub_Fn25Impl(uVar3 + 0xc,0,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  return;
}

