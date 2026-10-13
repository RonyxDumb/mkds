/* Decompiled C draft; module arm9; ROM address 02046c10. No matching claim. */
#include "types.h"
#include "deps/02046c10_func_02046c10.h"

short func_02046c10(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(uRam02046c70 & 0xfffffffc) >> (uRam02046c70 & 3) * 8 |
          *(uint *)(uRam02046c70 & 0xfffffffc) << (uRam02046c70 & 3) * -8 + 0x20;
  uVar1 = uVar5 + 0x30 & 3;
  uVar3 = *(uint *)(uVar5 + 0x30 & 0xfffffffc);
  if ((((int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) << 0x1f) < 0) &&
      (*(short *)(uVar5 + 0x2c) != 0)) && (*(short *)(uVar5 + 0x2e) == 0)) {
    uVar4 = *(ushort *)(uVar5 + 0x28) & 0xff;
    uVar2 = *(ushort *)(uVar5 + 0x2a) & 0xff;
  }
  else {
    uVar4 = 0xff;
    uVar2 = 0xff;
  }
  return uVar2 + uVar4 * 0x100;
}

