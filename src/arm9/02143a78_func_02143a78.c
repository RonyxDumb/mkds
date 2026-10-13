/* Decompiled C draft; module arm9; ROM address 02143a78. No matching claim. */
#include "types.h"
#include "deps/02143a78_func_02143a78.h"

int func_02143a78(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  iVar2 = func_02142988(3,2,3,5);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (param_2 == 0) {
    return 6;
  }
  if (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 == 0 &&
      *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20 == 0) {
    return 6;
  }
  if ((*(ushort *)(param_2 + 4) != 0) && (*(ushort *)(param_2 + 4) < 0xf)) {
    SetSomeFunctionPtr(10,param_1);
    iVar2 = Wm_GetGlobal();
    uVar1 = iVar2 + 0xcU & 3;
    uVar3 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
    puVar4 = (undefined2 *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    *puVar4 = 10;
    puVar4[1] = *(undefined2 *)(param_2 + 4);
    *(uint *)(puVar4 + 2) =
         *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    puVar4[4] = *(undefined2 *)(param_2 + 6);
    *(undefined1 *)(puVar4 + 5) = *(undefined1 *)(param_2 + 8);
    *(undefined1 *)((int)puVar4 + 0xb) = *(undefined1 *)(param_2 + 9);
    *(undefined1 *)(puVar4 + 6) = *(undefined1 *)(param_2 + 10);
    *(undefined1 *)((int)puVar4 + 0xd) = *(undefined1 *)(param_2 + 0xb);
    *(undefined1 *)(puVar4 + 7) = *(undefined1 *)(param_2 + 0xc);
    *(undefined1 *)((int)puVar4 + 0xf) = *(undefined1 *)(param_2 + 0xd);
    iVar2 = WM_SomeFn(10,0);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
    return iVar2;
  }
  return 6;
}

