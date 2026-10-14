/* Decompiled C draft; module arm9; ROM address 02044bf8. No matching claim. */
#include "types.h"
#include "deps/02044bf8_MaybeLoadStaffGhost.h"

undefined4 MaybeLoadStaffGhost(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = (*(uint *)(uRam02044d3c & 0xfffffffc) >> (uRam02044d3c & 3) * 8 |
          *(uint *)(uRam02044d3c & 0xfffffffc) << (uRam02044d3c & 3) * -8 + 0x20) + 500;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) == 2) {
    return 1;
  }
  uVar3 = (*(uint *)(uRam02044d40 & 0xfffffffc) >> (uRam02044d40 & 3) * 8 |
          *(uint *)(uRam02044d40 & 0xfffffffc) << (uRam02044d40 & 3) * -8 + 0x20) + 0x1c;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if ((uVar3 != 0) &&
     (uVar6 = uVar3 + 8 & 3, uVar4 = *(uint *)(uVar3 + 8 & 0xfffffffc),
     (int)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) << 0x1f) < 0)) {
    uVar6 = uVar3 + 4 & 3;
    uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    StructCO_ConfigureRacerDefault(param_2,uVar6 & 0xf,(uVar6 << 0x16) >> 0x1a,2);
    iVar2 = iRam02044d44;
    *(undefined4 *)
     (param_2 * 0x30 +
      (*(uint *)(uRam02044d3c & 0xfffffffc) >> (uRam02044d3c & 3) * 8 |
      *(uint *)(uRam02044d3c & 0xfffffffc) << (uRam02044d3c & 3) * -8 + 0x20) + 0x268) = 2;
    uVar6 = iVar2 + param_2 * 0x5c;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)(uVar3 + 0x230),(uint *)(uintptr_t)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20),uRam02044d48);
    StructNKPG_CopyToTime_from_thumb
              (uVar3,(ushort *)(uintptr_t)((*(uint *)(uRam02044d3c & 0xfffffffc) >> (uRam02044d3c & 3) * 8 |
                     *(uint *)(uRam02044d3c & 0xfffffffc) << (uRam02044d3c & 3) * -8 + 0x20) + 1000))
    ;
    uVar6 = uRam02044d3c;
    uVar4 = 1;
    do {
      uVar1 = uVar6 & 3;
      uVar5 = *(uint *)(uVar6 & 0xfffffffc);
      StructNKPG_AnotherCopyToTime_from_thumb
                (uVar3,uVar4,
                 (ushort *)(uintptr_t)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x3ec + (uVar4 - 1) * 4));
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 6);
    return 1;
  }
  StructCO_ConfigureRacerDefault(param_2,0,0,4);
  return 0;
}

