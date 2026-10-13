/* Decompiled C draft; module arm9_ov000; ROM address 021aaf38. No matching claim. */
#include "types.h"
#include "deps/021aaf38_FUN_021aaf38.h"

undefined4 FUN_021aaf38(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  
  if ((((*(int *)(param_1 + DAT_021ab07c) == 0) || (*(int *)(param_1 + DAT_021ab080) == 0)) ||
      (*(int *)(param_2 + 0x10) == 0)) ||
     (((*(int *)(param_2 + 0xc) == 0 || (*(int *)(param_2 + 8) == 0)) ||
      (*(int *)(param_2 + 4) == 0)))) {
    return 2;
  }
  iVar1 = func_0x02133068(*(int *)(param_2 + 4) << 1,2);
  iVar2 = (*(code *)*DAT_021ab084)(iVar1 << 3);
  if (iVar2 == 0) {
    return 2;
  }
  iVar7 = iVar1 * 2;
  pcVar8 = (char *)(iVar2 + iVar7);
  pcVar3 = pcVar8 + iVar7;
  pcVar4 = pcVar3 + iVar7;
  FUN_021ac4b8(pcVar8,*(undefined4 *)(param_1 + DAT_021ab07c),
               *(undefined4 *)(param_1 + DAT_021ab080),iVar1);
  FUN_021ac4b8(pcVar3,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0xc),iVar1);
  FUN_021ac4b8(pcVar4,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),iVar1);
  if (*DAT_021ab088 < 0x20) {
    uVar5 = *(undefined4 *)(DAT_021ab08c + 4);
    uVar6 = func_0x0200dcd8();
    func_0x0200dce0(uVar5,*DAT_021ab088);
    FUN_021ac7e8(iVar2,pcVar8,pcVar3,iVar1,pcVar4);
    func_0x0200dce0(uVar5,uVar6);
  }
  else {
    FUN_021ac7e8(iVar2,pcVar8,pcVar3,iVar1,pcVar4);
  }
  FUN_021ac488(pcVar8,iVar2,*(undefined4 *)(param_2 + 4),iVar1);
  uVar5 = 0;
  if ((*pcVar8 == '\0') && (pcVar8[1] == '\x01')) {
    iVar1 = 2;
    iVar7 = *(int *)(param_2 + 4);
    if (2 < iVar7) {
      do {
        if (pcVar8[iVar1] != -1) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar7);
    }
    if ((((iVar7 <= iVar1 + 1) || (pcVar8[iVar1] != '\0')) || (pcVar8[iVar1 + 1] != '0')) ||
       (iVar1 = func_0x02134d30(param_1 + DAT_021ab094,
                                pcVar8 + (iVar7 - *(int *)(param_1 + DAT_021ab090))), iVar1 != 0)) {
      uVar5 = 2;
    }
  }
  else {
    uVar5 = 2;
  }
  (*(code *)*DAT_021ab098)(iVar2);
  return uVar5;
}

