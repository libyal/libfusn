/*
 * Debug functions
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
#include <types.h>

#include "libfusn_debug.h"
#include "libfusn_definitions.h"
#include "libfusn_libcerror.h"
#include "libfusn_libcnotify.h"

#if defined( HAVE_DEBUG_OUTPUT )

/* Prints the update reason flags
 */
void libfusn_debug_print_update_reason_flags(
      uint32_t update_reason_flags )
{
/* TODO add description */
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_DATA_OVERWRITE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_DATA_OVERWRITE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_DATA_EXTEND ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_DATA_EXTEND)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_DATA_TRUNCATION ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_DATA_TRUNCATION)\n" );
	}

	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_NAMED_DATA_OVERWRITE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_NAMED_DATA_OVERWRITE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_NAMED_DATA_EXTEND ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_NAMED_DATA_EXTEND)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_NAMED_DATA_TRUNCATION ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_NAMED_DATA_TRUNCATION)\n" );
	}

	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_FILE_CREATE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_FILE_CREATE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_FILE_DELETE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_FILE_DELETE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_EXTENDED_ATTRIBUTE_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_EA_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_SECURITY_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_SECURITY_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_RENAME_OLD_NAME ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_RENAME_OLD_NAME)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_RENAME_NEW_NAME ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_RENAME_NEW_NAME)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_INDEXABLE_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_INDEXABLE_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_BASIC_INFO_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_BASIC_INFO_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_HARD_LINK_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_HARD_LINK_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_COMPRESSION_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_COMPRESSION_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_ENCRYPTION_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_ENCRYPTION_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_OBJECT_IDENTIFIER_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_OBJECT_IDENTIFIER_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_REPARSE_POINT_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_REPARSE_POINT_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_STREAM_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_STREAM_CHANGE)\n" );
	}
	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_TRANSACTED_CHANGE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_TRANSACTED_CHANGE)\n" );
	}

	if( ( update_reason_flags & LIBFUSN_UPDATE_REASON_FLAG_CLOSE ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_REASON_CLOSE)\n" );
	}
}

/* Prints the update source flags
 */
void libfusn_debug_print_update_source_flags(
      uint32_t update_source_flags )
{
/* TODO add description */
	if( ( update_source_flags & LIBFUSN_UPDATE_SOURCE_FLAG_DATA_MANAGEMENT ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_SOURCE_DATA_MANAGEMENT)\n" );
	}
	if( ( update_source_flags & LIBFUSN_UPDATE_SOURCE_FLAG_AUXILIARY_DATA ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_SOURCE_AUXILIARY_DATA)\n" );
	}
	if( ( update_source_flags & LIBFUSN_UPDATE_SOURCE_FLAG_REPLICATION_MANAGEMENT ) != 0 )
	{
		libcnotify_printf(
		 "\t(USN_SOURCE_REPLICATION_MANAGEMENT)\n" );
	}
}

/* Prints the file attribute flags
 */
void libfusn_debug_print_file_attribute_flags(
      uint32_t file_attribute_flags )
{
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_READ_ONLY ) != 0 )
	{
		libcnotify_printf(
		 "\tIs read-only (FILE_ATTRIBUTE_READ_ONLY)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_HIDDEN ) != 0 )
	{
		libcnotify_printf(
		 "\tIs hidden (FILE_ATTRIBUTE_HIDDEN)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_SYSTEM ) != 0 )
	{
		libcnotify_printf(
		 "\tIs system (FILE_ATTRIBUTE_SYSTEM)\n" );
	}

	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_DIRECTORY ) != 0 )
	{
		libcnotify_printf(
		 "\tIs directory (FILE_ATTRIBUTE_DIRECTORY)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_ARCHIVE ) != 0 )
	{
		libcnotify_printf(
		 "\tShould be archived (FILE_ATTRIBUTE_ARCHIVE)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_DEVICE ) != 0 )
	{
		libcnotify_printf(
		 "\tIs device (FILE_ATTRIBUTE_DEVICE)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_NORMAL ) != 0 )
	{
		libcnotify_printf(
		 "\tIs normal (FILE_ATTRIBUTE_NORMAL)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_TEMPORARY ) != 0 )
	{
		libcnotify_printf(
		 "\tIs temporary (FILE_ATTRIBUTE_TEMPORARY)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_SPARSE_FILE ) != 0 )
	{
		libcnotify_printf(
		 "\tIs a sparse file (FILE_ATTRIBUTE_SPARSE_FILE)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_REPARSE_POINT ) != 0 )
	{
		libcnotify_printf(
		 "\tIs a reparse point or symbolic link (FILE_ATTRIBUTE_FLAG_REPARSE_POINT)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_COMPRESSED ) != 0 )
	{
		libcnotify_printf(
		 "\tIs compressed (FILE_ATTRIBUTE_COMPRESSED)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_OFFLINE ) != 0 )
	{
		libcnotify_printf(
		 "\tIs offline (FILE_ATTRIBUTE_OFFLINE)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_NOT_CONTENT_INDEXED ) != 0 )
	{
		libcnotify_printf(
		 "\tContent should not be indexed (FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)\n" );
	}
	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_ENCRYPTED ) != 0 )
	{
		libcnotify_printf(
		 "\tIs encrypted (FILE_ATTRIBUTE_ENCRYPTED)\n" );
	}

	if( ( file_attribute_flags & LIBFUSN_FILE_ATTRIBUTE_FLAG_VIRTUAL ) != 0 )
	{
		libcnotify_printf(
		 "\tIs virtual (FILE_ATTRIBUTE_VIRTUAL)\n" );
	}
}

#endif

