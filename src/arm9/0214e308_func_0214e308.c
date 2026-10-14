/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_020a80cc SDK_data_021803d8
#define func_0205e9fc func_0214e308
extern unsigned char data_020a80cc[];
int func_0205e9fc(int mask) {
    return *(unsigned short *)(data_020a80cc + 0x34) & mask;
}
