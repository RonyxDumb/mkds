/* Verified local Thumb bytes. Global caller ABI and full ROM remain unverified. */
unsigned int func_02006380(unsigned char *p,int bit) { unsigned int word=((unsigned int **)p)[5][bit>>5]; return (word & (1u << (bit&31))) != 0; }
