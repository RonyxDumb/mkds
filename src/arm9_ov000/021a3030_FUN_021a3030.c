/* Decompiled C draft; module arm9_ov000; ROM address 021a3030. No matching claim. */
#include "types.h"
#include "deps/021a3030_FUN_021a3030.h"

void FUN_021a3030(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  longlong lVar7;
  int local_24;
  int local_18;
  
  if (*DAT_021a3138 != 0) {
    iVar2 = FUN_0219bb04(&local_18);
    local_24 = 0;
    if (0 < iVar2) {
      do {
        uVar6 = (uint)*(byte *)(local_18 + local_24);
        uVar3 = FUN_0219bb50();
        if ((uVar6 == uVar3) || (iVar4 = FUN_021a2fc8(uVar6), iVar4 != 1)) {
LAB_021a30ca:
          iVar4 = FUN_0219bac8(uVar6);
          if (((iVar4 != 0) &&
              (iVar4 = FUN_021a2fdc(uVar6), *(int *)(*DAT_021a3138 + DAT_021a3144) != 0)) &&
             (*(int *)(iVar4 + 0x2c) != 0)) {
            lVar7 = func_0x0200f5ac();
            lVar1 = lVar7 - *(longlong *)(iVar4 + 0x24);
            uVar3 = (uint)lVar1;
            uVar3 = func_0x02132e40(uVar3 * 0x40,
                                    (int)((ulonglong)lVar1 >> 0x20) * 0x40 | uVar3 >> 0x1a,
                                    DAT_021a3148,0);
            if (*(uint *)(iVar4 + 0x2c) < uVar3) {
              (**(code **)(*DAT_021a3138 + DAT_021a3144))(uVar6);
              *(longlong *)(iVar4 + 0x24) = lVar7;
            }
          }
        }
        else {
          piVar5 = (int *)FUN_021a2fdc(uVar6);
          uVar3 = (uint)*(ushort *)(*DAT_021a3138 + DAT_021a313c);
          if (piVar5[5] - piVar5[3] <= (int)(uint)*(ushort *)(*DAT_021a3138 + DAT_021a313c)) {
            uVar3 = piVar5[5] - piVar5[3];
          }
          iVar4 = FUN_021a2d18(uVar6);
          if ((int)uVar3 <= iVar4) {
            FUN_021a2f98(uVar6,*piVar5 + piVar5[3],uVar3,1);
            piVar5[3] = piVar5[3] + uVar3;
            if (piVar5[3] == piVar5[5]) {
              if (*(code **)(*DAT_021a3138 + DAT_021a3140) != (code *)0x0) {
                (**(code **)(*DAT_021a3138 + DAT_021a3140))(piVar5[5],uVar6);
              }
              *(undefined1 *)(piVar5 + 7) = 0;
              *piVar5 = 0;
              piVar5[3] = 0;
              piVar5[5] = 0;
            }
            goto LAB_021a30ca;
          }
        }
        local_24 = local_24 + 1;
      } while (local_24 < iVar2);
    }
  }
  return;
}

