/* Decompiled C draft; module arm9; ROM address 0203b6ac. No matching claim. */
#include "types.h"
#include "deps/0203b6ac_func_0203b6ac.h"

void func_0203b6ac(undefined4 param_1)

{
  undefined2 uVar1;
  ulonglong uVar2;
  int *piVar3;
  int iVar4;
  int extraout_r1;
  int extraout_r1_00;
  uint uVar5;
  ushort uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined4 local_5c;
  ushort local_58 [2];
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined2 local_28 [10];
  
  iVar4 = Rtc_GetTime(&local_34);
  if (iVar4 != 0) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
  }
  MKDS_SLICE_4(local_4c,0) = Os_GetTick();
  piVar3 = piRam0203b8ac;
  uVar9 = uRam0203b8a4;
  uVar7 = uRam0203b8a0;
  MKDS_SLICE_4(local_4c,0) = local_2c + (local_30 + local_34 * 0x3c) * 0x3c + (int)local_4c;
  MKDS_SLICE_4(local_4c,4) = 0;
  local_44 = uRam0203b8a0;
  local_40 = uRam0203b8a4;
  local_3c = uRam0203b8a8;
  local_38 = 0;
  *(undefined4 *)(*piRam0203b8ac + iRam0203b8b0) = 0;
  *(undefined4 *)(*piVar3 + iRam0203b8b4) = 1;
  *(undefined4 *)(*piVar3 + iRam0203b8b8) = 2;
  *(undefined1 *)(*piVar3 + iRam0203b8bc) = 0;
  *(undefined4 *)(*piVar3 + iRam0203b8c0) = 0;
  *(undefined4 *)(*piVar3 + iRam0203b8c4) = 0;
  *(undefined1 *)(*piVar3 + iRam0203b8c8) = 0;
  *(undefined1 *)(*piVar3 + iRam0203b8cc) = 0xff;
  *(undefined4 *)(*piVar3 + iRam0203b8d0) = 2;
  local_4c = Multiply64(uVar7,uVar9,(int)local_4c,0);
  local_4c = local_4c + CONCAT44(local_38,local_3c);
  uVar2 = (ulonglong)local_4c >> 0x3e;
  iVar4 = func_0203b8e4(&local_4c);
  *(undefined4 *)(*piRam0203b8ac + iRam0203b8d8) =
       *(undefined4 *)
        ((((uint)uVar2 << 0x10) >> 0xe) + iRam0203b8d4 + ((uint)(iVar4 << 0x10) >> 0xc));
  lVar11 = Multiply64(local_44,local_40,(int)local_4c,MKDS_SLICE_4(local_4c,4));
  lVar11 = lVar11 + CONCAT44(local_38,local_3c);
  uVar5 = 0;
  *(byte *)(*piRam0203b8ac + iRam0203b8dc) = (byte)((ulonglong)lVar11 >> 0x3d);
  do {
    uVar8 = 0;
    do {
      if (uVar8 != (uint)((ulonglong)lVar11 >> 0x3d)) {
        local_58[uVar5] = (ushort)uVar8;
        break;
      }
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 8);
    uVar5 = uVar5 + 1 & 0xffff;
    if (1 < uVar5) {
      uVar5 = 0;
      do {
        local_28[uVar5] = (short)uVar5;
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < 8);
      uVar5 = 0;
      do {
        MKDS_SLICE_4(local_4c,4) = (undefined4)((ulonglong)lVar11 >> 0x20);
        MKDS_SLICE_4(local_4c,0) = (int)lVar11;
        lVar12 = Multiply64(local_44,local_40,(int)local_4c,MKDS_SLICE_4(local_4c,4));
        local_4c = lVar11;
        local_4c = lVar12 + CONCAT44(local_38,local_3c);
        uVar9 = (undefined4)local_4c;
        uVar7 = (undefined4)((ulonglong)local_4c >> 0x20);
        Multiply64(uVar7,0,7,0);
        lVar11 = Multiply64(local_44,local_40,uVar9,uVar7);
        local_4c = lVar11 + CONCAT44(local_38,local_3c);
        uVar10 = (uint)(extraout_r1 << 0x10) >> 0xf;
        uVar1 = *(undefined2 *)((int)local_28 + uVar10);
        Multiply64((int)((ulonglong)local_4c >> 0x20),0,7,0);
        uVar8 = (uint)(extraout_r1_00 << 0x10) >> 0xf;
        *(undefined2 *)((int)local_28 + uVar10) = *(undefined2 *)((int)local_28 + uVar8);
        *(undefined2 *)((int)local_28 + uVar8) = uVar1;
        uVar5 = uVar5 + 1 & 0xffff;
        lVar11 = local_4c;
      } while (uVar5 < uRam0203b8e0);
      func_0203be6c(param_1,0,0,0);
      func_0203ba70(param_1);
      uVar6 = 0;
      local_5c = 0;
      do {
        uVar7 = 3;
        if (local_58[0] == uVar6) {
          uVar7 = local_5c;
        }
        if (local_58[1] == uVar6) {
          uVar7 = 1;
        }
        func_0203be48(param_1,uVar6 & 0xff,&local_54,&local_50);
        StructCO_ConfigureRacerDefault(uVar6,local_54,local_50,1,0xffffffff,uVar7);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 8);
      func_020467a0();
      return;
    }
  } while( true );
}

