/* Decompiled C draft; module arm9_ov000; ROM address 021af1e4. No matching claim. */
#include "types.h"
#include "deps/021af1e4_FUN_021af1e4.h"

void FUN_021af1e4(int param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_021b0188(param_2,param_3);
  if ((iVar1 == DAT_021af27c) &&
     (iVar1 = FUN_021af284(((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                           (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
                           (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                           (*(ushort *)(param_1 + 0xe) & 0xff) << 8,
                           ((int)(uint)*(ushort *)(param_1 + 0x10) >> 8 |
                           (*(ushort *)(param_1 + 0x10) & 0xff) << 8) << 0x10 |
                           (int)(uint)*(ushort *)(param_1 + 0x12) >> 8 |
                           (*(ushort *)(param_1 + 0x12) & 0xff) << 8), iVar1 != 0)) {
    if (*param_2 == '\0') {
      FUN_021af2a0(param_1,param_2,param_3);
      return;
    }
    if (*param_2 != '\b') {
      return;
    }
    if (*DAT_021af280 != 0) {
      FUN_021af348(param_1,param_2,param_3);
    }
  }
  return;
}

