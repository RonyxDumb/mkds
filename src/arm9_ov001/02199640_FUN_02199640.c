/* Decompiled C draft; module arm9_ov001; ROM address 02199640. No matching claim. */
#include "types.h"
#include "deps/02199640_FUN_02199640.h"

void FUN_02199640(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar2 = func_0x02036bec(param_1,0x90);
  piVar1 = DAT_021997c8;
  *DAT_021997c8 = iVar2;
  *(undefined4 *)(iVar2 + 0x50) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 1;
  FUN_02199464();
  func_0x0212b928(param_1,*(undefined4 *)(*DAT_021997c8 + 0x70),3);
  piVar1 = DAT_021997c8;
  iVar2 = 0;
  puVar5 = DAT_021997cc;
  do {
    func_0x02124a98(*puVar5,1,*(undefined4 *)(*piVar1 + 0x60),*(undefined4 *)(*piVar1 + 0x78));
    puVar5 = puVar5 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  uVar3 = FUN_0219e920();
  uVar4 = FUN_0219e90c();
  func_0x020ae6d4(uVar3,uVar4);
  iVar2 = *DAT_021997c8;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar2 + 0x74),*(undefined4 *)(iVar2 + 0x80),(undefined4 *)(uintptr_t)(iVar2 + 0x54));
  iVar2 = *DAT_021997c8;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar2 + 0x78),*(undefined4 *)(iVar2 + 0x84),(undefined4 *)(uintptr_t)(iVar2 + 0x58));
  uVar3 = func_0x0204799c(DAT_021997d0);
  *(undefined4 *)(*DAT_021997c8 + 0x88) = uVar3;
  uVar3 = func_0x02047a28(DAT_021997d4);
  *(undefined4 *)(*DAT_021997c8 + 0x8c) = uVar3;
  FUN_021997dc();
  piVar1 = DAT_021997c8;
  *(undefined2 *)(*DAT_021997c8 + 0x24) = 0xff74;
  iVar2 = 0;
  iVar6 = 0;
  do {
    if (iVar2 == 2) {
      *(undefined2 *)(*piVar1 + iVar6 + 0x26) = 0;
      *(undefined2 *)(*piVar1 + iVar6 + 0x28) = 0x28;
    }
    else if (iVar2 == 1) {
      *(undefined2 *)(*piVar1 + iVar6 + 0x26) = 0xfa;
      *(undefined2 *)(*piVar1 + iVar6 + 0x28) = 0;
    }
    else {
      *(undefined2 *)(*piVar1 + iVar6 + 0x26) = 0xff06;
      *(undefined2 *)(*piVar1 + iVar6 + 0x28) = 0;
    }
    iVar6 = iVar6 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  FUN_02199374();
  if ((int)((uint)*(byte *)(*(int *)*DAT_021997d8 + 0x31) << 0x1b) < 0) {
    *(undefined4 *)(*DAT_021997c8 + 0x10) = 1;
  }
  else {
    *(undefined4 *)(*DAT_021997c8 + 0x10) = 0;
  }
  piVar1 = DAT_021997c8;
  iVar2 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar6 + 0x14) = *(undefined4 *)(*piVar1 + iVar6 + 0xc);
    iVar6 = iVar6 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  FUN_02198bbc();
  FUN_02198b58();
  piVar1 = DAT_021997c8;
  iVar2 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar6 + 0x40) = 0;
    *(undefined4 *)(*piVar1 + iVar6 + 0x44) = 0;
    iVar6 = iVar6 + 8;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 0x3c) = 1;
  func_0x021281c8(0xe);
  return;
}

