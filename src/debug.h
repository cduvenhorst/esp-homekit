#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdlib.h>
#include <stdio.h>
#include "tlv.h"

typedef unsigned char byte;
void tlv_debug(const tlv_values_t *values);

#if HOMEKIT_DEBUG >= 1 // Error
#define ERROR(message, ...) printf("HomeKit ERROR: " message "\n", ##__VA_ARGS__)
#else
#define ERROR(message, ...)
#endif

#if HOMEKIT_DEBUG >= 2 // Warn
#define WARN(message, ...) printf("HomeKit WARN: " message "\n", ##__VA_ARGS__)
#else
#define WARN(message, ...)
#endif

#if HOMEKIT_DEBUG >= 3 // Info
#define INFO(message, ...) printf("HomeKit INFO: " message "\n", ##__VA_ARGS__)
#else
#define INFO(message, ...)
#endif

#if HOMEKIT_DEBUG >= 4 // Debug
#define DEBUG(message, ...) printf("HomeKit DEBUG %s: " message "\n", __func__, ##__VA_ARGS__)
#define TLV_DEBUG(values) tlv_debug(values)
#else
#define DEBUG(message, ...)
#define TLV_DEBUG(values)
#endif

#define DEBUG_HEAP() DEBUG("Free heap: %d", xPortGetFreeHeapSize());

#define CLIENT_DEBUG(client, message, ...) DEBUG("[Client %d] " message, client->socket, ##__VA_ARGS__)
#define CLIENT_INFO(client, message, ...) INFO("[Client %d] " message, client->socket, ##__VA_ARGS__)
#define CLIENT_ERROR(client, message, ...) ERROR("[Client %d] " message, client->socket, ##__VA_ARGS__)

char *binary_to_string(const byte *data, size_t size);
void print_binary(const char *prompt, const byte *data, size_t size);

#endif // __DEBUG_H__
