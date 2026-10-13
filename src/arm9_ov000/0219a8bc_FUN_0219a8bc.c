/* Decompiled C draft; module arm9_ov000; ROM address 0219a8bc. No matching claim. */
#include "types.h"
#include "deps/0219a8bc_FUN_0219a8bc.h"

void FUN_0219a8bc(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*(char *)(param_2 + 7) == '\x01') {
    if ((((*(byte *)(param_2 + 0xc) < 3) &&
         (param_1[*(byte *)(param_2 + 0xc) + 5] = 1, param_1[4] == 0)) && (param_1[6] != 0)) &&
       ((param_1[7] != 0 && ((param_1[1] == -1 || (param_1[5] != 0)))))) {
      param_1[4] = 1;
      iVar1 = FUN_0218e8c4();
      param_1[10] = iVar1 + DAT_0219a950;
      (*(code *)param_1[0xd])(param_1[4],param_1[0xf]);
      return;
    }
  }
  else {
    if (*(char *)(param_2 + 7) != '\x02') {
      return;
    }
    *(undefined1 *)(param_2 + 7) = 3;
    FUN_0219b0b0(*param_1,*(undefined4 *)(param_3 + 4),
                 (int)(uint)*(ushort *)(param_3 + 2) >> 8 |
                 (uint)*(ushort *)(param_3 + 2) << 8 & DAT_0219a954 & 0xffff,param_2,0x15);
  }
  return;
}

