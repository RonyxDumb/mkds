/* Decompiled C draft; module arm9_ov000; ROM address 021afc5c. No matching claim. */
#include "types.h"
#include "deps/021afc5c_FUN_021afc5c.h"

void FUN_021afc5c(uint param_1)

{
  uint uVar1;
  undefined1 auStack_38 [6];
  undefined1 auStack_32 [6];
  undefined2 local_2c;
  undefined1 local_29;
  undefined1 local_28;
  undefined2 local_26;
  undefined1 local_23;
  undefined1 auStack_22 [6];
  ushort local_1c;
  ushort local_1a;
  ushort local_12;
  ushort local_10;
  
  func_0x0214d168((uint *)(void *)(auStack_38),0,0x2a);
  func_0x0214d168((uint *)(void *)(auStack_38),0xff,6);
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021afcf0),(uint *)(void *)(auStack_32),6);
  local_2c = (undefined2)DAT_021afcf4;
  local_29 = 1;
  local_28 = 8;
  local_26 = (undefined2)DAT_021afcf8;
  local_23 = 1;
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021afcf0),(uint *)(void *)(auStack_22),6);
  uVar1 = *DAT_021afcfc;
  local_1c = (ushort)(byte)(uVar1 >> 0x18) | (ushort)((uVar1 >> 0x10) << 8);
  local_1a = (ushort)((uVar1 & 0xffff) >> 8) | (ushort)((uVar1 & 0xffff) << 8);
  local_12 = (ushort)(byte)(param_1 >> 0x18) | (ushort)((param_1 >> 0x10) << 8);
  local_10 = (ushort)((param_1 & 0xffff) >> 8) | (ushort)((param_1 & 0xffff) << 8);
  FUN_021affcc((int)(uintptr_t)(auStack_38),0x2a,0,0);
  return;
}

