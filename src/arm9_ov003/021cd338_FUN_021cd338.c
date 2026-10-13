/* Decompiled C draft; module arm9_ov003; ROM address 021cd338. No matching claim. */
#include "types.h"
#include "deps/021cd338_FUN_021cd338.h"

/* WARNING: Type propagation algorithm not settling */

void FUN_021cd338(uint param_1)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  bool bVar10;
  int local_28 [5];
  
  piVar9 = local_28;
  cVar1 = *(char *)(*DAT_021cd41c + param_1 * 0x100 + 0xe7);
  uVar7 = 1 << (param_1 & 0xff);
  func_0x0214d168(local_28 + 1,0,0x10);
  local_28[param_1 + 1] = 1;
  if ((int)param_1 < 3) {
    iVar5 = *DAT_021cd41c;
    bVar10 = (*(byte *)(iVar5 + 0xef) & uVar7) == 0;
    bVar2 = (byte)uVar7;
    if ((cVar1 != -1) || (bVar10)) {
      if ((cVar1 != -1) && (bVar10)) {
        *(byte *)(iVar5 + 0xef) = *(byte *)(iVar5 + 0xef) | bVar2;
        *(byte *)(*DAT_021cd41c + DAT_021cd420) = *(byte *)(*DAT_021cd41c + DAT_021cd420) | bVar2;
        local_28[2] = 1;
        local_28[1] = 1;
      }
    }
    else {
      *(byte *)(iVar5 + 0xef) = *(byte *)(iVar5 + 0xef) & ~bVar2;
      *(byte *)(*DAT_021cd41c + DAT_021cd420) = *(byte *)(*DAT_021cd41c + DAT_021cd420) & ~bVar2;
      local_28[2] = 1;
      local_28[1] = 1;
    }
  }
  piVar3 = DAT_021cd41c;
  iVar8 = 0;
  iVar5 = 0;
  do {
    piVar9 = piVar9 + 1;
    if (*piVar9 != 0) {
      iVar6 = *piVar3;
      uVar4 = func_0x020205e8(iVar6 + DAT_021cd424,iVar6 + iVar5,0xfe);
      *(undefined2 *)(*piVar3 + iVar5 + 0xfe) = uVar4;
    }
    iVar5 = iVar5 + DAT_021cd428;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 4);
  local_28[0] = FUN_021d285c(DAT_021cd428,0x20);
  func_0x02151794(*DAT_021cd41c,local_28 + 1);
  FUN_021d2808(local_28);
  return;
}

