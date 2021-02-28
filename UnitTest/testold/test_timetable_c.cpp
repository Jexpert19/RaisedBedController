#include <catch2/catch.hpp>

extern "C" {

#define UNIT_TEST

#include <timetable.c>

}


TEST_CASE("Test x", "[timetable_h]") {

	//add timer
	timetable_add(0, 3, 5, 0);

	timetable_add(0, 3, 5, 0);

	timetable_add(0, 3, 5, 1);

	timetable_entry* x = timetable_get(1);

	timetable_delete(0);


	REQUIRE(x);
}

