/* Decompiled C draft; module arm9; ROM address 02039230. No matching claim. */
#include "types.h"
#include "deps/02039230_GetSomeInput.h"

uint GetSomeInput(void)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  uVar5 = iRam020392c4 + 0x14U & 3;
  uVar3 = *(uint *)(iRam020392c4 + 0x14U & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = iRam020392c4 + 8U & 3;
  uVar3 = *(uint *)(iRam020392c4 + 8U & 0xfffffffc);
  puVar2 = (ushort *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  uVar5 = iRam020392c4 + 4U & 3;
  uVar3 = *(uint *)(iRam020392c4 + 4U & 0xfffffffc);
  if ((byte *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) < (byte *)((int)puVar2 + uVar4)) {
    return 0;
  }
  if (uVar4 == 1) {
    uVar3 = 1;
    uVar4 = 1;
    uVar5 = 0;
    do {
      if ((uVar3 & 0xffff & (uint)*(ushort *)(iRam020392c4 + 0x18)) != 0) {
        if ((uVar4 & (byte)*puVar2) != 0) {
          uVar5 = uVar5 | uVar3 & 0xffff;
        }
        uVar1 = uVar4 & 0x7f;
        uVar4 = uVar1 << 1;
        if (uVar1 == 0) break;
      }
      uVar3 = uVar3 << 1;
    } while (uVar3 < 0x10000);
  }
  else {
    uVar5 = (uint)*puVar2;
  }
  func_02039378(1,1);
  return uVar5;
}

