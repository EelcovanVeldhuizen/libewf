/*
 * Volume section functions
 *
 * Copyright (C) 2006-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBEWF_VOLUME_SECTION_H )
#define _LIBEWF_VOLUME_SECTION_H

#include <common.h>
#include <types.h>

#include "libewf_io_handle.h"
#include "libewf_libbfio.h"
#include "libewf_libcerror.h"
#include "libewf_media_values.h"
#include "libewf_section_descriptor.h"

#include "ewf_data.h"
#include "ewf_section.h"
#include "ewf_table.h"

#if defined( __cplusplus )
extern "C" {
#endif

int libewf_volume_section_e01_read_data(
     const uint8_t *data,
     size_t data_size,
     libewf_io_handle_t *io_handle,
     libewf_media_values_t *media_values,
     libcerror_error_t **error );

ssize_t libewf_volume_section_e01_read(
         libewf_section_descriptor_t *section_descriptor,
         libewf_io_handle_t *io_handle,
         libbfio_pool_t *file_io_pool,
         int file_io_pool_entry,
         libewf_media_values_t *media_values,
         libcerror_error_t **error );

ssize_t libewf_volume_section_e01_write(
         libewf_section_descriptor_t *section_descriptor,
         libewf_io_handle_t *io_handle,
         libbfio_pool_t *file_io_pool,
         int file_io_pool_entry,
         off64_t section_offset,
         libewf_media_values_t *media_values,
         libcerror_error_t **error );

int libewf_volume_section_s01_read_data(
     const uint8_t *data,
     size_t data_size,
     libewf_io_handle_t *io_handle,
     libewf_media_values_t *media_values,
     libcerror_error_t **error );

ssize_t libewf_volume_section_s01_read(
         libewf_section_descriptor_t *section_descriptor,
         libewf_io_handle_t *io_handle,
         libbfio_pool_t *file_io_pool,
         int file_io_pool_entry,
         libewf_media_values_t *media_values,
         libcerror_error_t **error );

ssize_t libewf_volume_section_s01_write(
         libewf_section_descriptor_t *section_descriptor,
         libewf_io_handle_t *io_handle,
         libbfio_pool_t *file_io_pool,
         int file_io_pool_entry,
         off64_t section_offset,
         libewf_media_values_t *media_values,
         libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBEWF_VOLUME_SECTION_H ) */

