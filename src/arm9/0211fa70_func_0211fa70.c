/* Decompiled C draft; module arm9; ROM address 0211fa70. No matching claim. */
#include "types.h"
#include "deps/0211fa70_func_0211fa70.h"

void func_0211fa70(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x021a38d8();
  if (iVar1 == 0) {
    func_0x021a3884();
    return;
  }
  iVar1 = func_0x021a3810();
  if (iVar1 != 4) {
    if (iVar1 != 7) {
      return;
    }
    uVar2 = func_0x0219c3cc((*(uint *)(uRam0211fb3c & 0xfffffffc) >> (uRam0211fb3c & 3) * 8 |
                            *(uint *)(uRam0211fb3c & 0xfffffffc) << (uRam0211fb3c & 3) * -8 + 0x20)
                            + iRam0211fb40);
    *(undefined4 *)
     ((*(uint *)(uRam0211fb3c & 0xfffffffc) >> (uRam0211fb3c & 3) * 8 |
      *(uint *)(uRam0211fb3c & 0xfffffffc) << (uRam0211fb3c & 3) * -8 + 0x20) + 0x1f44) = uVar2;
    func_0x0219c0f4();
    func_0x021a37dc();
    *(undefined4 *)
     ((*(uint *)(uRam0211fb3c & 0xfffffffc) >> (uRam0211fb3c & 3) * 8 |
      *(uint *)(uRam0211fb3c & 0xfffffffc) << (uRam0211fb3c & 3) * -8 + 0x20) + 0x1f2c) = 7;
    return;
  }
  func_0x0219bea8(0,0,uRam0211fb38,0);
  *(undefined4 *)
   ((*(uint *)(uRam0211fb3c & 0xfffffffc) >> (uRam0211fb3c & 3) * 8 |
    *(uint *)(uRam0211fb3c & 0xfffffffc) << (uRam0211fb3c & 3) * -8 + 0x20) + 0x1f2c) = 2;
  return;
}

