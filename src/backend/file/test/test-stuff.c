/*
 * Created 20010320 by bstanley to hold only those
 * testing functions which are independent of the rest of
 * the GNUCash system.
 *
 * This allows me to compile simple test programs standalone...
 *
 */


#include "config.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "test-stuff.h"

void vsuccess_args(
		const char *test_title,
		const char *file,
		int line,
		const char *format,
		va_list ap);

void vfailure_args(
		const char *test_title,
		const char *file,
		int line,
		const char *format,
		va_list ap);

static guint successes;
static guint failures;
static gboolean success_should_print = FALSE;

void
success_call(
		const char *test_title,
		const char* file,
		int line )
{
	success_args( test_title, file, line, "" );
}

void
success_args(
		const char *test_title,
		const char *file,
		int line,
		const char *format,
		... )
{
	va_list ap;
	va_start(ap,format);
	vsuccess_args( test_title, file, line, format, ap );
	va_end(ap);
}

void
vsuccess_args(
		const char *test_title,
		const char *file,
		int line,
		const char *format,
		va_list ap)
{
	if( success_should_print ) {
		printf("SUCCESS: %s, %s:%d ", test_title, file, line );
		vprintf(format, ap);
		printf("\n");
		fflush(stdout);
	}
	++successes;
}

void
failure_call(
		const char *test_title,
		const char *file,
		int line)
{
	failure_args( test_title, file, line, "" );
}


void
failure_args(
		const char *test_title,
		const char *file,
		int line,
		const char *format,
		... )
{
	va_list ap;
	va_start(ap,format);
	vfailure_args( test_title, file, line, format, ap );
	va_end(ap);
}
void
vfailure_args(
		const char *test_title,
		const char* file,
		int line,
		const char *format,
		va_list ap)
{
	printf("FAILURE %s %s:%d ", test_title, file, line );
	vprintf(format, ap);
	printf("\n");
	fflush(stdout);

	++failures;
}

int
get_rv(void)
{
	if( failures ) {
		return 1;
	}
	return 0;
}

void
do_test_call(
    gboolean result,
    const char* test_title,
    const char* filename,
    int line )
{
	if( result ) {
		success_args( test_title, filename, line, "" );
	} else {
		failure_args( test_title, filename, line, "" );
	}
}

void
do_test_args(
	gboolean result,
	const char* test_title,
	const char* filename,
	int line,
	const char* format,
	... )
{
	va_list ap;
	va_start(ap, format);

	if( result ) {
		vsuccess_args( test_title, filename, line, format, ap );
	} else {
		vfailure_args( test_title, filename, line, format, ap );
	}
	va_end(ap);
}

void
print_test_results(void)
{
	guint total = successes+failures;
	if( total == 1 ) {
		printf( "Executed 1 test." );
	} else {
		printf("Executed %d tests.", successes+failures );
	}
	if( failures ) {
		if( failures == 1 ) {
			printf(" There was 1 failure." );
		} else {
			printf(" There were %d failures.", failures );
		}
	} else {
		printf(" All tests passed.");
	}
	printf("\n");
	fflush(stdout);
}

void
set_success_print( gboolean in_should_print )
{
	success_should_print = in_should_print;
}

