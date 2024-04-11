#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <pjlib.h>
#include <pjlib-util.h>
#include <pjsip.h>
#include <pjsip/sip_types.h>

#include <pjsip.h>
#include <pjlib.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    // Allocate memory pool for the parser
    pj_caching_pool caching_pool;
    pj_pool_t *pool;
    pj_status_t status;

    pj_init();
    pj_caching_pool_init(&caching_pool, NULL, 0);
    pool = pj_pool_create(&caching_pool.factory, "fuzz_parser_pool", 4096, 4096, NULL);

    if (!pool)
    {
        pj_shutdown();
        return 0;
    }

    // Prepare buffer for the parser
    char *buf = (char *)pj_pool_alloc(pool, Size + 1);
    if (!buf)
    {
        pj_pool_release(pool);
        pj_shutdown();
        return 0;
    }

    memcpy(buf, Data, Size);
    buf[Size] = '\0';

    // Error list for the parser
    pjsip_parser_err_report err_list;
    memset(&err_list, 0, sizeof(err_list));

    // Call the pjsip_parse_msg function with the fuzzed input
    pjsip_msg *msg = pjsip_parse_msg(pool, buf, Size, &err_list);

    // Clean up and return
    pj_pool_release(pool);
    pj_shutdown();

    return 0;
}