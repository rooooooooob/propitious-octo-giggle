#ifndef DS_STATEMENT_HPP
#define DS_STATEMENT_HPP

namespace ds
{

class Context;

class Statement
{
public:
	virtual ~Statement() {}
	
	/**
	 * @return True if statement prematurely finishes (ie function return, etc)
	 */
	virtual bool execute(Context& context) const = 0;

protected:
	Statement() {}

private:
	// deleted
	Statement(const Statement&);
	// deleted
	Statement& operator=(const Statement&);
};

} // ds

#endif // DS_STATEMENT_HPP