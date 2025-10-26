#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stddef.h>
#include <time.h>
#include <stdint.h>

size_t get_default_capacity(void);
time_t get_cleanup_interval(void);
time_t get_entry_ttl(void);
uint8_t get_max_retries(void);

#endif