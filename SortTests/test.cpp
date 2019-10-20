#include "pch.h"
#include "../QuickSort/sort.h"


namespace tests {
	template<typename T, typename Compare>
	bool isSorted(T* start, T* end, Compare comp) {
		
			while (start < end) {
				if (comp (*(start + 1), *start)) {
					return false;
				}
				start++;
		}
		return true;
	}
	TEST(basicTests, commonIntSortTest) {

		int a[] = { 5,5,6,7,4,6,7,1,2,3,4 };

		quick_sort(a, a + (std::size(a) - 1), [](int a, int b) {return a < b; });

		EXPECT_TRUE(isSorted(a, a + (std::size(a) - 1), [](int a, int b) {return a < b; }));
		

	}

	TEST(basicTests, reverseIntSort) {

		int a[] = { 55,53,52,51,49,47,44,43,42,32,31,30,25,24,23,22,15,11,4,3,2,1,-5 };
		quick_sort(a, a + (std::size(a) - 1), [](int a, int b) {return a < b; });
		EXPECT_TRUE(isSorted(a, a + (std::size(a) - 1), [](int a, int b) {return a < b; }));

	}

	TEST(basicTests, repeatableIntSort) {

		int a[] = { 4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5 };
		quick_sort(a, a + (std::size(a) - 1), [](int a, int b) {return a < b; });
		EXPECT_TRUE(isSorted(a, a + (std::size(a) - 1), [](int a, int b) {return a < b; }));

	}
}
