/* Decompiled C draft; module arm9; ROM address 020f6150. No matching claim. */
#include "types.h"
#include "deps/020f6150_func_020f6150.h"

undefined4 func_020f6150(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  func_020f9114(param_2);
  func_0210b850(param_2 + 0x16c);
  *(undefined4 *)(param_2 + 0x30) = uRam020f621c;
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if ((*(ushort *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1ec) & 0x20) != 0) {
    func_020f2b94(param_2,param_1);
    return 0;
  }
  func_020f2b94(param_2,param_1);
  return 1;
}

