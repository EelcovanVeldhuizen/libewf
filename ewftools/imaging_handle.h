/* 
 * Imaging handle
 *
 * Copyright (C) 2008-2009, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _IMAGING_HANDLE_H )
#define _IMAGING_HANDLE_H

#include <common.h>
#include <types.h>

#include <liberror.h>

/* If libtool DLL support is enabled set LIBEWF_DLL_IMPORT
 * before including libewf_extern.h
 */
#if defined( _WIN32 ) && defined( DLL_EXPORT )
#define LIBEWF_DLL_EXPORT
#endif

#include <libewf.h>

#include "digest_context.h"
#include "digest_hash.h"
#include "md5.h"
#include "sha1.h"
#include "storage_media_buffer.h"
#include "system_string.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct imaging_handle imaging_handle_t;

struct imaging_handle
{
	/* Value to indicate if the MD5 digest hash should be calculated
	 */
	uint8_t calculate_md5;

	/* Value to indicate if the SHA1 digest hash should be calculated
	 */
	uint8_t calculate_sha1;

	/* The MD5 digest context
	 */
	md5_context_t md5_context;

	/* The SHA1 digest context
	 */
	sha1_context_t sha1_context;

	/* The libewf input handle
	 */
	libewf_handle_t *output_handle;

	/* The last offset of the input data
	 */
	off64_t input_offset;

	/* The last offset of the output data
	 */
	off64_t output_offset;

	/* TODO refactor */
	size32_t chunk_size;
	uint32_t bytes_per_sector;
	size64_t media_size;
	uint32_t error_granularity;

	/* The amount of retries after a read error
	 */
	uint8_t read_error_retry;

	/* Value to indicate if the chunk
	 * is wiped on error
	 */
	uint8_t wipe_chunk_on_error;

	/* Value to indicate if the next sector
	 * is seeked on error
	 */
	uint8_t seek_on_error;
};

int imaging_handle_initialize(
     imaging_handle_t **imaging_handle,
     uint8_t calculate_md5,
     uint8_t calculate_sha1,
     liberror_error_t **error );

int imaging_handle_free(
     imaging_handle_t **imaging_handle,
     liberror_error_t **error );

int imaging_handle_open_output(
     imaging_handle_t *imaging_handle,
     char * const * filenames,
     int amount_of_files,
     liberror_error_t **error );

ssize_t imaging_handle_read_buffer(
         imaging_handle_t *imaging_handle,
         int input_file_descriptor,
         storage_media_buffer_t *storage_media_buffer,
         size_t read_size,
         liberror_error_t **error );

ssize_t imaging_handle_write_prepare_buffer(
         imaging_handle_t *imaging_handle,
         storage_media_buffer_t *storage_media_buffer,
         liberror_error_t **error );

ssize_t imaging_handle_write_buffer(
         imaging_handle_t *imaging_handle,
         storage_media_buffer_t *storage_media_buffer,
         size_t write_size,
         liberror_error_t **error );

/* TODO refactor ? */
ssize_t imaging_handle_write_finalize(
         imaging_handle_t *imaging_handle,
         liberror_error_t **error );

int imaging_handle_swap_byte_pairs(
     imaging_handle_t *imaging_handle,
     storage_media_buffer_t *storage_media_buffer,
     size_t read_size,
     liberror_error_t **error );

int imaging_handle_update_integrity_hash(
     imaging_handle_t *imaging_handle,
     storage_media_buffer_t *storage_media_buffer,
     size_t read_size,
     liberror_error_t **error );

int imaging_handle_close(
     imaging_handle_t *imaging_handle,
     liberror_error_t **error );

int imaging_handle_set_input_values(
     imaging_handle_t *imaging_handle,
     uint8_t read_error_retry,
     uint8_t wipe_chunk_on_error,
     uint8_t seek_on_error,
     liberror_error_t **error );

int imaging_handle_set_output_values(
     imaging_handle_t *imaging_handle,
     uint32_t sectors_per_chunk,
     uint32_t bytes_per_sector,
     size64_t media_size,
     uint32_t error_granularity,
     liberror_error_t **error );

int imaging_handle_finalize(
     imaging_handle_t *imaging_handle,
     system_character_t *calculated_md5_hash_string,
     size_t calculated_md5_hash_string_size,
     system_character_t *calculated_sha1_hash_string,
     size_t calculated_sha1_hash_string_size,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
