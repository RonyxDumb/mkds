/* Decompiled C draft; module arm9; ROM address 0205e900. No matching claim. */
#include "types.h"
#include "deps/0205e900_GlobalATFunction_0.h"

void GlobalATFunction_0(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_40;
  char local_3c [8];
  char local_34 [16];
  
  uVar7 = uRam0205ebfc;
  uVar4 = 0;
  bVar1 = false;
  uVar6 = 0;
  do {
    local_34[uVar4] = '\0';
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0xc);
  do {
    local_3c[uVar6] = -1;
    uVar4 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    if ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 2) {
      uVar3 = (uint)*(ushort *)(uVar4 + 0x432);
    }
    else {
      uVar3 = 0;
    }
    if (((uVar6 != uVar3) &&
        (uVar3 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                 *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20,
        ((uint)*(byte *)(uVar3 + 0x457) & 1 << (*(ushort *)(uVar3 + uVar6 * 2 + 0x1e8c) & 0xff)) ==
        0)) && (((uint)*(byte *)(uVar4 + 0x15f6) & 1 << (uVar6 & 0xff)) != 0)) {
      iVar5 = uVar6 * 0x22c + uVar4 + iRam0205ec00;
      iVar2 = func_02060c68(iVar5,1);
      if ((iVar2 != -1) && (*(char *)(iVar5 + 0x214) != '\0')) {
        local_3c[uVar6] = (char)iVar2;
        local_34[(int)((longlong)iRam0205ec04 * (longlong)iVar2 >> 0x21) - (iVar2 >> 0x1f)] = '\x01'
        ;
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 8);
  uVar6 = (*(uint *)(uRam0205ec08 & 0xfffffffc) >> (uRam0205ec08 & 3) * 8 |
          *(uint *)(uRam0205ec08 & 0xfffffffc) << (uRam0205ec08 & 3) * -8 + 0x20) + 0x20;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  WriteSaveDataSection_FriendList_from_thumb(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  uVar6 = (*(uint *)(uRam0205ec0c & 0xfffffffc) >> (uRam0205ec0c & 3) * 8 |
          *(uint *)(uRam0205ec0c & 0xfffffffc) << (uRam0205ec0c & 3) * -8 + 0x20) + 0xc;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    func_02145d38();
  }
  uVar6 = 0;
  local_40 = 0;
  do {
    if (local_34[uVar6] != '\0') {
      uVar4 = *(uint *)(uRam0205ec08 & 0xfffffffc) >> (uRam0205ec08 & 3) * 8 |
              *(uint *)(uRam0205ec08 & 0xfffffffc) << (uRam0205ec08 & 3) * -8 + 0x20;
      uVar7 = uVar4 + 0x24 & 3;
      uVar3 = *(uint *)(uVar4 + 0x24 & 0xfffffffc);
      uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      iVar2 = func_0205743c(uVar6,(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x2e,2
                           );
      if (iVar2 == 0) {
        Mem_CpuFill8(uVar7,0,0xb00);
        uVar3 = *(uint *)(uRam0205ec08 & 0xfffffffc) >> (uRam0205ec08 & 3) * 8 |
                *(uint *)(uRam0205ec08 & 0xfffffffc) << (uRam0205ec08 & 3) * -8 + 0x20;
        uVar4 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        MaybeSetPersonalGhostForCoursePresent_from_thumb
                  (uVar6,(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x2e,2);
        bVar1 = true;
      }
      else {
        ReadSaveDataSection_NKFE_from_thumb(uVar7,uVar6);
        uVar4 = (*(uint *)(uRam0205ec0c & 0xfffffffc) >> (uRam0205ec0c & 3) * 8 |
                *(uint *)(uRam0205ec0c & 0xfffffffc) << (uRam0205ec0c & 3) * -8 + 0x20) + 0xc;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
          func_02145d38();
        }
      }
      uVar4 = local_40;
      do {
        iVar2 = (int)local_3c[uVar4];
        if (((int)(iVar2 + uVar6 * -5) < 0 == SBORROW4(iVar2,uVar6 * 5)) &&
           ((int)(iVar2 + (uVar6 + 1) * -5) < 0 != SBORROW4(iVar2,(uVar6 + 1) * 5))) {
          uVar3 = iVar2 - iRam0205ec10 *
                          ((int)((longlong)iRam0205ec04 * (longlong)iVar2 >> 0x21) - (iVar2 >> 0x1f)
                          ) & 0xff;
          *(byte *)(uVar7 + 4) = *(byte *)(uVar7 + 4) | (byte)(1 << uVar3);
          Mem_CpuCopy8(uVar4 * 0x22c +
                       (*(uint *)(uRam0205ebfc & 0xfffffffc) >> (uRam0205ebfc & 3) * 8 |
                       *(uint *)(uRam0205ebfc & 0xfffffffc) << (uRam0205ebfc & 3) * -8 + 0x20) +
                       iRam0205ec00 + 0x14,uVar7 + 8 + uVar3 * 0x200,0x200);
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < 8);
      WriteSaveDataSection_NKFE_from_thumb(uVar7,uVar6);
      uVar7 = (*(uint *)(uRam0205ec0c & 0xfffffffc) >> (uRam0205ec0c & 3) * 8 |
              *(uint *)(uRam0205ec0c & 0xfffffffc) << (uRam0205ec0c & 3) * -8 + 0x20) + 0xc;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if (uVar7 >> uVar4 * 8 != 0 || uVar7 << uVar4 * -8 + 0x20 != 0) {
        func_02145d38();
      }
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0xc);
  if ((bVar1) &&
     (uVar7 = *(uint *)(uRam0205ec08 & 0xfffffffc) >> (uRam0205ec08 & 3) * 8 |
              *(uint *)(uRam0205ec08 & 0xfffffffc) << (uRam0205ec08 & 3) * -8 + 0x20,
     uVar6 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
     WriteSaveDataSection_Header_from_thumb(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20),
     uVar6 = (*(uint *)(uRam0205ec0c & 0xfffffffc) >> (uRam0205ec0c & 3) * 8 |
             *(uint *)(uRam0205ec0c & 0xfffffffc) << (uRam0205ec0c & 3) * -8 + 0x20) + 0xc,
     uVar7 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0)) {
    func_02145d38();
  }
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

