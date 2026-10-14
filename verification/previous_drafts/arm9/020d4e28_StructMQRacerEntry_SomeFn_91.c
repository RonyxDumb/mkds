/* Decompiled C draft; module arm9; ROM address 020d4e28. No matching claim. */
#include "types.h"
#include "deps/020d4e28_StructMQRacerEntry_SomeFn_91.h"

void StructMQRacerEntry_SomeFn_91(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_3 & 4) != 0) {
    if ((*(ushort *)(param_1 + 0x34) & 1) != 0) {
      StructMQRacerEntry_SomeFn_47(param_1,2,1);
      return;
    }
    return;
  }
  uVar1 = iRam020d4eec + 0xcU & 3;
  uVar5 = *(uint *)(iRam020d4eec + 0xcU & 0xfffffffc);
  uVar2 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  iVar3 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) -
          (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  if ((-0x12c000 < iVar3) &&
     (iVar3 < (int)(*(uint *)(uRam020d4ef0 & 0xfffffffc) >> (uRam020d4ef0 & 3) * 8 |
                   *(uint *)(uRam020d4ef0 & 0xfffffffc) << (uRam020d4ef0 & 3) * -8 + 0x20))) {
    if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
      StructMQRacerEntry_SomeFn_47(param_1,2,1);
      return;
    }
    return;
  }
  if ((*(ushort *)(param_1 + 0x34) & 1) != 0) {
    StructMQRacerEntry_SomeFn_47(param_1,2,1);
    return;
  }
  return;
}

