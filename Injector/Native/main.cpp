#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

enum class ArgState {
	NONE,
	INJECT,
	UNINJECT
};

auto main(int argc, char** argv) -> int {
	cout << "Hello, World!" << endl;

	auto currentState = ArgState::NONE;
	for(int i = 0; i < argc; i++) {
		string argStr = string(argv[i]);
		//If theres no state, we are expecting one. If one isnt provided, keep going until one is.
		if(currentState == ArgState::NONE) {
			if(argStr == "-i") {
				currentState = ArgState::INJECT;
			}
		}
		//If there is a Inject state, we are expecting a file name to inject.
		if(currentState == ArgState::INJECT) {
			string path = argStr;
			//TODO: Inject dll
		}
		cout << argv[i] << endl;
	}
	return 0;
};