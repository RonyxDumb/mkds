/* Decompiled C draft; module arm9; ROM address 021464a4. No matching claim. */
#include "types.h"
#include "deps/021464a4_StructSZ_SomeFn.h"

int StructSZ_SomeFn(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar3 = iRam021465ec;
  iVar8 = 0;
  uVar9 = iRam021465ec + 0x20U & 3;
  uVar10 = *(uint *)(iRam021465ec + 0x20U & 0xfffffffc);
  uVar11 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  bVar2 = false;
  bVar1 = false;
  uVar9 = iRam021465ec + 0x24U & 3;
  uVar10 = *(uint *)(iRam021465ec + 0x24U & 0xfffffffc);
  uVar9 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  if (((uVar11 & 3) == 0) &&
     (uVar10 = iRam021465ec + 0x28U & 3, uVar4 = *(uint *)(iRam021465ec + 0x28U & 0xfffffffc),
     (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) < 4)) {
    uVar10 = GetDtcmStartAddress();
    bVar7 = true;
    bVar6 = false;
    if ((uRam021465f0 < uVar11 + uVar9) && (uVar11 < 0x2000000)) {
      bVar6 = true;
    }
    if ((!bVar6) && ((uVar11 + uVar9 <= uVar10 || (uVar10 + 0x4000 <= uVar11)))) {
      bVar7 = false;
    }
    if (!bVar7) {
      bVar1 = true;
    }
  }
  if ((bVar1) &&
     (uVar10 = iVar3 + 0x1cU & 3, uVar4 = *(uint *)(iVar3 + 0x1cU & 0xfffffffc),
     ((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20 | uVar9) & uRam021465f4) == 0)) {
    bVar2 = true;
  }
  if ((bVar2) && (uVar9 != 0)) {
    iVar8 = 1;
  }
  *(uint *)(param_1 + 4) =
       (*(uint *)(uRam021465f8 & 0xfffffffc) >> (uRam021465f8 & 3) * 8 |
       *(uint *)(uRam021465f8 & 0xfffffffc) << (uRam021465f8 & 3) * -8 + 0x20) & 0xf8ffffff |
       0xa1000000;
  if (iVar8 != 0) {
    uVar5 = Os_DisableIrq();
    IC_InvalidateRangeNoClean(uVar11,uVar9);
    if ((uVar11 & 0x1f) != 0) {
      uVar11 = uVar11 - (uVar11 & 0x1f);
      DC_SomeClean(uVar11,0x20);
      DC_SomeClean(uVar11 + uVar9,0x20);
      uVar9 = uVar9 + 0x20;
    }
    DC_InvalidateRangeNoClean(uVar11,uVar9);
    Mem_DcDrainWriteBuffer();
    Os_SetIrqHandler(0x80000,uRam021465fc);
    SetIF(0x80000);
    Os_EnableIrqHandler(0x80000);
    Os_RestoreIrq(uVar5);
    MaybeGamecardTransferSY();
  }
  return iVar8;
}

