/* Decompiled C draft; module arm9_ov003; ROM address 021d14b8. No matching claim. */
#include "types.h"
#include "deps/021d14b8_FUN_021d14b8.h"

uint * FUN_021d14b8(undefined4 param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint *local_60;
  undefined1 auStack_5c [36];
  int local_38;
  int local_34;
  
  FUN_021d1cd4((ushort *)(uintptr_t)(*(undefined4 *)(*DAT_021d155c + 0x84)));
  func_0x02004d80((undefined4 *)(void *)(auStack_5c));
  iVar1 = func_0x02004a30(auStack_5c,param_1);
  if (iVar1 == 0) {
    func_0x0200fd1c();
  }
  uVar4 = local_34 - local_38;
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar4;
  }
  iVar2 = FUN_021d1440(param_1,DAT_021d1560,2);
  iVar1 = param_3;
  if (iVar2 != 0) {
    iVar1 = -4;
  }
  local_60 = (uint *)FUN_021d285c(uVar4,iVar1);
  func_0x020048ac(auStack_5c,local_60,uVar4);
  func_0x020049e8((int)(uintptr_t)(auStack_5c));
  if (iVar1 < 1) {
    uVar4 = *local_60;
    if (param_2 != (uint *)0x0) {
      *param_2 = uVar4 >> 8;
    }
    puVar3 = (uint *)FUN_021d285c(uVar4 >> 8,param_3);
    func_0x0214d344((uint)(uintptr_t)(local_60),(byte *)(void *)(puVar3));
    FUN_021d2808((int *)(void *)(&local_60));
    return puVar3;
  }
  return local_60;
}

