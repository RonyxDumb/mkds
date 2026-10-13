/* Decompiled C draft; module arm9; ROM address 02151e20. No matching claim. */
#include "types.h"
#include "deps/02151e20_func_02151e20.h"

undefined4 func_02151e20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  longlong lVar9;
  undefined8 uVar10;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [12];
  
  local_38 = 0;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0;
  StructDW_MaybeCreate_from_thumb();
  Rtc_Initialize();
  iVar2 = Rtc_GetDate(auStack_30);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = Rtc_GetTime(auStack_20);
  if (iVar2 != 0) {
    return 0;
  }
  lVar9 = ComputeTotalSeconds_EpochMaybe_from_thumb(auStack_30,auStack_20);
  iVar2 = (int)lVar9;
  if (lVar9 < 0) {
    return 0;
  }
  iVar3 = OS_IsTickAvailable(iVar2);
  if (iVar3 != 0) {
    iVar2 = iVar2 + iRam02151f34;
  }
  Os_GetMacAddress(&local_38);
  iVar1 = iRam02151f40;
  iVar3 = iRam02151f3c;
  bVar8 = ((uint)local_36 | (uint)local_38 << 0x10 | (uint)local_37 << 8) != uRam02151f38;
  uVar4 = (uint)local_33;
  uVar5 = (uint)local_35;
  uVar6 = (uint)local_34;
  uVar7 = iRam02151f3c * iVar2 + iRam02151f40;
  *(short *)(param_1 + 0x10) = (short)(iRam02151f44 * (uVar7 >> 0x10) >> 0x10);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(int *)(param_1 + 0xc) == 0 && *(int *)(param_1 + 8) == 0) {
    do {
      do {
        do {
          uVar7 = iVar3 * uVar7 + iVar1;
        } while (uVar7 == 0);
      } while ((uint)*(ushort *)(param_1 + 0x12) == (uVar7 & 0xffff));
      *(short *)(param_1 + 0x12) = (short)uVar7;
      uVar10 = func_0215211c(*(undefined2 *)(param_1 + 0x12),uVar4 | uVar5 << 0x10 | uVar6 << 8,
                             bVar8,0);
      *(undefined8 *)(param_1 + 8) = uVar10;
    } while (*(int *)(param_1 + 0xc) == 0 && *(int *)(param_1 + 8) == 0);
  }
  return 1;
}

