/* Decompiled C draft; module arm9_ov001; ROM address 02199464. No matching claim. */
#include "types.h"
#include "deps/02199464_FUN_02199464.h"

void FUN_02199464(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8 [2];
  
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995bc));
  func_0x020b4934(&local_10,uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995c0));
  func_0x020b47d8(&local_c,uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995c4));
  func_0x020b4a44(local_8,uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995c8));
  *(undefined4 *)(*(int *)PTR_data_ov001_021995cc + 0x74) = uVar1;
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995d0));
  *(undefined4 *)(*(int *)PTR_data_ov001_021995cc + 0x78) = uVar1;
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995d4));
  *(undefined4 *)(*(int *)PTR_data_ov001_021995cc + 0x7c) = uVar1;
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995d8));
  *(undefined4 *)(*(int *)PTR_data_ov001_021995cc + 0x80) = uVar1;
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995dc));
  *(undefined4 *)(*(int *)PTR_data_ov001_021995cc + 0x84) = uVar1;
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995e0));
  func_0x020b49bc((int *)(uintptr_t)(*(int *)PTR_data_ov001_021995cc + 100),uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995e4));
  func_0x020b48b4((int *)(uintptr_t)(*(int *)PTR_data_ov001_021995cc + 0x5c),uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995e8));
  func_0x020b4a44((int *)(uintptr_t)(*(int *)PTR_data_ov001_021995cc + 0x6c),uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995ec));
  func_0x020b49bc((int *)(uintptr_t)(*(int *)PTR_data_ov001_021995cc + 0x68),uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995f0));
  func_0x020b48b4((int *)(uintptr_t)(*(int *)PTR_data_ov001_021995cc + 0x60),uVar1);
  uVar1 = func_0x0204799c((undefined4)(uintptr_t)(PTR_data_ov001_021995f4));
  func_0x020b4a44(*(int *)PTR_data_ov001_021995cc + 0x70,uVar1);
  func_0x02016468(5,0,*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  func_0x02016468(9,0,local_c + 0xc,*(undefined4 *)(local_c + 8));
  func_0x02016468(0xf,0x20,*(int *)(local_8[0] + 0xc) + 0x20,0x20);
  func_0x02016468(0x13,0,*(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 100) + 0x14),
                  *(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 100) + 0x10));
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 0x68) + 0x14),
                  *(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 0x68) + 0x10));
  func_0x02016468(0xe,0,*(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 0x6c) + 0xc),
                  *(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 0x6c) + 8));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 0x70) + 0xc),
                  *(undefined4 *)(*(int *)(*(int *)PTR_data_ov001_021995cc + 0x70) + 8));
  return;
}

