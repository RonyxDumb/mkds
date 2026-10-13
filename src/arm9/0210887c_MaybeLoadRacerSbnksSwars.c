/* Decompiled C draft; module arm9; ROM address 0210887c. No matching claim. */
#include "types.h"
#include "deps/0210887c_MaybeLoadRacerSbnksSwars.h"

undefined4 MaybeLoadRacerSbnksSwars(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = *(uint *)((uint)puRam0210893c & 0xfffffffc) >> ((uint)puRam0210893c & 3) * 8 |
          *(uint *)((uint)puRam0210893c & 0xfffffffc) << ((uint)puRam0210893c & 3) * -8 + 0x20;
  uVar2 = uRam02108944 & 3;
  uVar7 = *(uint *)(uRam02108944 & 0xfffffffc);
  *puRam0210893c =
       *(uint *)(uRam02108940 & 0xfffffffc) >> (uRam02108940 & 3) * 8 |
       *(uint *)(uRam02108940 & 0xfffffffc) << (uRam02108940 & 3) * -8 + 0x20;
  if ((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) != 2) {
    Sound_LoadSbnk(1);
  }
  iVar4 = iRam0210894c;
  iVar3 = iRam02108948;
  uVar2 = uRam02108940;
  uVar7 = 0;
  do {
    if ((param_1 >> (uVar7 & 0xff) & 1U) != 0) {
      uVar5 = iVar3 + uVar7 * 4;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      iVar6 = Sound_LoadSbnkWithFlags
                        (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,2,
                         *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
      if (iVar6 == 0) {
        *puRam0210893c = uVar8;
        return 0;
      }
      uVar5 = iVar4 + uVar7 * 4;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      iVar6 = Sound_LoadSwar(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,
                             *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
      if (iVar6 == 0) {
        *puRam0210893c = uVar8;
        return 0;
      }
    }
    uVar7 = uVar7 + 1;
    if (0xc < (int)uVar7) {
      *puRam0210893c = uVar8;
      return 1;
    }
  } while( true );
}

