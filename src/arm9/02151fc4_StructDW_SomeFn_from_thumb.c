/* Decompiled C draft; module arm9; ROM address 02151fc4. No matching claim. */
#include "types.h"
#include "deps/02151fc4_StructDW_SomeFn_from_thumb.h"

undefined4 StructDW_SomeFn_from_thumb(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  longlong lVar7;
  undefined8 uVar8;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [12];
  
  StructDW_MaybeCreate_from_thumb();
  Rtc_Initialize();
  iVar2 = Rtc_GetDate((undefined4)(uintptr_t)(auStack_30));
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = Rtc_GetTime((undefined4)(uintptr_t)(auStack_20));
  if (iVar2 == 0) {
    lVar7 = ComputeTotalSeconds_EpochMaybe_from_thumb((undefined4)(uintptr_t)(auStack_30),(undefined4)(uintptr_t)(auStack_20));
    iVar2 = (int)lVar7;
    if (-1 < lVar7) {
      iVar3 = OS_IsTickAvailable(iVar2);
      if (iVar3 != 0) {
        iVar2 = iVar2 + iRam02152108;
      }
      Os_GetMacAddress((undefined4)(uintptr_t)(&local_38));
      iVar1 = iRam02152114;
      iVar3 = iRam02152110;
      bVar6 = ((uint)local_36 | (uint)local_38 << 0x10 | (uint)local_37 << 8) != uRam0215210c;
      uVar4 = (uint)local_33 | (uint)local_35 << 0x10 | (uint)local_34 << 8;
      uVar5 = iRam02152110 * iVar2 + iRam02152114;
      *(short *)(param_1 + 4) = (short)(iRam02152118 * (uVar5 >> 0x10) >> 0x10);
      *param_1 = 0;
      param_1[1] = 0;
      if (*(short *)((int)param_1 + 0x12) == 0) {
        param_1[2] = 0;
        param_1[3] = 0;
        if (param_1[3] == 0 && param_1[2] == 0) {
          do {
            do {
              uVar5 = iVar3 * uVar5 + iVar1;
            } while (uVar5 == 0);
            *(short *)((int)param_1 + 0x12) = (short)uVar5;
            uVar8 = func_0215211c(*(undefined2 *)((int)param_1 + 0x12),uVar4,bVar6,0);
            *(undefined8 *)(param_1 + 2) = uVar8;
          } while (param_1[3] == 0 && param_1[2] == 0);
        }
      }
      else {
        param_1[2] = 0;
        param_1[3] = 0;
        if (param_1[3] == 0 && param_1[2] == 0) {
          do {
            *(short *)((int)param_1 + 0x12) = *(short *)((int)param_1 + 0x12) + 1;
            uVar8 = func_0215211c(*(undefined2 *)((int)param_1 + 0x12),uVar4,bVar6,0);
            *(undefined8 *)(param_1 + 2) = uVar8;
          } while (param_1[3] == 0 && param_1[2] == 0);
        }
      }
      return 1;
    }
    return 0;
  }
  return 0;
}

