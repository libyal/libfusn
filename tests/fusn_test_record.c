/*
 * Library record type test program
 *
 * Copyright (C) 2011-2017, Joachim Metz <joachim.metz@gmail.com>
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
#include "fusn_test_libfusn.h"
#include "fusn_test_macros.h"
#include "fusn_test_memory.h"
#include "fusn_test_unused.h"

uint8_t fusn_test_record_data1[ 80 ] = {
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
	libcerror_error_t *error        = NULL;
	libfusn_record_t *record        = NULL;
	int result                      = 0;

#if defined( HAVE_FUSN_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
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

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfusn_record_initialize with malloc failing
		 */
		fusn_test_malloc_attempts_before_fail = test_number;

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
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfusn_record_initialize with memset failing
		 */
		fusn_test_memset_attempts_before_fail = test_number;

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

	/* Test regular cases
	 */
	result = libfusn_record_copy_from_byte_stream(
	          record,
	          fusn_test_record_data1,
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
	          fusn_test_record_data1,
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
	          fusn_test_record_data1,
	          (size_t) SSIZE_MAX + 1,
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
	          fusn_test_record_data1,
	          0,
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
	          fusn_test_record_data1,
	          80 / 2,
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
     libfusn_record_t *record )
{
	libcerror_error_t *error = NULL;
	uint32_t size            = 0;
	int result               = 0;
	int size_is_set          = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_size(
	          record,
	          &size,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	size_is_set = result;

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

	if( size_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_time function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_time(
     libfusn_record_t *record )
{
	libcerror_error_t *error = NULL;
	uint64_t update_time     = 0;
	int result               = 0;
	int update_time_is_set   = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_update_time(
	          record,
	          &update_time,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	update_time_is_set = result;

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

	if( update_time_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_file_reference function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_file_reference(
     libfusn_record_t *record )
{
	libcerror_error_t *error  = NULL;
	uint64_t file_reference   = 0;
	int file_reference_is_set = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_file_reference(
	          record,
	          &file_reference,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	file_reference_is_set = result;

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

	if( file_reference_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_parent_file_reference function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_parent_file_reference(
     libfusn_record_t *record )
{
	libcerror_error_t *error         = NULL;
	uint64_t parent_file_reference   = 0;
	int parent_file_reference_is_set = 0;
	int result                       = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_parent_file_reference(
	          record,
	          &parent_file_reference,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	parent_file_reference_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_parent_file_reference(
	          NULL,
	          &parent_file_reference,
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

	if( parent_file_reference_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_sequence_number function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_sequence_number(
     libfusn_record_t *record )
{
	libcerror_error_t *error          = NULL;
	uint64_t update_sequence_number   = 0;
	int result                        = 0;
	int update_sequence_number_is_set = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_update_sequence_number(
	          record,
	          &update_sequence_number,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	update_sequence_number_is_set = result;

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

	if( update_sequence_number_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_reason_flags function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_reason_flags(
     libfusn_record_t *record )
{
	libcerror_error_t *error       = NULL;
	uint32_t update_reason_flags   = 0;
	int result                     = 0;
	int update_reason_flags_is_set = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_update_reason_flags(
	          record,
	          &update_reason_flags,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	update_reason_flags_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_update_reason_flags(
	          NULL,
	          &update_reason_flags,
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

	if( update_reason_flags_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_update_source_flags function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_update_source_flags(
     libfusn_record_t *record )
{
	libcerror_error_t *error       = NULL;
	uint32_t update_source_flags   = 0;
	int result                     = 0;
	int update_source_flags_is_set = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_update_source_flags(
	          record,
	          &update_source_flags,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	update_source_flags_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_update_source_flags(
	          NULL,
	          &update_source_flags,
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

	if( update_source_flags_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_file_attribute_flags function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_file_attribute_flags(
     libfusn_record_t *record )
{
	libcerror_error_t *error        = NULL;
	uint32_t file_attribute_flags   = 0;
	int file_attribute_flags_is_set = 0;
	int result                      = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_file_attribute_flags(
	          record,
	          &file_attribute_flags,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	file_attribute_flags_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_file_attribute_flags(
	          NULL,
	          &file_attribute_flags,
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

	if( file_attribute_flags_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_utf8_name_size function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_utf8_name_size(
     libfusn_record_t *record )
{
	libcerror_error_t *error  = NULL;
	size_t utf8_name_size     = 0;
	int result                = 0;
	int utf8_name_size_is_set = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_utf8_name_size(
	          record,
	          &utf8_name_size,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_utf8_name_size(
	          NULL,
	          &utf8_name_size,
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

	if( utf8_name_size_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_utf8_name function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_utf8_name(
     libfusn_record_t *record )
{
	uint8_t utf8_name[ 512 ];

	libcerror_error_t *error = NULL;
	int result               = 0;
	int utf8_name_is_set     = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_utf8_name(
	          record,
	          utf8_name,
	          512,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_name_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_utf8_name(
	          NULL,
	          utf8_name,
	          512,
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

	if( utf8_name_is_set != 0 )
	{
		result = libfusn_record_get_utf8_name(
		          record,
		          NULL,
		          512,
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

		result = libfusn_record_get_utf8_name(
		          record,
		          utf8_name,
		          0,
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

		result = libfusn_record_get_utf8_name(
		          record,
		          utf8_name,
		          (size_t) SSIZE_MAX + 1,
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_utf16_name_size function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_utf16_name_size(
     libfusn_record_t *record )
{
	libcerror_error_t *error   = NULL;
	size_t utf16_name_size     = 0;
	int result                 = 0;
	int utf16_name_size_is_set = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_utf16_name_size(
	          record,
	          &utf16_name_size,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_utf16_name_size(
	          NULL,
	          &utf16_name_size,
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

	if( utf16_name_size_is_set != 0 )
	{
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfusn_record_get_utf16_name function
 * Returns 1 if successful or 0 if not
 */
int fusn_test_record_get_utf16_name(
     libfusn_record_t *record )
{
	uint16_t utf16_name[ 512 ];

	libcerror_error_t *error = NULL;
	int result               = 0;
	int utf16_name_is_set    = 0;

	/* Test regular cases
	 */
	result = libfusn_record_get_utf16_name(
	          record,
	          utf16_name,
	          512,
	          &error );

	FUSN_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_name_is_set = result;

	/* Test error cases
	 */
	result = libfusn_record_get_utf16_name(
	          NULL,
	          utf16_name,
	          512,
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

	if( utf16_name_is_set != 0 )
	{
		result = libfusn_record_get_utf16_name(
		          record,
		          NULL,
		          512,
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

		result = libfusn_record_get_utf16_name(
		          record,
		          utf16_name,
		          0,
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

		result = libfusn_record_get_utf16_name(
		          record,
		          utf16_name,
		          (size_t) SSIZE_MAX + 1,
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FUSN_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FUSN_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FUSN_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FUSN_TEST_ATTRIBUTE_UNUSED )
#endif
{
	libcerror_error_t *error = NULL;
	libfusn_record_t *record = NULL;
	int result               = 0;

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

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize record for tests
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
	          fusn_test_record_data1,
	          80,
	          &error );

	FUSN_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FUSN_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_size",
	 fusn_test_record_get_size,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_update_time",
	 fusn_test_record_get_update_time,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_file_reference",
	 fusn_test_record_get_file_reference,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_parent_file_reference",
	 fusn_test_record_get_parent_file_reference,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_update_sequence_number",
	 fusn_test_record_get_update_sequence_number,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_update_reason_flags",
	 fusn_test_record_get_update_reason_flags,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_update_source_flags",
	 fusn_test_record_get_update_source_flags,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_file_attribute_flags",
	 fusn_test_record_get_file_attribute_flags,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_utf8_name_size",
	 fusn_test_record_get_utf8_name_size,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_utf8_name",
	 fusn_test_record_get_utf8_name,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_utf16_name_size",
	 fusn_test_record_get_utf16_name_size,
	 record );

	FUSN_TEST_RUN_WITH_ARGS(
	 "libfusn_record_get_utf16_name",
	 fusn_test_record_get_utf16_name,
	 record );

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

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

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
	return( EXIT_FAILURE );
}

