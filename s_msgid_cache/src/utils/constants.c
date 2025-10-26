#include "../include/constants.h"

static const size_t DEFAULT_CAPACITY = 100;
static const time_t CLEANUP_INTERVAL = 300; // 5 минут
static const time_t ENTRY_TTL = 3600;       // 1 час
static const uint8_t MAX_RETRIES = 3;

size_t get_default_capacity(void)
{
    return DEFAULT_CAPACITY;
}

time_t get_cleanup_interval(void)
{
    return CLEANUP_INTERVAL;
}

time_t get_entry_ttl(void)
{
    return ENTRY_TTL;
}

uint8_t get_max_retries(void)
{
    return MAX_RETRIES;
}