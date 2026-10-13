/* Decompiled C draft; module arm9_ov001; ROM address 02182f98. No matching claim. */
#include "types.h"
#include "deps/02182f98_FUN_02182f98.h"

void FUN_02182f98(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined1 auStack_48 [36];
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((((0 < *(int *)(param_2 + 0xb0)) && (*(short *)(param_2 + 0xa0) != 0)) &&
      ((*(ushort *)(param_2 + 2) & 1) == 0)) &&
     ((int)(*(uint *)(param_2 + 0x78) & DAT_0218306c) < DAT_02183070)) {
    local_54 = *(undefined4 *)(param_2 + 4);
    local_50 = *(int *)(param_2 + 8) - DAT_02183074;
    local_4c = *(undefined4 *)(param_2 + 0xc);
    local_58 = 0x1e;
    func_0x01ff9048(0x14,&local_58);
    uVar1 = func_0x020e6cbc((uint)(uintptr_t)(&local_54));
    func_0x01ff9048(0x19,uVar1,0xc);
    iVar2 = *(int *)(param_2 + 0xb0);
    if (iVar2 < DAT_02183078) {
      local_24 = iVar2;
      local_20 = iVar2;
      local_1c = iVar2;
      func_0x01ff9048(0x1b,(undefined4)(uintptr_t)(&local_24),3);
    }
    func_0x01ff9048(0x1b,param_2 + 0x1c,3);
    iVar2 = (int)(uint)*(ushort *)(DAT_02183080 + (uint)*DAT_0218307c * 2) >> 4;
    func_0x02146d44((undefined4 *)(void *)(auStack_48),(int)*(short *)(DAT_02183084 + (iVar2 * 2 + 1) * 2),
                    (int)*(short *)(DAT_02183084 + iVar2 * 4));
    func_0x01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_48),9);
    local_18 = DAT_02183088;
    local_14 = DAT_0218308c;
    local_10 = DAT_02183088;
    func_0x01ff9048(0x1b,(undefined4)(uintptr_t)(&local_18),3);
    func_0x020e5348(8,param_4);
  }
  return;
}

