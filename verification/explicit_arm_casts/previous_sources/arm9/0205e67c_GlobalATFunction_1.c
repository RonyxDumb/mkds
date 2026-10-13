/* Decompiled C draft; module arm9; ROM address 0205e67c. No matching claim. */
#include "types.h"
#include "deps/0205e67c_GlobalATFunction_1.h"

void GlobalATFunction_1(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_4c;
  uint local_3c;
  char local_38 [4];
  char local_34 [16];
  
  uVar3 = 0;
  uVar5 = 0;
  do {
    local_34[uVar3] = '\0';
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xc);
  do {
    local_38[uVar5] = -1;
    uVar3 = func_0x0219bb50();
    if ((((uVar5 != uVar3) && (iVar1 = GetTKByIndex(uVar5 & 0xff), iVar1 != 0)) &&
        (iVar2 = func_02060c68(iVar1,0), iVar2 != -1)) && (*(char *)(iVar1 + 0x214) != '\0')) {
      local_38[uVar5] = (char)iVar2;
      local_34[(int)((longlong)iRam0205e8f0 * (longlong)iVar2 >> 0x21) - (iVar2 >> 0x1f)] = '\x01';
    }
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 4);
  uVar5 = (*(uint *)(uRam0205e8f4 & 0xfffffffc) >> (uRam0205e8f4 & 3) * 8 |
          *(uint *)(uRam0205e8f4 & 0xfffffffc) << (uRam0205e8f4 & 3) * -8 + 0x20) + 0x20;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  WriteSaveDataSection_FriendList_from_thumb(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar5 = (*(uint *)(uRam0205e8f8 & 0xfffffffc) >> (uRam0205e8f8 & 3) * 8 |
          *(uint *)(uRam0205e8f8 & 0xfffffffc) << (uRam0205e8f8 & 3) * -8 + 0x20) + 0xc;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
    func_02145d38();
  }
  local_4c = 0;
  local_3c = 0;
  do {
    if (local_34[local_4c] != '\0') {
      uVar4 = *(uint *)(uRam0205e8f4 & 0xfffffffc) >> (uRam0205e8f4 & 3) * 8 |
              *(uint *)(uRam0205e8f4 & 0xfffffffc) << (uRam0205e8f4 & 3) * -8 + 0x20;
      uVar5 = uVar4 + 0x24 & 3;
      uVar3 = *(uint *)(uVar4 + 0x24 & 0xfffffffc);
      uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      iVar1 = func_0205743c(local_4c,(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) +
                                     0x2e,2);
      if (iVar1 == 0) {
        Mem_CpuFill8(uVar5,0,0xb00);
        uVar4 = *(uint *)(uRam0205e8f4 & 0xfffffffc) >> (uRam0205e8f4 & 3) * 8 |
                *(uint *)(uRam0205e8f4 & 0xfffffffc) << (uRam0205e8f4 & 3) * -8 + 0x20;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        MaybeSetPersonalGhostForCoursePresent_from_thumb
                  (local_4c,(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x2e,2);
      }
      else {
        ReadSaveDataSection_NKFE_from_thumb(uVar5,local_4c);
        uVar3 = (*(uint *)(uRam0205e8f8 & 0xfffffffc) >> (uRam0205e8f8 & 3) * 8 |
                *(uint *)(uRam0205e8f8 & 0xfffffffc) << (uRam0205e8f8 & 3) * -8 + 0x20) + 0xc;
        uVar4 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
          func_02145d38();
        }
      }
      uVar3 = local_3c;
      do {
        iVar1 = (int)local_38[uVar3];
        if (((int)(iVar1 + local_4c * -5) < 0 == SBORROW4(iVar1,local_4c * 5)) &&
           ((int)(iVar1 + (local_4c + 1) * -5) < 0 != SBORROW4(iVar1,(local_4c + 1) * 5))) {
          uVar4 = iVar1 - iRam0205e8fc *
                          ((int)((longlong)iRam0205e8f0 * (longlong)iVar1 >> 0x21) - (iVar1 >> 0x1f)
                          ) & 0xff;
          *(byte *)(uVar5 + 4) = *(byte *)(uVar5 + 4) | (byte)(1 << uVar4);
          iVar1 = GetTKByIndex(uVar3 & 0xff);
          Mem_CpuCopy8(iVar1 + 0x14,uVar5 + 8 + uVar4 * 0x200,0x200);
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 4);
      WriteSaveDataSection_NKFE_from_thumb(uVar5,local_4c);
      uVar5 = (*(uint *)(uRam0205e8f8 & 0xfffffffc) >> (uRam0205e8f8 & 3) * 8 |
              *(uint *)(uRam0205e8f8 & 0xfffffffc) << (uRam0205e8f8 & 3) * -8 + 0x20) + 0xc;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
        func_02145d38();
      }
    }
    local_4c = local_4c + 1 & 0xff;
  } while (local_4c < 0xc);
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

