/* Decompiled C draft; module arm9; ROM address 02124c70. No matching claim. */
#include "types.h"
#include "deps/02124c70_func_02124c70.h"

undefined4
func_02124c70(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,int *param_6
             ,int param_7)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_34;
  int local_30;
  int *local_2c;
  ushort local_24;
  ushort local_22;
  int local_1c;
  int local_18;
  
  if (param_6[0xe] != -1) {
    func_02124c70(param_6[0xe] + (uint)*(ushort *)(param_3 + 6));
  }
  local_2c = (int *)0x0;
  if (*param_6 == 0) {
    return 0;
  }
  if (param_1 < (int)(uint)*(ushort *)(param_3 + 6)) {
    puVar1 = (ushort *)func_0201ea30(param_3,param_1);
    iVar4 = CellBank_GetMetatileEntry((ushort *)(uintptr_t)(param_2),*(uint *)(puVar1 + 2) & 0xffff);
    local_24 = *puVar1;
    local_22 = puVar1[1];
    local_34 = (int)*(short *)(iVar4 + 8) - (int)*(short *)(iVar4 + 0xc);
    local_30 = (int)*(short *)(iVar4 + 10) - (int)*(short *)(iVar4 + 0xe);
    iVar2 = func_0201ebe8(local_24,local_34);
    local_1c = ((local_34 >> 1) + iVar2) * 0x1000;
    iVar2 = func_0201eba0(puVar1[1],local_30);
    local_18 = ((local_30 >> 1) + iVar2) * 0x1000;
  }
  else {
    puVar1 = (ushort *)func_0201ea58(param_4,param_1 - (uint)*(ushort *)(param_3 + 6));
    iVar4 = *(int *)(param_6[0xf] + 0x44);
    local_24 = *puVar1;
    local_22 = puVar1[1];
    local_34 = (int)*(short *)(iVar4 + 8) - (int)*(short *)(iVar4 + 0xc);
    local_30 = (int)*(short *)(iVar4 + 10) - (int)*(short *)(iVar4 + 0xe);
    local_1c = (((int)(short)local_24 << 0x14) >> 0x14) << 0xc;
    local_18 = (((int)(short)local_22 << 0x14) >> 0x14) << 0xc;
  }
  if (param_6[2] != 0) {
    if (param_1 < (int)(uint)*(ushort *)(param_3 + 6)) {
      local_1c = ((int)(short)param_6[3] +
                 (1 - (((uint)local_24 << 0x12) >> 0x1e)) * (local_34 >> 1)) * 0x1000;
      local_18 = ((int)*(short *)((int)param_6 + 0xe) +
                 (1 - (((uint)local_22 << 0x12) >> 0x1e)) * (local_30 >> 1)) * 0x1000;
    }
    else {
      local_1c = (int)(short)param_6[3] << 0xc;
      local_18 = (int)*(short *)((int)param_6 + 0xe) << 0xc;
    }
  }
  iVar2 = local_1c + (short)param_6[1] * 0x1000 >> 0xc;
  if ((((-1 < iVar2 + local_34) && (iVar2 - local_34 <= iRam02124ec8)) &&
      (iVar2 = local_18 + *(short *)((int)param_6 + 6) * 0x1000 >> 0xc, -1 < iVar2 + local_30)) &&
     (iVar2 - local_30 < 0xc1)) {
    iVar2 = func_020ae5e4(param_5);
    if (param_6[4] != 0) {
      local_2c = param_6 + 9;
      iVar2 = param_5 + iVar2 * 0x20;
      *(short *)(iVar2 + 6) = (short)(param_6[5] >> 4);
      *(short *)(iVar2 + 0xe) = (short)(param_6[6] >> 4);
      *(short *)(iVar2 + 0x16) = (short)(param_6[7] >> 4);
      *(short *)(iVar2 + 0x1e) = (short)(param_6[8] >> 4);
      if (param_7 != 0) {
        func_020ae5d4(param_5);
      }
    }
    uVar3 = MaybeMakeOamSlot(param_5 + (uint)*(ushort *)(param_5 + iRam02124ecc) * 8,
                             0x80 - *(ushort *)(param_5 + iRam02124ecc) & 0xffff,iVar4,local_2c);
    *(short *)(param_5 + iRam02124ecc) = *(short *)(param_5 + iRam02124ecc) + (short)uVar3;
    return uVar3;
  }
  return 0;
}

