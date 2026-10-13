/* Decompiled C draft; module arm9; ROM address 0210d4a4. No matching claim. */
#include "types.h"
#include "deps/0210d4a4_func_0210d4a4.h"

void func_0210d4a4(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  func_0210e2c4((int *)(uintptr_t)(uRam0210d55c),param_1,param_2,0x1c);
  iVar3 = 0;
  if (0 < param_2) {
    do {
      func_0210e328(param_1);
      StructMQChild_Create((undefined4 *)(uintptr_t)(param_1 + 8));
      *(undefined1 *)(param_1 + 0x18) = 0;
      *(undefined2 *)(param_1 + 0x16) = 0;
      *(undefined1 *)(param_1 + 0x19) = 0;
      *(undefined2 *)(param_1 + 0x14) = 0;
      iVar3 = iVar3 + 1;
      *(undefined1 *)(param_1 + 0x1a) = 0x7f;
      param_1 = param_1 + 0x1c;
    } while (iVar3 < param_2);
  }
  IntrusiveListWrapper_InitializeEmpty((undefined4 *)(uintptr_t)(uRam0210d560),0);
  iVar2 = 0;
  iVar3 = iRam0210d564;
  do {
    IntrusiveListWrapper_InitializeEmpty((undefined4 *)(uintptr_t)(iVar3),0x1c);
    puVar1 = puRam0210d56c;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0xc;
  } while (iVar2 < 2);
  *puRam0210d568 = 0;
  *puVar1 = 0;
  return;
}

