/* Decompiled C draft; module arm9; ROM address 02015428. No matching claim. */
#include "types.h"
#include "deps/02015428_CreateAnimBlock_BMA.h"

void CreateAnimBlock_BMA(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_3 + 8U & 3;
  uVar3 = *(uint *)(param_3 + 8U & 0xfffffffc);
  *(uint *)(param_1 + 0xc) =
       *(uint *)(uRam020154e0 & 0xfffffffc) >> (uRam020154e0 & 3) * 8 |
       *(uint *)(uRam020154e0 & 0xfffffffc) << (uRam020154e0 & 3) * -8 + 0x20;
  *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_3 + 0x18);
  Mem_CpuFill16(0,param_1 + 0x1a,(uint)*(byte *)(param_1 + 0x19) << 1);
  uVar4 = 0;
  if (*(char *)(param_2 + 9) != '\0') {
    uVar5 = uVar4;
    do {
      iVar2 = param_2 + 8 + (uint)*(ushort *)(param_2 + 0xe);
      iVar2 = Dict_SomeFn_0(param_3 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4,
                            iVar2 + (uint)*(ushort *)(iVar2 + 2) + uVar4);
      if (-1 < iVar2) {
        *(ushort *)(param_1 + iVar2 * 2 + 0x1a) = (ushort)uVar5 | 0x100;
      }
      uVar5 = uVar5 + 1;
      uVar4 = uVar4 + 0x10;
    } while (uVar5 < *(byte *)(param_2 + 9));
    return;
  }
  return;
}

