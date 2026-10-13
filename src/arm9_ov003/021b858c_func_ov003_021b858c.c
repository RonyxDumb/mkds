/* Decompiled C draft; module arm9_ov003; ROM address 021b858c. No matching claim. */
#include "types.h"
#include "deps/021b858c_func_ov003_021b858c.h"

undefined4 func_ov003_021b858c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  char local_28 [2];
  short local_26;
  ushort local_24;
  undefined1 auStack_22 [14];
  
  local_28[0] = '\0';
  local_26 = 0;
  local_24 = 0;
  iVar4 = *piRam021b86cc;
  func_ov003_021b7d84(iVar4,0,uRam021b86d0);
  puVar2 = (undefined1 *)func_ov003_021ba178(uRam021b86d4);
  if (puVar2 == (undefined1 *)0x0) {
    func_ov003_021b94b8(2);
    return 0xffffffff;
  }
  func_ov003_021b7d84(puVar2,0,uRam021b86d4);
  func_ov003_021b7d90(uRam021b86d8,param_2,8);
  func_ov003_021b7d90(auStack_22,uRam021b86d8,8);
  local_26 = func_ov003_021b839c(puVar2 + 4);
  if (local_26 < 0) {
    func_ov003_021b94b8(3);
    if (puVar2 != (undefined1 *)0x0) {
      func_ov003_021ba164(puVar2);
    }
    return 0xffffffff;
  }
  *puVar2 = 0;
  uVar1 = func_ov003_021b7c94(local_26);
  *(undefined2 *)(puVar2 + 2) = uVar1;
  local_26 = local_26 + 4;
  func_ov003_021b8340(0,(undefined2 *)(uintptr_t)(iVar4 + 0x18),(undefined4)(uintptr_t)(puVar2),&local_26,&local_24,(undefined4)(uintptr_t)(local_28));
  local_24 = local_24 | 0x10;
  iVar3 = func_ov003_021b7f48((undefined4)(uintptr_t)(auStack_22),8,uRam021b86dc,6);
  if (iVar3 != 0) {
    func_ov003_021b94b8(2);
    if (puVar2 != (undefined1 *)0x0) {
      func_ov003_021ba164(puVar2);
    }
    return 0xffffffff;
  }
  func_ov003_021b82e0((undefined2 *)(uintptr_t)(iVar4),uRam021b86e0,(int)local_26,(int)(short)local_24,(int)local_28[0],0x11,
                      (undefined4)(uintptr_t)(auStack_22));
  local_26 = local_26 + 0x18;
  func_ov003_021b8278(iVar4,(int)local_26,0xff,param_3);
  if (puVar2 != (undefined1 *)0x0) {
    func_ov003_021ba164(puVar2);
  }
  return 0;
}

