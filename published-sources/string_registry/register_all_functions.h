#pragma once

class BusinessContext;
class FunctionRegistry;

bool registerAllFunctions(FunctionRegistry& registry, BusinessContext& business);
