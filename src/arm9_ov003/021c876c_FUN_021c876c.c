/* Decompiled C draft; module arm9_ov003; ROM address 021c876c. No matching claim. */
#include "types.h"
#include "deps/021c876c_FUN_021c876c.h"

void FUN_021c876c(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  ushort local_3c [20];
  
  func_0x0214d168((uint *)(void *)(local_3c),0,0x22);
  iVar2 = FUN_021d3254(param_1,0x20);
  iVar5 = iVar2;
  if (0x10 < iVar2) {
    iVar5 = 0x10;
  }
  iVar4 = 0;
  if (0 < iVar5) {
    puVar3 = local_3c;
    do {
      if (*(byte *)(param_1 + iVar4) == 0x20) {
        *puVar3 = (ushort)DAT_021c8830;
      }
      else {
        *puVar3 = (ushort)*(byte *)(param_1 + iVar4);
      }
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  iVar5 = param_2 * 0x1d + 2;
  if (iVar2 < 0x11) {
    iVar5 = param_2 * 0x1d + 7;
  }
  FUN_021d2094(*(undefined4 *)(*DAT_021c8834 + 0x14),0x48,iVar5,2,8,local_3c,1);
  if (0x10 < iVar2) {
    func_0x0214d168((uint *)(void *)(local_3c),0,0x22);
    iVar4 = 0;
    if (0 < iVar2 + -0x10) {
      puVar3 = local_3c;
      do {
        bVar1 = *(byte *)(param_1 + iVar4 + 0x10);
        if (bVar1 == 0x20) {
          *puVar3 = (ushort)DAT_021c8830;
        }
        else {
          *puVar3 = (ushort)bVar1;
        }
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2 + -0x10);
    }
    FUN_021d2094(*(undefined4 *)(*DAT_021c8834 + 0x14),0x48,iVar5 + 0xc,2,8,local_3c,1);
  }
  return;
}

