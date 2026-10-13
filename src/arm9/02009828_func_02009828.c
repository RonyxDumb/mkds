/* Decompiled C draft; module arm9; ROM address 02009828. No matching claim. */
#include "types.h"
#include "deps/02009828_func_02009828.h"

void func_02009828(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  Mem_CpuFill16(0,param_1,uRam020098e0);
  *(undefined1 *)(param_1 + iRam020098e4) = 0;
  iVar1 = SomeFileRead_from_thumb(*(undefined4 *)(param_2 + 0xc),param_1,1);
  iVar2 = SomeFileRead_from_thumb(*(undefined4 *)(param_2 + 0x10),param_1,0);
  if (iVar1 == 0 || iVar2 == 0) {
    *(undefined1 *)(param_1 + iRam020098e4) = 1;
    Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(param_1),iRam020098e8);
  }
  *(undefined4 *)(param_1 + iRam020098ec) = *(undefined4 *)(param_2 + 0x14);
  if (param_3 != 0) {
    CopyMemory16(param_3,param_1 + iRam020098e8,0x16);
  }
  *(undefined1 *)(param_1 + iRam020098f0) = *(undefined1 *)(param_2 + 0x18);
  iVar1 = func_02009724((short *)(uintptr_t)(*(undefined4 *)(param_2 + 4)));
  CopyMemory16(*(undefined4 *)(param_2 + 4),param_1 + iRam020098f4,(uint)(iVar1 << 0x11) >> 0x10);
  CopyMemory16(*(undefined4 *)(param_2 + 8),param_1 + iRam020098f8,0xc0);
  *(undefined1 *)(param_1 + iRam020098fc) = 1;
  *(undefined2 *)(param_1 + iRam02009900) = 1;
  *(undefined2 *)(param_1 + iRam02009904) = 1;
  return;
}

