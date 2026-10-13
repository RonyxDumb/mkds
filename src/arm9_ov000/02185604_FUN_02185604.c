/* Decompiled C draft; module arm9_ov000; ROM address 02185604. No matching claim. */
#include "types.h"
#include "deps/02185604_FUN_02185604.h"

void FUN_02185604(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = func_0x02036bec(param_1,0x54);
  piVar1 = DAT_0218569c;
  *DAT_0218569c = iVar2;
  *(undefined4 *)(iVar2 + 0x2c) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 0x28) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 8) = 0;
  uVar3 = func_0x0204799c(DAT_021856a0);
  *(undefined4 *)(*DAT_0218569c + 0x4c) = uVar3;
  uVar3 = func_0x02047a28(DAT_021856a4);
  *(undefined4 *)(*DAT_0218569c + 0x50) = uVar3;
  FUN_0218554c();
  uVar3 = func_ov000_021804f4();
  uVar4 = func_ov000_021804e0();
  func_0x020ae6d4(uVar3,uVar4);
  iVar2 = *DAT_0218569c;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 0x48),(undefined4 *)(uintptr_t)(iVar2 + 0x30));
  *(undefined2 *)(*DAT_0218569c + 0xc) = 0x50;
  FUN_021854f8();
  FUN_021856a8();
  uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_0218569c + 0x4c),0x11);
  func_0x02126638(uVar3,0,1,0,0,0,0);
  return;
}

