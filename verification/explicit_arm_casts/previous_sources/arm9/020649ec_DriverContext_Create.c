/* Decompiled C draft; module arm9; ROM address 020649ec. No matching claim. */
#include "types.h"
#include "deps/020649ec_DriverContext_Create.h"

void DriverContext_Create(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  bool bVar16;
  
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  uVar10 = (uint)*(ushort *)(param_1 + 0x74) * 0x30 +
           (*(uint *)(uRam02064d14 & 0xfffffffc) >> (uRam02064d14 & 3) * 8 |
           *(uint *)(uRam02064d14 & 0xfffffffc) << (uRam02064d14 & 3) * -8 + 0x20) + 0x70;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  bVar16 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) != 3;
  uVar7 = GetCharacterKart();
  *(undefined4 *)(param_1 + 0x590) = uVar7;
  uVar10 = param_1 + 0x590U & 3;
  uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  LightInfo_SomeFn((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x40,1);
  uVar6 = uRam02064d34;
  uVar15 = uRam02064d30;
  uVar5 = uRam02064d2c;
  uVar4 = uRam02064d28;
  uVar3 = uRam02064d24;
  uVar2 = uRam02064d20;
  uVar1 = uRam02064d1c;
  uVar7 = uRam02064d18;
  uVar10 = (*(uint *)(uRam02064d14 & 0xfffffffc) >> (uRam02064d14 & 3) * 8 |
           *(uint *)(uRam02064d14 & 0xfffffffc) << (uRam02064d14 & 3) * -8 + 0x20) + 8;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) == 5) {
    uVar10 = 0;
    do {
      if (uVar10 == 3) {
        uVar15 = uVar1;
        if (bVar16) {
          uVar15 = uVar7;
        }
        *(undefined4 *)(param_1 + 0x218) = uVar15;
      }
      else if (uVar10 == 4) {
        uVar15 = uVar3;
        if (bVar16) {
          uVar15 = uVar2;
        }
        *(undefined4 *)(param_1 + 0x21c) = uVar15;
      }
      else if (uVar10 == 5) {
        uVar15 = uVar5;
        if (bVar16) {
          uVar15 = uVar4;
        }
        *(undefined4 *)(param_1 + 0x220) = uVar15;
      }
      else {
        *(uint *)(param_1 + uVar10 * 4 + 0x20c) =
             *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
      }
      uVar10 = uVar10 + 1 & 0xffff;
      param_2 = param_2 + 4;
    } while (uVar10 < 9);
  }
  else {
    uVar10 = 0;
    do {
      if (uVar10 == 3) {
        *(undefined4 *)(param_1 + 0x218) = uVar6;
      }
      else if (uVar10 == 4) {
        *(undefined4 *)(param_1 + 0x21c) = uVar15;
      }
      else if (uVar10 == 5) {
        *(undefined4 *)(param_1 + 0x220) = uVar4;
      }
      else {
        *(uint *)(param_1 + uVar10 * 4 + 0x20c) =
             *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
      }
      uVar10 = uVar10 + 1 & 0xffff;
      param_2 = param_2 + 4;
    } while (uVar10 < 9);
  }
  *(undefined4 *)(param_1 + 0x514) = 0;
  uVar10 = param_1 + 0x210U & 3;
  uVar8 = *(uint *)(param_1 + 0x210U & 0xfffffffc);
  pcVar11 = (code *)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20);
  if (pcVar11 != (code *)0x0) {
    (*pcVar11)(param_1);
  }
  *(int *)(param_1 + 0x508) = param_1 + 0x80;
  *(int *)(param_1 + 0x50c) = param_1 + 0x110;
  *(int *)(param_1 + 0x510) = param_1 + 0x80;
  uVar10 = param_1 + 0x20cU & 3;
  uVar8 = *(uint *)(param_1 + 0x20cU & 0xfffffffc);
  pcVar11 = (code *)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20);
  if (pcVar11 != (code *)0x0) {
    (*pcVar11)(param_1);
  }
  uVar10 = (*(uint *)(uRam02064d14 & 0xfffffffc) >> (uRam02064d14 & 3) * 8 |
           *(uint *)(uRam02064d14 & 0xfffffffc) << (uRam02064d14 & 3) * -8 + 0x20) + 0xc;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if (((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) == 2) ||
     (uVar10 = param_1 + 0x7cU & 3, uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 1) == 0)) {
    *(undefined4 *)(param_1 + 0x214) = uRam02064d38;
  }
  else {
    *(undefined4 *)(param_1 + 0x214) = uRam02064d3c;
  }
  uVar10 = (*(uint *)(uRam02064d14 & 0xfffffffc) >> (uRam02064d14 & 3) * 8 |
           *(uint *)(uRam02064d14 & 0xfffffffc) << (uRam02064d14 & 3) * -8 + 0x20) + 8;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) == 5) {
    if (bVar16) {
      *(int *)(param_1 + 0x508) = param_1 + 0x80;
      *(int *)(param_1 + 0x50c) = param_1 + 0x110;
      *(int *)(param_1 + 0x510) = param_1 + 0x80;
    }
    else {
      uVar10 = param_1 + 0x514U & 3;
      uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      *(uint *)(param_1 + 0x508) = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x10;
      uVar10 = param_1 + 0x514U & 3;
      uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      *(uint *)(param_1 + 0x50c) = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x4c;
      uVar10 = param_1 + 0x514U & 3;
      uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      *(uint *)(param_1 + 0x510) = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
    }
  }
  else {
    *(int *)(param_1 + 0x508) = param_1 + 0x80;
    *(int *)(param_1 + 0x50c) = param_1 + 0x110;
    *(int *)(param_1 + 0x510) = param_1 + 0x80;
  }
  uVar10 = param_1 + 0x508U & 3;
  uVar8 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
  *(uint *)(param_1 + 0x534) = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
  StructMQRacerEntry_MaybeInitializePosition(param_1,0);
  iVar9 = IsNotStaffRoll();
  uVar7 = uRam02064d40;
  if ((iVar9 != 0) &&
     (uVar10 = (*(uint *)(uRam02064d14 & 0xfffffffc) >> (uRam02064d14 & 3) * 8 |
               *(uint *)(uRam02064d14 & 0xfffffffc) << (uRam02064d14 & 3) * -8 + 0x20) + 0xc,
     uVar8 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
     (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) != 5)) {
    *(undefined4 *)(param_1 + 0x218) = uRam02064d40;
    *(undefined4 *)(param_1 + 0x21c) = uVar7;
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x174);
    *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x178);
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x17c);
    uVar10 = param_1 + 0x174U & 3;
    uVar8 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    *(int *)(param_1 + 0x174) = (int)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) >> 4;
    uVar10 = param_1 + 0x178U & 3;
    uVar8 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
    *(int *)(param_1 + 0x178) = (int)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) >> 4;
    uVar10 = param_1 + 0x17cU & 3;
    uVar8 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
    *(int *)(param_1 + 0x17c) = (int)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) >> 4;
    uVar10 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x10) != 0) {
      StructMQRacerEntry_SomeFn_20(param_1);
      uVar10 = param_1 + 0x590U & 3;
      uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      uVar10 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 8;
      uVar8 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar13 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
      uVar10 = uVar13 + 0x1c & 3;
      uVar12 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
      uVar8 = uVar13 + 0xc & 3;
      uVar14 = *(uint *)(uVar13 + 0xc & 0xfffffffc);
      uVar10 = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) +
               (uint)*(ushort *)(uVar13 + 0x1a) * 4;
      uVar12 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      *(uint *)(uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) =
           uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20;
    }
  }
  DriverContext_PopulateNetworkState(param_1);
  uVar10 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 2) != 0) {
    uVar10 = param_1 + 0x310U & 3;
    uVar8 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
    func_0208c260(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20,*(undefined2 *)(param_1 + 0x74))
    ;
    return;
  }
  return;
}

