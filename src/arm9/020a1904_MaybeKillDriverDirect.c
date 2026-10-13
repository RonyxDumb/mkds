/* Decompiled C draft; module arm9; ROM address 020a1904. No matching claim. */
#include "types.h"
#include "deps/020a1904_MaybeKillDriverDirect.h"

void MaybeKillDriverDirect(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  code *pcVar4;
  
  uVar3 = (*(uint *)(uRam020a19f0 & 0xfffffffc) >> (uRam020a19f0 & 3) * 8 |
          *(uint *)(uRam020a19f0 & 0xfffffffc) << (uRam020a19f0 & 3) * -8 + 0x20) + 0x38c;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  pcVar4 = (code *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)();
  }
  uVar5 = uRam020a19f4;
  uVar1 = uRam020a19f0;
  iVar2 = param_1 * 0x70;
  *(undefined4 *)
   ((*(uint *)(uRam020a19f0 & 0xfffffffc) >> (uRam020a19f0 & 3) * 8 |
    *(uint *)(uRam020a19f0 & 0xfffffffc) << (uRam020a19f0 & 3) * -8 + 0x20) + iVar2 + 8) = 1;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 8;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == 2) {
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar2 + 0x4c) = 0xffffffff;
    *(undefined2 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar2 + 0x50) = 0;
  }
  if (*(byte *)((*(uint *)(uRam020a19f4 & 0xfffffffc) >> (uRam020a19f4 & 3) * 8 |
                *(uint *)(uRam020a19f4 & 0xfffffffc) << (uRam020a19f4 & 3) * -8 + 0x20) + 0x3d0) <=
      param_1) {
    return;
  }
  func_020a19f8(param_1);
  uVar3 = (*(uint *)(uRam020a19f4 & 0xfffffffc) >> (uRam020a19f4 & 3) * 8 |
          *(uint *)(uRam020a19f4 & 0xfffffffc) << (uRam020a19f4 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  if (uVar3 == 2) {
    GetDriverEntry(param_1);
    StructMQRacerEntry_SomeFn_52();
    return;
  }
  if (uVar3 == 4) {
    iVar2 = GetDriverEntry(param_1);
    uVar3 = iVar2 + 0x48U & 3;
    uVar5 = *(uint *)(iVar2 + 0x48U & 0xfffffffc);
    *(uint *)(iVar2 + 0x48) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20 | 0x2000;
    uVar3 = iVar2 + 0x7cU & 3;
    uVar5 = *(uint *)(iVar2 + 0x7cU & 0xfffffffc);
    *(uint *)(iVar2 + 0x7c) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20 | 8;
    return;
  }
  return;
}

