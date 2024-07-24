/** !
 * Include header for pack library
 * 
 * @file pack/pack.h 
 * 
 * @author Jacob Smith
 */

// Include guard
#pragma once

// Standard library
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Platform dependent macros
#ifdef _WIN64
#define DLLEXPORT extern __declspec(dllexport)
#else
#define DLLEXPORT
#endif

// Pack
/** !
 * Pack data into a buffer
 * 
 * @param p_buffer the buffer
 * @param format   format string
 * @param ...      variadic arguments
 * 
 * @return bytes written on success, 0 on error
 */
DLLEXPORT size_t pack_pack ( void *p_buffer, const char *restrict format, ... );

// Unpack
//
