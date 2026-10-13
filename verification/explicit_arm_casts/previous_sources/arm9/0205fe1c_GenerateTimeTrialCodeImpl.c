/* Decompiled C draft; module arm9; ROM address 0205fe1c. No matching claim. */
#include "types.h"
#include "deps/0205fe1c_GenerateTimeTrialCodeImpl.h"

undefined4 GenerateTimeTrialCodeImpl(int param_1,ushort *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  byte local_30 [16];
  
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  local_30[8] = 0;
  local_30[9] = 0;
  uVar8 = (uint)*param_2 +
          (uint)*(byte *)((int)param_2 + 3) * 1000 + (uint)(byte)param_2[1] * iRam0205fff0;
  if (uRam0205fff4 <= uVar8) {
    return 0;
  }
  uVar2 = GetCourseIdFromInternalId(param_3);
  if ((-1 < (int)uVar2) && ((int)uVar2 < 0x20)) {
    uVar6 = (uint)*(byte *)((int)param_2 + 0x19) * 0x25 + (uint)(byte)param_2[0xd];
    if (uVar6 < 0x200) {
      iVar1 = (uVar8 & uRam0205fff8) << 0xe;
      uVar6 = uRam0205fffc & uVar6;
      local_30[1] = (byte)((uint)iVar1 >> 8) | (byte)(((uVar2 & 0x1f) << 9) >> 8) |
                    (byte)(uVar6 >> 8);
      local_30[3] = (byte)((uint)iVar1 >> 0x18);
      local_30[2] = (byte)((uint)iVar1 >> 0x10);
      local_30[0] = (byte)uVar6;
      Mem_CpuCopy8(param_2 + 2,local_30 + 4,4);
      local_30[9] = 0;
      local_30[8] = 0;
      CalculateCRCChecksum_from_thumb(local_30,10,1);
      iVar1 = iRam02060000;
      bVar4 = 0xc3;
      iVar7 = 9;
      pbVar3 = local_30 + 9;
      do {
        iVar7 = iVar7 + -1;
        *pbVar3 = *pbVar3 ^ bVar4;
        bVar4 = *pbVar3;
        pbVar3 = pbVar3 + -1;
      } while (-1 < iVar7);
      iVar7 = 0;
      cVar5 = '\0';
      do {
        bVar4 = 0;
        uVar8 = 0;
        do {
          uVar6 = uVar8;
          bVar9 = cVar5 + bVar4;
          bVar4 = bVar4 + 1;
          uVar2 = (int)(uint)local_30[bVar9 >> 3] >> (uint)(byte)(7 - (bVar9 & 7)) & 1;
          uVar8 = ((uVar6 | uVar2) << 0x11) >> 0x10;
        } while (bVar4 < 5);
        cVar5 = cVar5 + '\x05';
        *(undefined1 *)(param_1 + iVar7) = *(undefined1 *)(iVar1 + (uVar6 & 0xff | uVar2));
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x10);
      return 1;
    }
    return 0;
  }
  return 0;
}

