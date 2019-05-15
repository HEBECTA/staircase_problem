#include "pch.h"
#include <iostream>
#include <vector>

void print(const std::vector<int> &li) {

	for (auto i = li.begin(); i != li.end(); ++i) {
		
		if ( *i != 0 )
		std::cout << *i << " ";
	}

	std::cout << std::endl;
}

void stairs_nmb(int n) {

	int stairs = 1;

	bool done = false;

	std::vector<int> stair;

	stair.push_back(n);
	stair.push_back(0);

	std::cout << n << std::endl;

	while (!done) {

		done = true;

		if (stair[0] - 1 != stair[1])
			--stair[0];

		else {

			--stair[0];
			break;
		}


		for (int i = stair.size() - 1; i > 0; --i) {

			if (stair[i] + 1 != stair[i - 1]) {

				++stair[i];

				++stairs;

				print(stair);

				if (i == stair.size() - 1) {

					stair.push_back(0);
				}

				i = -1;

				done = false;
			}
		}
	}

	++stair[0];

	//****************************************************************************************

	stair.pop_back();

	if (n > 5) {

		while (n - 3 != stair[0]) {

			if (stair.size() == 2) {

				++stair[0];

				--stair[1];

				++stairs;

				print(stair);
			}

			for (int i = stair.size() - 2; i > 0; --i) {

				if (stair[i] + 1 != stair[i - 1]) {

					++stair[i];

					++stairs;

					if (--stair[stair.size() - 1] == 0) {

						stair.pop_back();
					}

					print(stair);

					i = -1;
				}

				else if (i == 1) {

					++stair[0];

					++stairs;

					if (--stair[stair.size() - 1] == 0) {

						stair.pop_back();
					}

					print(stair);

					i = -1;
				}
			}
		}
	}

	std::cout << "total ways to build stairs is: " << stairs << std::endl;

}

// bad
/*
void combination_of_stairs(const int n) {

	int stairs = 1;

	bool done = false;

	std::vector<int> stair;

	stair.push_back(n);
	stair.push_back(0);

	while (!done) {

		done = true;

		--stair[0];

		for (int i = stair.size() - 1; i > 0; --i) {

				if ( (stair[i] + 1 != stair[i - 1] )  &&  (stair[0] - 1 != stair[1]) ) {

				++stair[i];

				--stair[0];

				++stairs;

				print(stair);

				if (stair.back() != 0) {
					stair.push_back(0);
				}

				i = -1;

				done = false;
			}
		}
	}

	//*******************************************************************

	stair.pop_back();

	while (stair[1] > 3 ) {

		if (stair.size() == 2) {

			++stair[0];

			--stair[1];

			++stairs;

			print(stair);
		}

		for (int i = stair.size() - 2; i > 0; --i) {

			if (stair[i] + 1 != stair[i - 1]) {

				++stair[i];

				++stairs;

				if (--stair[stair.size() - 1] == 0) {

					stair.pop_back();
				}

				print(stair);

				i = -1;
			}

			else if (i == 1) {

				++stair[0];

				++stairs;

				if (--stair[stair.size() - 1] == 0) {

					stair.pop_back();
				}

				print(stair);

				i = - 1;
			}
		}
	}

	std::cout << "total ways to build stairs is: " << stairs << std::endl;
}
*/