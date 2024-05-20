#include "ParserFactory.h"

void ParserFactory::registerWith(IParsable* parser) {
	_container.insert({ parser->parsedObjectName(), parser });
}

IParsable* ParserFactory::create(string type) {
	return _container[type];
}

string ParserFactory::toString() {
	return "ParserFactory";
}