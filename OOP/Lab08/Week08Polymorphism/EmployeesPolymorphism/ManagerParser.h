#pragma once
#include "IParsable.h"

class ManagerParser : public IParsable {
public:
	Object* parse(string) override;
	string parsedObjectName() override;
};