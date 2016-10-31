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

	/* TODO: add test for libfusn_record_copy_from_byte_stream */
	/* TODO: add test for libfusn_record_get_size */
	/* TODO: add test for libfusn_record_get_update_time */
	/* TODO: add test for libfusn_record_get_file_reference */
	/* TODO: add test for libfusn_record_get_parent_file_reference */
	/* TODO: add test for libfusn_record_get_update_sequence_number */
	/* TODO: add test for libfusn_record_get_update_reason_flags */
	/* TODO: add test for libfusn_record_get_update_source_flags */
	/* TODO: add test for libfusn_record_get_file_attribute_flags */
	/* TODO: add test for libfusn_record_get_utf8_name_size */
	/* TODO: add test for libfusn_record_get_utf8_name */
	/* TODO: add test for libfusn_record_get_utf16_name_size */
	/* TODO: add test for libfusn_record_get_utf16_name */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

