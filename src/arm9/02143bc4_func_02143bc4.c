/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0201818c SDK_data_02143bd4
#define LoadFile func_02143bc4
/* LoadFile at 0x0201816c
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (arm9 main).
 */

extern int func_0201818c(int handle, int mode);

int LoadFile(int handle) {
    return func_0201818c(handle, 1);
}
