#include "GateFactory.h"
#include "AcademicGate.h"
#include "BusinessGate.h"
#include "PowerGate.h"

Gate* GateFactory::createGate(GateType type) {
	Gate* result = nullptr;
	switch (type)
	{
	case POWER:
		result = new PowerGate();
		break;
	case ACADEMIC:
		result = new AcademicGate();
		break;
	case BUSINESS:
		result = new BusinessGate();
		break;
	default:
		break;
	}

	return result;
}