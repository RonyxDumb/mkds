/* Decompiled C draft; module arm9; ROM address 0204e568. No matching claim. */
#include "types.h"
#include "deps/0204e568_func_0204e568.h"

void func_0204e568(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  byte local_24 [28];
  
  piVar1 = piRam0204e63c;
  *(undefined4 *)(*piRam0204e63c + 0xc) = 0x16;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  StructBin_SomeFn_from_thumb(*piVar1 + iRam0204e640);
  local_24[1] = 10;
  local_24[0] = *(byte *)(*piRam0204e644 + 0x40) & 0xf | 0x80;
  Mem_CpuCopy8(*(int *)*puRam0204e648 + 0xc,local_24 + 2,0x14);
  uVar2 = func_02052c5c(1);
  iVar3 = iRam0204e64c;
  piVar1 = piRam0204e63c;
  *(undefined2 *)(*piRam0204e63c + iRam0204e64c) = uVar2;
  iVar3 = SetupSomePointer_from_thumb
                    (*(undefined4 *)(*piVar1 + iRam0204e650),local_24,0x25,
                     *(undefined2 *)(*piVar1 + iVar3),2);
  if (iVar3 != 0) {
    func_02050e60(5);
  }
  func_02009f38(uRam0204e654,7);
  func_02007ea0(uRam0204e658);
  iVar3 = func_02009cc8((int)*(char *)(*piRam0204e63c + 0x88));
  if (iVar3 != 0) {
    func_02050e60(5);
  }
  iVar3 = func_0204ea3c();
  if (iVar3 == 0) {
    func_02050e60(5);
  }
  piVar1 = piRam0204e63c;
  *(byte *)(*piRam0204e63c + 0x8b) = *(byte *)(*piRam0204e63c + 0x8b) & 0xfb;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  return;
}

