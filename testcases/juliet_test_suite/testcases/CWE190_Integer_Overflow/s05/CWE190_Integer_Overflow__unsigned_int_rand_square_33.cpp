/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_square_33.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <math.h>

namespace CWE190_Integer_Overflow__unsigned_int_rand_square_33
{

#ifndef OMITBAD

void bad()
{
    unsigned int data;
    unsigned int &dataRef = data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    {
        unsigned int data = dataRef;
        {
            /* POTENTIAL FLAW: if (data*data) > UINT_MAX, this will overflow */
            unsigned int result = data * data;
            printUnsignedLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    unsigned int data;
    unsigned int &dataRef = data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    {
        unsigned int data = dataRef;
        {
            /* POTENTIAL FLAW: if (data*data) > UINT_MAX, this will overflow */
            unsigned int result = data * data;
            printUnsignedLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    unsigned int data;
    unsigned int &dataRef = data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    {
        unsigned int data = dataRef;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (abs((long)data) <= (long)sqrt((double)UINT_MAX))
        {
            unsigned int result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE190_Integer_Overflow__unsigned_int_rand_square_33; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
