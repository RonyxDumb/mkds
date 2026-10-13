/* Decompiled C draft; module arm9_ov000; ROM address 02183a0c. No matching claim. */
#include "types.h"
#include "deps/02183a0c_FUN_02183a0c.h"

void FUN_02183a0c(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int local_20;
  int local_1c;
  
  iVar5 = *(int *)(*DAT_02183b54 + 8);
  uVar2 = func_0x02133068(iVar5 << 0x10,0x14);
  iVar5 = func_0x02133068(DAT_02183b58 * (0x13 - iVar5),0x14);
  iVar7 = 0;
  pbVar6 = DAT_02183b5c;
  do {
    func_0x02124b1c(*(int *)(*DAT_02183b54 + DAT_02183b60) + (uint)*pbVar6 * 0x40,uVar2,iVar5 + 0xcd
                   );
    piVar1 = DAT_02183b54;
    pbVar6 = pbVar6 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 3);
  *(int *)(*DAT_02183b54 + 8) = *(int *)(*DAT_02183b54 + 8) + 1;
  if ((0x13 < *(int *)(*piVar1 + 8)) && (iVar5 = func_0x02125f88(), iVar5 != 0)) {
    iVar7 = func_0x02077f00();
    iVar5 = DAT_02183b60;
    piVar1 = DAT_02183b54;
    iVar4 = 0;
    pbVar6 = DAT_02183b5c;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + iVar5) + (uint)*pbVar6 * 0x40) = 0;
      pbVar6 = pbVar6 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    FUN_021840c8();
    iVar4 = 0;
    iVar5 = *DAT_02183b54;
    if (0 < *(int *)(iVar5 + 0x30)) {
      local_20 = 0;
      local_1c = 0;
      pbVar6 = DAT_02183b5c;
      pbVar8 = DAT_02183b64;
      do {
        if (*(int *)(iVar5 + local_20 + DAT_02183b68) != 0) {
          iVar9 = *DAT_02183b54;
          iVar5 = func_0x0212497c(*pbVar6,*(undefined4 *)(iVar9 + DAT_02183b6c),
                                  *(undefined4 *)(iVar9 + DAT_02183b70));
          func_0x02016468(0x23,iVar5 << 5,iVar9 + DAT_02183b74 + local_1c,DAT_02183b78);
          func_0x02016468(0x1e,(iVar4 + 3) * 0x20,*(undefined4 *)(iVar7 + 0xc),0x20);
        }
        *(undefined4 *)
         (*(int *)(*DAT_02183b54 + DAT_02183b60) +
         ((uint)*pbVar8 + (uint)*(ushort *)(*(int *)(*DAT_02183b54 + DAT_02183b70) + 6)) * 0x40) = 0
        ;
        local_20 = local_20 + 4;
        local_1c = local_1c + DAT_02183b78;
        pbVar6 = pbVar6 + 1;
        pbVar8 = pbVar8 + 1;
        iVar4 = iVar4 + 1;
        iVar5 = *DAT_02183b54;
      } while (iVar4 < *(int *)(iVar5 + 0x30));
    }
    uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar5 + DAT_02183b7c),0xb);
    func_0x02126638(uVar3,0,0,1,0,0,0);
    piVar1 = DAT_02183b54;
    *(undefined4 *)(*DAT_02183b54 + 4) = 3;
    *(undefined4 *)(*piVar1 + 8) = 0;
  }
  return;
}

