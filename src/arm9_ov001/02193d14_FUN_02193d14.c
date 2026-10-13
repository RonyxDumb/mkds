/* Decompiled C draft; module arm9_ov001; ROM address 02193d14. No matching claim. */
#include "types.h"
#include "deps/02193d14_FUN_02193d14.h"

void FUN_02193d14(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02193da4;
  *(undefined4 *)(*DAT_02193da4 + 0x60) = *(undefined4 *)(*DAT_02193da4 + 100);
  switch(*(undefined4 *)(*piVar1 + 0x60)) {
  case 0:
    FUN_02194690();
    break;
  case 1:
    FUN_021944e0();
    break;
  case 2:
    FUN_021942f8();
    break;
  case 3:
    FUN_02194148();
    break;
  case 4:
    FUN_02193f98();
    break;
  case 5:
    FUN_02193dec();
    break;
  case 6:
    FUN_02193da8();
  }
  iVar3 = *DAT_02193da4;
  uVar2 = func_0x02111318();
  func_0x02124c30(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x10),uVar2,*(undefined4 *)(iVar3 + 0x50));
  iVar3 = *DAT_02193da4;
  uVar2 = func_0x0211130c();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x1c),*(undefined4 *)(iVar3 + 0x18),
                  *(undefined4 *)(iVar3 + 0x24),uVar2,*(undefined4 *)(iVar3 + 0x54));
  return;
}

