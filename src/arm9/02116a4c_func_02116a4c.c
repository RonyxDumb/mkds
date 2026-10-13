/* Decompiled C draft; module arm9; ROM address 02116a4c. No matching claim. */
#include "types.h"
#include "deps/02116a4c_func_02116a4c.h"

void func_02116a4c(undefined1 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)*puRam02116b4c;
  if (iVar1 == 0) {
    func_02116b50(0x14);
    func_02116b50(*param_1,param_2 + 4);
    *(undefined2 *)(param_2 + 8) = 0x2f;
    func_02116b50(param_1[1],param_2 + 10);
    *(undefined2 *)(param_2 + 0xe) = 0x2f;
    func_02116b50(param_1[2],param_2 + 0x10);
    *(undefined2 *)(param_2 + 0x14) = 0;
    return;
  }
  if (iVar1 == 1) {
    func_02116b50(param_1[1]);
    *(undefined2 *)(param_2 + 4) = 0x2f;
    func_02116b50(param_1[2],param_2 + 6);
    *(undefined2 *)(param_2 + 10) = 0x2f;
    func_02116b50(0x14,param_2 + 0xc);
    func_02116b50(*param_1,param_2 + 0x10);
    *(undefined2 *)(param_2 + 0x14) = 0;
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  if (((int *)*puRam02116b4c)[1] == 3) {
    func_02116b50(param_1[2]);
    *(undefined2 *)(param_2 + 4) = 0x2e;
    func_02116b50(param_1[1],param_2 + 6);
    *(undefined2 *)(param_2 + 10) = 0x2e;
    func_02116b50(0x14,param_2 + 0xc);
    func_02116b50(*param_1,param_2 + 0x10);
    *(undefined2 *)(param_2 + 0x14) = 0;
    return;
  }
  func_02116b50(param_1[2]);
  *(undefined2 *)(param_2 + 4) = 0x2f;
  func_02116b50(param_1[1],param_2 + 6);
  *(undefined2 *)(param_2 + 10) = 0x2f;
  func_02116b50(0x14,param_2 + 0xc);
  func_02116b50(*param_1,param_2 + 0x10);
  *(undefined2 *)(param_2 + 0x14) = 0;
  return;
}

