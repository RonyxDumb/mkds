/* Decompiled C draft; module arm9_ov001; ROM address 0219a0e8. No matching claim. */
#include "types.h"
#include "deps/0219a0e8_FUN_0219a0e8.h"

void FUN_0219a0e8(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  piVar1 = DAT_0219a1a0;
  *(undefined4 *)(*DAT_0219a1a0 + 0x30) = *(undefined4 *)(*DAT_0219a1a0 + 0x34);
  switch(*(undefined4 *)(*piVar1 + 0x30)) {
  case 0:
    FUN_0219a938();
    break;
  case 1:
    FUN_0219a80c();
    break;
  case 2:
    FUN_0219a77c();
    break;
  case 3:
    FUN_0219a764();
    break;
  case 4:
    FUN_0219a5bc();
    break;
  case 5:
    FUN_0219a4fc();
    break;
  case 6:
    FUN_0219a3a0();
    break;
  case 7:
    FUN_0219a304();
    break;
  case 8:
    FUN_0219a2ec();
    break;
  case 9:
    FUN_0219a258();
    break;
  case 10:
    FUN_0219a240();
    break;
  case 0xb:
    FUN_0219a1a4();
  }
  puVar3 = (undefined4 *)*DAT_0219a1a0;
  uVar2 = func_0x02111318();
  func_0x02124c30(puVar3[1],*puVar3,puVar3[2],uVar2,puVar3[6]);
  iVar4 = *DAT_0219a1a0;
  uVar2 = func_0x0211130c();
  func_0x02124c30(*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0xc),0,uVar2,
                  *(undefined4 *)(iVar4 + 0x1c));
  return;
}

