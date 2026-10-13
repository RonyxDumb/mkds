/* Decompiled C draft; module arm9; ROM address 020094b8. No matching claim. */
#include "types.h"
#include "deps/020094b8_func_020094b8.h"

void func_020094b8(undefined4 param_1,undefined4 param_2,byte param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  
  puVar3 = puRam020095a8;
  uVar5 = *(int *)(iRam020095a0 + 4) + iRam020095a4;
  if (uVar5 < *(int *)(iRam020095a0 + 8) + 0x62U) {
    *(char *)(puRam020095a8 + 3) = (char)uVar5 - (char)*(int *)(iRam020095a0 + 8);
    Mem_CpuFill16(0,iRam020095ac + (uint)*(byte *)(puVar3 + 3),0x62 - (uint)*(byte *)(puVar3 + 3));
  }
  else {
    *(undefined1 *)(puRam020095a8 + 3) = 0x62;
  }
  CopyMemory16(*(undefined4 *)(iRam020095a0 + 8),iRam020095ac,*(undefined1 *)(puRam020095a8 + 3));
  puVar3 = puRam020095a8;
  iVar2 = iRam020095a0;
  *(undefined1 *)((int)puRam020095a8 + 10) = *(undefined1 *)(iRam020095a0 + 0xf);
  *(undefined1 *)((int)puVar3 + 0xb) = *(undefined1 *)(iVar2 + 0x10);
  iVar6 = *(int *)(iVar2 + 4);
  *(byte *)(puVar3 + 1) = *(byte *)(puVar3 + 1) & 0xfc | *(byte *)(iVar6 + iRam020095b0) & 3;
  *(undefined1 *)((int)puVar3 + 5) = *(undefined1 *)(iVar6 + iRam020095b4);
  *(undefined1 *)((int)puVar3 + 6) = *(undefined1 *)(iVar2 + 0xe);
  *puVar3 = *(undefined4 *)(iVar6 + iRam020095b8);
  *(byte *)(puVar3 + 1) =
       *(byte *)(puVar3 + 1) & 3 | (byte)((*(byte *)(iVar6 + iRam020095bc) & 0x3f) << 2);
  cVar1 = *(char *)(iVar2 + 0x11);
  *(char *)(iVar2 + 0x11) = cVar1 + '\x01';
  *(char *)((int)puVar3 + 7) = cVar1;
  *(undefined2 *)(puVar3 + 2) = 0;
  uVar4 = func_020088dc(uRam020095c0,0x68);
  *(undefined2 *)(puRam020095a8 + 2) = uVar4;
  iVar2 = iRam020095a0;
  *(char *)(iRam020095a0 + 0xf) = *(char *)(iRam020095a0 + 0xf) + '\x01';
  if (*(byte *)(iVar2 + 0xf) < *(byte *)(iVar2 + 0x10)) {
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x62;
  }
  else {
    *(undefined1 *)(iVar2 + 0xc) = 4;
  }
  func_021455a0(0,puRam020095a8,0x70,param_1,param_2,param_3 | 2);
  return;
}

