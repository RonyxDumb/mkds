/* Decompiled C draft; module arm9_ov003; ROM address 021cd790. No matching claim. */
#include "types.h"
#include "deps/021cd790_FUN_021cd790.h"

void FUN_021cd790(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar3 = *DAT_021cd828;
  puVar4 = (undefined1 *)(iVar3 + param_1 * 0x100);
  puVar6 = (undefined1 *)(iVar3 + DAT_021cd82c);
  iVar5 = 0xf0;
  puVar2 = puVar4;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(char *)(iVar3 + DAT_021cd830) = (char)param_1;
  iVar3 = func_0x02134d30((uint)(uintptr_t)(puVar4 + 0xc0),DAT_021cd834,4);
  if (iVar3 == 0) {
    *(undefined1 *)(*DAT_021cd828 + DAT_021cd838) = 1;
  }
  else {
    *(undefined1 *)(*DAT_021cd828 + DAT_021cd838) = 0;
  }
  iVar3 = func_0x02134d30((uint)(uintptr_t)(puVar4 + 200),DAT_021cd834,4);
  if ((iVar3 == 0) && (iVar3 = func_0x02134d30((uint)(uintptr_t)(puVar4 + 0xcc),DAT_021cd834,4), iVar3 == 0)) {
    *(undefined1 *)(*DAT_021cd828 + DAT_021cd83c) = 1;
  }
  else {
    *(undefined1 *)(*DAT_021cd828 + DAT_021cd83c) = 0;
  }
  func_0x021516b0(puVar4[0xd0],*DAT_021cd828 + DAT_021cd840);
  return;
}

