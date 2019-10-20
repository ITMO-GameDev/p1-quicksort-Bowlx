#include "pch.h"
#include "../Array/array.h"

TEST(ArrayTests, initTest) {
	Array<int> d;
	EXPECT_TRUE(d.size()==0);
	EXPECT_TRUE(d.capacity() == 8);

	Array<int> c(42);
	EXPECT_TRUE(c.size() == 0);
	EXPECT_TRUE(c.capacity() == 42);
}

TEST(ArrayTests, insertTest) {
	Array<int> d;
	d.insert(5);
	d.insert(5);
	d.insert(0 , 4);
	d.insert(3, 15);
	EXPECT_TRUE(d[0] == 4);
	EXPECT_TRUE(d[1] == 5);
	EXPECT_TRUE(d[3] == 15);
	EXPECT_TRUE(d.size() == 4);
	ASSERT_ANY_THROW(d.insert(125, 5));
}

TEST(ArrayTests, removeTest) {
	Array<int> d;
	d.insert(1);
	d.insert(2);
	d.insert(0, 3);
	d.remove(1);
	EXPECT_TRUE(d[0] == 3);
	EXPECT_TRUE(d[1] == 2);
	EXPECT_TRUE(d.size() == 2);
	ASSERT_ANY_THROW(d.insert(125, 5));
}

TEST(ArrayTests, test) {
	Array<int> a;
	for (int i = 0; i < 1110; ++i)
		a.insert(i);
	for (int i = 0; i < a.size(); ++i)
		a[i] *= 2;
	for (int i = 0; i < a.size(); ++i)
		EXPECT_TRUE(a[i] == i * 2);
}

TEST(ArrayTests, iteratorInitTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	EXPECT_TRUE(it.get() == 0);
	EXPECT_FALSE(it.hasPrev());
	
}
TEST(ArrayTests, iteratorForwardMoveTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	it.next();
	EXPECT_TRUE(it.get() == 1);
	it.next();
	EXPECT_TRUE(it.get() == 2);
	EXPECT_FALSE(it.hasNext());
}
TEST(ArrayTests, iteratorBackMoveTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	it.toIndex(2);
	EXPECT_TRUE(it.get() == 2);
	it.prev();
	EXPECT_TRUE(it.get() == 1);
	it.prev();
	EXPECT_FALSE(it.hasPrev());
}

TEST(ArrayTests, iteratorSetTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	it.set(5);
	EXPECT_TRUE(it.get() == 5);
	EXPECT_TRUE(a.size() == 3);
}

TEST(ArrayTests, iteratorInsertTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	it.insert(5);
	EXPECT_TRUE(it.get() == 5);
	EXPECT_TRUE(a.size() == 4);
}

TEST(ArrayTests, iteratorRemoveTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	it.remove();
	EXPECT_TRUE(it.get()== 1);
	EXPECT_TRUE(a.size() == 2);
}
TEST(ArrayTests, iteratorToIndexTest) {
	Array<int> a;
	for (int i = 0; i < 3; ++i)
		a.insert(i);
	auto it = a.iterator();
	it.toIndex(2);
	EXPECT_TRUE(it.get() == 2);
}