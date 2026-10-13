/* Decompiled C draft; module arm9_ov000; ROM address 021aeed8. No matching claim. */
#include "types.h"
#include "deps/021aeed8_FUN_021aeed8.h"

void FUN_021aeed8(int param_1,ushort *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = DAT_021aefa4;
  func_0x0214d168((uint *)(uintptr_t)(DAT_021aefa4),0,100);
  *(ushort *)(iVar1 + 10) = param_2[1] >> 8 | param_2[1] << 8;
  *(ushort *)(iVar1 + 0x18) = *param_2 >> 8 | *param_2 << 8;
  *(uint *)(iVar1 + 0x1c) =
       ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 | (*(ushort *)(param_1 + 0xc) & 0xff) << 8) <<
       0x10 | (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 | (*(ushort *)(param_1 + 0xe) & 0xff) << 8;
  if ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0) {
    *(uint *)(iVar1 + 0x28) =
         ((int)(uint)param_2[4] >> 8 | (param_2[4] & 0xff) << 8) << 0x10 |
         (int)(uint)param_2[5] >> 8 | (param_2[5] & 0xff) << 8;
    FUN_021aefc0(iVar1,4,param_4);
    return;
  }
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(uint *)(iVar1 + 0x24) =
       param_3 + (((int)(uint)param_2[2] >> 8 | (param_2[2] & 0xff) << 8) << 0x10 |
                 (int)(uint)param_2[3] >> 8 | (param_2[3] & 0xff) << 8);
  if ((*(byte *)((int)param_2 + 0xd) & 3) != 0) {
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
  }
  FUN_021aefc0(iVar1,0x14,param_4);
  return;
}

