/*
 * Codepage definitions for libfusn
 *
 * Copyright (C) 2011-2023, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFUSN_CODEPAGE_H )
#define _LIBFUSN_CODEPAGE_H

#include <libfusn/types.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* The codepage definitions
 */
enum LIBFUSN_CODEPAGES
{
	LIBFUSN_CODEPAGE_ASCII				= 20127,

	LIBFUSN_CODEPAGE_ISO_8859_1			= 28591,
	LIBFUSN_CODEPAGE_ISO_8859_2			= 28592,
	LIBFUSN_CODEPAGE_ISO_8859_3			= 28593,
	LIBFUSN_CODEPAGE_ISO_8859_4			= 28594,
	LIBFUSN_CODEPAGE_ISO_8859_5			= 28595,
	LIBFUSN_CODEPAGE_ISO_8859_6			= 28596,
	LIBFUSN_CODEPAGE_ISO_8859_7			= 28597,
	LIBFUSN_CODEPAGE_ISO_8859_8			= 28598,
	LIBFUSN_CODEPAGE_ISO_8859_9			= 28599,
	LIBFUSN_CODEPAGE_ISO_8859_10			= 28600,
	LIBFUSN_CODEPAGE_ISO_8859_11			= 28601,
	LIBFUSN_CODEPAGE_ISO_8859_13			= 28603,
	LIBFUSN_CODEPAGE_ISO_8859_14			= 28604,
	LIBFUSN_CODEPAGE_ISO_8859_15			= 28605,
	LIBFUSN_CODEPAGE_ISO_8859_16			= 28606,

	LIBFUSN_CODEPAGE_KOI8_R				= 20866,
	LIBFUSN_CODEPAGE_KOI8_U				= 21866,

	LIBFUSN_CODEPAGE_WINDOWS_874			= 874,
	LIBFUSN_CODEPAGE_WINDOWS_932			= 932,
	LIBFUSN_CODEPAGE_WINDOWS_936			= 936,
	LIBFUSN_CODEPAGE_WINDOWS_949			= 949,
	LIBFUSN_CODEPAGE_WINDOWS_950			= 950,
	LIBFUSN_CODEPAGE_WINDOWS_1250			= 1250,
	LIBFUSN_CODEPAGE_WINDOWS_1251			= 1251,
	LIBFUSN_CODEPAGE_WINDOWS_1252			= 1252,
	LIBFUSN_CODEPAGE_WINDOWS_1253			= 1253,
	LIBFUSN_CODEPAGE_WINDOWS_1254			= 1254,
	LIBFUSN_CODEPAGE_WINDOWS_1255			= 1255,
	LIBFUSN_CODEPAGE_WINDOWS_1256			= 1256,
	LIBFUSN_CODEPAGE_WINDOWS_1257			= 1257,
	LIBFUSN_CODEPAGE_WINDOWS_1258			= 1258
};

#define LIBFUSN_CODEPAGE_US_ASCII			LIBFUSN_CODEPAGE_ASCII

#define LIBFUSN_CODEPAGE_ISO_WESTERN_EUROPEAN		LIBFUSN_CODEPAGE_ISO_8859_1
#define LIBFUSN_CODEPAGE_ISO_CENTRAL_EUROPEAN		LIBFUSN_CODEPAGE_ISO_8859_2
#define LIBFUSN_CODEPAGE_ISO_SOUTH_EUROPEAN		LIBFUSN_CODEPAGE_ISO_8859_3
#define LIBFUSN_CODEPAGE_ISO_NORTH_EUROPEAN		LIBFUSN_CODEPAGE_ISO_8859_4
#define LIBFUSN_CODEPAGE_ISO_CYRILLIC			LIBFUSN_CODEPAGE_ISO_8859_5
#define LIBFUSN_CODEPAGE_ISO_ARABIC			LIBFUSN_CODEPAGE_ISO_8859_6
#define LIBFUSN_CODEPAGE_ISO_GREEK			LIBFUSN_CODEPAGE_ISO_8859_7
#define LIBFUSN_CODEPAGE_ISO_HEBREW			LIBFUSN_CODEPAGE_ISO_8859_8
#define LIBFUSN_CODEPAGE_ISO_TURKISH			LIBFUSN_CODEPAGE_ISO_8859_9
#define LIBFUSN_CODEPAGE_ISO_NORDIC			LIBFUSN_CODEPAGE_ISO_8859_10
#define LIBFUSN_CODEPAGE_ISO_THAI			LIBFUSN_CODEPAGE_ISO_8859_11
#define LIBFUSN_CODEPAGE_ISO_BALTIC			LIBFUSN_CODEPAGE_ISO_8859_13
#define LIBFUSN_CODEPAGE_ISO_CELTIC			LIBFUSN_CODEPAGE_ISO_8859_14

