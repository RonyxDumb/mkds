/* Decompiled C draft; module arm9; ROM address 02044e9c. No matching claim. */
#include "types.h"
#include "deps/02044e9c_MaybeLoadPersonalGhost.h"

undefined4 MaybeLoadPersonalGhost(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar1 = (*(uint *)(uRam02044fb0 & 0xfffffffc) >> (uRam02044fb0 & 3) * 8 |
          *(uint *)(uRam02044fb0 & 0xfffffffc) << (uRam02044fb0 & 3) * -8 + 0x20) + 500;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 2) {
    uVar1 = (*(uint *)(uRam02044fb4 & 0xfffffffc) >> (uRam02044fb4 & 3) * 8 |
            *(uint *)(uRam02044fb4 & 0xfffffffc) << (uRam02044fb4 & 3) * -8 + 0x20) + 0x14;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar4 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar1 = uVar4 + 8 & 3;
    uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
    if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
      uVar1 = uVar4 + 4 & 3;
      uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
      uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      StructCO_ConfigureRacerDefault(param_2,uVar1 & 0xf,(uVar1 << 0x16) >> 0x1a,2);
      *(undefined4 *)
       (param_2 * 0x30 +
        (*(uint *)(uRam02044fb0 & 0xfffffffc) >> (uRam02044fb0 & 3) * 8 |
        *(uint *)(uRam02044fb0 & 0xfffffffc) << (uRam02044fb0 & 3) * -8 + 0x20) + 0x268) = 0;
      uVar1 = iRam02044fb8 + param_2 * 0x5c;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      Mem_CpuCopy8(uVar4 + 0x30,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,uRam02044fbc);
      uVar5 = 1;
      func_02056574(0,(*(uint *)(uRam02044fb0 & 0xfffffffc) >> (uRam02044fb0 & 3) * 8 |
                      *(uint *)(uRam02044fb0 & 0xfffffffc) << (uRam02044fb0 & 3) * -8 + 0x20) + 1000
                   );
      uVar1 = uRam02044fb0;
      uVar2 = 1;
      do {
        uVar4 = uVar1 & 3;
        uVar3 = *(uint *)(uVar1 & 0xfffffffc);
        func_020565ac(0,uVar2,(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x3ec +
                              (uVar2 - 1) * 4);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 6);
    }
    return uVar5;
  }
  return 1;
}

