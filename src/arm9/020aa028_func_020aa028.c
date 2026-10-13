/* Decompiled C draft; module arm9; ROM address 020aa028. No matching claim. */
#include "types.h"
#include "deps/020aa028_func_020aa028.h"

void func_020aa028(undefined4 param_1,undefined4 param_2,undefined4 param_3,short param_4,
                  undefined2 param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = iRam020aa090;
  puVar1 = puRam020aa08c;
  *(undefined4 **)(iRam020aa090 + 0x2c) = puRam020aa08c;
  *puVar1 = param_1;
  *(undefined4 *)(*(int *)(iVar2 + 0x2c) + 4) = param_2;
  *(undefined4 *)(*(int *)(iVar2 + 0x2c) + 8) = param_3;
  *(short *)(*(int *)(iVar2 + 0x2c) + 0xc) = param_4 + -1;
  *(undefined2 *)(*(int *)(iVar2 + 0x2c) + 0xe) = param_5;
  *(int *)(iVar2 + 0x30) = param_6 + 2;
  if (*(int *)(iVar2 + 0x10) != 0) {
    uVar3 = func_020ab61c();
    uVar4 = func_020ab610();
    uVar3 = func_020aaea0((byte *)(uintptr_t)(iRam020aa090),uVar3,uVar4);
    *(undefined4 *)(iRam020aa090 + 0x10) = uVar3;
  }
  func_020aafa8(iRam020aa090);
  func_020aad9c(iRam020aa090);
  func_020aab70(iRam020aa090);
  func_020aa300(iRam020aa090);
  return;
}