#define LIBFUSN_CODEPAGE_ISO_LATIN_1			LIBFUSN_CODEPAGE_ISO_8859_1
#define LIBFUSN_CODEPAGE_ISO_LATIN_2			LIBFUSN_CODEPAGE_ISO_8859_2
#define LIBFUSN_CODEPAGE_ISO_LATIN_3			LIBFUSN_CODEPAGE_ISO_8859_3
#define LIBFUSN_CODEPAGE_ISO_LATIN_4			LIBFUSN_CODEPAGE_ISO_8859_4
#define LIBFUSN_CODEPAGE_ISO_LATIN_5			LIBFUSN_CODEPAGE_ISO_8859_9
#define LIBFUSN_CODEPAGE_ISO_LATIN_6			LIBFUSN_CODEPAGE_ISO_8859_10
#define LIBFUSN_CODEPAGE_ISO_LATIN_7			LIBFUSN_CODEPAGE_ISO_8859_13
#define LIBFUSN_CODEPAGE_ISO_LATIN_8			LIBFUSN_CODEPAGE_ISO_8859_14
#define LIBFUSN_CODEPAGE_ISO_LATIN_9			LIBFUSN_CODEPAGE_ISO_8859_15
#define LIBFUSN_CODEPAGE_ISO_LATIN_10			LIBFUSN_CODEPAGE_ISO_8859_16

#define LIBFUSN_CODEPAGE_KOI8_RUSSIAN			LIBFUSN_CODEPAGE_KOI8_R
#define LIBFUSN_CODEPAGE_KOI8_UKRAINIAN			LIBFUSN_CODEPAGE_KOI8_U

#define LIBFUSN_CODEPAGE_WINDOWS_THAI			LIBFUSN_CODEPAGE_WINDOWS_874
#define LIBFUSN_CODEPAGE_WINDOWS_JAPANESE		LIBFUSN_CODEPAGE_WINDOWS_932
#define LIBFUSN_CODEPAGE_WINDOWS_CHINESE_SIMPLIFIED	LIBFUSN_CODEPAGE_WINDOWS_936
#define LIBFUSN_CODEPAGE_WINDOWS_KOREAN			LIBFUSN_CODEPAGE_WINDOWS_949
#define LIBFUSN_CODEPAGE_WINDOWS_CHINESE_TRADITIONAL	LIBFUSN_CODEPAGE_WINDOWS_950
#define LIBFUSN_CODEPAGE_WINDOWS_CENTRAL_EUROPEAN	LIBFUSN_CODEPAGE_WINDOWS_1250
#define LIBFUSN_CODEPAGE_WINDOWS_CYRILLIC		LIBFUSN_CODEPAGE_WINDOWS_1251
#define LIBFUSN_CODEPAGE_WINDOWS_WESTERN_EUROPEAN	LIBFUSN_CODEPAGE_WINDOWS_1252
#define LIBFUSN_CODEPAGE_WINDOWS_GREEK			LIBFUSN_CODEPAGE_WINDOWS_1253
#define LIBFUSN_CODEPAGE_WINDOWS_TURKISH		LIBFUSN_CODEPAGE_WINDOWS_1254
#define LIBFUSN_CODEPAGE_WINDOWS_HEBREW			LIBFUSN_CODEPAGE_WINDOWS_1255
#define LIBFUSN_CODEPAGE_WINDOWS_ARABIC			LIBFUSN_CODEPAGE_WINDOWS_1256
#define LIBFUSN_CODEPAGE_WINDOWS_BALTIC			LIBFUSN_CODEPAGE_WINDOWS_1257
#define LIBFUSN_CODEPAGE_WINDOWS_VIETNAMESE		LIBFUSN_CODEPAGE_WINDOWS_1258

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFUSN_CODEPAGE_H ) */

