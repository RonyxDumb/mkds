/* Decompiled C draft; module arm9; ROM address 0213ecf8. No matching claim. */
#include "types.h"
#include "deps/0213ecf8_wcschr.h"

wchar_t * wcschr(wchar_t *__wcs,wchar_t __wc)

{
  ushort uVar1;
  ushort *puVar2;
  wchar_t *pwVar3;
  
  uVar1 = (ushort)*__wcs;
  puVar2 = (ushort *)((int)__wcs + 2);
  while( true ) {
    if ((uint)uVar1 == L'\0') {
      if (__wc == L'\0') {
        pwVar3 = (wchar_t *)(puVar2 + -1);
      }
      else {
        pwVar3 = (wchar_t *)0x0;
      }
      return pwVar3;
    }
    if ((uint)uVar1 == __wc) break;
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  return (wchar_t *)(puVar2 + -1);
}

