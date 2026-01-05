#include <iostream>
#include "template_header.h"

using namespace std;

extern template void displayTypeInfo(int value);

int main() {
    int intValue = 42;
    displayTypeInfo(intValue); // Uses the extern template instantiation

    intValue = 55;
    displayTypeInfo(intValue); // Uses the extern template instantiation

    return 0;
}