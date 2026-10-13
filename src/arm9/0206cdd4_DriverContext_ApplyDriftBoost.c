/* Decompiled C draft; module arm9; ROM address 0206cdd4. No matching claim. */
#include "types.h"
#include "deps/0206cdd4_DriverContext_ApplyDriftBoost.h"

void DriverContext_ApplyDriftBoost(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x10) == 0) {
    uVar3 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20 | 0x8000;
  }
  uVar3 = param_1 + 0x2fcU & 3;
  uVar1 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 4) {
    uVar3 = param_1 + 0x2ccU & 3;
    uVar1 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    DriverContext_MaybeApplyBoost
              (param_1,1,(int)*(short *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0xe));
    uVar3 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20 | 0x80000;
    uVar3 = param_1 + 0x2ccU & 3;
    uVar1 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    *(undefined2 *)(param_1 + 0x23c) =
         *(undefined2 *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0xe);
    uVar3 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 1) != 0) {
      iVar2 = GetGlobalRK();
      uVar1 = uRam0206ceac;
      uVar3 = iVar2 + 4U & 3;
      uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
      *(uint *)(iVar2 + 4) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 1;
      uVar3 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 8;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 4) {
        func_0x0218171c();
      }
    }
  }
  uVar3 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & uRam0206ceb0;
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  *(undefined4 *)(param_1 + 0x2fc) = 0;
  *(undefined2 *)(param_1 + 0x302) = 0;
  *(undefined2 *)(param_1 + 0x300) = *(undefined2 *)(param_1 + 0x302);
  *(undefined4 *)(param_1 + 0x30c) = 0;
  func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
  func_0208c534();
  return;
}

