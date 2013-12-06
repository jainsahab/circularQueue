# Creates a myfile.c source file, myfileTest.c test file and testUtils.h header file
# ./createScaffold.sh mymath.c
# Edited Oct 26, 2013.
# Treats multiple asserts in one test as a single test
# prints the failed expression also.
# More accurate in locating crashes in setup and teardown

source=$1
testHeader='testUtils.h'
header=`echo $source |sed -e s/.c$/.h/`
testSource=`echo $source |sed -e s/.c$/Test.c/`
fileCount=`ls $testHeader $testSource $source 2>nul| wc -l`
if [ "$fileCount" -gt "0" ]; then
	echo 'skipping code generation as current files will be overwritten'
	exit
fi
touch $header
cat > $source <<END_OF_SOURCE
#include "$header"
END_OF_SOURCE
cat > $testSource <<END_OF_TESTSOURCE
#include "$testHeader"
#include "$header"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_fail(){
	ASSERT(0);
}
END_OF_TESTSOURCE
cat > $testHeader <<END_OF_TEST_HEADER
void testFailed(const char* fileName, int lineNumber, char* expression);
#define ASSERT(expr) \
	if(!(expr)) testFailed(__FILE__,__LINE__,#expr)
END_OF_TEST_HEADER
