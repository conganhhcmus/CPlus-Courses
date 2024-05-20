#pragma once
#include "Object.h"
#include "IParsable.h"
#include "map"

using namespace std;

class ParserFactory : public Object {
private:
	map<string, IParsable*> _container;

public:
	void registerWith(IParsable*);
	IParsable* create(string);
	string toString() override;
};