/* Decompiled C draft; module arm9; ROM address 02062284. No matching claim. */
#include "types.h"
#include "deps/02062284_RaceRenderingFogRelated.h"

void RaceRenderingFogRelated(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(uint *)(uRam02062424 & 0xfffffffc) >> (uRam02062424 & 3) * 8 == 0 &&
      *(uint *)(uRam02062424 & 0xfffffffc) << (uRam02062424 & 3) * -8 + 0x20 == 0) {
    uVar2 = *(uint *)(uRam02062440 & 0xfffffffc) >> (uRam02062440 & 3) * 8 |
            *(uint *)(uRam02062440 & 0xfffffffc) << (uRam02062440 & 3) * -8 + 0x20;
    uVar3 = uVar2 + 0x20;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar2 = uVar2 + 0x24;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar4 != (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      if (uVar4 == 0) {
        uVar3 = (*(uint *)(uRam02062444 & 0xfffffffc) >> (uRam02062444 & 3) * 8 |
                *(uint *)(uRam02062444 & 0xfffffffc) << (uRam02062444 & 3) * -8 + 0x20) + 0x18;
        uVar2 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if (*(char *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 5) == '\0') {
          G3X_SetFog(0,0,5,0);
        }
        else {
          G3X_SetFog(1,0,*(uint *)(uRam02062428 & 0xfffffffc) >> (uRam02062428 & 3) * 8 |
                         *(uint *)(uRam02062428 & 0xfffffffc) << (uRam02062428 & 3) * -8 + 0x20,
                     *(uint *)(uRam02062448 & 0xfffffffc) >> (uRam02062448 & 3) * 8 |
                     *(uint *)(uRam02062448 & 0xfffffffc) << (uRam02062448 & 3) * -8 + 0x20);
          uVar1 = uRam02062454;
          *puRam0206243c =
               (uint)*puRam0206244c |
               (*(uint *)(uRam02062450 & 0xfffffffc) >> (uRam02062450 & 3) * 8 |
               *(uint *)(uRam02062450 & 0xfffffffc) << (uRam02062450 & 3) * -8 + 0x20) << 0x10;
          G3X_SetFogTable(uVar1);
        }
      }
      else {
        G3X_SetFog(1,0,*(uint *)(uRam02062428 & 0xfffffffc) >> (uRam02062428 & 3) * 8 |
                       *(uint *)(uRam02062428 & 0xfffffffc) << (uRam02062428 & 3) * -8 + 0x20,0);
        uVar1 = uRam02062430;
        *puRam0206243c =
             (uint)*puRam02062458 |
             (*(uint *)(uRam0206245c & 0xfffffffc) >> (uRam0206245c & 3) * 8 |
             *(uint *)(uRam0206245c & 0xfffffffc) << (uRam0206245c & 3) * -8 + 0x20) << 0x10;
        G3X_SetFogTable(uVar1);
      }
    }
  }
  else {
    G3X_SetFog(1,0,*(uint *)(uRam02062428 & 0xfffffffc) >> (uRam02062428 & 3) * 8 |
                   *(uint *)(uRam02062428 & 0xfffffffc) << (uRam02062428 & 3) * -8 + 0x20,
               *(uint *)(uRam0206242c & 0xfffffffc) >> (uRam0206242c & 3) * 8 |
               *(uint *)(uRam0206242c & 0xfffffffc) << (uRam0206242c & 3) * -8 + 0x20);
    G3X_SetFogTable(uRam02062430);
    *puRam0206243c =
         (uint)*puRam02062434 |
         (*(uint *)(uRam02062438 & 0xfffffffc) >> (uRam02062438 & 3) * 8 |
         *(uint *)(uRam02062438 & 0xfffffffc) << (uRam02062438 & 3) * -8 + 0x20) << 0x10;
  }
  uVar4 = *(uint *)(uRam02062440 & 0xfffffffc) >> (uRam02062440 & 3) * 8 |
          *(uint *)(uRam02062440 & 0xfffffffc) << (uRam02062440 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x20;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 0x24) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  func_02062078();
  func_0208b870(*(uint *)(uRam02062460 & 0xfffffffc) >> (uRam02062460 & 3) * 8 |
                *(uint *)(uRam02062460 & 0xfffffffc) << (uRam02062460 & 3) * -8 + 0x20);
  func_0208ee7c(*(uint *)(uRam02062460 & 0xfffffffc) >> (uRam02062460 & 3) * 8 |
                *(uint *)(uRam02062460 & 0xfffffffc) << (uRam02062460 & 3) * -8 + 0x20);
  func_02089fa0();
  uVar3 = (*(uint *)(uRam02062440 & 0xfffffffc) >> (uRam02062440 & 3) * 8 |
          *(uint *)(uRam02062440 & 0xfffffffc) << (uRam02062440 & 3) * -8 + 0x20) + 0x28;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
    func_02086250(*(uint *)(uRam02062460 & 0xfffffffc) >> (uRam02062460 & 3) * 8 |
                  *(uint *)(uRam02062460 & 0xfffffffc) << (uRam02062460 & 3) * -8 + 0x20);
  }
  func_02104118();
  uVar4 = *(uint *)(uRam02062440 & 0xfffffffc) >> (uRam02062440 & 3) * 8 |
          *(uint *)(uRam02062440 & 0xfffffffc) << (uRam02062440 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 8) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 1;
  return;
}

