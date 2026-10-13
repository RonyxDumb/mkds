/* Decompiled C draft; module arm9; ROM address 02056750. No matching claim. */
#include "types.h"
#include "deps/02056750_FillPersonalGhostData_from_thumb.h"

void FillPersonalGhostData_from_thumb(undefined4 param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte local_3c;
  byte local_3b;
  ushort local_3a;
  uint local_38;
  uint local_34;
  int local_30;
  byte local_28 [20];
  
  uVar3 = GetCourseIdFromInternalId();
  iVar4 = param_2 * 0x30;
  iVar7 = *(int *)(*piRam0205696c + iVar4 + 0x7c);
  iVar6 = *(int *)(*piRam02056970 + 0x14);
  if (uVar3 != 0xffffffff) {
    Mem_CpuFill8(iVar6,0,uRam02056974);
    GetCurrentDate(&local_38);
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & uRam02056978 | (local_38 & 0x7f) << 0x10;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & uRam0205697c | (local_34 & 0xf) << 0x17;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & uRam02056980 | local_30 << 0x1b;
    piVar1 = piRam0205696c;
    *(uint *)(iVar6 + 4) =
         *(uint *)(iVar6 + 4) & 0xfffffff0 | *(uint *)(*piRam0205696c + iVar4 + 0x68) & 0xf;
    *(uint *)(iVar6 + 4) =
         *(uint *)(iVar6 + 4) & uRam02056984 | (*(uint *)(*piVar1 + iVar4 + 0x6c) & 0x3f) << 4;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & uRam02056988 | (*(uint *)*piVar1 & 0x3f) << 10;
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffe | 1;
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffd;
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffff3 | (*(uint *)*puRam0205698c & 3) << 2;
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xffffff0f;
    bVar2 = GetWorstStarRank_from_thumb();
    *(byte *)(iVar6 + 0x2f) = *(byte *)(iVar6 + 0x2f) & 0xfc | bVar2 & 3;
    GetPlayerTotalTime(param_2,&local_3c,&local_3b,&local_3a);
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & uRam02056990 | (local_3c & 0x7f) << 8;
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & uRam02056994 | (local_3b & 0x7f) << 0xf;
    *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & uRam02056998 | (local_3a & uRam0205699c) << 0x16;
    Mem_CpuCopy8(*(int *)*piRam02056970 + 0xc,iVar6 + 0xc,0x14);
    Mem_CpuCopy8(*(undefined4 *)(iRam020569a0 + iVar7 * 0x5c),iVar6 + 0x30,uRam020569a4);
    Mem_CpuFill8(local_28,0,0xf);
    uVar5 = 1;
    iVar4 = GetCurrentLapCount();
    if (0 < iVar4) {
      do {
        uVar8 = (uVar5 - 1) * 3 & 0xff;
        MaybeGetPlayerLapTime(param_2,uVar5,&local_3c,&local_3b,&local_3a);
        iVar4 = (local_3b & 0x7f) << 10;
        local_28[uVar8] = (byte)(((local_3c & 0x7f) << 0x11) >> 0x10) | (byte)((uint)iVar4 >> 0x10);
        local_28[uVar8 + 1] = (byte)((uint)iVar4 >> 8) | (byte)((local_3a & uRam0205699c) >> 8);
        local_28[uVar8 + 2] = (byte)(local_3a & uRam0205699c);
        uVar5 = uVar5 + 1 & 0xff;
        iVar4 = GetCurrentLapCount();
      } while ((int)uVar5 <= iVar4);
    }
    Mem_CpuCopy8(local_28,iVar6 + 0x20,0xf);
    uVar3 = uVar3 & 0xff;
    WriteSaveDataSection_PersonalGhost_from_thumb(uVar3,iVar6);
    iVar4 = MaybeHasPersonalGhostForCourse_from_thumb(uVar3);
    if (iVar4 == 0) {
      MaybeSetPersonalGhostForCoursePresent_from_thumb(uVar3,*(int *)*piRam02056970 + 0x26,4);
      WriteSaveDataHeader_from_thumb();
    }
  }
  return;
}

