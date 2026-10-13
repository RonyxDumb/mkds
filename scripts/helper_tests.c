#include "../src/ghidra_compat.h"
#include <assert.h>
int main(void){
 uint32_t x=0x12345678;
 for(unsigned i=0;i<100000;i++){
  x=x*1664525u+1013904223u;uint32_t a=x;
  x=x*1664525u+1013904223u;uint32_t b=x,r=a-b;
  assert(CARRY4(a,b)==((uint32_t)(a+b)<a));
  assert(SBORROW4(a,b)==((((a^b)&(a^r))>>31)!=0));
  uint64_t joined=CONCAT44(a,b);assert((uint32_t)joined==b);assert(SUB84(joined,4)==a);
  assert(CONCAT13(a,b)==((a&0xffu)<<24|(b&0xffffffu)));
 }
 assert(LZCOUNT(0)==32);for(unsigned n=0;n<32;n++)assert(LZCOUNT(1u<<n)==31-n);
 uint32_t word=0x12345678u;assert(MKDS_SLICE_2(word,2)==0x1234u);MKDS_SLICE_2(word,2)=0xabcd;assert(word==0xabcd5678u);
 return 0;
}
