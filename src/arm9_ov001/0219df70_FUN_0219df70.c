/* Decompiled C draft; module arm9_ov001; ROM address 0219df70. No matching claim. */
#include "types.h"
#include "deps/0219df70_FUN_0219df70.h"

void FUN_0219df70(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar2 = func_0x02036bec(param_1,0x58);
  piVar1 = DAT_0219e094;
  *DAT_0219e094 = iVar2;
  *(undefined4 *)(iVar2 + 0x30) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = 1;
  FUN_0219de58();
  piVar1 = DAT_0219e094;
  iVar2 = 0;
  puVar6 = DAT_0219e098;
  do {
    func_0x02124a98(*puVar6,1,*(undefined4 *)(*piVar1 + 0x38),*(undefined4 *)(*piVar1 + 0x44));
    puVar6 = puVar6 + 0xb;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  uVar3 = FUN_0219e920();
  uVar4 = FUN_0219e90c();
  func_0x020ae6d4(uVar3,uVar4);
  iVar2 = *DAT_0219e094;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar2 + 0x44),*(undefined4 *)(iVar2 + 0x4c),(undefined4 *)(uintptr_t)(iVar2 + 0x34));
  uVar3 = func_0x0204799c(DAT_0219e09c);
  *(undefined4 *)(*DAT_0219e094 + 0x50) = uVar3;
  uVar3 = func_0x02047a28(DAT_0219e0a0);
  piVar1 = DAT_0219e094;
  *(undefined4 *)(*DAT_0219e094 + 0x54) = uVar3;
  iVar2 = *piVar1;
  func_0x021243ac(param_1,0,*(undefined4 *)(iVar2 + 0x4c),0xa0,0xe,9,*(undefined4 *)(iVar2 + 0x38),
                  *(undefined4 *)(iVar2 + 0x44),*(undefined4 *)(iVar2 + 0x34),DAT_0219e0a4);
  iVar2 = *DAT_0219e094;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x50),8);
  func_0x0212426c(1,0,*(undefined4 *)(*DAT_0219e094 + 0x4c),uVar3,*(undefined4 *)(iVar2 + 0x44),
                  *(undefined4 *)(iVar2 + 0x34));
  piVar1 = DAT_0219e094;
  iVar2 = 0;
  iVar5 = 0;
  do {
    *(undefined2 *)(*piVar1 + iVar5 + 0x18) = 0xfa;
    *(undefined2 *)(*piVar1 + iVar5 + 0x1a) = 0;
    iVar5 = iVar5 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  uVar3 = FUN_0219de38();
  piVar1 = DAT_0219e094;
  *(undefined4 *)(*DAT_0219e094 + 0xc) = uVar3;
  *(undefined4 *)(*piVar1 + 0x10) = *(undefined4 *)(*piVar1 + 0xc);
  FUN_0219d858();
  FUN_0219d810();
  piVar1 = DAT_0219e094;
  *(undefined4 *)(*DAT_0219e094 + 0x28) = 0;
  *(undefined4 *)(*piVar1 + 0x2c) = 0;
  func_0x021281c8(0xe);
  return;
}

