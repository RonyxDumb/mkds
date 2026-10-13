/* Decompiled C draft; module arm9_ov001; ROM address 021957a8. No matching claim. */
#include "types.h"
#include "deps/021957a8_FUN_021957a8.h"

void FUN_021957a8(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02195890;
  *(undefined4 *)(*DAT_02195890 + 0x50) = *(undefined4 *)(*DAT_02195890 + 0x54);
  switch(*(undefined4 *)(*piVar1 + 0x50)) {
  case 0:
    FUN_021968bc();
    break;
  case 1:
    FUN_02196724();
    break;
  case 2:
    FUN_02196514();
    break;
  case 3:
    FUN_021963a8();
    break;
  case 4:
    FUN_0219623c();
    break;
  case 5:
    FUN_021960a4();
    break;
  case 6:
    FUN_02196058();
    break;
  case 7:
    FUN_02195ff8();
    break;
  case 8:
    FUN_02195eb8();
    break;
  case 9:
    FUN_02195ea0();
    break;
  case 10:
    FUN_02195e38();
    break;
  case 0xb:
    FUN_02195d64();
    break;
  case 0xc:
    FUN_02195ba4();
    break;
  case 0xd:
    FUN_02195a6c();
    break;
  case 0xe:
    FUN_02195a54();
    break;
  case 0xf:
    FUN_021959d8();
    break;
  case 0x10:
    FUN_021959c0();
    break;
  case 0x11:
    FUN_02195894();
  }
  iVar3 = *DAT_02195890;
  uVar2 = func_0x02111318();
  func_0x02124c30(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x10),uVar2,*(undefined4 *)(iVar3 + 0x38));
  iVar3 = *DAT_02195890;
  uVar2 = func_0x0211130c();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x1c),*(undefined4 *)(iVar3 + 0x18),
                  *(undefined4 *)(iVar3 + 0x24),uVar2,*(undefined4 *)(iVar3 + 0x3c));
  return;
}

