/* Decompiled C draft; module arm9; ROM address 02108720. No matching claim. */
#include "types.h"
#include "deps/02108720_DisposeSomeSoundStuff.h"

void DisposeSomeSoundStuff(void)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  Sound_Context_Dispose
            (*(uint *)((uint)puRam021087ac & 0xfffffffc) >> ((uint)puRam021087ac & 3) * 8 |
             *(uint *)((uint)puRam021087ac & 0xfffffffc) << ((uint)puRam021087ac & 3) * -8 + 0x20);
  uVar1 = (uint)puRam021087b0 & 3;
  uVar4 = *(uint *)((uint)puRam021087b0 & 0xfffffffc);
  *puRam021087ac = 0;
  Sound_Context_Dispose(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar1 = (uint)puRam021087b4 & 3;
  uVar4 = *(uint *)((uint)puRam021087b4 & 0xfffffffc);
  *puRam021087b0 = 0;
  Sound_Context_Dispose(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  *puRam021087b4 = 0;
  func_0210ef50();
  func_0210ef68();
  func_0210ef50();
  func_0210efac();
  uVar3 = uRam021087c0;
  puVar2 = puRam021087bc;
  uVar1 = uRam021087b8 + 4 & 3;
  uVar4 = *(uint *)(uRam021087b8 + 4 & 0xfffffffc);
  *puRam021087bc =
       *(uint *)(uRam021087b8 & 0xfffffffc) >> (uRam021087b8 & 3) * 8 |
       *(uint *)(uRam021087b8 & 0xfffffffc) << (uRam021087b8 & 3) * -8 + 0x20;
  puVar2[1] = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  func_0210e4ec(uVar3);
  return;
}

