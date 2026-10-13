/* Decompiled C draft; module arm9_ov001; ROM address 0219f430. No matching claim. */
#include "types.h"
#include "deps/0219f430_FUN_0219f430.h"

void FUN_0219f430(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_18;
  
  piVar1 = DAT_0219f4f4;
  iVar5 = 0;
  local_18 = 0;
  iVar4 = DAT_0219f4f0;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 2) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 4) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 6) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 8) * 0x40) = 0;
    iVar2 = *piVar1;
    iVar3 = *(int *)(iVar2 + local_18 + 0x28);
    if (iVar3 < 1) {
      if (*(short *)(iVar2 + 0x4c) == iVar5) {
        *(undefined4 *)(*(int *)(iVar2 + 0x10) + (uint)*(ushort *)(iVar4 + 4) * 0x40) = 1;
      }
      else {
        iVar2 = FUN_0219f688((int)(short)iVar5);
        if (iVar2 == 0) {
          if (iVar5 != 6) {
            *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 8) * 0x40) = 1;
          }
        }
        else {
          *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 2) * 0x40) = 1;
        }
      }
    }
    else {
      *(int *)(iVar2 + local_18 + 0x28) = iVar3 + -1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 6) * 0x40) = 1;
      *(short *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 6) * 0x40 + 6) =
           *(short *)(*(int *)(*piVar1 + 0x10) + (uint)*(ushort *)(iVar4 + 4) * 0x40 + 6) + 1;
    }
    iVar4 = iVar4 + 0x16;
    local_18 = local_18 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  return;
}

