/* Decompiled C draft; module arm9; ROM address 020c6428. No matching claim. */
#include "types.h"
#include "deps/020c6428_CheckHandleSaveTimeTrialRecord_LeastLap.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 CheckHandleSaveTimeTrialRecord_LeastLap(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte local_10;
  byte local_f;
  ushort local_e;
  
  uVar3 = *(uint *)(uRam020c6570 & 0xfffffffc) >> (uRam020c6570 & 3) * 8 |
          *(uint *)(uRam020c6570 & 0xfffffffc) << (uRam020c6570 & 3) * -8 + 0x20;
  uVar4 = GetCurrentPlayerRacerId();
  uVar2 = GetLeastTimeLap(uVar4,&local_10,&local_f,&local_e);
  *(undefined2 *)
   ((*(uint *)(uRam020c6570 & 0xfffffffc) >> (uRam020c6570 & 3) * 8 |
    *(uint *)(uRam020c6570 & 0xfffffffc) << (uRam020c6570 & 3) * -8 + 0x20) + 0x14) = uVar2;
  if ((*(char *)(uVar3 + 0xd4) != '\0') &&
     ((int)((uint)*(ushort *)(uVar3 + 0xbc) +
           (uint)*(byte *)(uVar3 + 0xbf) * 1000 + (uint)*(byte *)(uVar3 + 0xbe) * iRam020c6574) <=
      (int)((uint)local_e + (uint)local_f * 1000 + (uint)local_10 * iRam020c6574))) {
    return 0;
  }
  if (param_1 != 0) {
    uVar5 = *(uint *)(uRam020c6570 & 0xfffffffc) >> (uRam020c6570 & 3) * 8 |
            *(uint *)(uRam020c6570 & 0xfffffffc) << (uRam020c6570 & 3) * -8 + 0x20;
    *(byte *)(uVar5 + 0xbe) = local_10;
    *(byte *)(uVar5 + 0xbf) = local_f;
    *(ushort *)(uVar5 + 0xbc) = local_e;
    iVar6 = GetCurrentPlayerRacerId();
    uVar3 = iVar6 * 0x30 +
            (*(uint *)(uRam020c6578 & 0xfffffffc) >> (uRam020c6578 & 3) * 8 |
            *(uint *)(uRam020c6578 & 0xfffffffc) << (uRam020c6578 & 3) * -8 + 0x20) + 0x88;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    CopyMemory16(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,uVar5 + 0xc0,0x14);
    *(undefined1 *)(uVar5 + 0xd4) = 1;
    iVar6 = GetCurrentPlayerRacerId();
    uVar3 = iVar6 * 0x30 +
            (*(uint *)(uRam020c6578 & 0xfffffffc) >> (uRam020c6578 & 3) * 8 |
            *(uint *)(uRam020c6578 & 0xfffffffc) << (uRam020c6578 & 3) * -8 + 0x20) + 0x68;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(byte *)(uVar5 + 0xd5) = (byte)(uVar3 >> uVar7 * 8) | (byte)(uVar3 << uVar7 * -8 + 0x20);
    iVar6 = GetCurrentPlayerRacerId();
    uVar1 = uRam020c6578;
    uVar3 = iVar6 * 0x30 +
            (*(uint *)(uRam020c6578 & 0xfffffffc) >> (uRam020c6578 & 3) * 8 |
            *(uint *)(uRam020c6578 & 0xfffffffc) << (uRam020c6578 & 3) * -8 + 0x20) + 0x6c;
    uVar7 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(byte *)(uVar5 + 0xd6) = (byte)(uVar3 >> uVar7 * 8) | (byte)(uVar3 << uVar7 * -8 + 0x20);
    uVar3 = uVar1 & 3;
    uVar7 = *(uint *)(uVar1 & 0xfffffffc);
    uVar7 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
    uVar3 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    TimeTrialCopyToSaveData_from_thumb
              (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20,5,uVar5 + 0xbc);
  }
  return 1;
}

