/* Decompiled C draft; module arm9; ROM address 021192c4. No matching claim. */
#include "types.h"
#include "deps/021192c4_func_021192c4.h"

void func_021192c4(void)

{
  int *piVar1;
  int iVar2;
  
  func_02119d78();
  if (*(int *)(*piRam0211933c + 0x3c) == 5) {
    *(undefined4 *)(*piRam0211933c + 0x54) = 1;
  }
  piVar1 = piRam0211933c;
  *(int *)(*piRam0211933c + 0x3c) = *(int *)(*piRam0211933c + 0x3c) + 1;
  if ((9 < *(int *)(*piVar1 + 0x3c)) && (iVar2 = func_02119dfc(), iVar2 == 0)) {
    if (*(int *)(*piRam0211933c + 0x40) == 0) {
      func_02119e14();
      iVar2 = func_0211e130();
      if (iVar2 != 0) {
        func_0211e0c4(0);
        func_02119ac4();
        return;
      }
      func_02119e50();
      *(undefined4 *)(*piRam0211933c + 0x6c) = 1;
      func_021199f8();
      return;
    }
    func_02119ac4();
  }
  return;
}

