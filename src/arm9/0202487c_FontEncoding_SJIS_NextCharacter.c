/* Decompiled C draft; module arm9; ROM address 0202487c. No matching claim. */
#include "types.h"
#include "deps/0202487c_FontEncoding_SJIS_NextCharacter.h"

ushort FontEncoding_SJIS_NextCharacter(int *param_1)

{
  byte bVar1;
  byte *pbVar2;
  ushort uVar3;
  
  pbVar2 = (byte *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  bVar1 = *pbVar2;
  uVar3 = (ushort)bVar1;
  if (((uVar3 < 0x81) || (0x9f < uVar3)) && (uVar3 < 0xe0)) {
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 1;
  }
  else {
    uVar3 = CONCAT11(bVar1,pbVar2[1]);
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 2;
  }
  return uVar3;
}

