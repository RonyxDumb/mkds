/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_020a80cc SDK_data_021803d8
#define func_0205ea10 WaitForTPFlags
extern unsigned char data_020a80cc[];
void func_0205ea10(int mask) {
    while (*(volatile unsigned short*)(data_020a80cc + 0x36) & mask) ;
}
