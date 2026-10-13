/* Decompiled C draft; module arm9; ROM address 02044d4c. No matching claim. */
#include "types.h"
#include "deps/02044d4c_MaybeLoadDownloadGhost.h"

bool MaybeLoadDownloadGhost(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar2 = (*(uint *)(uRam02044e8c & 0xfffffffc) >> (uRam02044e8c & 3) * 8 |
          *(uint *)(uRam02044e8c & 0xfffffffc) << (uRam02044e8c & 3) * -8 + 0x20) + 500;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 2) {
    uVar2 = (*(uint *)(uRam02044e90 & 0xfffffffc) >> (uRam02044e90 & 3) * 8 |
            *(uint *)(uRam02044e90 & 0xfffffffc) << (uRam02044e90 & 3) * -8 + 0x20) + 0x18;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar2 = uVar5 + 8 & 3;
    uVar3 = *(uint *)(uVar5 + 8 & 0xfffffffc);
    bVar6 = (int)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) << 0x1f) < 0;
    if (bVar6) {
      uVar2 = uVar5 + 4 & 3;
      uVar3 = *(uint *)(uVar5 + 4 & 0xfffffffc);
      uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      StructCO_ConfigureRacerDefault(param_2,uVar2 & 0xf,(uVar2 << 0x16) >> 0x1a,2);
      iVar1 = iRam02044e94;
      *(undefined4 *)
       (param_2 * 0x30 +
        (*(uint *)(uRam02044e8c & 0xfffffffc) >> (uRam02044e8c & 3) * 8 |
        *(uint *)(uRam02044e8c & 0xfffffffc) << (uRam02044e8c & 3) * -8 + 0x20) + 0x268) = 1;
      uVar2 = iVar1 + param_2 * 0x5c;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      Mem_CpuCopy8(uVar5 + 0x230,uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,uRam02044e98);
      func_02056574(1,(*(uint *)(uRam02044e8c & 0xfffffffc) >> (uRam02044e8c & 3) * 8 |
                      *(uint *)(uRam02044e8c & 0xfffffffc) << (uRam02044e8c & 3) * -8 + 0x20) + 1000
                   );
      uVar2 = uRam02044e8c;
      uVar3 = 1;
      do {
        uVar5 = uVar2 & 3;
        uVar4 = *(uint *)(uVar2 & 0xfffffffc);
        func_020565ac(1,uVar3,(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x3ec +
                              (uVar3 - 1) * 4);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 6);
    }
    else {
      StructCO_ConfigureRacerDefault(param_2,0,0,4);
    }
    return bVar6;
  }
  return true;
}

