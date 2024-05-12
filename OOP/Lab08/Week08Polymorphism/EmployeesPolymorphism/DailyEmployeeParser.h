#pragma once
#include "IParsable.h"

class DailyEmployeeParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};