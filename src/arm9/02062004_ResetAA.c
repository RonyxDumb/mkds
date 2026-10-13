/* Decompiled C draft; module arm9; ROM address 02062004. No matching claim. */
#include "types.h"
#include "deps/02062004_ResetAA.h"

void ResetAA(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  
  func_020d2d94();
  DisposeDrivers();
  DisposeAllModelResources();
  func_0203d568();
  bVar3 = false;
  uVar4 = *(uint *)(uRam02062070 & 0xfffffffc) >> (uRam02062070 & 3) * 8 |
          *(uint *)(uRam02062070 & 0xfffffffc) << (uRam02062070 & 3) * -8 + 0x20;
  if ((uVar4 != 0) &&
     (uVar1 = uVar4 + 0x1f30 & 3, uVar2 = *(uint *)(uVar4 + 0x1f30 & 0xfffffffc),
     uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0)) {
    bVar3 = true;
  }
  if (bVar3) {
    *(undefined1 *)(uVar4 + 0x1f55) =
         *(undefined1 *)
          ((*(uint *)((uint)puRam02062074 & 0xfffffffc) >> ((uint)puRam02062074 & 3) * 8 |
           *(uint *)((uint)puRam02062074 & 0xfffffffc) << ((uint)puRam02062074 & 3) * -8 + 0x20) +
          0x749);
  }
  *puRam02062074 = 0;
  return;
}

