/* Decompiled C draft; module arm9_ov000; ROM address 02180cdc. No matching claim. */
#include "types.h"
#include "deps/02180cdc_FUN_02180cdc.h"

void FUN_02180cdc(void)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = func_0x02125fa4();
  if ((iVar3 != 0) && (iVar3 = func_0x02128294(), iVar3 != 0)) {
    if ((*(ushort *)(DAT_02180d78 + 0x2e0) & 2) == 0) {
      bVar2 = false;
      bVar4 = false;
      if ((*(short *)(DAT_02180d7c + 0x2e0) == 0) && (*(ushort *)(DAT_02180d80 + 0x2e0) < 5)) {
        bVar4 = true;
      }
      if (((!bVar4) && (*(short *)(DAT_02180d84 + 0x2e0) == 0)) &&
         (*(short *)(DAT_02180d7c + 0x2e0) != 0)) {
        bVar2 = true;
      }
      if ((!bVar2) ||
         (iVar3 = func_0x02128210(*(undefined2 *)(DAT_02180d88 + 0x2e0),
                                  *(undefined2 *)(DAT_02180d8c + 0x2e0)), iVar3 == 0))
      goto LAB_02180d50;
    }
    func_0x02128310(0);
    func_0x02125fc0();
    return;
  }
LAB_02180d50:
  iVar3 = func_0x02125f88();
  if ((iVar3 != 0) && (iVar3 = func_0x02128294(), piVar1 = DAT_02180d90, iVar3 != 0)) {
    *(undefined4 *)(*DAT_02180d90 + 0xc) = 1;
    func_ov000_021806e0(*(undefined4 *)(*piVar1 + 0xc));
  }
  return;
}

