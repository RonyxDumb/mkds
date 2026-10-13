/* Decompiled C draft; module arm9; ROM address 02006aac. No matching claim. */
#include "types.h"
#include "deps/02006aac_func_02006aac.h"

void func_02006aac(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_b0 [39];
  
  uVar2 = Os_DisableIrq();
  if (*piRam02006b38 == 1) {
    Os_RestoreIrq();
    return;
  }
  *piRam02006b38 = 1;
  func_02007008(0);
  SetGlobalGO_from_thumb(0);
  puVar3 = (undefined4 *)func_020070b8();
  iVar4 = 0;
  *puVar3 = 0;
  *(undefined2 *)(puVar3 + 2) = 0;
  *(undefined2 *)((int)puVar3 + 10) = 0;
  puVar3[4] = 0;
  *(undefined4 *)((int)puVar3 + iRam02006b3c) = 0;
  *(undefined2 *)((int)puVar3 + iRam02006b40) = 0;
  *(undefined2 *)((int)puVar3 + iRam02006b44) = 0;
  *(undefined4 *)((int)puVar3 + iRam02006b48) = param_3;
  iVar1 = iRam02006b4c;
  do {
    *(undefined1 *)((int)puVar3 + iVar1) = 0;
    puVar3 = puVar3 + 0x1a;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  local_b0[0] = 0;
  func_0200704c(local_b0);
  func_020070f0();
  func_020070c0(param_1 + -0xe);
  func_020070cc(param_2 + -0xe);
  Os_RestoreIrq(uVar2);
  return;
}

