/* Decompiled C draft; module arm9_ov003; ROM address 021b8428. No matching claim. */
#include "types.h"
#include "deps/021b8428_func_ov003_021b8428.h"

undefined4 func_ov003_021b8428(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_1c [12];
  
  uVar2 = *puRam021b8488;
  func_ov003_021b7d84(uVar2,0,uRam021b848c);
  func_ov003_021b7d90(auStack_1c,param_2 + 0x10,8);
  uVar1 = func_ov003_021b7c30((char *)(uintptr_t)(uRam021b8490));
  func_ov003_021b7f48((undefined4)(uintptr_t)(auStack_1c),8,uRam021b8490,uVar1);
  func_ov003_021b82e0((undefined2 *)(uintptr_t)(uVar2),uRam021b8494,0,0,0,0x11,(undefined4)(uintptr_t)(auStack_1c));
  func_ov003_021b8278(uVar2,0x18,0,param_3);
  return 0;
}

