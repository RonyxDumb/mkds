/* Decompiled C draft; module arm9; ROM address 02116dd4. No matching claim. */
#include "types.h"
#include "deps/02116dd4_func_02116dd4.h"

void func_02116dd4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined2 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Mem_AllocateHeap(param_1,0x2c);
  *piRam02116e5c = iVar2;
  uVar3 = find_buf_fn_from_thumb(*puRam02116e60);
  func_020b48b4((int *)(uintptr_t)(*piRam02116e5c),uVar3);
  uVar3 = find_buf_fn_from_thumb(*puRam02116e64);
  Gfx_ReadCharGraphicsRelative((int *)(uintptr_t)(*piRam02116e5c + 4),uVar3);
  uVar3 = find_buf_fn_from_thumb(*puRam02116e68);
  Gfx_ReadPaletteRelative((int *)(uintptr_t)(*piRam02116e5c + 8),uVar3);
  uVar3 = find_buf_fn_from_thumb(*puRam02116e6c);
  piVar1 = piRam02116e5c;
  *(undefined4 *)(*piRam02116e5c + 0xc) = uVar3;
  *(undefined4 *)(*piVar1 + 0x10) = param_2;
  *(undefined4 *)(*piVar1 + 0x14) = param_3;
  *(undefined4 *)(*piVar1 + 0x18) = param_4;
  *(undefined2 *)(*piVar1 + 0x1c) = param_5;
  *(undefined4 *)(*piVar1 + 0x20) = param_6;
  *(undefined2 *)(*piVar1 + 0x24) = 2;
  *(undefined4 *)(*piVar1 + 0x28) = 3;
  return;
}

