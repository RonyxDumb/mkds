/* Decompiled C draft; module arm9_ov003; ROM address 021b8498. No matching claim. */
#include "types.h"
#include "deps/021b8498_func_ov003_021b8498.h"

undefined4 func_ov003_021b8498(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char local_2c [2];
  short local_2a;
  short local_28;
  undefined1 auStack_26 [10];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  undefined4 local_18;
  
  local_2c[0] = '\0';
  local_2a = 0;
  local_28 = 0;
  iVar2 = *piRam021b8574;
  func_ov003_021b7d84(&local_1c,0,8);
  func_ov003_021b7d84(iVar2,0,uRam021b8578);
  local_1c = 2;
  local_1b = 0;
  local_1a = func_ov003_021b7c94(4);
  local_18 = *(undefined4 *)(iRam021b857c + 8);
  local_18 = func_ov003_021b7cac();
  local_2a = 8;
  func_ov003_021b8340(*puRam021b8580,iVar2 + 0x18,&local_1c,&local_2a,&local_28,local_2c);
  func_ov003_021b7d90(auStack_26,param_2 + 8,8);
  iVar1 = func_ov003_021b7f48(auStack_26,8,uRam021b8584,6);
  if (iVar1 != 0) {
    func_ov003_021b94b8(2);
    return 0xffffffff;
  }
  func_ov003_021b82e0(iVar2,uRam021b8588,(int)local_2a,(int)local_28,(int)local_2c[0],0x11,
                      auStack_26);
  local_2a = local_2a + 0x18;
  func_ov003_021b8278(iVar2,(int)local_2a,0,param_3);
  return 0;
}

