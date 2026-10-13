/* Decompiled C draft; module arm9; ROM address 01ffa1f8. No matching claim. */
#include "types.h"
#include "deps/01ffa1f8_func_01ffa1f8.h"

undefined4 func_01ffa1f8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = uRam01ffa34c;
  uVar3 = uRam01ffa334;
  uVar4 = param_1 + 0x84U & 3;
  uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((int)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) < 0) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x400) == 0) &&
       (uVar4 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x800) == 0)) {
      uVar4 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x800;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 8;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 2) {
        uVar5 = GetCourseCpoiRespawnId(0);
      }
      else {
        uVar5 = GetCourseCpoiRespawnId
                          (*(undefined2 *)
                            ((uint)*(ushort *)(param_1 + 0x74) * 0x8c +
                             (*(uint *)(uRam01ffa338 & 0xfffffffc) >> (uRam01ffa338 & 3) * 8 |
                             *(uint *)(uRam01ffa338 & 0xfffffffc) << (uRam01ffa338 & 3) * -8 + 0x20)
                            + 0x46));
      }
      *(undefined4 *)(param_1 + 0x3c4) = uVar5;
      uVar4 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) != 0) &&
          (uVar3 = *(uint *)(uRam01ffa334 & 0xfffffffc) >> (uRam01ffa334 & 3) * 8 |
                   *(uint *)(uRam01ffa334 & 0xfffffffc) << (uRam01ffa334 & 3) * -8 + 0x20,
          uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
          (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0x1d)) &&
         (((*(uint *)(uRam01ffa33c & 0xfffffffc) >> (uRam01ffa33c & 3) * 8 |
           *(uint *)(uRam01ffa33c & 0xfffffffc) << (uRam01ffa33c & 3) * -8 + 0x20) & 1) != 0)) {
        func_02108ea0(0);
        uVar3 = GetSomeSndPlayer();
        uVar4 = iRam01ffa340 + 0xcU & 3;
        uVar2 = *(uint *)(iRam01ffa340 + 0xcU & 0xfffffffc);
        if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
          if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
            func_0212c6f0(uVar3,0);
          }
          if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
            func_0212c6f0(uVar3,0);
          }
          NNSi_MaybeSndPlayerStartSeq(uVar3,0,uRam01ffa344);
        }
      }
    }
    return 1;
  }
  uVar4 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & uRam01ffa348;
  uVar4 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & uVar2;
  return 0;
}

