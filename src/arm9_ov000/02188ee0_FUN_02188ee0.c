/* Decompiled C draft; module arm9_ov000; ROM address 02188ee0. No matching claim. */
#include "types.h"
#include "deps/02188ee0_FUN_02188ee0.h"

uint FUN_02188ee0(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint local_24;
  int local_20;
  int local_1c;
  
  iVar5 = DAT_0218901c;
  iVar1 = param_1 + DAT_02189010 + (uint)*(byte *)(param_1 + DAT_02189014) * 0xc0;
  local_24 = 0;
  if (((uint)*(byte *)(param_1 + DAT_02189018) << 0x18) >> 0x1e == 0) {
    iVar5 = 0;
    if (*(short *)(iVar1 + 10) == 0x20) {
      local_24 = FUN_02188c1c(iVar1);
      if ((int)local_24 < 1) {
        local_24 = 0;
      }
      else {
        iVar5 = 1;
      }
    }
    else if (*(short *)(iVar1 + 10) == 8) {
      local_24 = FUN_02189714(iVar1);
      if (local_24 == 0) {
        local_24 = 0;
      }
      else {
        iVar5 = 1;
      }
    }
    local_20 = 0;
    if (*(char *)(param_1 + DAT_0218901c) != '\0') {
      local_1c = param_1 + DAT_02189020;
      pbVar3 = (byte *)(param_1 + DAT_02189024);
      iVar4 = param_1;
      do {
        if ((*(ushort *)(iVar1 + 10) == (ushort)*(byte *)(iVar4 + DAT_02189028)) &&
           (iVar2 = func_0x0213a038(iVar1 + 0xc,local_1c), iVar2 == 0)) {
          if (iVar5 == 0) {
            local_24 = (uint)*(byte *)(iVar4 + DAT_0218902c);
          }
          else {
            *pbVar3 = *pbVar3 & 0xf | 0x10;
            *(byte *)(param_1 + DAT_02189018) = *(byte *)(param_1 + DAT_02189018) & 0x3f | 0x40;
          }
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 0x24;
        local_1c = local_1c + 0x24;
        pbVar3 = pbVar3 + 0x24;
        local_20 = local_20 + 1;
      } while (local_20 < (int)(uint)*(byte *)(param_1 + DAT_0218901c));
    }
  }
  else {
    iVar4 = 0;
    iVar1 = iVar4;
    if (*(char *)(param_1 + DAT_0218901c) != '\0') {
      pbVar3 = (byte *)(param_1 + DAT_02189024);
      iVar2 = param_1;
      do {
        if (((uint)*pbVar3 << 0x18) >> 0x1c == 1) {
          if (iVar1 == 0) {
            *pbVar3 = *pbVar3 & 0xf;
            local_24 = (uint)*(byte *)(iVar2 + DAT_0218902c);
          }
          iVar1 = iVar1 + 1;
        }
        pbVar3 = pbVar3 + 0x24;
        iVar2 = iVar2 + 0x24;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + iVar5));
    }
    if (iVar1 == 1) {
      *(byte *)(param_1 + DAT_02189018) = *(byte *)(param_1 + DAT_02189018) & 0x3f;
    }
  }
  return local_24 & 0xff;
}

