/* Decompiled C draft; module arm9; ROM address 0205d360. No matching claim. */
#include "types.h"
#include "deps/0205d360_func_0205d360.h"

undefined1 func_0205d360(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = *(uint *)(uRam0205d3e8 & 0xfffffffc) >> (uRam0205d3e8 & 3) * 8 |
          *(uint *)(uRam0205d3e8 & 0xfffffffc) << (uRam0205d3e8 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  iVar2 = *(ushort *)(uVar3 + 0x60) - 1;
  iVar5 = iVar2 >> 0x1f;
  iVar5 = (int)(((((uint)(iVar2 * 0x40000000 + iVar5) >> 0x1e | iVar5 << 2) - iVar5 & 0xff) - 1) *
               0x1000000) >> 0x18;
  if ((((uVar4 == 2) || (uVar4 == 3)) || (uVar4 == 5)) && (iVar5 < 0)) {
    iVar5 = (iVar5 + 4) * 0x1000000 >> 0x18;
  }
  if (-1 < iVar5) {
    return *(undefined1 *)
            ((param_1 & 0xff) * 10 +
             iVar5 * 0x50 +
             (*(uint *)(uRam0205d3ec & 0xfffffffc) >> (uRam0205d3ec & 3) * 8 |
             *(uint *)(uRam0205d3ec & 0xfffffffc) << (uRam0205d3ec & 3) * -8 + 0x20) + 5);
  }
  return 0;
}

