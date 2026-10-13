/* Decompiled C draft; module arm9; ROM address 02062078. No matching claim. */
#include "types.h"
#include "deps/02062078_func_02062078.h"

void func_02062078(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  
  func_02076c50(*(uint *)(uRam02062240 & 0xfffffffc) >> (uRam02062240 & 3) * 8 |
                *(uint *)(uRam02062240 & 0xfffffffc) << (uRam02062240 & 3) * -8 + 0x20,1);
  func_02076bcc((undefined4 *)(uintptr_t)(*(uint *)(uRam02062240 & 0xfffffffc) >> (uRam02062240 & 3) * 8 |
                *(uint *)(uRam02062240 & 0xfffffffc) << (uRam02062240 & 3) * -8 + 0x20));
  uVar3 = *(uint *)(uRam02062244 & 0xfffffffc) >> (uRam02062244 & 3) * 8 |
          *(uint *)(uRam02062244 & 0xfffffffc) << (uRam02062244 & 3) * -8 + 0x20;
  uVar4 = *(uint *)(uRam02062240 & 0xfffffffc) >> (uRam02062240 & 3) * 8 |
          *(uint *)(uRam02062240 & 0xfffffffc) << (uRam02062240 & 3) * -8 + 0x20;
  func_02010fac(0,(int)*(short *)(uVar3 + 0x40),(int)*(short *)(uVar3 + 0x42),
                (int)*(short *)(uVar3 + 0x44));
  func_02010f98(0,uRam02062248);
  uVar3 = uVar4 + 0x34 & 3;
  uVar2 = *(uint *)(uVar4 + 0x34 & 0xfffffffc);
  local_20 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 0x40 & 3;
  uVar2 = *(uint *)(uVar4 + 0x40 & 0xfffffffc);
  local_1c = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 0x4c & 3;
  uVar2 = *(uint *)(uVar4 + 0x4c & 0xfffffffc);
  local_18 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 0x38 & 3;
  uVar2 = *(uint *)(uVar4 + 0x38 & 0xfffffffc);
  local_14 = -(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar3 = uVar4 + 0x44 & 3;
  uVar2 = *(uint *)(uVar4 + 0x44 & 0xfffffffc);
  local_10 = -(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar3 = uVar4 + 0x50 & 3;
  uVar2 = *(uint *)(uVar4 + 0x50 & 0xfffffffc);
  local_c = -(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  VecFx32_Subtract((uint)(uintptr_t)(&local_14),(uint)(uintptr_t)(&local_20),&local_2c);
  lVar1 = (longlong)local_24 * (longlong)local_24 +
          (longlong)local_2c * (longlong)local_2c + (longlong)local_28 * (longlong)local_28;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_2c),&local_2c);
  }
  func_02010fac(1,(int)(short)local_2c,(int)(short)local_28,(int)(short)local_24);
  func_02010f98(1,uRam02062248);
  func_02011034();
  func_01ff9048(0x17,*(uint *)(uRam0206224c & 0xfffffffc) >> (uRam0206224c & 3) * 8 |
                     *(uint *)(uRam0206224c & 0xfffffffc) << (uRam0206224c & 3) * -8 + 0x20,0xc);
  local_30 = 0x1e;
  func_01ff9048(0x13,(undefined4)(uintptr_t)(&local_30),1);
  func_02063228();
  func_02076c50(*(uint *)(uRam02062240 & 0xfffffffc) >> (uRam02062240 & 3) * 8 |
                *(uint *)(uRam02062240 & 0xfffffffc) << (uRam02062240 & 3) * -8 + 0x20,0);
  func_02011034();
  func_01ff92e0((undefined4 *)(uintptr_t)(*(uint *)(uRam02062250 & 0xfffffffc) >> (uRam02062250 & 3) * 8 |
                *(uint *)(uRam02062250 & 0xfffffffc) << (uRam02062250 & 3) * -8 + 0x20));
  func_0206326c();
  func_020d4418(*(uint *)(uRam02062240 & 0xfffffffc) >> (uRam02062240 & 3) * 8 |
                *(uint *)(uRam02062240 & 0xfffffffc) << (uRam02062240 & 3) * -8 + 0x20);
  func_01ff92b4();
  func_0207a9f4();
  uVar3 = *(uint *)(uRam02062244 & 0xfffffffc) >> (uRam02062244 & 3) * 8 |
          *(uint *)(uRam02062244 & 0xfffffffc) << (uRam02062244 & 3) * -8 + 0x20;
  func_02010fac(0,(int)*(short *)(uVar3 + 0x40),(int)*(short *)(uVar3 + 0x42),
                (int)*(short *)(uVar3 + 0x44));
  func_020e9810();
  func_020d4484(*(uint *)(uRam02062240 & 0xfffffffc) >> (uRam02062240 & 3) * 8 |
                *(uint *)(uRam02062240 & 0xfffffffc) << (uRam02062240 & 3) * -8 + 0x20);
  func_020fa8ac(*(uint *)(uRam0206224c & 0xfffffffc) >> (uRam0206224c & 3) * 8 |
                *(uint *)(uRam0206224c & 0xfffffffc) << (uRam0206224c & 3) * -8 + 0x20);
  func_0208e358();
  func_01ff9234();
  return;
}

