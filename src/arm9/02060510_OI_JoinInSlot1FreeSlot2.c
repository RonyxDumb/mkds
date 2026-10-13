/* Decompiled C draft; module arm9; ROM address 02060510. No matching claim. */
#include "types.h"
#include "deps/02060510_OI_JoinInSlot1FreeSlot2.h"

void OI_JoinInSlot1FreeSlot2(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  short local_88;
  short local_86;
  short local_84;
  short local_82;
  short local_80;
  ushort local_7c;
  undefined1 auStack_7a [20];
  byte local_66;
  short local_64;
  short local_62;
  short local_60;
  short local_5e;
  short local_5c;
  short local_5a;
  ushort local_58;
  undefined1 auStack_56 [20];
  byte local_42;
  short local_40;
  short local_3e;
  short local_3c;
  short local_3a;
  short local_38;
  short local_36;
  ushort local_34;
  undefined1 auStack_32 [20];
  byte local_1e;
  
  GlobalZ_GetOI(param_1,(int)(uintptr_t)(&local_88));
  GlobalZ_GetOI(param_2,(int)(uintptr_t)(&local_64));
  StructOI_Initialize_from_thumb(&local_40);
  if (-1 < (int)((uint)local_42 << 0x1e)) {
    local_40 = local_40 + local_64;
    local_3e = local_3e + local_62;
    local_3c = local_3c + local_60;
    local_3a = local_3a + local_5e;
    local_38 = local_38 + local_5c;
    local_36 = local_36 + local_5a;
    Mem_CpuCopy8((ushort *)(void *)(auStack_56),(uint *)(void *)(auStack_32),0x14);
    uVar2 = (uint)local_58;
    local_34 = (ushort)((uVar2 << 0x19) >> 0x19) | (ushort)(((uVar2 << 0x15) >> 0x1c) << 7) |
               (ushort)(((uVar2 << 0x10) >> 0x1b) << 0xb);
  }
  if (-1 < (int)((uint)local_66 << 0x1e)) {
    local_40 = local_40 + local_88;
    local_3e = local_3e + local_86;
    local_3c = local_3c + local_84;
    local_3a = local_3a + local_82;
    local_38 = local_38 + local_80;
    local_36 = local_36 + local_5a;
    Mem_CpuCopy8((ushort *)(void *)(auStack_7a),(uint *)(void *)(auStack_32),0x14);
    uVar2 = (uint)local_7c;
    local_34 = (ushort)((uVar2 << 0x19) >> 0x19) | (ushort)(((uVar2 << 0x15) >> 0x1c) << 7) |
               (ushort)(((uVar2 << 0x10) >> 0x1b) << 0xb);
  }
  if (((int)((uint)local_66 << 0x1c) < 0) || ((int)((uint)local_42 << 0x1c) < 0)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  local_1e = local_1e & 0xf0 | 1 | (byte)((((uint)local_66 << 0x1d) >> 0x1f) << 2) |
             (byte)(iVar1 << 3);
  GlobalZ_SetOI(param_1,(undefined4)(uintptr_t)(&local_40));
  Mem_CpuFill8((uint *)(void *)(&local_64),0,0x24);
  local_42 = local_42 & 0xfe;
  GlobalZ_SetOI(param_2,(undefined4)(uintptr_t)(&local_64));
  return;
}

