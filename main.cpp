#include <iostream>

class AirConditioning {
	int max_temp;
	int speed;
	bool fan_broken;
	bool fan_running;
public:
	AirConditioning() {
		this->max_temp = 22;
	}
	AirConditioning(int max_temp) : max_temp(max_temp) {};
	bool verify_temperature() {

	}
	void set_fan_speed() {
		std::cout << "wybierz predkosc z zakresu 1-5: ";
		std::cin >> this->speed;
	}
	bool is_fan_broken() {
		return this->fan_broken;
	}
	void report_damage() {
		std::cout << "wentylator jest uszkodzony";
	}
	void start_fan() {
		if (this->is_fan_broken()) this->report_damage();
		else {
			this->fan_running = true;
			std::cout << "uruchomiono wentylator";
		}
		
	}
	void start_fan() {
		this->fan_running = false;
		std::cout << "zatrzymano wentylator";
	}

};

int main() {

	AirConditioning ac(20);

	return 0;
}