/* Decompiled C draft; module arm9_ov001; ROM address 0218516c. No matching claim. */
#include "types.h"
#include "deps/0218516c_FUN_0218516c.h"

void FUN_0218516c(ushort *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_50;
  int local_48;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  
  local_50 = 0;
  if (*param_1 != 0) {
    local_48 = 0;
    do {
      iVar6 = *(int *)(param_1 + 2) + local_48;
      if ((*(code **)(iVar6 + 0x84) != (code *)0x0) &&
         (iVar2 = (**(code **)(iVar6 + 0x84))(iVar6), iVar2 != 0)) {
        *(undefined4 *)(iVar6 + 0x84) = 0;
      }
      if ((*(int *)(iVar6 + 0xc) != 0) && (0 < *(int *)(iVar6 + 0x18))) {
        iVar2 = (*(int *)(iVar6 + 4) >> 0xc) + *(int *)(param_1 + 8);
        iVar7 = (*(int *)(iVar6 + 8) >> 0xc) + *(int *)(param_1 + 10);
        if ((-0x41 < iVar2) && (((iVar2 <= DAT_021852ec && (-0x31 < iVar7)) && (iVar7 < 0xf1)))) {
          if (*(int *)(iVar6 + 0x18) == DAT_021852f0) {
            local_2c = iVar2 * 0x1000;
            local_28 = iVar7 * 0x1000;
            sVar1 = func_0x020224e0(param_2 + (uint)*(ushort *)(param_2 + DAT_021852f4) * 8,
                                    0x80 - *(ushort *)(param_2 + DAT_021852f4) & 0xffff,
                                    (ushort *)(uintptr_t)(*(undefined4 *)(iVar6 + 0x58)),0,(uint)(uintptr_t)(&local_2c),0,0);
            *(short *)(param_2 + DAT_021852f4) = *(short *)(param_2 + DAT_021852f4) + sVar1;
          }
          else {
            iVar3 = func_0x020ae5c4(param_2);
            local_24 = 0;
            local_20 = 0;
            local_1c = 0;
            local_18 = 0;
            local_24 = func_0x02147f34(DAT_021852f0,*(undefined4 *)(iVar6 + 0x18));
            iVar4 = func_0x02147f34(DAT_021852f0,*(undefined4 *)(iVar6 + 0x18));
            iVar5 = param_2 + iVar3 * 0x20;
            *(short *)(iVar5 + 6) = (short)(local_24 >> 4);
            *(short *)(iVar5 + 0xe) = (short)(local_20 >> 4);
            *(short *)(iVar5 + 0x16) = (short)(local_1c >> 4);
            *(short *)(iVar5 + 0x1e) = (short)(iVar4 >> 4);
            local_24 = *(int *)(iVar6 + 0x18);
            local_18 = *(undefined4 *)(iVar6 + 0x18);
            local_34 = iVar2 * 0x1000;
            local_30 = iVar7 * 0x1000;
            sVar1 = func_0x020224e0(param_2 + (uint)*(ushort *)(param_2 + DAT_021852f4) * 8,
                                    0x80 - *(ushort *)(param_2 + DAT_021852f4) & 0xffff,
                                    (ushort *)(uintptr_t)(*(undefined4 *)(iVar6 + 0x58)),(uint)(uintptr_t)(&local_24),(uint)(uintptr_t)(&local_34),iVar3,1);
            *(short *)(param_2 + DAT_021852f4) = *(short *)(param_2 + DAT_021852f4) + sVar1;
          }
        }
      }
      if (*(int *)(iVar6 + 0x34) != 0) {
        func_0x02022890(iVar6 + 0x2c,DAT_021852f0);
        func_0x020228c0(iVar6 + 0x2c,DAT_021852f0);
      }
      local_48 = local_48 + 0x88;
      local_50 = local_50 + 1;
    } while (local_50 < (int)(uint)*param_1);
  }
  return;
}

