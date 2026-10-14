/* Decompiled C draft; module arm9; ROM address 02046fb4. No matching claim. */
#include "types.h"
#include "deps/02046fb4_CreateGlobal59C4Sub.h"

void CreateGlobal59C4Sub(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = (*(uint *)(uRam02047050 & 0xfffffffc) >> (uRam02047050 & 3) * 8 |
          *(uint *)(uRam02047050 & 0xfffffffc) << (uRam02047050 & 3) * -8 + 0x20) + 0x30;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (-1 < (int)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) << 0x1e)) {
    uVar1 = Mem_AllocateHeapAligned(param_1,0x420,0x20);
    uVar2 = uRam02047050;
    *(undefined4 *)
     ((*(uint *)(uRam02047050 & 0xfffffffc) >> (uRam02047050 & 3) * 8 |
      *(uint *)(uRam02047050 & 0xfffffffc) << (uRam02047050 & 3) * -8 + 0x20) + 0x3c) = uVar1;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x3c;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Struct59C4Sub_Initialize(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar3 = (*(uint *)(uRam02047050 & 0xfffffffc) >> (uRam02047050 & 3) * 8 |
            *(uint *)(uRam02047050 & 0xfffffffc) << (uRam02047050 & 3) * -8 + 0x20) + 0x3c;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Struct59C4Sub_SomeFn(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar4 = uRam02047050;
    uVar5 = *(uint *)(uRam02047050 & 0xfffffffc) >> (uRam02047050 & 3) * 8 |
            *(uint *)(uRam02047050 & 0xfffffffc) << (uRam02047050 & 3) * -8 + 0x20;
    uVar3 = uVar5 + 0x30;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar5 + 0x30) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 | 2;
    uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    uVar3 = uVar5 + 0x30;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar5 + 0x30) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xfffffffb;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    uVar3 = uVar4 + 0x30;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar4 + 0x30) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xfffffff7;
    return;
  }
  return;
}

