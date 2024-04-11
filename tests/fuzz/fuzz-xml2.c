#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <pjlib.h>
#include <pjlib-util.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    pj_pool_t *pool;
    pj_xml_node *xml_node;
    char *msg;

    // Create a memory pool
    pool = pj_pool_create(NULL, "fuzz_pool", 1024, 1024, NULL);
    if (!pool)
    {
        return 0;
    }

    // Allocate memory for the message
    msg = pj_pool_alloc(pool, Size + 1);
    if (!msg)
    {
        pj_pool_release(pool);
        return 0;
    }

    // Copy data to the message and add null terminator
    memcpy(msg, Data, Size);
    msg[Size] = '\0';

    // Call the function to be fuzzed
    xml_node = pj_xml_parse(pool, msg, Size);

    // Release the memory pool
    pj_pool_release(pool);

    // Indicate success
    return 0;
}