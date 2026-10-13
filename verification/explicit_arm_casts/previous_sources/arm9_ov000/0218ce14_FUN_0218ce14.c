/* Decompiled C draft; module arm9_ov000; ROM address 0218ce14. No matching claim. */
#include "types.h"
#include "deps/0218ce14_FUN_0218ce14.h"

undefined4 FUN_0218ce14(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined1 uStack_90;
  undefined1 local_8f;
  undefined2 local_8e;
  int local_8c;
  undefined1 auStack_88 [128];
  
  uVar1 = FUN_0218cef4(param_1 + 0xc,0x14);
  if (*DAT_0218cee4 == 0) {
    func_0x02135014(auStack_88,DAT_0218cee8,param_1 + 0xc,uVar1);
  }
  else {
    func_0x0213a2d0(auStack_88);
  }
  local_8f = 2;
  local_8e = (undefined2)DAT_0218ceec;
  local_8c = FUN_0218e374(auStack_88);
  if (local_8c == -1) {
    iVar2 = FUN_021a8f84(auStack_88);
    if (iVar2 == 0) {
      return 2;
    }
    local_8c = *(int *)**(undefined4 **)(iVar2 + 0xc);
  }
  iVar2 = *(int *)(param_1 + DAT_0218cef0);
  if (iVar2 == -1) {
    iVar2 = FUN_0218e554(2,1);
    piVar3 = (int *)(param_1 + DAT_0218cef0);
    *piVar3 = iVar2;
    iVar2 = *piVar3;
    if (iVar2 == -1) {
      return 1;
    }
  }
  iVar2 = FUN_0218e4b4(iVar2,&uStack_90,8);
  if (iVar2 != 0) {
    FUN_0218e53c(*(undefined4 *)(param_1 + DAT_0218cef0));
    *(undefined4 *)(param_1 + DAT_0218cef0) = 0xffffffff;
    return 3;
  }
  return 0;
}

