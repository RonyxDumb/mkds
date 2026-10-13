/* Decompiled C draft; module arm9_ov000; ROM address 021aee38. No matching claim. */
#include "types.h"
#include "deps/021aee38_FUN_021aee38.h"

void FUN_021aee38(int param_1,ushort *param_2,int param_3)

{
  undefined8 uVar1;
  
  *(undefined1 *)(param_3 + 8) = 3;
  uVar1 = func_0x0200f5ac();
  *(uint *)(param_3 + 0x10) = (uint)uVar1 >> 0x10 | (int)((ulonglong)uVar1 >> 0x20) << 0x10;
  *(uint *)(param_3 + 0x14) =
       ((int)(uint)*(ushort *)(param_1 + 0x10) >> 8 | (*(ushort *)(param_1 + 0x10) & 0xff) << 8) <<
       0x10 | (int)(uint)*(ushort *)(param_1 + 0x12) >> 8 |
              (*(ushort *)(param_1 + 0x12) & 0xff) << 8;
  *(ushort *)(param_3 + 0x18) = *param_2 >> 8 | *param_2 << 8;
  *(uint *)(param_3 + 0x1c) =
       ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 | (*(ushort *)(param_1 + 0xc) & 0xff) << 8) <<
       0x10 | (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 | (*(ushort *)(param_1 + 0xe) & 0xff) << 8;
  *(uint *)(param_3 + 0x24) =
       (((int)(uint)param_2[2] >> 8 | (param_2[2] & 0xff) << 8) << 0x10 |
       (int)(uint)param_2[3] >> 8 | (param_2[3] & 0xff) << 8) + 1;
  FUN_021af030((int)(uintptr_t)(param_2),param_3);
  FUN_021aefc0(param_3,0x12,(ushort)*(byte *)(param_1 + 5) * 0x100 + 1);
  return;
}

