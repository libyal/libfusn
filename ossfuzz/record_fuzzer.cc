/*
 * OSS-Fuzz target for libfusn record type
 *
 * Copyright (C) 2011-2026, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Note that some of the OSS-Fuzz engines use C++
 */
extern "C" {

#include "ossfuzz_libfusn.h"

int LLVMFuzzerTestOneInput(
     const uint8_t *data,
     size_t size )
{
	const char *version           = NULL;
	libfusn_error_t *error        = NULL;
	libfusn_record_t *record      = NULL;
	uint16_t *utf16_name          = NULL;
	uint8_t *utf8_name            = NULL;
	uint32_t flags                = 0;
	uint32_t record_size          = 0;
	uint64_t value_64bit          = 0;
	int result                    = 0;
	size_t utf16_name_size        = 0;
	size_t utf8_name_size         = 0;
	char error_message[ 4000 ];

	version  = libfusn_get_version();

	if( version == NULL )
	{
		return( 0 );
	}
	if( libfusn_record_initialize(
	     &record,
	     &error ) != 1 )
	{
		if( error != NULL )
		{
			libfusn_error_free(
			 &error );
		}
		return( 0 );
	}
	if( libfusn_record_copy_from_byte_stream(
	     record,
	     data,
	     size,
	     &error ) != 1 )
	{
		if( error != NULL )
		{
			/* Exercise the library error functions
			 */
			libfusn_error_backtrace_fprint(
			 error,
			 stderr );

			libfusn_error_backtrace_sprint(
			 error,
			 error_message,
			 sizeof( error_message ) );

			libfusn_error_fprint(
			 error,
			 stderr );

			libfusn_error_sprint(
			 error,
			 error_message,
			 sizeof( error_message ) );

			libfusn_error_free(
			 &error );
		}
	}

	/* Exercise the "record was already copied" branch
	 */
	libfusn_record_copy_from_byte_stream(
	 record,
	 data,
	 size,
	 NULL );

	/* Exercise the record getter functions
	 * also for records that failed to parse
	 */
	libfusn_record_get_size(
	 record,
	 &record_size,
	 NULL );

	libfusn_record_get_update_time(
	 record,
	 &value_64bit,
	 NULL );

	libfusn_record_get_file_reference(
	 record,
	 &value_64bit,
	 NULL );

	libfusn_record_get_parent_file_reference(
	 record,
	 &value_64bit,
	 NULL );

	libfusn_record_get_update_sequence_number(
	 record,
	 &value_64bit,
	 NULL );

	libfusn_record_get_update_reason_flags(
	 record,
	 &flags,
	 NULL );

	libfusn_record_get_update_source_flags(
	 record,
	 &flags,
	 NULL );

	libfusn_record_get_file_attribute_flags(
	 record,
	 &flags,
	 NULL );

	/* Exercise the UTF-8 and UTF-16 name getter functions
	 * including those for records without a name
	 */
	libfusn_record_get_utf8_name_size(
	 record,
	 NULL,
	 &error );

	libfusn_error_free(
	 &error );

	libfusn_record_get_utf8_name(
	 record,
	 NULL,
	 1,
	 &error );

	libfusn_error_free(
	 &error );

	libfusn_record_get_utf16_name_size(
	 record,
	 NULL,
	 &error );

	libfusn_error_free(
	 &error );

	libfusn_record_get_utf16_name(
	 record,
	 NULL,
	 1,
	 &error );

	libfusn_error_free(
	 &error );

	result = libfusn_record_get_utf8_name_size(
	         record,
	         &utf8_name_size,
	         &error );

	libfusn_error_free(
	 &error );

	if( result == 1 )
	{
		if( utf8_name_size > 0 )
		{
			utf8_name = (uint8_t *) malloc(
			                                 utf8_name_size );

			if( utf8_name != NULL )
			{
				/* Exercise the "UTF-8 string too small" branch
				 */
				libfusn_record_get_utf8_name(
				 record,
				 utf8_name,
				 1,
				 &error );

				libfusn_error_free(
				 &error );

				/* Exercise the UTF-16 stream to UTF-8 string conversion
				 */
				libfusn_record_get_utf8_name(
				 record,
				 utf8_name,
				 utf8_name_size,
				 NULL );

				free(
				 utf8_name );
			}
		}
	}
	result = libfusn_record_get_utf16_name_size(
	         record,
	         &utf16_name_size,
	         &error );

	libfusn_error_free(
	 &error );

	if( result == 1 )
	{
		if( utf16_name_size > 0 )
		{
			utf16_name = (uint16_t *) malloc(
			                                   utf16_name_size * sizeof( uint16_t ) );

			if( utf16_name != NULL )
			{
				/* Exercise the "UTF-16 string too small" branch
				 */
				libfusn_record_get_utf16_name(
				 record,
				 utf16_name,
				 1,
				 &error );

				libfusn_error_free(
				 &error );

				/* Exercise the UTF-16 stream to UTF-16 string conversion
				 */
				libfusn_record_get_utf16_name(
				 record,
				 utf16_name,
				 utf16_name_size,
				 NULL );

				free(
				 utf16_name );
			}
		}
	}
	/* Exercise the "invalid record" error branches of the getter functions
	 */
	libfusn_record_get_size(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_update_time(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_file_reference(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_parent_file_reference(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_update_sequence_number(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_update_reason_flags(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_update_source_flags(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_file_attribute_flags(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_utf8_name_size(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_utf8_name(
	 NULL,
	 NULL,
	 1,
	 NULL );

	libfusn_record_get_utf16_name_size(
	 NULL,
	 NULL,
	 NULL );

	libfusn_record_get_utf16_name(
	 NULL,
	 NULL,
	 1,
	 NULL );

	/* Exercise the "invalid record" and "record already set" error branches
	 * of the initialize function and the "invalid record" error branch of
	 * the free function
	 */
	libfusn_record_initialize(
	 NULL,
	 NULL );

	libfusn_record_initialize(
	 &record,
	 NULL );

	libfusn_record_free(
	 NULL,
	 NULL );

	if( libfusn_record_free(
	     &record,
	     &error ) != 1 )
	{
		if( error != NULL )
		{
			libfusn_error_free(
			 &error );
		}
	}
	return( 0 );
}

} /* extern "C" */
