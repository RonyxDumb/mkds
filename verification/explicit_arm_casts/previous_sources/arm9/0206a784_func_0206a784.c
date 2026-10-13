/* Decompiled C draft; module arm9; ROM address 0206a784. No matching claim. */
#include "types.h"
#include "deps/0206a784_func_0206a784.h"

void func_0206a784(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 + 0x318U & 3;
  uVar1 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
    *(uint *)(param_1 + 0x260) =
         *(uint *)(uRam0206a96c & 0xfffffffc) >> (uRam0206a96c & 3) * 8 |
         *(uint *)(uRam0206a96c & 0xfffffffc) << (uRam0206a96c & 3) * -8 + 0x20;
  }
  else {
    uVar3 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x10000) != 0) {
      if (*(short *)(param_1 + 0x370) == 0) {
        *(uint *)(param_1 + 0x260) =
             *(uint *)(uRam0206a970 & 0xfffffffc) >> (uRam0206a970 & 3) * 8 |
             *(uint *)(uRam0206a970 & 0xfffffffc) << (uRam0206a970 & 3) * -8 + 0x20;
      }
      *(short *)(param_1 + 0x370) = *(short *)(param_1 + 0x370) + 1;
    }
  }
  uVar3 = param_1 + 0x318U & 3;
  uVar1 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 1) {
    uVar3 = -uVar3;
  }
  if ((int)uVar3 <= iRam0206a974) {
    uVar3 = param_1 + 0x318U & 3;
    uVar4 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
    uVar1 = param_1 + 0x360U & 3;
    uVar2 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
    *(uint *)(param_1 + 0x318) =
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
         (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar3 = param_1 + 0x318U & 3;
    uVar1 = *(uint *)(param_1 + 0x318U & 0xfffffffc);
    uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    if ((int)uVar3 < 1) {
      uVar3 = -uVar3;
    }
    if (iRam0206a974 < (int)uVar3) {
      *(undefined2 *)(param_1 + 0x314) = 0;
      uVar3 = param_1 + 0x4cU & 3;
      uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xfffffffe;
    }
    else {
      uVar3 = param_1 + 0x360U & 3;
      uVar1 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
      *(ushort *)(param_1 + 0x314) =
           *(short *)(param_1 + 0x314) +
           ((ushort)(uVar1 >> uVar3 * 8) | (ushort)(uVar1 << uVar3 * -8 + 0x20));
    }
    uVar3 = param_1 + 0x360U & 3;
    uVar2 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
    uVar1 = param_1 + 0x360U & 3;
    uVar4 = *(uint *)(param_1 + 0x360U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
      uVar3 = -(*(uint *)(uRam0206a978 & 0xfffffffc) >> (uRam0206a978 & 3) * 8 |
               *(uint *)(uRam0206a978 & 0xfffffffc) << (uRam0206a978 & 3) * -8 + 0x20);
    }
    else {
      uVar3 = *(uint *)(uRam0206a978 & 0xfffffffc) >> (uRam0206a978 & 3) * 8 |
              *(uint *)(uRam0206a978 & 0xfffffffc) << (uRam0206a978 & 3) * -8 + 0x20;
    }
    *(uint *)(param_1 + 0x360) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - uVar3;
    func_01ffd190(param_1 + 0x31c,*(undefined2 *)(param_1 + 0x314),param_1 + 0x34c);
    func_01ffcf7c(param_1 + 0x34c,param_1 + 0x34c);
    return;
  }
  if (*(short *)(param_1 + 0x35c) == 0) {
    uVar3 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20 | 0x44000;
    *(undefined2 *)(param_1 + 0x23a) = 0;
    uVar3 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xffffffef;
  }
  *(short *)(param_1 + 0x35c) = *(short *)(param_1 + 0x35c) + 1;
  if (*(short *)(param_1 + 0x35c) < 10) {
    return;
  }
  *(undefined4 *)(param_1 + 0x180) = 0;
  uVar3 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xffffffcf;
  uVar3 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xfffdffff;
  DriverContext_UpdateCharacterAnimation(param_1,0,1);
  uVar3 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20 | 0x80000000;
  uVar3 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 2) != 0) &&
      (uVar1 = *(uint *)(uRam0206a97c & 0xfffffffc) >> (uRam0206a97c & 3) * 8 |
               *(uint *)(uRam0206a97c & 0xfffffffc) << (uRam0206a97c & 3) * -8 + 0x20,
      uVar3 = uVar1 + 8, uVar2 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
      (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 2)) &&
     (uVar1 = uVar1 + 0x18, uVar3 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
     uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0)) {
    uVar3 = param_1 + 0x310U & 3;
    uVar1 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
    func_02088c7c(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
  }
  uVar3 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x388) = 0;
  }
  return;
}

