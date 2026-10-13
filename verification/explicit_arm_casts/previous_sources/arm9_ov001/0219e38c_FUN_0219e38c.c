/* Decompiled C draft; module arm9_ov001; ROM address 0219e38c. No matching claim. */
#include "types.h"
#include "deps/0219e38c_FUN_0219e38c.h"

void FUN_0219e38c(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0204799c(DAT_0219e544);
  func_0x020b496c(*DAT_0219e548 + 0x38,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e54c);
  func_0x020b4810(*DAT_0219e548 + 0x40,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e550);
  func_0x020b4a7c(*DAT_0219e548 + 0x48,uVar1);
  if (*(int *)(*DAT_0219e548 + 0xc) == 0) {
    uVar1 = func_0x0204799c(DAT_0219e554);
    func_0x020b496c(*DAT_0219e548 + 0x3c,uVar1);
    uVar1 = func_0x0204799c(DAT_0219e558);
    func_0x020b4810(*DAT_0219e548 + 0x44,uVar1);
    uVar1 = func_0x0204799c(DAT_0219e55c);
    func_0x020b4a7c(*DAT_0219e548 + 0x4c,uVar1);
  }
  else if (*(int *)(*DAT_0219e548 + 0xc) == 1) {
    uVar1 = func_0x0204799c(DAT_0219e560);
    func_0x020b496c(*DAT_0219e548 + 0x3c,uVar1);
    uVar1 = func_0x0204799c(DAT_0219e564);
    func_0x020b4810(*DAT_0219e548 + 0x44,uVar1);
    uVar1 = func_0x0204799c(DAT_0219e568);
    func_0x020b4a7c(*DAT_0219e548 + 0x4c,uVar1);
  }
  uVar1 = func_0x0204799c(DAT_0219e56c);
  func_0x020b496c(*DAT_0219e548 + 0x50,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e570);
  func_0x020b4810(*DAT_0219e548 + 0x58,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e574);
  func_0x020b4a7c(*DAT_0219e548 + 0x60,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e578);
  func_0x020b496c(*DAT_0219e548 + 0x54,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e57c);
  func_0x020b4810(*DAT_0219e548 + 0x5c,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e580);
  func_0x020b4a7c(*DAT_0219e548 + 100,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e584);
  func_0x020b48ec(*DAT_0219e548 + 0x24,uVar1);
  uVar1 = func_0x0204799c(DAT_0219e588);
  func_0x020b4a7c(*DAT_0219e548 + 0x2c,uVar1);
  if (*(int *)(*DAT_0219e548 + 0xc) == 0) {
    uVar1 = func_0x0204799c(DAT_0219e58c);
    *(undefined4 *)(*DAT_0219e548 + 0x30) = uVar1;
    uVar1 = func_0x0204799c(DAT_0219e590);
    *(undefined4 *)(*DAT_0219e548 + 0x34) = uVar1;
  }
  else if (*(int *)(*DAT_0219e548 + 0xc) == 1) {
    uVar1 = func_0x0204799c(DAT_0219e594);
    *(undefined4 *)(*DAT_0219e548 + 0x30) = uVar1;
    uVar1 = func_0x0204799c(DAT_0219e598);
    *(undefined4 *)(*DAT_0219e548 + 0x34) = uVar1;
  }
  if (*(int *)(*DAT_0219e59c + 0x70) == 0) {
    FUN_0219e5d4(0);
  }
  else {
    FUN_0219e5a0();
  }
  func_0x02016468(0xe,0,*(undefined4 *)(*(int *)(*DAT_0219e548 + 0x2c) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_0219e548 + 0x2c) + 8));
  return;
}

