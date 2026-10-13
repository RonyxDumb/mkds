/* Decompiled C draft; module arm9; ROM address 0202b100. No matching claim. */
#include "types.h"
#include "deps/0202b100_func_0202b100.h"

void func_0202b100(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  short *psVar9;
  int local_3c;
  int local_38;
  ushort *local_34;
  int local_30;
  
  iVar3 = *piRam0202b250;
  uVar7 = (uint)*(ushort *)(*(int *)(iVar3 + 0x54) + 6);
  uVar8 = 0;
  if (0 < *(int *)(iVar3 + 0xb8)) {
    local_3c = 0;
    local_38 = 0;
    local_34 = puRam0202b258;
    local_30 = 0;
    iVar5 = iVar3;
    psVar9 = psRam0202b254;
    do {
      func_02025edc(iVar5 + 0xfc + local_3c);
      iVar4 = func_02122734(uVar8 & 0xff);
      iVar5 = local_30;
      if (-1 < iVar4) {
        uVar1 = func_02122734(uVar8 & 0xff);
        iVar5 = func_02121e24(uVar1);
      }
      iVar4 = *(int *)(*piRam0202b250 + 0xac);
      if ((((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) &&
         ((iVar5 != 0 && (iVar5 != *(int *)(*piRam0202b250 + local_38 + 0xbc))))) {
        uVar6 = GetBmgIndexFromCircuitIndex_from_thumb(iVar5);
        uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202b250 + 0x88),uVar6);
        func_0212426c(0,(int)*psVar9,*(undefined4 *)(iVar3 + 0x5c),uVar6,
                      *(undefined4 *)(iVar3 + 0x54),*(undefined4 *)(iVar3 + 0x60));
        *(int *)(*piRam0202b250 + local_38 + 0xbc) = iVar5;
        func_02025f14(*piRam0202b250 + 0xfc + local_3c,0);
        if (*(uint *)(*piRam0202b250 + 0xb4) != uVar8) {
          NNSi_MaybeSndPlayerStartSeq(uRam0202b25c,0,uRam0202b260);
        }
      }
      uVar2 = func_02025ebc(*piRam0202b250 + 0xfc + local_3c);
      *(undefined2 *)(*(int *)(iVar3 + 0x60) + (uVar7 + (int)*psVar9) * 0x40 + 4) = uVar2;
      *(undefined2 *)(*(int *)(iVar3 + 0x60) + (uint)*local_34 * 0x40 + 4) =
           *(undefined2 *)(*(int *)(iVar3 + 0x60) + (uVar7 + (int)*psVar9) * 0x40 + 4);
      local_3c = local_3c + 0x10;
      local_38 = local_38 + 4;
      psVar9 = psVar9 + 4;
      local_34 = local_34 + 1;
      uVar8 = uVar8 + 1;
      iVar5 = *piRam0202b250;
    } while ((int)uVar8 < *(int *)(iVar5 + 0xb8));
  }
  return;
}

