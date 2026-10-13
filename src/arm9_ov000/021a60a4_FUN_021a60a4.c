/* Decompiled C draft; module arm9_ov000; ROM address 021a60a4. No matching claim. */
#include "types.h"
#include "deps/021a60a4_FUN_021a60a4.h"

undefined4 FUN_021a60a4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = func_0x0200fca0();
  if (*DAT_021a61a8 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  iVar3 = *(int *)(*DAT_021a61a8 + DAT_021a61ac);
  if (iVar3 == 3) {
    FUN_021a5948(param_1,(char *)(uintptr_t)(param_2),param_3);
    func_0x0200ee3c(*(undefined4 *)(*DAT_021a61a8 + DAT_021a61b0),
                    *(undefined2 *)(*DAT_021a61a8 + DAT_021a61b4));
    piVar1 = DAT_021a61a8;
    *(int *)(*DAT_021a61a8 + DAT_021a61b8) = *(int *)(*DAT_021a61a8 + DAT_021a61b8) + 1;
    iVar3 = func_0x021438f0(DAT_021a61bc,*piVar1 + DAT_021a61b0);
    if (iVar3 == 2) {
      FUN_021a57fc(5);
      *(undefined2 *)(*DAT_021a61a8 + DAT_021a61c0) = 3;
      func_0x0200fcb4(uVar2);
      return 3;
    }
    if ((iVar3 != 3) && (iVar3 == 8)) {
      func_0x0200fcb4(uVar2);
      return 4;
    }
    FUN_021a57fc(0xb);
    func_0x0200fcb4(uVar2);
    return 7;
  }
  if (iVar3 == 5) {
    FUN_021a5948(param_1,(char *)(uintptr_t)(param_2),param_3);
    func_0x0200fcb4(uVar2);
    return 2;
  }
  if (iVar3 == 6) {
    FUN_021a5948(param_1,(char *)(uintptr_t)(param_2),param_3);
    func_0x0200fcb4(uVar2);
    return 0;
  }
  func_0x0200fcb4();
  return 1;
}

