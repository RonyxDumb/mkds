/* Decompiled C draft; module arm9; ROM address 02060d1c. No matching claim. */
#include "types.h"
#include "deps/02060d1c_func_02060d1c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_02060d1c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                  int param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bStack_60;
  byte bStack_5f;
  byte bStack_5e;
  byte bStack_5d;
  byte bStack_5c;
  byte bStack_5b;
  undefined1 auStack_5a [12];
  ushort uStack_4e;
  undefined1 auStack_4c [20];
  byte local_38;
  ushort local_34 [2];
  uint local_30;
  uint local_2c;
  
  uVar6 = 0xffffffff;
  bVar1 = false;
  GetCurrentDate(local_34);
  uVar5 = 0;
  iVar3 = param_1;
  do {
    GlobalZ_GetOI(uVar5 & 0xff,auStack_5a);
    if (((((int)((uint)local_38 << 0x1f) < 0) &&
         (iVar2 = FriendCode_HasNonzeroState_0_from_thumb(param_3), iVar2 != 0)) &&
        (iVar2 = FriendCode_HasNonzeroState_0_from_thumb(iVar3), iVar2 != 0)) &&
       (iVar2 = FriendCode_SameAs_from_thumb(iVar3,param_3), iVar2 != 0)) {
      bVar1 = true;
      uVar6 = uVar5;
      break;
    }
    uVar5 = (int)((uVar5 + 1) * 0x1000000) >> 0x18;
    iVar3 = iVar3 + 0xc;
  } while ((int)uVar5 < 0x3c);
  if ((param_4 != 0) && (bVar1)) {
    return 0xffffffff;
  }
  if ((param_6 == 0) && (uVar6 == 0xffffffff)) {
    return 0xffffffff;
  }
  uVar5 = uVar6;
  if (uVar6 == 0xffffffff) {
    uVar4 = 0;
    do {
      GlobalZ_GetOI(uVar4 & 0xff,auStack_5a);
      uVar5 = uVar4;
      if (-1 < (int)((uint)local_38 << 0x1f)) break;
      uVar4 = (int)((uVar4 + 1) * 0x1000000) >> 0x18;
      uVar5 = uVar6;
    } while ((int)uVar4 < 0x3c);
  }
  uVar6 = 0xffffffff;
  if (uVar5 == 0xffffffff) {
    bStack_60 = 100;
    bStack_5f = 0xc;
    bStack_5e = 0x1f;
    uVar4 = 0;
    do {
      GlobalZ_GetOI(uVar4 & 0xff,auStack_5a);
      bStack_5d = (byte)(((uint)uStack_4e << 0x19) >> 0x19);
      bStack_5c = (byte)(((uint)uStack_4e << 0x15) >> 0x1c);
      bStack_5b = (byte)(uStack_4e >> 0xb);
      if ((((int)((uint)local_38 << 0x1f) < 0) && (-1 < (int)((uint)local_38 << 0x1c))) &&
         (iVar3 = func_0203b0a0(&bStack_5d,&bStack_60), iVar3 != 0)) {
        bStack_60 = bStack_5d;
        bStack_5f = bStack_5c;
        bStack_5e = bStack_5b;
        uVar6 = uVar4;
      }
      uVar4 = (int)((uVar4 + 1) * 0x1000000) >> 0x18;
    } while ((int)uVar4 < 0x3c);
    if (uVar6 != 0xffffffff) {
      uVar5 = uVar6;
    }
  }
  if (uVar5 != 0xffffffff) {
    Mem_CpuCopy8(param_3,uVar5 * 0xc + param_1);
    GlobalZ_GetOI(uVar5 & 0xff,auStack_5a);
    if (!bVar1) {
      StructOI_Initialize_from_thumb(auStack_5a);
    }
    uStack_4e = local_34[0] & 0x7f | (ushort)((local_30 & 0xf) << 7) |
                (ushort)((local_2c & 0x1f) << 0xb);
    Mem_CpuCopy8(param_2,auStack_4c,0x14);
    GlobalZ_SetOI(uVar5 & 0xff,auStack_5a);
    return uVar5;
  }
  return 0xffffffff;
}

