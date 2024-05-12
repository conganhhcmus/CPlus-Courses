#pragma once
#include "IParsable.h"

class ProductEmployeeParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};