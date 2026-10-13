/* Decompiled C draft; module arm9; ROM address 02006a10. No matching claim. */
#include "types.h"
#include "deps/02006a10_func_02006a10.h"

void func_02006a10(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_a8 [39];
  
  uVar2 = Os_DisableIrq();
  if (*piRam02006a94 == 1) {
    Os_RestoreIrq();
    return;
  }
  *piRam02006a94 = 1;
  func_02007008(0xffffffff);
  SetGlobalGO_from_thumb(0);
  puVar3 = (undefined4 *)func_020070b8();
  iVar4 = 0;
  *puVar3 = 0;
  *(undefined2 *)(puVar3 + 2) = 0;
  *(undefined2 *)((int)puVar3 + 10) = 0;
  puVar3[4] = 0;
  *(undefined4 *)((int)puVar3 + iRam02006a98) = 0;
  *(undefined2 *)((int)puVar3 + iRam02006a9c) = 0;
  *(undefined2 *)((int)puVar3 + iRam02006aa0) = 0;
  *(undefined4 *)((int)puVar3 + iRam02006aa4) = param_1;
  iVar1 = iRam02006aa8;
  do {
    *(undefined1 *)((int)puVar3 + iVar1) = 0;
    puVar3 = puVar3 + 0x1a;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  local_a8[0] = 0;
  func_0200704c(local_a8);
  func_020070f0();
  func_020070c0(0);
  func_020070cc(0);
  Os_RestoreIrq(uVar2);
  return;
}

