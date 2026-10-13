/* Decompiled C draft; module arm9_ov000; ROM address 021a8454. No matching claim. */
#include "types.h"
#include "deps/021a8454_FUN_021a8454.h"

void FUN_021a8454(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c [2];
  
  if (param_1 != 0) {
    func_0x0200e084(param_1 + 0x20);
    uVar1 = func_0x0200fca0();
    func_0x0200db9c();
    iVar2 = func_0x0200ea3c(param_1,local_1c,0);
    if (iVar2 != 0) {
      do {
        if (local_1c[0] != 0) {
          if (*(int *)(local_1c[0] + 8) != 0) {
            func_0x0200eae8(*(int *)(local_1c[0] + 8),0xfffffff5,0);
          }
          FUN_021a7048(local_1c[0]);
        }
        iVar2 = func_0x0200ea3c(param_1,local_1c,0);
      } while (iVar2 != 0);
    }
    func_0x0200db64();
    func_0x0200fcb4(uVar1);
    func_0x0200de50();
  }
  return;
}

