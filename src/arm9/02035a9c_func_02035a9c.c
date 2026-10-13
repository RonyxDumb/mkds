/* Decompiled C draft; module arm9; ROM address 02035a9c. No matching claim. */
#include "types.h"
#include "deps/02035a9c_func_02035a9c.h"

void func_02035a9c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [20];
  undefined1 auStack_2c [20];
  undefined2 local_18;
  
  iVar1 = func_0202ddb0();
  iVar1 = *(int *)(*piRam02035b04 + 0x80) + iVar1;
  func_0202dcf4(iVar1,(undefined4)(uintptr_t)(auStack_44));
  func_0202dc68(iVar1,(undefined4)(uintptr_t)(auStack_40));
  CopyMemory16((int)(uintptr_t)(auStack_40),(int)(uintptr_t)(auStack_2c),0x14);
  local_18 = 0;
  uVar2 = func_0202dbe8(iVar1);
  uVar3 = func_0202db68(iVar1);
  uVar4 = func_0202db04(iVar1);
  func_0202de00(*piRam02035b04 + 0x2c,(short *)(uintptr_t)(uRam02035b08),(undefined4)(uintptr_t)(auStack_2c),uVar2,uVar3,uVar4,(undefined2 *)(void *)(auStack_44));
  return;
}

