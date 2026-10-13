/* Decompiled C draft; module arm9_ov001; ROM address 02182a3c. No matching claim. */
#include "types.h"
#include "deps/02182a3c_FUN_02182a3c.h"

/* WARNING: Removing unreachable block (ram,0x02182aea) */

void FUN_02182a3c(int param_1)

{
  int *piVar1;
  longlong *plVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  int local_34;
  int local_30;
  
  local_30 = 0;
  piVar1 = (int *)func_0x02100138(0x68);
  func_0x0207a974((short)*(char *)(*DAT_02182ba4 + 0x62));
  if (piVar1 != (int *)0x0) {
    local_34 = 0;
    for (iVar7 = 0;
        (local_34 < (int)(uint)*(ushort *)(piVar1 + 1) &&
        (iVar8 = *(int *)(*piVar1 + iVar7), iVar8 != 0)); iVar7 = iVar7 + 4) {
      if (*(int *)(iVar8 + 0xf8) == 7) {
        local_30 = local_30 + 1;
        if (param_1 < local_30) {
          if (*(int *)(iVar8 + 0xe8) != 0) {
            *(undefined4 *)(iVar8 + 0xe8) = 0;
          }
        }
        else if (*(int *)(iVar8 + 0xe8) == 0) {
          plVar2 = (longlong *)func_0x020d22d0();
          lVar9 = func_0x02133048((int)plVar2[1],*(undefined4 *)((int)plVar2 + 0xc),(int)*plVar2,
                                  *(undefined4 *)((int)plVar2 + 4));
          *plVar2 = lVar9 + plVar2[2];
          uVar3 = *(uint *)((int)plVar2 + 4);
          *(undefined4 *)(iVar8 + 0xb0) = DAT_02182ba8;
          *(undefined2 *)(iVar8 + 0xa0) = 0;
          if (*(int *)(*DAT_02182ba4 + 8) == 4) {
            uVar4 = FUN_02181b54();
            iVar5 = FUN_02181b68(uVar4);
          }
          else {
            iVar5 = 0;
          }
          *(int *)(iVar8 + 0xe8) = iVar5 + 4;
          *(undefined4 *)(iVar8 + 4) = **(undefined4 **)(iVar8 + 0xe8);
          *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(*(int *)(iVar8 + 0xe8) + 4);
          *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(*(int *)(iVar8 + 0xe8) + 8);
          *(undefined4 *)(iVar8 + 0x10) = 0;
          *(undefined4 *)(iVar8 + 0x14) = DAT_02182bac;
          *(undefined4 *)(iVar8 + 0x18) = 0;
          iVar5 = (int)(uVar3 >> 0x10) >> 4;
          iVar6 = (int)*(short *)(DAT_02182bb0 + iVar5 * 4);
          uVar10 = func_0x02133048(iVar6,iVar6 >> 0x1f,DAT_02182bb4,0);
          *(uint *)(iVar8 + 0xec) = (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
          *(undefined4 *)(iVar8 + 0xf0) = DAT_02182bb8;
          iVar5 = (int)*(short *)(DAT_02182bb0 + (iVar5 * 2 + 1) * 2);
          uVar10 = func_0x02133048(iVar5,iVar5 >> 0x1f,DAT_02182bb4,0);
          *(uint *)(iVar8 + 0xf4) = (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
        }
      }
      local_34 = local_34 + 1;
    }
  }
  return;
}

