#include "InputGateProvider.h"
#include "AcademicGate.h"
#include "BusinessGate.h"
#include "PowerGate.h"

Gate* InputGateProvider::inputGate(GateType type) {
	Gate* result = nullptr;
	float power = 0, wisdom = 0, cost = 0;
	int num = 0;

	switch (type)
	{
	case POWER:
		cout << "Enter power of Gate: ";
		cin >> power;
		result = new PowerGate(power);
		break;
	case ACADEMIC:
		cout << "Enter wisdom of Gate: ";
		cin >> wisdom;
		result = new AcademicGate(wisdom);
		break;
	case BUSINESS:
		cout << "Enter cost and number of goods in Gate: ";
		cin >> cost >> num;
		result = new BusinessGate(cost, num);
		break;
	default:
		break;
	}

	return result;
}