/* Decompiled C draft; module arm9_ov003; ROM address 021c5b90. No matching claim. */
#include "types.h"
#include "deps/021c5b90_FUN_021c5b90.h"

void FUN_021c5b90(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  ushort local_3c [20];
  
  iVar6 = param_1 * 0x2a;
  iVar1 = FUN_021d3254(*(int *)*DAT_021c5c64 + iVar6,0x20);
  param_2 = param_2 * 0x1c;
  if (param_1 < (int)(uint)*(byte *)(*DAT_021c5c64 + 0x51)) {
    if (iVar1 < 0x11) {
      param_2 = param_2 + 6;
    }
    func_0x0214d168(local_3c,0,0x22);
    iVar3 = iVar1;
    if (0x10 < iVar1) {
      iVar3 = 0x10;
    }
    iVar5 = 0;
    if (0 < iVar3) {
      puVar4 = local_3c;
      piVar2 = (int *)*DAT_021c5c64;
      do {
        *puVar4 = (ushort)*(byte *)(iVar5 + iVar6 + *piVar2);
        puVar4 = puVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    FUN_021d2094(*(undefined4 *)(*DAT_021c5c64 + 0xc),10,param_2,2,10,local_3c,1);
    if (0x10 < iVar1) {
      func_0x0214d168(local_3c,0,0x22);
      iVar3 = 0;
      if (0 < iVar1 + -0x10) {
        puVar4 = local_3c;
        piVar2 = (int *)*DAT_021c5c64;
        do {
          *puVar4 = (ushort)*(byte *)(iVar3 + 0x10 + iVar6 + *piVar2);
          puVar4 = puVar4 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1 + -0x10);
      }
      FUN_021d2094(*(undefined4 *)(*DAT_021c5c64 + 0xc),10,param_2 + 0xc,2,10,local_3c,1);
    }
  }
  return;
}

