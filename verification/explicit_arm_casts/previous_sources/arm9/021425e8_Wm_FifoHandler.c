/* Decompiled C draft; module arm9; ROM address 021425e8. No matching claim. */
#include "types.h"
#include "deps/021425e8_Wm_FifoHandler.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void Wm_FifoHandler(undefined4 param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  ushort *unaff_r4;
  ushort *unaff_r5;
  ushort unaff_r6;
  ushort *unaff_r7;
  uint unaff_r8;
  
  if (param_3 != 0) {
    return;
  }
  uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
          *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 0x10;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  DC_InvalidateRangeNoClean(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20,0x100);
  uVar6 = *(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
          *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20;
  if (*(short *)(uVar6 + 0x16) == 0) {
    uVar6 = uVar6 + 4;
    uVar9 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    DC_InvalidateRangeNoClean(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20,0x800);
  }
  uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
          *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 0x10;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (param_2 != (ushort *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) {
    DC_InvalidateRangeNoClean(param_2,0x100);
  }
  uVar6 = uRam0214296c;
  uVar2 = *param_2;
  if (uVar2 < 0x2a) {
    if (((uVar2 == 0xe) && (((uint)param_2[2] + iRam02142970 & 0xffff) < 2)) && (param_2[1] == 0)) {
      uVar9 = (uint)(param_2 + 4) & 3;
      uVar7 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
      uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
              *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 4;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      DC_InvalidateRangeNoClean
                (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20,
                 *(undefined2 *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x46));
    }
    if ((*param_2 == 2) && (param_2[1] == 0)) {
      uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
              *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 0x20;
      uVar9 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      pcVar8 = (code *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
      func_02142c24();
      if (pcVar8 == (code *)0x0) {
        return;
      }
      (*pcVar8)(param_2);
      return;
    }
    uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
            *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) +
            (uint)*param_2 * 4 + 0x18;
    uVar9 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    pcVar8 = (code *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
    if ((pcVar8 != (code *)0x0) && ((*pcVar8)(param_2), *psRam02142974 == 0)) {
      return;
    }
    uVar5 = uRam02142980;
    puVar4 = puRam02142978;
    uVar2 = *param_2;
    if ((uVar2 == 8) || (uVar2 == 0xc)) {
      if (uVar2 == 8) {
        unaff_r5 = param_2 + 5;
        unaff_r4 = param_2 + 10;
        unaff_r8 = (uint)param_2[4];
        unaff_r6 = 0;
        unaff_r7 = (ushort *)(uint)param_2[8];
      }
      else if (uVar2 == 0xc) {
        unaff_r4 = (ushort *)0x0;
        unaff_r8 = (uint)param_2[4];
        unaff_r6 = param_2[8];
        unaff_r5 = param_2 + 5;
        unaff_r7 = unaff_r4;
      }
      if ((unaff_r8 == 7) || (unaff_r8 == 9)) {
        uVar3 = (undefined2)uRam0214297c;
        *puRam02142978 = 0x82;
        puVar4[1] = 0;
        puVar4[2] = (short)unaff_r8;
        *(undefined4 *)(puVar4 + 4) = 0;
        *(undefined4 *)(puVar4 + 6) = 0;
        puVar4[8] = 0;
        puVar4[9] = (short)unaff_r7;
        puVar4[0x10] = unaff_r6;
        puVar4[0xd] = uVar3;
        Mem_CpuCopy8(unaff_r5,uVar5,6);
        if (unaff_r4 == (ushort *)0x0) {
          Mem_CpuFill16(0,uRam02142984,0x18);
        }
        else {
          CopyMemory16(unaff_r4,uRam02142984,0x18);
        }
        puVar4 = puRam02142978;
        uVar9 = uRam0214296c;
        uVar6 = 0;
        do {
          uVar1 = uVar9 & 3;
          uVar7 = *(uint *)(uVar9 & 0xfffffffc);
          puVar4[3] = (short)uVar6;
          iVar10 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) + uVar6 * 4;
          uVar1 = iVar10 + 0xc4U & 3;
          uVar7 = *(uint *)(iVar10 + 0xc4U & 0xfffffffc);
          if (uVar7 >> uVar1 * 8 != 0 || uVar7 << uVar1 * -8 + 0x20 != 0) {
            uVar1 = iVar10 + 0x104U & 3;
            uVar7 = *(uint *)(iVar10 + 0x104U & 0xfffffffc);
            *(uint *)(puVar4 + 0xe) = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
            uVar1 = iVar10 + 0xc4U & 3;
            uVar7 = *(uint *)(iVar10 + 0xc4U & 0xfffffffc);
            (*(code *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20))(puVar4);
          }
          uVar6 = uVar6 + 1 & 0xffff;
        } while (uVar6 < 0x10);
      }
    }
  }
  else if (uVar2 == 0x80) {
    if (param_2[1] == 0x13) {
      Os_Terminate();
    }
    uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
            *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 0xc0;
    uVar9 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    pcVar8 = (code *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
    if (pcVar8 != (code *)0x0) {
      (*pcVar8)(param_2);
    }
  }
  else if (uVar2 == 0x82) {
    iVar10 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
             *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) +
             (uint)param_2[3] * 4;
    uVar9 = iVar10 + 0xc4;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if (uVar9 >> uVar1 * 8 != 0 || uVar9 << uVar1 * -8 + 0x20 != 0) {
      uVar9 = iVar10 + 0x104;
      uVar1 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      *(uint *)(param_2 + 0xe) = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar9 = (uint)(param_2 + 4) & 3;
      uVar7 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
      uVar6 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 4;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      DC_InvalidateRangeNoClean
                (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20,
                 *(undefined2 *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x46));
      uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
              *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) +
              (uint)param_2[3] * 4 + 0xc4;
      uVar9 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      (*(code *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20))(param_2);
    }
  }
  else if (uVar2 == 0x81) {
    *param_2 = 0xf;
    uVar6 = (uint)(param_2 + 0xe) & 3;
    uVar9 = *(uint *)((uint)(param_2 + 0xe) & 0xfffffffc);
    pcVar8 = (code *)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20);
    if (pcVar8 != (code *)0x0) {
      (*pcVar8)(param_2);
    }
  }
  uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
          *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 0x10;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  DC_InvalidateRangeNoClean(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20,0x100);
  Wm_DisableCallbackControl();
  uVar6 = (*(uint *)(uRam0214296c & 0xfffffffc) >> (uRam0214296c & 3) * 8 |
          *(uint *)(uRam0214296c & 0xfffffffc) << (uRam0214296c & 3) * -8 + 0x20) + 0x10;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (param_2 == (ushort *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) {
    return;
  }
  *param_2 = *param_2 | 0x8000;
  DC_SomeClean(param_2,0x100);
  return;
}

