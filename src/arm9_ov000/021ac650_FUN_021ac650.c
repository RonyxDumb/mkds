/* Decompiled C draft; module arm9_ov000; ROM address 021ac650. No matching claim. */
#include "types.h"
#include "deps/021ac650_FUN_021ac650.h"

void FUN_021ac650(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  
  func_0x0214d1fc();
  if (param_3 == 1) {
    FUN_021acab0(param_1,(ushort *)(uintptr_t)(param_2),param_4);
  }
  else if (param_3 != 0) {
    FUN_021acbf8(param_1,(ushort *)(uintptr_t)(param_2),(ushort *)(uintptr_t)(param_3),param_4);
  }
  FUN_021acbf8(param_8,(ushort *)(uintptr_t)(param_1),(ushort *)(uintptr_t)(param_7),param_5);
  iVar1 = (param_4 - param_5) * 2;
  iVar2 = param_5 * 2;
  func_0x0214d168((uint *)(uintptr_t)(param_8 + iVar2),0,iVar1);
  FUN_021acbf8(param_9,(ushort *)(uintptr_t)(param_8),(ushort *)(uintptr_t)(param_6),param_4);
  FUN_021ace14((ushort *)(uintptr_t)(param_1),(ushort *)(uintptr_t)(param_1),(ushort *)(uintptr_t)(param_9),param_4);
  func_0x02134df8((uint *)(uintptr_t)(param_1),(uint *)(uintptr_t)(param_1 + iVar2),iVar1);
  func_0x0214d168((uint *)(uintptr_t)(param_1 + param_4 * 2 + param_5 * -2),0,iVar2);
  iVar1 = FUN_021acc8c(param_1,param_6,param_4);
  if (iVar1 != 0) {
    if (iVar1 != 1) {
      return;
    }
    FUN_021acd24((ushort *)(uintptr_t)(param_1),(ushort *)(uintptr_t)(param_1),(ushort *)(uintptr_t)(param_6),param_4);
    return;
  }
  func_0x0214d168((uint *)(uintptr_t)(param_1),0,param_4 << 1);
  return;
}

