/* Decompiled C draft; module arm9_ov001; ROM address 0219be5c. No matching claim. */
#include "types.h"
#include "deps/0219be5c_FUN_0219be5c.h"

void FUN_0219be5c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  piVar1 = DAT_0219bfb0;
  uVar4 = (uint)*(ushort *)(*(int *)(*DAT_0219bfb0 + 4) + 6);
  **(undefined4 **)(*DAT_0219bfb0 + 0x30) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + 0x80) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + DAT_0219bfb4) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + 0xc0) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + DAT_0219bfb8) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + uVar4 * 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + (uVar4 + 1) * 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + (uVar4 + 2) * 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + (uVar4 + 3) * 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + (uVar4 + 4) * 0x40) = 1;
  *(undefined4 *)(*(int *)(*piVar1 + 0x30) + (uVar4 + 5) * 0x40) = 1;
  puVar5 = (undefined4 *)*piVar1;
  iVar2 = func_0x0202968c();
  func_0x0211de00(*(undefined4 *)(DAT_0219bfbc + iVar2 * 4),*puVar5,puVar5[1],0,0);
  puVar5 = (undefined4 *)*DAT_0219bfb0;
  iVar2 = func_0x0202968c();
  uVar3 = func_0x02124a68(5,*puVar5,puVar5[1]);
  func_0x0211ded0(*(undefined4 *)(DAT_0219bfbc + iVar2 * 4),*puVar5,puVar5[1],5,uVar3,0);
  iVar2 = *DAT_0219bfb0;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),0x73);
  func_0x0212426c(0,2,*(undefined4 *)(*DAT_0219bfb0 + 8),uVar3,*(undefined4 *)(iVar2 + 4),
                  *(undefined4 *)(iVar2 + 0x30));
  iVar2 = *DAT_0219bfb0;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),0x74);
  func_0x0212426c(0,4,*(undefined4 *)(*DAT_0219bfb0 + 8),uVar3,*(undefined4 *)(iVar2 + 4),
                  *(undefined4 *)(iVar2 + 0x30));
  iVar2 = *DAT_0219bfb0;
  func_0x02124140(0,0,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 4));
  iVar2 = *DAT_0219bfb0;
  func_0x02124140(1,0,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 4));
  iVar2 = *DAT_0219bfb0;
  func_0x02124140(2,0,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 4));
  iVar2 = *DAT_0219bfb0;
  func_0x02124140(4,0,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 4));
  return;
}

