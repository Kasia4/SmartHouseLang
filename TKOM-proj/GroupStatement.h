
#include <list>
#include "c:\Users\katar\source\repos\SmartHouseLang\TKOM-proj\statement\Statement.h"
#include "Parameter.h"
class GroupStatement :
	public Statement, public Parameter
{
public:
	GroupStatement() = default;
	GroupStatement(std::string& type, std::string& identifier) : Parameter(type, identifier) {};
	void add_component(std::string& name);
	~GroupStatement() = default;
private:
	std::list<std::string> components;
};
