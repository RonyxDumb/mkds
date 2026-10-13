/* Decompiled C draft; module arm9; ROM address 0202d6a0. No matching claim. */
#include "types.h"
#include "deps/0202d6a0_func_0202d6a0.h"

void func_0202d6a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [20];
  undefined1 auStack_24 [20];
  undefined2 local_10;
  
  func_0202dcf4(*(undefined4 *)(*piRam0202d718 + 0xa4),(undefined4)(uintptr_t)(auStack_3c));
  func_0202dc68(*(undefined4 *)(*piRam0202d718 + 0xa4),(undefined4)(uintptr_t)(auStack_38));
  CopyMemory16((int)(uintptr_t)(auStack_38),(int)(uintptr_t)(auStack_24),0x14);
  local_10 = 0;
  uVar1 = func_0202dbe8(*(undefined4 *)(*piRam0202d718 + 0xa4));
  uVar2 = func_0202db68(*(undefined4 *)(*piRam0202d718 + 0xa4));
  uVar3 = func_0202db04(*(undefined4 *)(*piRam0202d718 + 0xa4));
  func_0202de00(*piRam0202d718 + 0x50,(short *)(uintptr_t)(uRam0202d71c),(undefined4)(uintptr_t)(auStack_24),uVar1,uVar2,uVar3,(undefined2 *)(void *)(auStack_3c));
  return;
}

