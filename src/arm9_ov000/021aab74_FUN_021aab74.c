/* Decompiled C draft; module arm9_ov000; ROM address 021aab74. No matching claim. */
#include "types.h"
#include "deps/021aab74_FUN_021aab74.h"

void FUN_021aab74(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  func_0x0214d1fc((ushort *)(uintptr_t)(param_2 + 2),param_1 + 10,0x20);
  iVar2 = param_2 + 0x23;
  uVar3 = (uint)*(byte *)(param_2 + 0x22);
  iVar4 = *param_1;
  if (((iVar4 == 0) || (uVar3 != 0x20)) || (iVar1 = func_0x02134d30(iVar4,iVar2,0x20), iVar1 != 0))
  {
    if (iVar4 != 0) {
      *(undefined1 *)(iVar4 + 0x5a) = 0;
    }
    if (uVar3 == 0) {
      *param_1 = DAT_021aabe8;
    }
    else {
      iVar4 = FUN_021ab5e4(iVar2);
      *param_1 = iVar4;
    }
    *(undefined1 *)(param_1 + 1) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 1;
  }
  *(ushort *)((int)param_1 + 6) =
       (ushort)*(byte *)(iVar2 + uVar3) * 0x100 + (ushort)*(byte *)(iVar2 + uVar3 + 1);
  *(undefined1 *)((int)param_1 + DAT_021aabec) = 2;
  return;
}

