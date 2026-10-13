/* Decompiled C draft; module arm9_ov003; ROM address 021cd9dc. No matching claim. */
#include "types.h"
#include "deps/021cd9dc_FUN_021cd9dc.h"

void FUN_021cd9dc(int param_1)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  func_0x0214d168((uint *)(uintptr_t)(*DAT_021cdb08 + DAT_021cdb0c),0,0x10);
  iVar4 = FUN_021d3254(param_1,0x20);
  piVar1 = DAT_021cdb08;
  if (iVar4 < 0xb) {
    if ((9 < iVar4) || (iVar4 == 0)) goto LAB_021cda18;
LAB_021cda56:
    *(byte *)(*DAT_021cdb08 + DAT_021cdb10) = *(byte *)(*DAT_021cdb08 + DAT_021cdb10) & 3 | 4;
    func_0x0214d1fc((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(*piVar1 + DAT_021cdb0c),0x10);
  }
  else {
    if (0x1a < iVar4) {
      if (iVar4 == 0x20) goto LAB_021cda18;
      goto LAB_021cda56;
    }
    if (iVar4 != 0x1a) goto LAB_021cda56;
LAB_021cda18:
    *(byte *)(*DAT_021cdb08 + DAT_021cdb10) = *(byte *)(*DAT_021cdb08 + DAT_021cdb10) & 3;
    pcVar6 = (char *)(*piVar1 + DAT_021cdb0c);
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        cVar2 = FUN_021cd2cc(*(undefined1 *)(param_1 + iVar5));
        cVar3 = FUN_021cd2cc(*(undefined1 *)(param_1 + iVar5 + 1));
        *pcVar6 = cVar2 * '\x10' + cVar3;
        iVar5 = iVar5 + 2;
        pcVar6 = pcVar6 + 1;
      } while (iVar5 < iVar4);
    }
  }
  if (iVar4 < 6) {
    if (4 < iVar4) {
LAB_021cdab6:
      *(byte *)(*DAT_021cdb08 + DAT_021cdb10) = *(byte *)(*DAT_021cdb08 + DAT_021cdb10) & 0xfc | 1;
      return;
    }
    if (iVar4 == 0) {
      *(byte *)(*DAT_021cdb08 + DAT_021cdb10) = *(byte *)(*DAT_021cdb08 + DAT_021cdb10) & 0xfc;
      return;
    }
  }
  else if (iVar4 < 0xe) {
    if (9 < iVar4) {
      if (iVar4 == 10) goto LAB_021cdab6;
      if (iVar4 == 0xd) goto LAB_021cdad2;
    }
  }
  else if (iVar4 == 0x1a) {
LAB_021cdad2:
    *(byte *)(*DAT_021cdb08 + DAT_021cdb10) = *(byte *)(*DAT_021cdb08 + DAT_021cdb10) & 0xfc | 2;
    return;
  }
  *(byte *)(*DAT_021cdb08 + DAT_021cdb10) = *(byte *)(*DAT_021cdb08 + DAT_021cdb10) & 0xfc | 3;
  return;
}

