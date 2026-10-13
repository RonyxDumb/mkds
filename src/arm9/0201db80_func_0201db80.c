/* Decompiled C draft; module arm9; ROM address 0201db80. No matching claim. */
#include "types.h"
#include "deps/0201db80_func_0201db80.h"

void func_0201db80(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (0xff - param_3) * 0x1f;
  *(ushort *)(param_1 + 0x2e) =
       *(ushort *)(param_1 + 0x2e) & 0xfc1f |
       (ushort)(((iVar1 + (int)((ulonglong)((longlong)iRam0201dbd4 * (longlong)iVar1) >> 0x20) >> 7)
                 - (iVar1 >> 0x1f) & 0x1fU) << 5);
  return;
}

