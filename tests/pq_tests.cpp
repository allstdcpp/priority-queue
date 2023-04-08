#include <catch.hpp>
#include <priority-queue/priority_queue.hpp>

TEST_CASE("priority_queue tests") {
    ds::priority_queue<int> pq{};

    SECTION("a new priority queue should have a size of 0 and be empty") {
        REQUIRE(pq.size() == 0);
        REQUIRE(pq.empty());
    }

    SECTION("adding a element") {

        pq.push_back(100);

        SECTION("should have a size of 1 and not be empty") {
            REQUIRE(pq.size() == 1);
            REQUIRE_FALSE(pq.empty());
        }

        SECTION("the max value returned should be correct") {
            REQUIRE(pq.top() == 100);
        }

        SECTION("pushing a larger value") {
            pq.push_back(200);

            SECTION("the max value returned should be correct") {
                REQUIRE(pq.top() == 200);
            }

            SECTION("pushing 3 values consequatively larger") {
                pq.push_back(300);
                pq.push_back(400);
                pq.push_back(500);

                SECTION("the max value returned should be correct") {
                    REQUIRE(pq.top() == 500);
                }

                SECTION("removing the top should pop it leaving the next largest value as the top") {
                    pq.pop_front();
                    REQUIRE(pq.top() == 400);

                    SECTION("removing the next top should pop it leaving the next largest value as the top") {
                        pq.pop_front();
                        REQUIRE(pq.top() == 300);
                    }
                }

            }



        }

    }
}
