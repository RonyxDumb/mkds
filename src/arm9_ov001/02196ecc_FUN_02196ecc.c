/* Decompiled C draft; module arm9_ov001; ROM address 02196ecc. No matching claim. */
#include "types.h"
#include "deps/02196ecc_FUN_02196ecc.h"

void FUN_02196ecc(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_20e [514];
  
  piVar1 = DAT_02196f58;
  *(undefined4 *)(*DAT_02196f58 + 0x54) = 9;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  func_0x0214cfe4(0,(int)(uintptr_t)(auStack_20e),DAT_02196f5c);
  iVar4 = *DAT_02196f58;
  uVar2 = func_0x020b3f7c(*(undefined4 *)(iVar4 + 0x44),
                          *(undefined4 *)(DAT_02196f60 + *(int *)(iVar4 + 0x6c) * 4));
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar4 + 0x48),10);
  func_0x0212513c(uVar2,uVar3,auStack_20e,DAT_02196f5c);
  uVar2 = func_0x020b3f7c(*(undefined4 *)(*DAT_02196f58 + 0x40),0);
  uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_02196f58 + 0x40),1);
  func_0x02125fd4((undefined4)(uintptr_t)(auStack_20e),uVar2,uVar3,1,0,1,1,1);
  return;
}

