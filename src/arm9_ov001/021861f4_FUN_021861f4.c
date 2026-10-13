/* Decompiled C draft; module arm9_ov001; ROM address 021861f4. No matching claim. */
#include "types.h"
#include "deps/021861f4_FUN_021861f4.h"

void FUN_021861f4(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 auStack_50 [36];
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar3 = *(int *)(param_2 + DAT_02186330) >> 0xc;
  if (*(int *)(param_2 + DAT_02186334) == 2) {
    local_5c = *(undefined4 *)(param_2 + 4);
    local_58 = *(undefined4 *)(param_2 + 8);
    local_54 = *(undefined4 *)(param_2 + 0xc);
  }
  else if (*(int *)(param_2 + DAT_02186334) == 3) {
    local_5c = *(undefined4 *)(param_2 + DAT_02186338);
    local_58 = *(undefined4 *)(*(int *)(param_2 + 0x9c) + 4);
    local_54 = *(undefined4 *)(param_2 + DAT_0218633c);
  }
  else {
    if (3 < (int)uVar3) {
      uVar3 = uVar3 - (*(int *)(param_2 + 8) - *(int *)(*(int *)(param_2 + 0x9c) + 4) >> 0xf);
      if ((int)uVar3 < 5) {
        uVar3 = 4;
      }
      uVar3 = uVar3 & 0xffff;
    }
    local_5c = *(undefined4 *)(param_2 + 4);
    local_58 = *(undefined4 *)(*(int *)(param_2 + 0x9c) + 4);
    local_54 = *(undefined4 *)(param_2 + 0xc);
  }
  if (0x10 < (int)uVar3) {
    uVar3 = 0x10;
  }
  if (param_3 != 0) {
    uVar3 = 0x14 - uVar3;
  }
  if (0 < (int)uVar3) {
    local_60 = 0x1e;
    func_0x01ff9048(0x14,(undefined4)(uintptr_t)(&local_60),1);
    uVar1 = func_0x020e6b58((uint)(uintptr_t)(&local_5c));
    func_0x01ff9048(0x19,uVar1,0xc);
    iVar2 = (int)(*(uint *)(param_2 + DAT_02186340) & 0xffff) >> 4;
    func_0x02146d44((undefined4 *)(void *)(auStack_50),(int)*(short *)(DAT_02186344 + iVar2 * 4),
                    (int)*(short *)(DAT_02186344 + (iVar2 * 2 + 1) * 2));
    func_0x01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_50),9);
    local_24 = *(int *)(param_2 + DAT_02186348) >> 4;
    local_28 = *(int *)(param_2 + DAT_0218634c) >> 4;
    local_2c = *(int *)(param_2 + DAT_02186350) >> 4;
    func_0x01ff9048(0x1c,(undefined4)(uintptr_t)(&local_2c),3);
    func_0x01ff9048(0x1b,param_2 + DAT_02186354,3);
    if (*DAT_02186358 == 0) {
      local_20 = DAT_0218635c;
      local_1c = DAT_02186360;
      local_18 = DAT_0218635c;
      func_0x01ff9048(0x1b,(undefined4)(uintptr_t)(&local_20),3);
    }
    func_0x0209b940(*(undefined4 *)(param_2 + DAT_02186364),3);
    func_0x0209b9a4(*(undefined4 *)(param_2 + DAT_02186364),uVar3 & 0xffff);
    func_0x0209bb2c(param_1,*(undefined4 *)(param_2 + DAT_02186364),param_2);
  }
  return;
}

