#ifndef TESTINGSUITE.H
#define TESTINGSUITE.H
#include "List.h"
#include "Dictionary.h"
#include "Object_Factory.h"
#include "string"

//#define TESTPLAN (Type)

class TestPlan;

class TestPlan
{
public:
	std::string m_planName;
	TestPlan(std::string planName)
	{
		m_planName = planName;
		*getCurrentTestPlan() = this;
	}

	TestPlan** getCurrentTestPlan() {
		static TestPlan* s_pCurrentTestPlan;
		return &s_pCurrentTestPlan;
	}
};

class TestCase
{	
public: 
	double m_time; 
	std::string m_exception;
	List<std::string> m_failedList;
	std::string m_name;
	//time, list of which failed, exception message
	TestCase(double time, std::string exception, List<std::string> failedList, std::string name)
	{
		m_time = time;
		m_exception = exception;
		m_failedList = failedList;
		m_name = name;
	}

private:
	void assert_implementation(bool condition1, bool condition2, std::string sCondition1, std::string sCondition2)
	{
		if (condition1 != condition2)
		{
			m_failedList.push(std::string() + "assertion (" + sCondition1 + " == " + sCondition2 + " failed!");
		}
	}
	virtual void runTestCase() { }

};




#endif
