/* Decompiled C draft; module arm9_ov000; ROM address 0218d488. No matching claim. */
#include "types.h"
#include "deps/0218d488_FUN_0218d488.h"

int FUN_0218d488(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar2 = *param_2;
  uVar4 = FUN_0218b280(*param_1,*(undefined4 *)(*DAT_0218d51c + DAT_0218d520),0,0);
  uVar5 = FUN_0218b280(uVar2,*(undefined4 *)(*DAT_0218d51c + DAT_0218d520),0,0);
  uVar4 = func_0x02130ccc((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                          (int)((ulonglong)uVar5 >> 0x20));
  if (*(int *)(*DAT_0218d51c + DAT_0218d524) == 0) {
    uVar4 = func_0x02130ccc(0,0,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  }
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar2 = func_0x0212fe20((int)uVar4,uVar3);
  iVar1 = func_0x02131860(uVar2,0);
  if (iVar1 != 0) {
    return 1;
  }
  uVar2 = func_0x0212fe20((int)uVar4,uVar3);
  iVar1 = func_0x021317b0(uVar2,0);
  return -(uint)(iVar1 != 0);
}

