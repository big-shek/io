#include <iostream>
#include <windows.h>

class Fan{
	int speed = 180;
	bool fan_broken = false;
public:
	bool is_fan_broken() {
		return this->fan_broken;
	}
	void report_damage() {
		std::cout << "wentylator jest uszkodzony";
	}
}

class FanController : public Fan{
	bool fan_running = false;
public:
	void set_fan_speed() {
		std::cout << "wybierz predkosc z zakresu 1-5: ";
		std::cin >> this->speed;
		this->speed *= 60;
	}
	void start_fan() {
		if (this->is_fan_broken()) this->report_damage();
		else {
			this->fan_running = true;
			std::cout << "uruchomiono wentylator" << std::endl;
		}

	}
	void stop_fan() {
		this->fan_running = false;
		std::cout << "zatrzymano wentylator" << std::endl;
	}
}

class AirConditioning : public FanController {
	int max_temp;
	int current_temp;
public:
	AirConditioning() {
		this->max_temp = 22;
	}
	AirConditioning(int max_temp, int current_temp) : max_temp(max_temp), current_temp(current_temp) {};
	
	int fetch_temp_from_temp_controller() {
		return this->current_temp;
	}
	void control_fan() {
		int fetched_temp = this->fetch_temp_from_temp_controller();
		if (fetched_temp >= this->max_temp) {
			this->set_fan_speed();
			if (this->is_fan_broken()) return;
			else {
				this->start_fan();
				while (fetched_temp >= this->max_temp) {
					std::cout << "obecna temperatura: " << fetched_temp << std::endl;
					Sleep(5000);
					this->current_temp--;
					fetched_temp = this->fetch_temp_from_temp_controller();
				}
				this->stop_fan();
				std::cout << "obecna temperatura: " << fetched_temp << std::endl;
			}

		}

	}
};

int main() {

	AirConditioning ac(22, 25);
	ac.control_fan();

	return 0;
}