# - Build a config.h file
# 

ADD_DEFINITIONS("-DHAVE_CONFIG_H")

#Platform checks
INCLUDE (CheckTypeSize)
CHECK_TYPE_SIZE("uint64_t" HAVE_UINT64_T)

INCLUDE (CheckFunctionExists)
CHECK_FUNCTION_EXISTS("strndup" HAVE_STRNDUP)
CHECK_FUNCTION_EXISTS("strlcpy" HAVE_STRLCPY)
CHECK_FUNCTION_EXISTS("setenv" HAVE_SETENV)
CHECK_FUNCTION_EXISTS("ldexpf" HAVE_LDEXPF)
CHECK_FUNCTION_EXISTS("realpath" HAVE_REALPATH)
CHECK_FUNCTION_EXISTS("mmap" HAVE_MMAP)
CHECK_FUNCTION_EXISTS("_aligned_malloc" HAVE_ALIGNED_MALLOC)
CHECK_FUNCTION_EXISTS("memalign" HAVE_MEMALIGN)
CHECK_FUNCTION_EXISTS("posix_memalign" HAVE_POSIX_MEMALIGN)

INCLUDE(CheckIncludeFiles)
CHECK_INCLUDE_FILES("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILES("malloc.h" HAVE_MALLOC_H)
CHECK_INCLUDE_FILES("langinfo.h" HAVE_LANGINFO_H)
CHECK_INCLUDE_FILES("dlfcn.h" HAVE_DLFCN_H)

IF(HAVE_MMAP OR WIN32)
	SET(SUPPORTS_MEMSTREAM 1)
ENDIF()

#Unneeded on windows
IF(NOT WIN32)
	INCLUDE (CheckCXXSourceCompiles)
	CHECK_CXX_SOURCE_COMPILES("typedef void *(* voidvoid)(void);

		void *object = 0;
		voidvoid function;
		function = (voidvoid) object;
		" PERMITS_OBJECT_TO_FUNCTION_CAST)

	IF( NOT PERMITS_OBJECT_TO_FUNCTION_CAST )
		SET(HAVE_FORBIDDEN_OBJECT_TO_FUNCTION_CAST 1)
	ENDIF( NOT PERMITS_OBJECT_TO_FUNCTION_CAST )
ENDIF(NOT WIN32)

IF(OPENAL_INCLUDE_DIR AND EXISTS "${OPENAL_INCLUDE_DIR}/efx.h")
	SET(HAVE_OPENAL_EFX_H 1)
ENDIF()

IF (MINGW)
	SET (WIN32_USE_STDIO Yes)
ENDIF ()
if (WIN32_USE_STDIO OR APPLE)
	SET (NOCOLOR Yes)
ENDIF()

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config.h ESCAPE_QUOTES)
