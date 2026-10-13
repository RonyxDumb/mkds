/* Decompiled C draft; module arm9; ROM address 020681f0. No matching claim. */
#include "types.h"
#include "deps/020681f0_StructMQRacerEntry_SomeFn_33.h"

void StructMQRacerEntry_SomeFn_33(int param_1)

{
  uint uVar1;
  ushort uVar2;
  short *psVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & uRam02068434) == 0) {
    uVar1 = param_1 + 0x2fcU & 3;
    uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
    if (2 < (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) {
      return;
    }
    uVar1 = param_1 + 0x30cU & 3;
    uVar5 = *(uint *)(param_1 + 0x30cU & 0xfffffffc);
    *(uint *)(param_1 + 0x30c) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) - 1;
    uVar1 = param_1 + 0x30cU & 3;
    uVar5 = *(uint *)(param_1 + 0x30cU & 0xfffffffc);
    if (0 < (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) {
      return;
    }
    uVar1 = param_1 + 0x78U & 3;
    uVar5 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    uVar2 = *(ushort *)(iRam02068438 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * 0x5c);
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x10) != 0) {
        uVar1 = param_1 + 0x308U & 3;
        uVar5 = *(uint *)(param_1 + 0x308U & 0xfffffffc);
        psVar3 = (short *)(param_1 + iRam0206843c);
        if ((short *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == psVar3) {
          if (*(ushort *)(param_1 + 0x302) < *(ushort *)(param_1 + 0x300)) {
            *psVar3 = *psVar3 + 1;
            uVar1 = param_1 + 0x2fcU & 3;
            uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
            *(uint *)(param_1 + 0x2fc) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 1;
            *(undefined4 *)(param_1 + 0x30c) = 10;
            uVar1 = param_1 + 0x2fcU & 3;
            uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
            if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 2) {
              uVar4 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
              uVar1 = param_1 + 0x7cU & 3;
              uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
              func_0208c884(uVar4,((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x10) != 0);
              DriverContext_MaybeQueuePlaySfx(param_1,0xd2,0x7f,0);
            }
          }
        }
        else if (*(short *)(param_1 + 0x302) == *(short *)(param_1 + 0x300)) {
          *psVar3 = *psVar3 + 1;
          *(undefined4 *)(param_1 + 0x30c) = 10;
        }
      }
    }
    else {
      uVar1 = param_1 + 0x304U & 3;
      uVar5 = *(uint *)(param_1 + 0x304U & 0xfffffffc);
      puVar6 = (ushort *)(param_1 + 0x300);
      if ((ushort *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == puVar6) {
        if (*(ushort *)(param_1 + 0x302) == *puVar6) {
          *puVar6 = *puVar6 + 1;
          *(undefined4 *)(param_1 + 0x30c) = 10;
        }
      }
      else if (*puVar6 < *(ushort *)(param_1 + 0x302)) {
        *puVar6 = *puVar6 + 1;
        uVar1 = param_1 + 0x2fcU & 3;
        uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
        *(uint *)(param_1 + 0x2fc) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 1;
        *(undefined4 *)(param_1 + 0x30c) = 10;
        uVar1 = param_1 + 0x2fcU & 3;
        uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
        if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 2) {
          uVar4 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
          uVar1 = param_1 + 0x7cU & 3;
          uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          func_0208c884(uVar4,((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x10) != 0);
          DriverContext_MaybeQueuePlaySfx(param_1,0xd2,0x7f,0);
        }
      }
    }
  }
  uVar1 = param_1 + 0x2fcU & 3;
  uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
  if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 3) {
    uVar4 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
    uVar1 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x8000) == 0) {
      func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
      func_0208c534();
    }
    else {
      func_0208d650();
      func_0208c520(uVar4);
      uVar1 = param_1 + 0x7cU & 3;
      uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      func_0208cacc(uVar4,((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x10) != 0);
    }
    uVar1 = param_1 + 0x2fcU & 3;
    uVar5 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
    *(uint *)(param_1 + 0x2fc) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 1;
    return;
  }
  return;
}

