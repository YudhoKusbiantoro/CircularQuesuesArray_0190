#include <iostream>
using namespace std;

//CircularQuesuesArray_0190
// Min commit = 15
class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}
