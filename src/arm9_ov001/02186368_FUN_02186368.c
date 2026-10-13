/* Decompiled C draft; module arm9_ov001; ROM address 02186368. No matching claim. */
#include "types.h"
#include "deps/02186368_FUN_02186368.h"

void FUN_02186368(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 auStack_3c [40];
  
  uVar4 = *(int *)(param_2 + DAT_02186498) >> 0xc;
  local_48 = *(int *)(param_2 + 4) >> 4;
  local_44 = *(int *)(param_2 + 8) >> 4;
  local_40 = *(int *)(param_2 + 0xc) >> 4;
  uVar1 = func_0x020e69bc((uint)(uintptr_t)(&local_48));
  if ((int)uVar4 <= (int)uVar1) {
    uVar1 = uVar4;
  }
  if (0 < (int)uVar1) {
    if (0x1e < (int)uVar1) {
      uVar1 = 0x1f;
    }
    if ((int)uVar1 < 0x1f) {
      if (*(uint *)(param_2 + DAT_021864a0) < 2) {
        func_0x02012ffc(*(undefined4 *)(*(int *)(*(int *)(param_2 + DAT_0218649c) + 0x10) + 4),1);
        func_0x0209b940(*(undefined4 *)(param_2 + DAT_0218649c),3);
      }
      else {
        iVar3 = *(int *)(*(int *)(*(int *)(param_2 + DAT_0218649c) + 0x10) + 4);
        func_0x02012ffc(iVar3,1);
        uVar4 = 0;
        if (*(char *)(iVar3 + 0x18) != '\0') {
          do {
            uVar2 = func_0x020d3c44();
            func_0x0209b904(*(undefined4 *)(param_2 + DAT_0218649c),uVar2,uVar4 & 0xffff);
            uVar4 = uVar4 + 1;
          } while ((int)uVar4 < (int)(uint)*(byte *)(iVar3 + 0x18));
        }
      }
    }
    else {
      func_0x02012ffc(*(undefined4 *)(*(int *)(*(int *)(param_2 + DAT_0218649c) + 0x10) + 4),1);
      func_0x0209b940(*(undefined4 *)(param_2 + DAT_0218649c),3);
    }
    local_4c = 0x1e;
    func_0x01ff9048(0x14,(undefined4)(uintptr_t)(&local_4c),1);
    uVar2 = func_0x020e6b58(param_2 + 4);
    func_0x01ff9048(0x19,uVar2,0xc);
    if (*(ushort *)(param_2 + 0x7e) != 0) {
      iVar3 = (int)(uint)*(ushort *)(param_2 + 0x7e) >> 4;
      func_0x02146d44((undefined4 *)(void *)(auStack_3c),(int)*(short *)(DAT_021864a4 + iVar3 * 4),
                      (int)*(short *)(DAT_021864a4 + (iVar3 * 2 + 1) * 2));
      func_0x01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_3c),9);
    }
    func_0x01ff9048(0x1b,param_2 + 0x1c,3);
    func_0x0209b9a4(*(undefined4 *)(param_2 + DAT_0218649c),uVar1 & 0xffff);
    func_0x0209b7a0((undefined4 *)(uintptr_t)(*(undefined4 *)(param_2 + DAT_0218649c)),*(ushort *)(param_2 + 2) & DAT_021864a8,
                    0);
    func_0x0209bb2c(param_1,*(undefined4 *)(param_2 + DAT_0218649c),param_2);
  }
  return;
}

