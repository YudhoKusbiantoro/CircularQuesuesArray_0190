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

	void insert() {
		int num;
		cout << "Enter a number : ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		// cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika REAR berapa di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element delete from the queue is :" << queue_array[FRONT] << "\N";

		//cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {

		int FRONT_Posisition = FRONT;
		int REAR_Posisition = REAR;

		// cek apakah antrian kosong 
		if (FRONT_Posisition == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElements in the queue are...\n";

		// jika FRONT <= REAR, iterasi dari FRONT hingga REAR 
		if (FRONT_Posisition <= REAR_Posisition) {
			while (FRONT_Posisition <= REAR_Posisition) {
				cout << queue_array[FRONT_Posisition] << "   ";
				FRONT_Posisition++;
			}
			cout << endl;
		}
		else {
			// jika FRONT > REAR, iterasi dari FRONT hingga akhir array
			while (FRONT_Posisition <= max - 1) {
				cout << queue_array[FRONT_Posisition] << "   ";
				FRONT_Posisition++;
			}

			FRONT_Posisition = 0;

			// iterasi dari awal array hingga REAR
			while (FRONT_Posisition <= REAR_Posisition) {
				cout << queue_array[FRONT_Posisition] << "   ";
				FRONT_Posisition++;
			}
			cout << endl;
		}
	}
};

int main()
{
	queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement delete operation" << endl;
			cout << "3. Display values" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
};