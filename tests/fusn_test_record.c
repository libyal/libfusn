/*
 * Library record type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fusn_test_libcerror.h"
#include "fusn_test_libcstring.h"
#include "fusn_test_libfusn.h"
#include "fusn_test_macros.h"
#include "fusn_test_memory.h"
#include "fusn_test_unused.h"

uint8_t fusn_test_record_byte_stream[ 80 ] = {
	0x50, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
	0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x50, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x8a, 0x5b, 0x3a, 0x41, 0xb4, 0x2b, 0xd1, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x04, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x12, 0x00, 0x3c, 0x00, 0x66, 0x00, 0x69, 0x00,
	0x72, 0x00, 0x73, 0x00, 0x74, 0x00, 0x2e, 0x00, 0x74, 0x00, 0x78, 0x00, 0x74, 0x00, 0x00, 0x00 };

/* Tests the libfusn_record_initialize function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_initialize(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	int result               = 0;

	/* Test libfusn_record_initialize
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_free(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_initialize(
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	record = (libfusn_record_t *) 0x12345678UL;

	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	record = NULL;

#if defined( HAVE_FUSN_TEST_MEMORY )

	/* Test libfusn_record_initialize with malloc failing
	 */
	fusn_test_malloc_attempts_before_fail = 0;

	result = libfusn_record_initialize(
	          &record,
	          &error );

	if( fusn_test_malloc_attempts_before_fail != -1 )
	{
		fusn_test_malloc_attempts_before_fail = -1;

		if( record != NULL )
		{
			libfusn_record_free(
			 &record,
			 NULL );
		}
	}
	else
	{
		FUSN_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FUSN_TEST_ASSERT_IS_NULL(
		 "record",
		 record );

		FUSN_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfusn_record_initialize with memset failing
	 */
	fusn_test_memset_attempts_before_fail = 0;

	result = libfusn_record_initialize(
	          &record,
	          &error );

	if( fusn_test_memset_attempts_before_fail != -1 )
	{
		fusn_test_memset_attempts_before_fail = -1;

		if( record != NULL )
		{
			libfusn_record_free(
			 &record,
			 NULL );
		}
	}
	else
	{
		FUSN_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FUSN_TEST_ASSERT_IS_NULL(
		 "record",
		 record );

		FUSN_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FUSN_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_free function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfusn_record_free(
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to copy security descriptor from byte stream
	 */
	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_copy_from_byte_stream(
	          NULL,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          NULL,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          0,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          60,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_size function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint32_t size            = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve size
	 */
	result = libfusn_record_get_size(
	          record,
	          &size,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_size(
	          NULL,
	          &size,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_size(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_time function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_time(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint64_t update_time     = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve update time
	 */
	result = libfusn_record_get_update_time(
	          record,
	          &update_time,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_update_time(
	          NULL,
	          &update_time,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_update_time(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_file_reference function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_file_reference(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint64_t file_reference  = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve file reference
	 */
	result = libfusn_record_get_file_reference(
	          record,
	          &file_reference,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_file_reference(
	          NULL,
	          &file_reference,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_file_reference(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_parent_file_reference function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_parent_file_reference(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint64_t file_reference  = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve parent file reference
	 */
	result = libfusn_record_get_parent_file_reference(
	          record,
	          &file_reference,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_parent_file_reference(
	          NULL,
	          &file_reference,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_parent_file_reference(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_sequence_number function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_sequence_number(
     void )
{
	libcerror_error_t *error        = NULL;
	libfusn_record_t *record        = NULL;
	uint64_t update_sequence_number = 0;
	int result                      = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve update sequence number
	 */
	result = libfusn_record_get_update_sequence_number(
	          record,
	          &update_sequence_number,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_update_sequence_number(
	          NULL,
	          &update_sequence_number,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_update_sequence_number(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_reason_flags function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_reason_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint32_t flags           = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve update reason flags
	 */
	result = libfusn_record_get_update_reason_flags(
	          record,
	          &flags,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_update_reason_flags(
	          NULL,
	          &flags,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_update_reason_flags(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_source_flags function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_source_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint32_t flags           = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve update source flags
	 */
	result = libfusn_record_get_update_source_flags(
	          record,
	          &flags,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_update_source_flags(
	          NULL,
	          &flags,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_update_source_flags(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_file_attribute_flags function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_file_attribute_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	uint32_t flags           = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve file attribute flags
	 */
	result = libfusn_record_get_file_attribute_flags(
	          record,
	          &flags,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_file_attribute_flags(
	          NULL,
	          &flags,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_file_attribute_flags(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_utf8_name_size function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_utf8_name_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve UTF-8 string size
	 */
	result = libfusn_record_get_utf8_name_size(
	          record,
	          &utf8_string_size,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_utf8_name_size(
	          NULL,
	          &utf8_string_size,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_utf8_name_size(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_utf16_name_size function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_utf16_name_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfusn_record_initialize(
	          &record,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_byte_stream,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve UTF-16 string size
	 */
	result = libfusn_record_get_utf16_name_size(
	          record,
	          &utf16_string_size,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfusn_record_get_utf16_name_size(
	          NULL,
	          &utf16_string_size,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libfusn_record_get_utf16_name_size(
	          record,
	          NULL,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FUSN_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfusn_record_free(
	          &record,
	          NULL );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FUSN_TEST_ASSERT_IS_NULL(
         "record",
         record );

        FUSN_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( record != NULL )
	{
		libfusn_record_free(
		 &record,
		 NULL );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FUSN_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FUSN_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FUSN_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FUSN_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FUSN_TEST_UNREFERENCED_PARAMETER( argc )
	FUSN_TEST_UNREFERENCED_PARAMETER( argv )

	FUSN_TEST_RUN(
	 "libfusn_record_initialize",
	 fusn_test_record_initialize );

	FUSN_TEST_RUN(
	 "libfusn_record_free",
	 fusn_test_record_free );

	FUSN_TEST_RUN(
	 "libfusn_record_copy_from_byte_stream",
	 fusn_test_record_copy_from_byte_stream );

	FUSN_TEST_RUN(
	 "libfusn_record_get_size",
	 fusn_test_record_get_size );

	FUSN_TEST_RUN(
	 "libfusn_record_get_update_time",
	 fusn_test_record_get_update_time );

	FUSN_TEST_RUN(
	 "libfusn_record_get_file_reference",
	 fusn_test_record_get_file_reference );

	FUSN_TEST_RUN(
	 "libfusn_record_get_parent_file_reference",
	 fusn_test_record_get_parent_file_reference );

	FUSN_TEST_RUN(
	 "libfusn_record_get_update_sequence_number",
	 fusn_test_record_get_update_sequence_number );

	FUSN_TEST_RUN(
	 "libfusn_record_get_update_reason_flags",
	 fusn_test_record_get_update_reason_flags );

	FUSN_TEST_RUN(
	 "libfusn_record_get_update_source_flags",
	 fusn_test_record_get_update_source_flags );

	FUSN_TEST_RUN(
	 "libfusn_record_get_file_attribute_flags",
	 fusn_test_record_get_file_attribute_flags );

	FUSN_TEST_RUN(
	 "libfusn_record_get_utf8_name_size",
	 fusn_test_record_get_utf8_name_size );

	/* TODO: add test for libfusn_record_get_utf8_name */

	FUSN_TEST_RUN(
	 "libfusn_record_get_utf16_name_size",
	 fusn_test_record_get_utf16_name_size );

	/* TODO: add test for libfusn_record_get_utf16_name */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

