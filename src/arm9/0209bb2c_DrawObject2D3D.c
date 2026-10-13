/* Decompiled C draft; module arm9; ROM address 0209bb2c. No matching claim. */
#include "types.h"
#include "deps/0209bb2c_DrawObject2D3D.h"

void DrawObject2D3D(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  func_01ff9048(0x1b,param_2,3);
  uVar2 = param_2 + 0xcU & 3;
  uVar1 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    func_020ea5b0(uVar2,*(undefined2 *)(param_3 + 0x66),0);
  }
  uVar2 = param_2 + 0x10U & 3;
  uVar1 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 == 0) &&
     (uVar1 = param_2 + 0x14U & 3, uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    return;
  }
  if (uVar2 != 0) {
    uVar1 = param_2 + 0x24U & 3;
    uVar3 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
      func_020ea7cc(uVar2,*(undefined2 *)(param_3 + 0x66));
    }
    else {
      func_020ea670(uVar2,*(undefined2 *)(param_3 + 0x66));
    }
  }
  uVar2 = param_2 + 0x14U & 3;
  uVar1 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    func_020ea618(uVar2,*(undefined2 *)(param_3 + 0x66));
    return;
  }
  return;
}

